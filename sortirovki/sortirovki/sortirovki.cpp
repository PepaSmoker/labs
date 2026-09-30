#include <iostream>
#include <vector>
using namespace std;

void combSort(vector<int>& a) {
    int n = a.size();
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = max(1, (int)(gap / 1.3));
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

void shellSort(vector<int>& a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

int main()
{
    setlocale(LC_ALL,"Russian");

    vector<int> a = { 8, 3, 1, 7, 0, 10, 2 };
    int c;

    while (true) {
        cout << "какой метод сортивки использовать (всего 4, 0 - выход): ";
        cin >> c;
        if (c == 1)
        {
            
            combSort(a);
            for (int x : a) cout << x << " ";
        }
        else if (c == 2)
        {
            insertionSort(a);
            for (int x : a) cout << x << " ";
        }
        else if (c == 3)
        {
            selectionSort(a);
            for (int x : a) cout << x << " ";
        }
        else if (c == 4)
        {
            shellSort(a);
            for (int x : a) cout << x << " ";
        }
        else if (c == 0)
        {
            break;
        }
    }

}