#pragma once
#include <vector>
#include <set>
#include <string>

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
	void info();
	void show_inventory(const std::vector <std::string>& inventory_);
	void checkHp();
	void takeDamage(int damage);
	void heal(int heal);


	Player();
	Player(std::string name, int x, int y, std::vector <std::string> inventory);
	Player(const Player& other);
	~Player();
    //kонструктор по умолч.
	

	//геттеры
	std::string get_soc_status() { return social_status_; }
	std::string get_name() { return name_; }
	std::string get_status() { return status_; }
	const std::vector <std::string>& get_inventory() const { return inventory_; }
	int get_x() const{ return x_; }
	int get_y() const{ return y_; }
	int get_hp() const{ return hp_; }

	//сеттер
	void set_x(int xx);
	void set_y(int yy);
	void set_name(std::string name);
	void set_inventory(std::vector <std::string> inventory);

};

int Rand(int min, int max);
int factorial(int a, int b);
std::string Rand_Name();
Player operator+(const Player& player1, const Player& player2);
Player operator-(const Player& player1, const Player& player2);
Player operator/(const Player& player1, const Player& player2);
