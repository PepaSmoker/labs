#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <windows.h>

const int MAX_STRING = 101;
const int MAX_WORD_LEN = 256;
const int MAX_WORDS = 1000;
const int MAX_TEXT = 10000;

bool isRussianLetter(unsigned char c) {
    return (c >= 0xC0 && c <= 0xDF) ||
        (c >= 0xE0 && c <= 0xFF) ||
        c == 0xF0 || c == 0xF1;
}

unsigned char toLowerRussian(unsigned char c) {
    if (c >= 0xC0 && c <= 0xDF) {
        if (c == 0xC0) return 0xE0;
        if (c == 0xC1) return 0xE1;
        if (c == 0xC2) return 0xE2;
        if (c == 0xC3) return 0xE3;
        if (c == 0xC4) return 0xE4;
        if (c == 0xC5) return 0xE5;
        if (c == 0xC6) return 0xE6;
        if (c == 0xC7) return 0xE7;
        if (c == 0xC8) return 0xE8;
        if (c == 0xC9) return 0xE9;
        if (c == 0xCA) return 0xEA;
        if (c == 0xCB) return 0xEB;
        if (c == 0xCC) return 0xEC;
        if (c == 0xCD) return 0xED;
        if (c == 0xCE) return 0xEE;
        if (c == 0xCF) return 0xEF;
        if (c == 0xD0) return 0xF0;
        if (c == 0xD1) return 0xF1;
        if (c == 0xD2) return 0xF2;
        if (c == 0xD3) return 0xF3;
        if (c == 0xD4) return 0xF4;
        if (c == 0xD5) return 0xF5;
        if (c == 0xD6) return 0xF6;
        if (c == 0xD7) return 0xF7;
        if (c == 0xD8) return 0xF8;
        if (c == 0xD9) return 0xF9;
        if (c == 0xDA) return 0xFA;
        if (c == 0xDB) return 0xFB;
        if (c == 0xDC) return 0xFC;
        if (c == 0xDD) return 0xFD;
        if (c == 0xDE) return 0xFE;
        if (c == 0xDF) return 0xFF;
    }
    else if (c == 0xF0) {
        return 0xF1;
    }
    return c;
}

char toLowerChar(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    if (isRussianLetter(uc)) {
        return static_cast<char>(toLowerRussian(uc));
    }
    else {
        return std::tolower(c);
    }
}

bool isVowel(char c) {
    char lower = toLowerChar(c);
    const char* vowels = "аеёиоуъыьэюя";
    for (int i = 0; vowels[i]; i++) {
        if (lower == vowels[i]) return true;
    }
    return false;
}

bool isLetter(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return (uc >= 'A' && uc <= 'Z') ||
        (uc >= 'a' && uc <= 'z') ||
        isRussianLetter(uc);
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

void printSymbolTable() {
    std::cout << "Таблица символов и их кодов:\n";
    std::cout << "------------------------------------\n";

    std::cout << "Строчные латинские буквы:\n";
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << c << " / " << static_cast<int>(c) << "    ";
    }
    std::cout << "\n\n";

    std::cout << "Заглавные латинские буквы:\n";
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::cout << c << " / " << static_cast<int>(c) << "    ";
    }
    std::cout << "\n\n";

    std::cout << "Цифры:\n";
    for (char c = '0'; c <= '9'; ++c) {
        std::cout << c << " / " << static_cast<int>(c) << "    ";
    }
    std::cout << "\n\n";

    const char* lowerRussian = "абвгдежзийклмнопрстуфхцчшщъыьэюяё";
    std::cout << "Строчные русские буквы (CP1251):\n";
    for (int i = 0; lowerRussian[i]; ++i) {
        unsigned char uc = static_cast<unsigned char>(lowerRussian[i]);
        std::cout << lowerRussian[i] << " / " << static_cast<int>(uc) << "    ";
    }
    std::cout << "\n\n";

    const char* upperRussian = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯЁ";
    std::cout << "Заглавные русские буквы (CP1251):\n";
    for (int i = 0; upperRussian[i]; ++i) {
        unsigned char uc = static_cast<unsigned char>(upperRussian[i]);
        std::cout << upperRussian[i] << " / " << static_cast<int>(uc) << "    ";
    }
    std::cout << "\n\n";

    const char* punctuation = ".,!?;:()[]{}<>/\\|`~@#$%^&*-_+= \"'";
    std::cout << "Знаки препинания:\n";
    for (int i = 0; punctuation[i]; ++i) {
        char c = punctuation[i];
        std::cout << c << " / " << static_cast<int>(c) << "    ";
    }
    std::cout << "\n\n";
}

void task1() {
    std::cout << "\n=== Задача 1 ===\n";
    std::cout << "Введите строку (не более 100 символов): ";
    char input[MAX_STRING];
    std::cin.getline(input, MAX_STRING);

    char result[MAX_STRING] = { 0 };
    int j = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (!isVowel(input[i])) {
            result[j++] = input[i];
        }
    }
    result[j] = '\0';

    std::cout << "Строка после удаления гласных: " << result << std::endl;
}

struct WordInfo {
    char original[MAX_WORD_LEN];
    char lower[MAX_WORD_LEN];
    int length;
};

bool isAlphabetOrder(const char* lowerWord) {
    char prev = 0;
    bool firstLetter = true;
    for (int i = 0; lowerWord[i] != '\0'; ++i) {
        if (isLetter(lowerWord[i])) {
            if (firstLetter) {
                prev = lowerWord[i];
                firstLetter = false;
            }
            else {
                if (lowerWord[i] < prev) return false;
                prev = lowerWord[i];
            }
        }
    }
    return true;
}

void toLowerWord(const char* src, char* dst) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = toLowerChar(src[i]);
        i++;
    }
    dst[i] = '\0';
}

bool isWordInList(const WordInfo* list, int count, const char* lowerWord) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(list[i].lower, lowerWord) == 0) return true;
    }
    return false;
}

void addWordToList(WordInfo* list, int& count, const char* original, const char* lower, int len, int maxCount) {
    if (isWordInList(list, count, lower)) return;

    if (count < maxCount) {
        strcpy(list[count].original, original);
        strcpy(list[count].lower, lower);
        list[count].length = len;
        count++;
    }
    else {
        int minIndex = 0;
        for (int i = 1; i < count; ++i) {
            if (list[i].length < list[minIndex].length) minIndex = i;
        }
        if (len > list[minIndex].length) {
            strcpy(list[minIndex].original, original);
            strcpy(list[minIndex].lower, lower);
            list[minIndex].length = len;
        }
        else {
            return;
        }
    }
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (list[j].length < list[j + 1].length) {
                WordInfo tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

bool extractWordFromText(const char*& ptr, char* wordBuf, int& wordLen) {
    while (*ptr && !isLetter(*ptr) && !isDigit(*ptr)) {
        ptr++;
    }
    if (!*ptr) return false;

    char temp[MAX_WORD_LEN];
    int tIndex = 0;
    while (*ptr && (isLetter(*ptr) || isDigit(*ptr))) {
        temp[tIndex++] = *ptr;
        ptr++;
    }
    temp[tIndex] = '\0';

    while (tIndex > 0 && isDigit(temp[tIndex - 1])) {
        tIndex--;
    }
    temp[tIndex] = '\0';
    wordLen = tIndex;

    if (wordLen == 0) {
        return extractWordFromText(ptr, wordBuf, wordLen);
    }

    strcpy(wordBuf, temp);
    return true;
}

void task2() {
    std::cout << "\n=== Задача 2 ===\n";

    std::ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла input.txt" << std::endl;
        return;
    }
    int N;
    inFile >> N;
    inFile.close();
    if (N <= 0) {
        std::cerr << "N должно быть положительным" << std::endl;
        return;
    }

    std::ifstream textFile("text.txt");
    if (!textFile.is_open()) {
        std::cerr << "Ошибка открытия файла text.txt" << std::endl;
        return;
    }
    char text[MAX_TEXT];
    textFile.read(text, MAX_TEXT - 1);
    int len = textFile.gcount();
    text[len] = '\0';
    textFile.close();

    WordInfo words[MAX_WORDS];
    int wordCount = 0;

    const char* ptr = text;
    char original[MAX_WORD_LEN];
    int wordLength;
    while (extractWordFromText(ptr, original, wordLength)) {
        char lowerWord[MAX_WORD_LEN];
        toLowerWord(original, lowerWord);
        if (isAlphabetOrder(lowerWord)) {
            addWordToList(words, wordCount, original, lowerWord, wordLength, N);
        }
    }

    std::ofstream outFile("result.txt");
    if (!outFile.is_open()) {
        std::cerr << "Ошибка создания файла result.txt" << std::endl;
        return;
    }

    int outCount = (wordCount < N) ? wordCount : N;
    for (int i = 0; i < outCount; ++i) {
        outFile << words[i].original << std::endl;
    }
    outFile.close();

    std::cout << "Готово. Результат записан в result.txt" << std::endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    printSymbolTable();
    task1();
    task2();

    return 0;
}