#pragma once

#include <iostream>
#include <clocale>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

#define SetLocaleOut() _setmode(_fileno(stdout), _O_U16TEXT)
#define SetLocaleIn() _setmode(_fileno(stdin), _O_U16TEXT)

const std::vector<std::wstring> morseLetters = {
	L".-",
	L"-...",
	L".--",
	L"--.",
	L"-..",
	L".",
	L"...-",
	L"--..",
	L"..",
	L".---",
	L"-.-",
	L".-..",
	L"--",
	L"-.",
	L"---",
	L".--.",
	L".-.",
	L"...",
	L"-",
	L"..-",
	L"..-.",
	L"....",
	L"-.-.",
	L"---.",
	L"----",
	L"--.-",
	L"--.--",
	L"-.--",
	L"-..-",
	L"..-..",
	L"..--",
	L".-.-",

	L".----",
	L"..---",
	L"...--",
	L"....-",
	L".....",
	L"-....",
	L"--...",
	L"---..",
	L"----.",
	L"-----",
	L"......",
	L".-.-.-",
	L"---...",
	L"-.-.-.",
	L"-.--.-",
	L"-.--.",
	L".----.",
	L".-..-.",
	L"-....-",
	L"-..-.",
	L"..--.-",
	L"..--..",
	L"--..--",
	L".-.-.",
	L"-...-",


};

const std::vector<wchar_t> russianLetters = {
	L'А',
	L'Б',
	L'В',
	L'Г',
	L'Д',
	L'Е',
	L'Ж',
	L'З',
	L'И',
	L'Й',
	L'К',
	L'Л',
	L'М',
	L'Н',
	L'О',
	L'П',
	L'Р',
	L'С',
	L'Т',
	L'У',
	L'Ф',
	L'Х',
	L'Ц',
	L'Ч',
	L'Ш',
	L'Щ',
	L'Ъ',
	L'Ы',
	L'Ь',
	L'Э',
	L'Ю',
	L'Я',

	L'1',
	L'2',
	L'3',
	L'4',
	L'5',
	L'6',
	L'7',
	L'8',
	L'9',
	L'0',
	L'.',
	L',',
	L':',
	L';',
	L'(',
	L')',
	L'’',
	L'\"',
	L'-',
	L'/',
	L'_',
	L'?',
	L'!',
	L'+',
	L'=',
};

const std::vector<wchar_t> englishLetters = {
	L'A',
	L'B',
	L'W',
	L'G',
	L'D',
	L'E',
	L'V',
	L'Z',
	L'I',
	L'J',
	L'K',
	L'L',
	L'M',
	L'N',
	L'O',
	L'P',
	L'R',
	L'S',
	L'T',
	L'U',
	L'F',
	L'H',
	L'C',
	L'Ö',
	L'Ш',
	L'Q',
	L'Ñ',
	L'Y',
	L'X',
	L'É',
	L'Ü',
	L'Ä',

	L'1',
	L'2',
	L'3',
	L'4',
	L'5',
	L'6',
	L'7',
	L'8',
	L'9',
	L'0',
	L'.',
	L',',
	L':',
	L';',
	L'(',
	L')',
	L'’',
	L'\"',
	L'-',
	L'/',
	L'_',
	L'?',
	L'!',
	L'+',
	L'=',
};

extern void ToUpperCase(std::wstring& lpText);

extern void MorseToEnglish(std::vector<std::wstring> lpBuffer, std::wstring& lpText);

extern void PrintArray(std::vector<std::wstring> lpData);

extern void TextToMorse(std::wstring lpText, std::vector<std::wstring>& lpBuffer);

extern void ConvertMorseToVector(std::wstring lpText, std::vector<std::wstring>& lpBuffer);

extern void MorseToRussian(std::vector<std::wstring> lpBuffer, std::wstring& lpText);

extern void PrintArray(std::wstring lpBuffer);

extern void PrintProgramInfo();

extern bool CheckWrongChars(std::wstring lpText);

extern bool IsEmptyString(std::wstring lpText);