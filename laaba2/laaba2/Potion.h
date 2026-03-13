#pragma once
#include <iostream>
#include <vector>
#include <string>

class Potion
{
private:
    std::string name_;
    std::string base_;
    int volume_;
    std::vector<std::string> ingredients_;

protected:
    std::string description_;

public:
    int price_;

    // конструкторы
    Potion();
    Potion(std::string name, std::string base, int volume,std::vector<std::string> ingredients, int price);
    Potion(const Potion& other);
    ~Potion();

    // геттеры
    std::string get_name() const;
    std::string get_base() const;
    int get_volume() const;
    std::vector<std::string> get_ingredients() const;
    int get_price() const;

    // сеттеры
    void set_price(int price);
    void set_name(std::string name);
    void set_base(std::string base);
    void set_volume(int volume);
    void set_ing(std::vector <std::string> ing);

    // методы
    void info();
    void change_base(std::string new_base);
    void change_base();
    void drink();


    Potion& operator+=(const Potion& b);
};

Potion operator+(const Potion& a, const Potion& b);
Potion operator*(const Potion& a, const Potion& b);