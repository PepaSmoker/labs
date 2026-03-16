#pragma once
#include <vector>
#include <string>

struct Item
{
    std::string name;
    std::string rarity;
    std::string description;

    void info() const;
};

class Lootbox
{
private:

    std::string name_;
    std::vector<Item> items_;

public:

    Lootbox();
    Lootbox(std::string name, std::vector<Item> items);
    Lootbox(const Lootbox& other);
    ~Lootbox();

    Item open();

    void info() const;
};