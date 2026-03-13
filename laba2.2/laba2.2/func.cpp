#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include "Player.h"

//Player
Player::Player()
{
	name_ = "";
	x_ = 0;
	y_ = 0;
	inventory_ = {};
}
Player::Player(std::string name, int x, int y, std::vector <std::string> inventory)
{
	name_ = name;
	x_ = x;
	y_ = y;
	inventory_ = inventory;
}
Player::Player(const Player& other)
{
	name_ = other.name_;
	x_ = other.x_;
	y_ = other.y_;
	inventory_ = other.inventory_;
}
Player::~Player()
{
	inventory_.clear();
	std::cout << name_ << "_destr\n";
	
}
void Player::info()
{
	std::cout << "\n--------------------------\\\\" << std::endl;
	std::cout <<
		"Player info:\n" << name_ <<
		"\nPosition: " << x_ << ", " << y_
		<< "\nInventory: ";
	show_inventory(inventory_);
	std::cout << "--------------------------//\n";
}
void Player::show_inventory(const std::vector <std::string>& inventory_)
{
	for (int i = 0; i < inventory_.size(); i++)
	{
		std::cout << inventory_[i] << " ";
	}
	std::cout << std::endl;
}
void Player::checkHp()
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
void Player::takeDamage(int damage)
{
	hp_ -= damage;
	checkHp();
	status_ = "damaged";
}
void Player::heal(int heal)
{
	hp_ += heal;
	checkHp();
	status_ = "healed";
}
void Player::set_x(int xx)
{
	x_ = xx;
}
void Player::set_y(int yy)
{
	y_ = yy;
}
void Player::set_name(std::string name)
{
	name_ = name;
}
void Player::set_inventory(std::vector <std::string> inventory)
{
	inventory_ = inventory;
}


//=============================

//Operators
int Rand(int min, int max)
{
	int a;
	a = min + rand() % (max - min + 1);
	return a;
}
int factorial(int a, int b)
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

std::string Rand_Name()
{
	std::string name1;
	std::string name2 = "P";
	int a = Rand(3, 1000);

	name1 = std::to_string(a);
	name2 += name1;

	return name2;
}

Player operator+(const Player& player1, const Player& player2)
{
	int x;
	int y;
	std::vector <std::string> inventory;
	std::vector <std::string> arr1 = player1.get_inventory();
	std::vector <std::string> arr2 = player2.get_inventory();
	std::set <std::string> s;

	Player player;

	//name
	player.set_name(Rand_Name());

	//x
	x = ((player1.get_x() + player2.get_x()) / 2);
	player.set_x(x);

	//y
	y = ((player1.get_y() + player2.get_y()) / 2);
	player.set_y(y);

	//inventory
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
		inventory.push_back(n);
	}

	player.set_inventory(inventory);

	return player;
}
Player operator-(const Player& player1, const Player& player2)
{
	int x;
	int y;
	int rand_pos = Rand(1, 2);
	std::vector <std::string> inventory;
	std::vector <std::string> arr1 = player1.get_inventory();
	std::vector <std::string> arr2 = player2.get_inventory();
	std::vector <std::string> del_el;
	Player player;

	//name
	player.set_name(Rand_Name());

	//x
	if (rand_pos == 1)
	{
		player.set_x(player1.get_x());
	}
	else
	{
		player.set_x(player2.get_x());
	}

	//y
	if (rand_pos == 1)
	{
		player.set_y(player1.get_y());
	}
	else
	{
		player.set_y(player2.get_y());
	}

	//inventory
	int rand_inv = Rand(0, arr2.size() - 1);

	if (rand_inv == 0)
	{
		player.set_inventory(arr1);
		return player;
	}

	for (int i = 0; i < rand_inv; i++)
	{
		int n = Rand(0, arr2.size() - 1);

		inventory.push_back(arr2[n]);

		arr2.erase(arr2.begin() + n);
	}

	for (int j = 0; j < size(inventory); j++)
	{
		arr1.erase(std::remove(arr1.begin(), arr1.end(), inventory[j]), arr1.end());
	}
	player.set_inventory(arr1);
	return player;
}
Player operator/(const Player& player1, const Player& player2)
{
	std::vector <std::string> inventory;
	std::vector <std::string> arr1 = player1.get_inventory();
	std::vector <std::string> arr2 = player2.get_inventory();

	Player player;

	//name
	player.set_name(Rand_Name());

	//x
	player.set_x(factorial(player1.get_x(), player2.get_x()));

	//y
	player.set_y(factorial(player1.get_y(), player2.get_y()));

	//inventory
	for (int i = 0; i < size(arr1) / 2; i++)
	{
		inventory.push_back(arr1[i]);
	}

	for (int j = size(arr2) / 2; j < size(arr2); j++)
	{
		inventory.push_back(arr2[j]);
	}

	player.set_inventory(inventory);

	return player;
}