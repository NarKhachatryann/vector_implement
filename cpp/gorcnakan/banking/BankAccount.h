#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string m_accountHolder;
    int m_accountNumber;
    double m_balance;

public:
    BankAccount();

    BankAccount(const std::string& name, int accountNumber, double initialBalance);

    BankAccount(const BankAccount& other);

    ~BankAccount();

    int getNumber() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
};

#endif
