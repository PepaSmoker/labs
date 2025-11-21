#include <iostream>

using namespace std;

int* findZeroColumns(int** arr, int n1, int n2, int& Count) {
    int* result = (int*)calloc(n2, sizeof(int));
    Count = 0;

    for (int j = 0; j < n2; j++) {
        for (int i = 0; i < n1; i++) {
            if (arr[i][j] == 0) {
                result[Count++] = j;
                break;
            }
        }
    }

    result = (int*)realloc(result, Count * sizeof(int));
    return result;
}

void removeColumns(int**& arr, int& n1, int& n2, int* removeList, int removeCount) {

    for (int k = 0; k < removeCount; k++) {
        int colToRemove = removeList[k] - k;

        for (int i = 0; i < n1; i++) {
            for (int j = colToRemove; j < n2 - 1; j++) {
                arr[i][j] = arr[i][j + 1];
            }

            arr[i] = (int*)realloc(arr[i], (n2 - 1) * sizeof(int));
        }

        n2--;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    //пункт 1------------------------------
    int n = 2;
    int n1 = 0;
    int n2 = 0;

    int** arr = (int**) malloc(n * sizeof(int*));

    cout << "Пункт 1: \n";
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = (int*) malloc(n*sizeof(int));
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Введите число >> ";
            cin >> arr[i][j];
        }
    }

    //проверка A
    while (true)
    {
        if (arr[0][0] >= 0)
        {
            break;
        }
        cout << "Ошибка ввода А" << endl;
        cin >> arr[0][0];
    }

    //проверка B
    while (true)
    {
        if (arr[0][1] >= 0)
        {
            break;
        }
        cout << "Ошибка ввода B" << endl;
        cin >> arr[0][1];
    }

    n1 = n + arr[0][0];
    n2 = n + arr[0][1];
    int C = arr[1][0];
    int D = arr[1][1];

    cout << "\nИзначальная матрица: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    arr = (int**) realloc(arr, n1 * sizeof(int*));
    for (int i = n; i < n1; i++)
    {
        arr[i] = (int*)calloc(n2, sizeof(int));
    }

    for (int i = 0; i < n1; i++)
    {
        arr[i] = (int*)realloc(arr[i], n2 * sizeof(int));
    }


    for (int i = 0; i < n1; i++)
    {
        int counter1 = i - arr[0][0];
        for (int j = 0; j < n2; j++)
        {
            if ((i == 0 && j <= 1) || (i == 1 && j <= 1))
            {
                continue;
            }
            else
            {
                arr[i][j] = counter1 * C + j * D;
            } 
        } 
    }
    
    cout << "Массив после расширения: \n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    int Count = 0;
    int* Cols = findZeroColumns(arr, n1, n2, Count);

    removeColumns(arr, n1, n2, Cols, Count);

    free(Cols);

    cout << "\nМатрица после удаления столбцов с нулями:\n";
    for (int i = 0; i < n1; i++) 
    {
        for (int j = 0; j < n2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n1; i++)
    {
        free(arr[i]);

    }
    free(arr);

    // пункт 2--------------------------------------

    double a, b;
    cout << "\nПункт 2:";
    cout << "\nВведите a: ";
    cin >> a;

    cout << "Введите b: ";
    cin >> b;

    double* pa = new double(a);
    double* pb = new double(b);

    *pa = (*pa) * 3;

    double temp = *pa;
    *pa = *pb;
    *pb = temp;

    cout << "\nЧисла после вычислений:\n";
    cout << "a = " << *pa << endl;
    cout << "b = " << *pb << endl;

    delete pa;
    delete pb;
    
}