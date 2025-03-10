#include "menu.h"

Menu::Menu(const Menu& other) {
    for (Dish* dish : other.dishes) {
        dishes.push_back(new Dish(*dish));
    }
}

Menu& Menu::operator=(const Menu& other) {
    if(this == &other) {
        return *this;
    }

    for(Dish* dish : dishes) {
        delete dish;
    }
    dishes.clear();

    for(Dish* dish : other.dishes) {
        dishes.push_back(new Dish(*dish));
    }

    return *this;
}

Menu::Menu(Menu&& other) noexcept {
    this-> dishes = std::move(other.dishes);

    other.dishes.clear();
}

Menu& Menu::operator=(Menu&& other) noexcept {
    if(this == &other) {
        return *this;
    }

    for(Dish* dish : dishes) {
        delete dish;
    }
    dishes.clear();

    dishes = std::move(other.dishes);

    other.dishes.clear();
    return *this;
}

Menu::~Menu() {
    for(Dish* dish : dishes) {
        delete dish;
    }
    dishes.clear();
}

void Menu::addDish(Dish* dish) {
    if(dish) {
        dishes.push_back(dish);
    }
}

void Menu::displayMenu() const {
    for(int i = 0; i < dishes.size(); ++i) {
        std::cout << dishes[i] << std::endl;
    }
}

Dish* Menu::getDishByName(const std::string& dishName) const {
    for(int i = 0; i < dishes.size(); ++i) {
        if(dishes[i]->getName() == dishName) {
            return dishes[i];
        }
    }
    return nullptr;
}