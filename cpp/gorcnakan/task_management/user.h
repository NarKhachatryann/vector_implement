#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "task.h"

class User {
private:
    std::string username;
    std::string password;
    std::vector<Task*> tasks;

public:
    User(const std::string& username, const std::string& password) {
        this->username = username;
        this->password = password;

        tasks = std::vector<Task*>();

        std::cout << "User " << username << " has been created." << std::endl;
    }

    User(const User& other) {
        username = other.username;
        password = other.password;
        tasks = other.tasks;
    }

    User(User&& other) noexcept {
        username = other.username;
        password = other.password;
        tasks = other.tasks;

        other.username = "";
        other.password = "";
        other.tasks.clear();
    }
    
    ~User() {
        for (Task* task : tasks) {
            delete task;
        }
    }

    void addTask(Task* task) {
        tasks.push_back(task);
    }

    void deleteTask(const std::string& title) {
        for(int i{}; i < tasks.size(); ++i) {
            if(tasks[i]->getTitle() == title) {
                delete tasks[i];
                tasks.erase(tasks.begin() + i);
                return;
            }
        }
    }
    
    void editTask(const std::string& title, const Task& updatedTask) {
        for(int i{}; i < tasks.size(); ++i) {
            if(tasks[i]->getTitle() == title) {
                tasks[i]->setCompleted(updatedTask.isCompleted());
                tasks[i]->setDeadline(updatedTask.getDeadline());
                tasks[i]->setPriority(updatedTask.getPriority());
                return;
            }
        }
    }

    void listTasks() const {
        for (const Task* task : tasks) {
            std::cout << "Title: " << task->getTitle() << std::endl;
            std::cout << "Description: " << task->getDescription() << std::endl;
            std::cout << "Deadline: " << task->getDeadline() << std::endl;
            std::cout << "Category: " << task->getCategory() << std::endl;
            std::cout << "Priority: " << task->getPriority() << std::endl;
            std::cout << "Completed: " << (task->isCompleted() ? "Yes" : "No") << std::endl;
            std::cout << std::endl;
        }
    }

    Task* searchTask(const std::string& title) {
        for (Task* task : tasks) {
            if (task->getTitle() == title) {
                return task;
            }
        }

        return nullptr;
    }

    Task* getTask(const std::string& title) {
        for (Task* task : tasks) {
            if (task->getTitle() == title) {
                return task;
            }
        }

        return nullptr;
    }

    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }

    void updatePassword(const std::string& newPassword) {
        password = newPassword;
        std::cout << "Password for user " << username << " has been updated." << std::endl;
    }

    void setUsername(const std::string& newUsername) {
        username = newUsername;
        std::cout << "Username has been updated to " << username << "." << std::endl;
    }

    void setPassword(const std::string& newPassword) {
        password = newPassword;
        std::cout << "Password has been updated." << std::endl;
    }

    bool authenticate(const std::string& inputPassword) const {
        return password == inputPassword;
    }

    void removeTask(const std::string& title) {
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i]->getTitle() == title) {
                delete tasks[i];
                tasks.erase(tasks.begin() + i);
                return;
            }
        }
        std::cout << "Task \"" << title << "\" not found." << std::endl;
    }

};

#endif