#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() : m_accountHolder("Unknown"), m_accountNumber(0), m_balance(0.0) {}

BankAccount::BankAccount(const std::string& name, int accountNumber, double initialBalance)
    : m_accountHolder(name), m_accountNumber(accountNumber), m_balance(initialBalance) {}

BankAccount::BankAccount(const BankAccount& other)
    : m_accountHolder(other.m_accountHolder), m_accountNumber(other.m_accountNumber), m_balance(other.m_balance) {}

BankAccount::~BankAccount() {
    std::cout << "Destroying account of " << m_accountHolder << std::endl;
}

void BankAccount::deposit(double amount) {
    m_balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if(m_balance >= amount && amount > 0) {
        m_balance -= amount;
        return true;
    } else {
        std::cout << "Error" << std::endl;
        return false;
    }
}

int BankAccount::getNumber() const {
    return m_accountNumber;
}

double BankAccount::getBalance() const {
    return m_balance;
}

void BankAccount::display() const {
    std::cout << "Account Holder: " << m_accountHolder << std::endl;
    std::cout << "Account Number: " << m_accountNumber << std::endl;
    std::cout << "Balance: " << m_balance << std::endl;
}