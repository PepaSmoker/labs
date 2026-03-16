#include <iostream>
#include <cstdlib>
#include "Lootbox.h"

void Item::info() const
{
    std::cout << "Item: " << name << "\n";
    std::cout << "Rarity: " << rarity << "\n";
    std::cout << "Description: " << description << "\n";
}

Lootbox::Lootbox()
{
    name_ = "default";
}

Lootbox::Lootbox(std::string name, std::vector<Item> items)
{
    name_ = name;
    items_ = items;
}

Lootbox::Lootbox(const Lootbox& other)
{
    name_ = other.name_;
    items_ = other.items_;
}

Lootbox::~Lootbox() {}

Item Lootbox::open()
{
    if (items_.empty())
        return { "Nothing","None","Empty" };

    int index = rand() % items_.size();

    return items_[index];
}

void Lootbox::info() const
{
    std::cout << "\nLootbox: " << name_ << "\n";

    for (const auto& i : items_)
    {
        i.info();
        std::cout << "\n";
    }
}