#pragma once
#include <vector>
#include <set>

class Player
{
private:
	//поля
	std::vector <std::string> inventory_;
	std::string name_;
	std::string status_;
	int x_;
	int y_;
	int hp_;

protected:
	std::string social_status_;

public:
	//методы

	void info()
	{
		std::cout <<
			"Player info:\n" << name_ <<
			"\nPosition: " << x_ << ", " << y_
			<< "\nInventory: ";
		show_inventory(inventory_);
		std::cout << "||--------------------------//\n\n";
	}

	void checkHp()
	{
		if (hp_ < 0)
		{
			hp_ = 0;
		}
		if (hp_ > 20)
		{
			hp_ = 20;
		}
	}

	void show_inventory(std::vector <std::string> inventory_)
	{
		for (int i = 0; i < inventory_.size(); i++)
		{
			std::cout << inventory_[i] << " ";
		}
		std::cout << std::endl;
	}
	
	void takeDamage(int damage)
	{
		hp_ -= damage;
		checkHp();
		status_ = "damaged";
	}

	void heal(int heal)
	{
		hp_ += heal;
		checkHp();
		status_ = "healed";
	}

	//конструктор по умолч.
	Player()
	{
		name_ = "";
		x_ = 0;
		y_ = 0;
		inventory_ = {};
	}

	Player(std::string name, int x, int y, std::vector <std::string> inventory)
	{
		name_ = name;
		x_ = x;
		y_ = y;
		inventory_ = inventory;
	}

	Player(const Player& other)
	{
		name_ = other.name_;
		x_ = other.x_;
		y_ = other.y_;
		inventory_ = other.inventory_;
	}

	~Player()
	{
		inventory_.clear();
		std::cout << name_ << "_destr" << std::endl;
	}

	//геттеры
	std::string get_soc_status() { return social_status_; }
	std::string get_name() { return name_; }
	std::string get_status() { return status_; }
	std::vector <std::string> get_inventory() { return inventory_; }
	int get_x() { return x_; }
	int get_y() { return y_; }
	int get_hp() { return hp_; }

	//сеттер
	void set_x(int xx)
	{
		x_ = xx;
	}

	void set_y(int yy)
	{
		y_ = yy;
	}

	void set_name(std::string name)
	{
		name_ = name;
	}
};

int Rand(int min, int max)
{
	int a;
	a = min + rand() % (max - min + 1);
	return a;
}

int factorial(int a, int b)//
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
	return f;
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
	std::cout << std::endl;
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
		if (o == '+')
		{
			std::cout << "P" << Rand(3, 1000) << ", " << (x1 + x2) / 2 << ", " << (y1 + y2) / 2 << ", ";
			Op1_Inventory(arr1, arr2);
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
				arr2.erase(arr2.begin() + k);
			}
			Print_array(arr1);
			Print_array(arr2);
		}
		else if (o == '/')
		{
			std::cout << "P" << Rand(3, 1000);
			factorial(x1, x2);
			factorial(y1, y2);
			Op3_Inventory(arr1, arr2);
		}
		else
		{
			std::cerr << "Operation Error. Enter operation again >>";
			std::cin >> o;
		}
	}

}