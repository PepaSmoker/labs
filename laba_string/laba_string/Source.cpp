#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <windows.h>

const int MAX_STRING = 101;

bool isRussianLetter(unsigned char c) {
    switch (c) {
    case 'А': case 'Б': case 'В': case 'Г': case 'Д': case 'Е': case 'Ё':
    case 'Ж': case 'З': case 'И': case 'Й': case 'К': case 'Л': case 'М':
    case 'Н': case 'О': case 'П': case 'Р': case 'С': case 'Т': case 'У':
    case 'Ф': case 'Х': case 'Ц': case 'Ч': case 'Ш': case 'Щ': case 'Ъ':
    case 'Ы': case 'Ь': case 'Э': case 'Ю': case 'Я':
        // Строчные буквы
    case 'а': case 'б': case 'в': case 'г': case 'д': case 'е': case 'ё':
    case 'ж': case 'з': case 'и': case 'й': case 'к': case 'л': case 'м':
    case 'н': case 'о': case 'п': case 'р': case 'с': case 'т': case 'у':
    case 'ф': case 'х': case 'ц': case 'ч': case 'ш': case 'щ': case 'ъ':
    case 'ы': case 'ь': case 'э': case 'ю': case 'я':
        return true;
    default:
        return false;
    }
}

unsigned char toLowerRussian(unsigned char c) {
    switch (c) {
    case 'А': return 'а';
    case 'Б': return 'б';
    case 'В': return 'в';
    case 'Г': return 'г';
    case 'Д': return 'д';
    case 'Е': return 'е';
    case 'Ё': return 'ё';
    case 'Ж': return 'ж';
    case 'З': return 'з';
    case 'И': return 'и';
    case 'Й': return 'й';
    case 'К': return 'к';
    case 'Л': return 'л';
    case 'М': return 'м';
    case 'Н': return 'н';
    case 'О': return 'о';
    case 'П': return 'п';
    case 'Р': return 'р';
    case 'С': return 'с';
    case 'Т': return 'т';
    case 'У': return 'у';
    case 'Ф': return 'ф';
    case 'Х': return 'х';
    case 'Ц': return 'ц';
    case 'Ч': return 'ч';
    case 'Ш': return 'ш';
    case 'Щ': return 'щ';
    case 'Ъ': return 'ъ';
    case 'Ы': return 'ы';
    case 'Ь': return 'ь';
    case 'Э': return 'э';
    case 'Ю': return 'ю';
    case 'Я': return 'я';
    default: return c; 
    }
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
    switch (lower) {
    case 'а': case 'е': case 'ё': case 'и': case 'о':
    case 'у': case 'ы': case 'э': case 'ю': case 'я':
        return true;
    default:
        return false;
    }
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
    std::cout << "Строчные русские буквы:\n";
    for (int i = 0; lowerRussian[i]; ++i) {
        unsigned char uc = static_cast<unsigned char>(lowerRussian[i]);
        std::cout << lowerRussian[i] << " / " << static_cast<int>(uc) << "    ";
    }
    std::cout << "\n\n";

    const char* upperRussian = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯЁ";
    std::cout << "Заглавные русские буквы:\n";
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
    std::cout << "Введите строку: ";
    char input[MAX_STRING];
    std::cin.getline(input, MAX_STRING);

    char result[MAX_STRING] = { 0 };
    int j = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (!isVowel(input[i]) && input[i] != ' ') {
            result[j++] = input[i];
        }
    }
    result[j] = '\0';

    std::cout << "Строка после удаления гласных и пробелов: " << result << std::endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    printSymbolTable();
    task1();
}