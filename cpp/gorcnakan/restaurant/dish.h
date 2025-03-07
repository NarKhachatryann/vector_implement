#pragma once
#include <iostream>

class Dish {
    protected:
        std::string name;
        double price;
    public:
        Dish(std::string dishName, double dishPrice);
        Dish(const Dish& other);
        Dish& operator=(const Dish& other);
        Dish(Dish&& other) noexcept;
        Dish& operator=(Dish&& other) noexcept;
    
        void display() const;
        double getPrice() const;
        std::string getName() const;
    };

class Appetizer : public Dish {
private:
    bool isSpicy;
public:
    Appetizer(std::string dishName, double dishPrice, bool spicy);
    void display() const;
};

class Entree : public Dish {
private:
    int calories;
public:
    Entree(std::string dishName, double dishPrice, int cal);
    void display() const;
};

class Dessert : public Dish {
private:
    bool containsNuts;
public:
    Dessert(std::string dishName, double dishPrice, bool nuts);
    void display() const;
};
    
