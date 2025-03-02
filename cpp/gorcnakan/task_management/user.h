#pragma once

#include <string>
#include <vector>
#include "task.h"

class User {
private:
    std::string username;
    std::string password;
    std::vector<Task*> tasks;

public:
    User(const std::string& username, const std::string& password);
    User(const User& other);
    User(User&& other) noexcept;
    ~User();
    
    void addTask(Task* task);
    void deleteTask(const std::string& title);
    void editTask(const std::string& title, const Task& updatedTask);
    void listTasks() const;
    Task* searchTask(const std::string& title);
    Task* getTask(const std::string& title);
    std::string getUsername() const;
    std::string getPassword() const;
    void updatePassword(const std::string& newPassword);
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);
    bool authenticate(const std::string& inputPassword) const;
    void removeTask(const std::string& title);
};