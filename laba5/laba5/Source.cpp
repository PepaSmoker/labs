#include <iostream>
#include <algorithm>

using namespace std;

int point(int num1, int num2)
{

	cout << "Исп. функция 'если одно число кратно другому вернуть частное чисел, иначе произведение'\n";

	cout << "\nВведите 2 числа >> ";

	cin >> num1 >> num2;

	if (num2 > num1)
	{
		swap(num1, num2);
	}

	if (num1 == 0 && num2 == 0)
	{
		cout << "Нет обоих чисел\n";
		return 0;
	}
	else if (num1 == 0 || num2 == 0)
	{
		cout << "Нет одного из чисел\n";
		return 0;
	}
	else if (num1 % num2 == 0)
	{
		cout << "Одно число кратно другому\n";
		return num1 / num2;
	}
	else
	{
		cout << "Числа не кратны друг другу\n";
		return num1 * num2;
	}
}

int point(int num1, int num2, int num3)
{

	cout << "Исп. функция 'если числа одинаковые то вернуть значение 1, иначе -1'";

	cout << "\nВведите 3 числа >> ";

	cin >> num1 >> num2 >> num3;

	if (num1 == num2 == num3)
	{
		cout << "Числа одинаковые\n";
		return 1;
	}
	else
	{
		cout << "Числа не одинаковые\n";
		return -1;
	}
}


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int choice;
	cout << "Какой пункт выполнить? (1 или 2) " << endl;
	
	cin >> choice;

	//проверка
	while (choice < 1 || choice > 2)
	{
		cout << "Неверный выбор пункта. Введите ещё раз >> ";
		cin >> choice;
	}
	
	//выбор пункта
	if (choice == 1)
	{
		cout << point(num1, num2);
	}
	else
	{
		cout << point(num1, num2, num3);
	}

}