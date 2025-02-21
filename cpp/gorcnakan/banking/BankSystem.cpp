#include "BankSystem.h"
#include <iostream>

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance) {
    BankAccount account(name, accountNumber, initialBalance);
    accounts.push_back(account);

    std::cout << "Account created." << "\n" << "Done!" << std::endl;
}

BankAccount* BankSystem::findAccount(int accountNumber) {
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].getNumber() == accountNumber) {
            return &accounts[i];
        }
    }
    std::cout << "Account not found." << std::endl;
    return nullptr;
}

void BankSystem::transferFunds(int senderAcc, int receiverAcc, double amount) {
    BankAccount* sender = findAccount(senderAcc);
    BankAccount* receiver = findAccount(receiverAcc);

    if(sender != nullptr && receiver != nullptr) {
        if(sender->withdraw(amount)) {
            receiver->deposit(amount);
            std::cout << "Transfer successful." << std::endl;
        } else {
            std::cout << "Transfer failed." << std::endl;
        }
    } else {
        std::cout << "Transfer failed: invalid accounts." << std::endl;
    }
}

void BankSystem::displayAllAccounts() const {
    for(int i = 0; i < accounts.size(); i++) {
        accounts[i].display();
        std::cout << std::endl;
    }
}