#include <iostream>
using namespace std;

void printArray(int* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

void fillRandom(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 21 - 10;   // [-10;10]
    }
}

void pushFront(int*& arr, int& size, int value) {
    int* newArr = new int[size + 1];

    newArr[0] = value;
    for (int i = 0; i < size; i++)
        newArr[i + 1] = arr[i];

    delete[] arr;
    arr = newArr;
    size++;
}

void pushBack(int*& arr, int& size, int value) {
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];

    newArr[size] = value;

    delete[] arr;
    arr = newArr;
    size++;
}

void clearArray(int*& arr, int& size) {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

void findElement(int* arr, int size, int value) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            cout << i << " ";
    cout << "]\n";
}

void variantTask(int*& arr, int& size) {
    if (size == 0) return;

    cout << "До: ";
    printArray(arr, size);

    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int countMax = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == maxVal)
            countMax++;

    int newSize = size - countMax;
    int* newArr = new int[newSize];

    int idx = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] != maxVal)
            newArr[idx++] = arr[i];

    delete[] arr;
    arr = newArr;
    size = newSize;

    if (countMax == 1)
        pushFront(arr, size, maxVal);
    else
        pushBack(arr, size, maxVal);

    cout << "После: ";
    printArray(arr, size);
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void sortByValue(int* arr, int size) {
    int* copy = new int[size];
    for (int i = 0; i < size; i++)
        copy[i] = arr[i];

    bubbleSort(copy, size);

    cout << "По значению: ";
    printArray(copy, size);

    delete[] copy;
}

void sortByReference(int*& arr, int size) {
    bubbleSort(arr, size);
}

void sortByPointer(int** arr, int size) {
    bubbleSort(*arr, size);
}

int main() {
    int size = 10;
    int* arr = new int[size];
    fillRandom(arr, size);

    int choice;
    do {
        cout << "0. Выход\n";
        cout << "1. Просмотр массива\n";
        cout << "2. Добавить элемент в начало\n";
        cout << "3. Добавить элемент в конец (лекционный способ)\n";
        cout << "4. Очистка массива\n";
        cout << "5. Поиск элемента\n";
        cout << "6. Задание варианта\n";
        cout << "Введите пункт: ";

        cin >> choice;

        if (choice == 1) 
        {
            printArray(arr, size);
        }
        else if (choice == 2) 
        {
            int x;
            cout << "Введите число: ";
            cin >> x;
            pushFront(arr, size, x);
        }
        else if (choice == 3)
        {
            int x;
            cout << "Введите число: ";
            cin >> x;
            pushBack(arr, size, x);
        }
        else if (choice == 4)
        {
            clearArray(arr, size);
            cout << "Массив очищен.\n";
        }
        else if (choice == 5) 
        {
            int x;
            cout << "Введите элемент для поиска: ";
            cin >> x;
            findElement(arr, size, x);
        }
        else if (choice == 6) 
        {
            variantTask(arr, size);
        }

    } while (choice != 0);

    cout << "\nПУНКТ 2:\n";

    int n = 10;
    int* arr2 = new int[n];
    fillRandom(arr2, n);

    cout << "Исходный массив: ";
    printArray(arr2, n);

    sortByValue(arr2, n);

    sortByReference(arr2, n);
    cout << "По ссылке: ";
    printArray(arr2, n);

    sortByPointer(&arr2, n);
    cout << "По указателю: ";
    printArray(arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}
