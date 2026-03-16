#include <iostream>
#include <set>
#include <algorithm>
#include "Player.h"

Player::Player()
{
    name_ = "";
    x_ = 0;
    y_ = 0;
    hp_ = 10;
}

Player::Player(std::string name, int x, int y, std::vector<Item> inventory)
{
    name_ = name;
    x_ = x;
    y_ = y;
    inventory_ = inventory;
    hp_ = 10;
}

Player::Player(const Player& other)
{
    name_ = other.name_;
    x_ = other.x_;
    y_ = other.y_;
    inventory_ = other.inventory_;
    hp_ = other.hp_;
}

Player::~Player()
{
    inventory_.clear();
    std::cout << name_ << "_destr\n";
}

void Player::info()
{
    std::cout << "\n--------------------------\\\\\n";
    std::cout << "Player info:\n" << name_;
    std::cout << "\nPosition: " << x_ << ", " << y_;
    std::cout << "\nHP: " << hp_;
    std::cout << "\nStatus: " << status_;
    std::cout << "\nInventory:\n";

    show_inventory(inventory_);

    std::cout << "--------------------------//\n";
}

void Player::show_inventory(const std::vector<Item>& inventory)
{
    for (const auto& i : inventory)
    {
        std::cout << i.name << " (" << i.rarity << ")\n";
    }
}

void Player::checkHp()
{
    if (hp_ < 0) hp_ = 0;
    if (hp_ > 20) hp_ = 20;
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

void Player::openLootbox(Lootbox& box)
{
    Item item = box.open();

    inventory_.push_back(item);

    std::cout << name_ << " opened lootbox and got:\n";
    item.info();
}

void Player::set_x(int xx) { x_ = xx; }
void Player::set_y(int yy) { y_ = yy; }
void Player::set_name(std::string name) { name_ = name; }
void Player::set_inventory(std::vector<Item> inventory) { inventory_ = inventory; }
void Player::set_status(std::string s) { status_ = s; }
void Player::set_hp(int hp) { hp_ = hp; }

int Rand(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int factorial(int a, int b)
{
    if (b > a) std::swap(a, b);

    int f = 1;
    int n = a - b;

    for (int i = 1; i <= n; i++)
        f *= i;

    return f;
}

std::string Rand_Name()
{
    std::string name = "P";
    name += std::to_string(Rand(3, 1000));
    return name;
}

Player operator+(const Player& p1, const Player& p2)
{
    Player player;

    player.set_name(Rand_Name());

    player.set_x((p1.get_x() + p2.get_x()) / 2);
    player.set_y((p1.get_y() + p2.get_y()) / 2);

    std::vector<Item> inv = p1.get_inventory();

    for (auto& i : p2.get_inventory())
        inv.push_back(i);

    player.set_inventory(inv);

    return player;
}

Player operator-(const Player& p1, const Player& p2)
{
    Player player;

    player.set_name(Rand_Name());

    if (Rand(1, 2) == 1)
    {
        player.set_x(p1.get_x());
        player.set_y(p1.get_y());
    }
    else
    {
        player.set_x(p2.get_x());
        player.set_y(p2.get_y());
    }

    std::vector<Item> inv = p1.get_inventory();

    if (!p2.get_inventory().empty())
        inv.pop_back();

    player.set_inventory(inv);

    return player;
}

Player operator/(const Player& p1, const Player& p2)
{
    Player player;

    player.set_name(Rand_Name());

    player.set_x(factorial(p1.get_x(), p2.get_x()));
    player.set_y(factorial(p1.get_y(), p2.get_y()));

    std::vector<Item> inv;

    auto a1 = p1.get_inventory();
    auto a2 = p2.get_inventory();

    for (int i = 0; i < a1.size() / 2; i++)
        inv.push_back(a1[i]);

    for (int i = a2.size() / 2; i < a2.size(); i++)
        inv.push_back(a2[i]);

    player.set_inventory(inv);

    return player;
}