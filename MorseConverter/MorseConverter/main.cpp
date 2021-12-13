#include "data.h"

using namespace std;

int main(){
	SetLocaleIn(); //UTF16
	SetLocaleOut(); //UTF16
	_wsetlocale(LC_ALL, L"Russian");

	int inputOption = 0;
	wstring lpText;
	vector<wstring> lpBuffer;

	while (true) {
		PrintProgramInfo();
		wcout << L"\033[1;38;05;189m" << L"What do you want to do:" << L"\033[0m" << endl;
		wcout << L"\033[1;38;05;180m" << L"1) Convert Text to Morse" << L"\033[0m" << endl;
		wcout << L"\033[1;38;05;123m" << L"2) Convert Morse to Russian Text" << L"\033[0m" << endl;
		wcout << L"\033[1;38;05;115m" << L"3) Convert Morse to English Text" << L"\033[0m" << endl;

		do {
			wcout << L">> " << L"\033[1;38;05;166m";
			wcin >> inputOption;
			wcout << L"\033[0m";
			if (inputOption < 1 || inputOption > 3) {
				wcout << L"\033[1;38;05;160m" << L"Error: Operation with that index does not exists" << L"\033[0m" << endl;
				wcin.clear(); //чистка буфера при ошибке
				wcin.ignore(SHRT_MAX, L'\n'); //игнорирование ненужных символов
			}
		} while (inputOption < 1 || inputOption > 3);

		wcin.ignore(SHRT_MAX, L'\n');
		switch (inputOption) {
		case 1:
			do {
				wcout << L"\033[1;38;05;144m" << L"Input: " << L"\033[1;38;05;178m";
				getline(wcin, lpText);
				if (IsEmptyString(lpText)) {
					wcout << L"\033[1;38;05;160m" << L"Error: String is empty" << L"\033[0m" << endl;
					continue;
				}
				TextToMorse(lpText, lpBuffer);
				wcout << L"\033[1;38;05;181m" << L"Output: " << L"\033[1;38;05;168m";
				PrintArray(lpBuffer);
				wcout << L"\033[0m\n";
				break;
			} while (IsEmptyString(lpText));
			break;
		case 2:
			do {
				wcout << L"\033[1;38;05;144m" << L"Input: " << L"\033[1;38;05;178m";
				getline(wcin, lpText);
				if (!CheckWrongChars(lpText)) {
					wcout << L"\033[1;38;05;160m" << L"Error: Wrong characters detected" << L"\033[0m" << endl;
					continue;
				}
				ConvertMorseToVector(lpText, lpBuffer); //эта строка конвертирует последовательность знаков морзе в вектор
				MorseToRussian(lpBuffer, lpText);
				wcout << L"\033[1;38;05;181m" << L"Output: " << L"\033[1;38;05;168m";
				PrintArray(lpText);
				wcout << L"\033[0m\n";
				break;
			} while (!CheckWrongChars(lpText));
			break;
		case 3:
			do {
				wcout << L"\033[1;38;05;144m" << L"Input: " << L"\033[1;38;05;178m";
				getline(wcin, lpText);
				if (!CheckWrongChars(lpText)) {
					wcout << L"\033[1;38;05;160m" << L"Error: Wrong characters detected" << L"\033[0m" << endl;
					continue;
				}
				ConvertMorseToVector(lpText, lpBuffer); //эта строка конвертирует последовательность знаков морзе в вектор
				MorseToEnglish(lpBuffer, lpText);
				wcout << L"\033[1;38;05;180m" << L"Output: " << L"\033[1;38;05;168m";
				PrintArray(lpText);
				wcout << L"\033[0m\n";
				break;
			} while (!CheckWrongChars(lpText));
			break;
		}
		wcout << L"\033[1;38;05;179m" << L"Press any key to continue... " << L"\033[0m";
		wcin.get();
		wcin.clear();
		wcin.ignore(SHRT_MAX, L'\n');
		_wsystem(L"cls");
	}
	return 0;
}

void MorseToRussian(vector<wstring> lpBuffer, wstring& lpText) {
	lpText = wstring(lpBuffer.size(), 0); //инициализируем буфер заново

	for (size_t i = 0; i < lpBuffer.size(); i++) {
		for (size_t j = 0; j < morseLetters.size(); j++) {
			if (lpBuffer[i] == morseLetters[j]) {
				lpText.insert(i, wstring(1, russianLetters[j])); //вставка русского символа при соответствии с символом азбуки морзе
				break;
			}
			else if (lpBuffer[i] == L" ") {
				lpText.insert(i, L" ");
				break;
			}
		}
	}
}

void MorseToEnglish(vector<wstring> lpBuffer, wstring& lpText) {
	lpText = wstring(lpBuffer.size() + 1, 0); //инициализируем буфер заново

	for (size_t i = 0, k = 0; i < lpBuffer.size(); i++) { //i итерирует исходный вектор, j вектор с символами морзе, k итерирует строку 
		for (size_t j = 0; j < morseLetters.size(); j++) {
			if (lpBuffer[i] == morseLetters[j]) {
				lpText.insert(k, wstring(1, englishLetters[j])); //вставка английского символа при соответствии с символом азбуки морзе
				k++;
				break;
			}
			else if (lpBuffer[i] == L"----") {
				lpText.insert(k, L"CH"); //при обнаружении '----' вставляется CH (Ш)
				k += 2;
				break;
			}
			else if (lpBuffer[i] == L" ") {
				lpText.insert(k, L" ");
				k++;
				break;
			}
		}
	}
}

void TextToMorse(wstring lpText, vector<wstring>& lpBuffer) {
	lpBuffer.clear(); //чистим буфер
	ToUpperCase(lpText); //переводим текст в верхний регистр

	for (size_t i = 0; i < lpText.size(); i++) {
		for (size_t j = 0; j < russianLetters.size(); j++) {
			if (lpText[i] == russianLetters[j]) {
				lpBuffer.push_back(morseLetters[j]); //помещение в вектор элемента буквы морзе
				break;
			}
			else if (lpText[i] == englishLetters[j]) {
				lpBuffer.push_back(morseLetters[j]); //помещение в вектор элемента буквы морзе
				break;
			}
			else if (lpText[i] == L'C' && lpText[i + 1] == L'H') {
				lpText.erase(i, 1);
				lpBuffer.push_back(L"----");
				break;
			}
			else if (lpText[i] == L' ') {
				lpBuffer.push_back(L" ");
				break;
			}
		}
	}
}