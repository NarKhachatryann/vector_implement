#include <iostream>
#include "order.h"

Order::Order(Customer* customer) : customer(customer), totalPrice(0.0) {}

Order::Order(const Order& other) : customer(other.customer), totalPrice(other.totalPrice) {}

Order& Order::operator=(const Order& other) { 
    if(this == &other) {
        return *this;
    }
    customer = other.customer;
    totalPrice = other.totalPrice;
    return *this;
}

Order::Order(Order&& other) noexcept {
    this->customer = std::move(other.customer);
    this->totalPrice = std::move(other.totalPrice);

    other.customer = nullptr;
    other.totalPrice = 0.0;
}

Order& Order::operator=(Order&& other) noexcept {
    if(this != &other) {
        customer = std::move(other.customer);
        totalPrice = std::move(other.totalPrice);

        other.customer = nullptr;
        other.totalPrice = 0.0;
    }
    return *this;
}

Order::~Order() {
    for(int i = 0; i < orderedDishes.size(); ++i) {
        delete orderedDishes[i];
    }
    orderedDishes.clear();
}

void Order::addDish(Dish* dish) {
    if (dish) {
        orderedDishes.push_back(dish);
    }
}

void Order::calculateTotal() {
    totalPrice = 0.0;
    for (const auto& dish : orderedDishes) {
        totalPrice += dish->getPrice();
    }
}

void Order::displayOrder() const {
    for (const auto& dish : orderedDishes) {
        std::cout << dish->getName() << " - " << dish->getPrice() << std::endl;
    }
    std::cout << "Total Price: " << totalPrice << std::endl;
    std::cout << "Number of Dishes Ordered: " << orderedDishes.size() << std::endl;
}