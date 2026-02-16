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

int Rand(int min, int max);

void factorial(int a, int b);
void Op1_Inventory(std::vector <std::string> arr1, std::vector <std::string> arr2);
void Op3_Inventory(std::vector <std::string> arr1, std::vector <std::string> arr2);
void Print_array(std::vector <std::string> arr);
void operations(char o, Player player1, Player player2);