#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "task.h"

class TaskManager {
private:
    std::vector<User*> users;
    User* loggedInUser = nullptr;

public:
    TaskManager() = default;
    TaskManager(const TaskManager& other);
    TaskManager(TaskManager&& other) noexcept;
    ~TaskManager();

    void registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();
    void addTaskForUser(const Task& task);
    void deleteTaskForUser(const std::string& title);
    void editTaskForUser(const std::string& title, const Task& updatedTask);
    void removeTaskForUser(const std::string& title);
    void displayTasksForUser() const;
};