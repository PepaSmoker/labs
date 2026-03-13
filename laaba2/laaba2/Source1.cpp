#include "Potion.h"
#include <algorithm>

// ===== конструкторы =====
Potion::Potion()
{
    name_ = "";
    base_ = "";
    volume_ = 0;
    price_ = 0;
    ingredients_.clear();
}

Potion::Potion(std::string name, std::string base, int volume,
    std::vector<std::string> ingredients, int price)
{
    name_ = name;
    base_ = base;
    volume_ = volume;
    ingredients_ = ingredients;
    price_ = price;
}

Potion::Potion(const Potion& other)
{
    name_ = other.name_;
    base_ = other.base_;
    volume_ = other.volume_;
    ingredients_ = other.ingredients_;
    price_ = other.price_;
}

Potion::~Potion()
{
    std::cout << name_ << " destructor\n";
}

// ===== геттеры =====

std::string Potion::get_name() const
{
    return name_;
}

std::string Potion::get_base() const
{
    return base_;
}

int Potion::get_volume() const
{
    return volume_;
}

std::vector<std::string> Potion::get_ingredients() const
{
    return ingredients_;
}

int Potion::get_price() const
{
    return price_;
}

// ===== сеттеры =====

void Potion::set_price(int price)
{
    if (price >= 0)
        price_ = price;
}

void Potion::set_name(std::string name)
{
    if (!name.empty())
        name_ = name;
}

void Potion::set_base(std::string base)
{
    if (!base.empty())
        base_ = base;
}

void Potion::set_volume(int volume)
{
    if (volume >= 0)
        volume_ = volume;
}
void Potion::set_ing(std::vector <std::string> ing)
{
    ingredients_ = ing;
}

// ===== методы =====

void Potion::info()
{
    std::cout << "\nPotion: " << name_;
    std::cout << "\nBase: " << base_;
    std::cout << "\nVolume: " << volume_;
    std::cout << "\nIngredients: ";

    for (int i = 0; i < ingredients_.size(); i++)
    {
        std::cout << ingredients_[i] << " ";
    }

    std::cout << "\nPrice: " << price_ << "\n";
}

void Potion::change_base(std::string new_base)
{
    base_ = new_base;
}

void Potion::change_base()
{
    base_ = "water";
}

void Potion::drink()
{
    if (volume_ >= 10)
        volume_ -= 10;
    else
        volume_ = 0;
}

// ===== оператор + =====

Potion operator+(const Potion& a, const Potion& b)
{
    Potion result;

    result.set_name("C");

    int volume = a.get_volume() + b.get_volume();
    result.set_volume(volume);

    if (a.get_volume() > b.get_volume())
        result.change_base(a.get_base());
    else
        result.change_base(b.get_base());

    std::vector<std::string> ingredients = a.get_ingredients();
    std::vector<std::string> b_ing = b.get_ingredients();

    for (int i = 0; i < b_ing.size(); i++)
    {
        std::string ing = b_ing[i];

        if (std::find(ingredients.begin(), ingredients.end(), ing) != ingredients.end())
        {
            ingredients.push_back(ing + " доп");
        }
        else
        {
            ingredients.push_back(ing);
        }
    }

    result.set_ing(ingredients);

    return result;
}

// ===== оператор += =====

Potion& Potion::operator+=(const Potion& b)
{
    *this = *this + b;
    name_ += "(обн.)";
    return *this;
}

// ===== оператор * =====

Potion operator*(const Potion& a, const Potion& b)
{
    Potion result;

    result.set_name("K");

    if (rand() % 2)
        result.set_base(a.get_base());
    else
        result.set_base(b.get_base());

    int vol = (a.get_volume() + b.get_volume()) * 0.8;
    result.set_volume(vol);

    std::vector<std::string> res;

    std::vector<std::string> a_ing = a.get_ingredients();
    std::vector<std::string> b_ing = b.get_ingredients();

    for (int i = 0; i < a_ing.size(); i++)
    {
        if (std::find(b_ing.begin(), b_ing.end(), a_ing[i]) != b_ing.end())
            res.push_back(a_ing[i]);
    }

    res.push_back("хвост");
    res.push_back("вода");

    result.set_ing(res);

    return result;
}