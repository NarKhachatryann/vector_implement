#pragma once

#include <iostream>
#include <vector>
#include "dish.h"


class Menu {
private:
    std::vector<Dish*> dishes;
public:

    Menu(const Menu& other);
    Menu& operator=(const Menu& other);
    Menu(Menu&& other) noexcept;
    Menu& operator=(Menu&& other) noexcept;
    ~Menu();
    void addDish(Dish* dish);
    void displayMenu() const;
    Dish* getDishByName(const std::string& dishName) const;
};
    
    