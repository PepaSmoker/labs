#pragma once

class Player
{
private:
	//поля
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
			"Player info:\n" << name_ << std::endl
			<< "Status: " << status_ << std::endl
			<< "Hp: " << hp_ << std::endl
			<< "Position: " << x_ << ", "
			<< y_ << std::endl << std::endl;
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
		hp_ = 20;
		status_ = "";
	}

	Player(std::string name, int x, int y, int hp, std::string status)
	{
		name_ = name;
		status_ = status;
		x_ = x;
		y_ = y;
		hp_ = hp;
	}

	Player(const Player& other)
	{
		name_ = other.name_;
		status_ = other.status_;
		x_ = other.x_;
		y_ = other.y_;
		hp_ = other.hp_;
	}

	~Player()
	{
		std::cout << name_ <<"_destr" << std::endl;
	}

	//геттеры
	std::string get_soc_status() { return social_status_; }
	std::string get_name() { return name_; }
	std::string get_status() { return status_;}
	int get_x() { return x_; }
	int get_y() { return y_; }
	int get_hp(){ return hp_; }

	//сеттер
	void set_x(int xx)
	{
		x_ = xx;
	}

	void set_y(int yy)
	{
		y_ = yy;
	}
};
