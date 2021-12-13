#include <iostream>
#include <clocale>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

void ConvertMorseToVector(wstring lpText, vector<wstring>& lpBuffer) {
	lpBuffer.clear(); //очистка буффера дл€ внесени€ данных

	for (size_t i = 0; i < lpText.size(); i++) {
		if (lpText[i] == L' ') {
			if (lpText[i + 1] == L' ') {
				lpText.erase(i, 2); //стирание двух символов, €вл€ющихс€ пробелами (двойной пробел)
				lpText.insert(i, L"+ +"); //замена их на конструкцию '+ +' дл€ последующего выделени€
			}
			else if (lpText[i + 1] != L'+') {
				lpText[i] = L'+'; //вставление '+' между буквами
			}
		}
	}
	boost::split(lpBuffer, lpText, boost::is_any_of(L"+")); //разбивка строки на части и занесение в буффер
}

void ToUpperCase(wstring& lpText) {
	for (size_t i = 0; i < lpText.size(); i++) {
		lpText[i] = towupper(lpText[i]); //перевод всех символов в верхний регистр
	}
}

void PrintArray(vector<wstring> lpData) {
	for (size_t i = 0; i < lpData.size(); i++) {
		if (lpData[i] != L" ") {
			wcout << lpData[i] << L" ";
			continue;
		}
		wcout << L" ";
	}
}

void PrintArray(wstring lpData) {
	for (size_t i = 0; i < lpData.size(); i++) {
		wcout << lpData[i];
	}
}

bool CheckWrongChars(wstring lpText) {
	bool bResult = false;
	for (size_t i = 0; i < lpText.size(); i++) {
		if (lpText[i] == L' ') continue;
		if (lpText[i] == L'.' || lpText[i] == L'-')
		{
			bResult = true;
			continue;
		}
		return false;
	}
	return bResult;
}

bool IsEmptyString(wstring lpText) {
	int spacesCount = 0;
	for (size_t i = 0; i < lpText.size(); i++)
	{
		if (lpText[i] == L' ') {
			spacesCount++;
		}
	}
	return (lpText.empty() || spacesCount == lpText.size());
}  

void PrintProgramInfo() {
	_wsystem(L"@TITLE Morse Converter - Made By Zero");
	wcout << L"\033[1;38;05;150m" << L"======= Morse Converter =======\n" << L"\033[0m";
	wcout << L"\033[1;38;05;150m" << L"	    Made By:\n" << L"\033[0m";
	wcout << L"\033[1;38;05;30m" << L"  _____  _____   ____     ___  \n" << L"\033[0m";
	wcout << L"\033[1;38;05;30m" << L" |__  / | ____| |  _ \\   / _ \\ \n" << L"\033[0m";
	wcout << L"\033[1;38;05;30m" << L"   / /  |  _|   | |_) | | | | |\n" << L"\033[0m";
	wcout << L"\033[1;38;05;30m" << L"  / /_  | |___  |  _ <  | |_| |\n" << L"\033[0m";
	wcout << L"\033[1;38;05;30m" << L" /____| |_____| |_| \\_\\  \\___/ \n" << L"\033[0m";
	wcout << L"\033[1;38;05;150m" << L"===============================\n" << L"\033[0m";
}
