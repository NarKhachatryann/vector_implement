#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

class Order;

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Order> orderHistory;
public:
    Customer(std::string customerName, std::string contact);
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);
    Customer(Customer&& other) noexcept;
    Customer& operator=(Customer&& other) noexcept;
    ~Customer();
    void placeOrder(Order order);
    void viewOrderHistory() const;
    std::string getName() const;
};
    
#endif