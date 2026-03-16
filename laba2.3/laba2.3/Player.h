#pragma once
#include <vector>
#include <string>
#include "Lootbox.h"

class Player
{
private:

    std::vector<Item> inventory_;
    std::string name_;
    std::string status_;
    int x_;
    int y_;
    int hp_;

protected:
    std::string social_status_;

public:

    void info();
    void show_inventory(const std::vector<Item>& inventory);
    void checkHp();
    void takeDamage(int damage);
    void heal(int heal);

    void openLootbox(Lootbox& box);

    Player();
    Player(std::string name, int x, int y, std::vector<Item> inventory);
    Player(const Player& other);
    ~Player();

    //геттеры
    std::string get_soc_status() { return social_status_; }
    std::string get_name() { return name_; }
    std::string get_status() { return status_; }
    std::vector<Item> get_inventory() const { return inventory_; }
    int get_x() const { return x_; }
    int get_y() const { return y_; }
    int get_hp() const { return hp_; }

    //сеттеры
    void set_x(int xx);
    void set_y(int yy);
    void set_name(std::string name);
    void set_inventory(std::vector<Item> inventory);
    void set_status(std::string s);
    void set_hp(int hp);
};

int Rand(int min, int max);
int factorial(int a, int b);
std::string Rand_Name();

Player operator+(const Player& player1, const Player& player2);
Player operator-(const Player& player1, const Player& player2);
Player operator/(const Player& player1, const Player& player2);