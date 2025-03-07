#include "dish.h"

Dish::Dish(std::string dishName, double dishPrice) : name(dishName), price(dishPrice) {}

Dish::Dish(const Dish& other) {
    name = other.name;
    price = other.price;
}

Dish& Dish::operator=(const Dish& other) {
    if(this == &other) return *this;
    name = other.name;
    price = other.price;
    return *this;
}

Dish::Dish(Dish&& other) noexcept : name(std::move(other.name)), price(other.price) {}
Dish& Dish::operator=(Dish&& other) noexcept{
    if(this == &other) return *this;
    name = std::move(other.name);
    price = other.price;
    return *this;
}

void Dish::display() const {
    std::cout << "Dish Name: " << name << ", Price: " << price << std::endl;
}
double Dish::getPrice() const {
    return price;
}
std::string Dish::getName() const {
    return name;
}

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy) : Dish(dishName, dishPrice) {}

void Appetizer::display() const {
    std::cout << "Appetizer Name: " << getName() << ", Price: " << getPrice() << (isSpicy ? ", Spicy" : ", Not Spicy") << std::endl;
}

Entree::Entree(std::string dishName, double dishPrice, int cal) : Dish(dishName, dishPrice), calories(cal) {}

void Entree::display() const {
    std::cout << "Entree Name: " << getName() << ", Price: " << getPrice() << ", Calories: " << calories << std::endl;
}