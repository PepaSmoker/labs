#include <iostream>
#include "Header.h"

int Rand(int min, int max)
{
	int a;
	a = min + rand() % (max - min + 1);
	return a;
}

void factorial(int a, int b)
{
	if (b > a)
	{
		std::swap(b, a);
	}

	int f = 1;
	int n = a - b;

	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	std::cout << f << ", ";
}

void Op1_Inventory(std::vector <std::string> arr1, std::vector <std::string> arr2)
{
	std::set <std::string> s;

	for (std::string n : arr1)
	{
		s.insert(n);
	}

	for (std::string n : arr2)
	{
		s.insert(n);
	}
	for (std::string n : s)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;
}

void Op3_Inventory(std::vector <std::string> arr1, std::vector <std::string> arr2)
{
	for (int i = 0; i < (arr1.size()) / 2 + 1; i++)
	{
		std::cout << arr1[i] << " ";
	}
	for (int i = (arr2.size()) / 2 + 1; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
}

void Print_array(std::vector <std::string> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
}

void operations(char o, Player player1, Player player2)
{
	int x1 = player1.get_x();
	int y1 = player1.get_y();
	int x2 = player2.get_x();
	int y2 = player2.get_y();

	std::vector <std::string> arr1 = player1.get_inventory();
	std::vector <std::string> arr2 = player2.get_inventory();

	while (true)
	{
		std::cout << std::endl;
		if (o == '+')
		{
			std::cout << "P" << Rand(3, 1000) << ", " << (x1 + x2) / 2 << ", " << (y1 + y2) / 2 << ", ";
			Op1_Inventory(arr1, arr2);
			std::cout << std::endl;
			break;
		}
		else if (o == '-')
		{
			int p = Rand(1, 2);
			int r = Rand(1, arr2.size());

			std::cout << "P" << Rand(3, 1000) << ", ";

			if (p == 1)
			{
				std::cout << x1 << ", " << y1 << ", ";
			}
			else
			{
				std::cout << x2 << ", " << y2 << ", ";
			}
			for (int i = 0; i < r; i++)
			{
				int k = Rand(1, arr2.size());
				arr2[k] = "";
			}
			Print_array(arr1);
			Print_array(arr2);
			std::cout << std::endl;
			break;
		}
		else if (o == '/')
		{
			std::cout << "P" << Rand(3, 1000) << ", ";
			factorial(x1, x2);
			factorial(y1, y2);
			Op3_Inventory(arr1, arr2);
			std::cout << std::endl;
			break;
		}
		else
		{
			std::cerr << "Operation Error. Enter operation again >> ";
			std::cin >> o;
		}
	}

}