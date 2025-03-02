#include "user.h"

User::User(const std::string& username, const std::string& password) {
    this->username = username;
    this->password = password;

    tasks = std::vector<Task*>();

    std::cout << "User " << username << " has been created." << std::endl;
}

User::User(const User& other) {
    username = other.username;
    password = other.password;
    tasks = other.tasks;
}

User::User(User&& other) noexcept {
    username = other.username;
    password = other.password;
    tasks = std::move(other.tasks);

    other.username = "";
    other.password = "";
}

User::~User() {
    for (Task* task : tasks) {
        delete task;
    }
}

void User::addTask(Task* task) {
    tasks.push_back(task);
}

void User::deleteTask(const std::string& title) {
    for(int i{}; i < tasks.size(); ++i) {
        if(tasks[i]->getTitle() == title) {
            delete tasks[i];
            tasks.erase(tasks.begin() + i);
            return;
        }
    }
}

void User::editTask(const std::string& title, const Task& updatedTask) {
    for(int i{}; i < tasks.size(); ++i) {
        if(tasks[i]->getTitle() == title) {
            tasks[i]->setCompleted(updatedTask.isCompleted());
            tasks[i]->setDeadline(updatedTask.getDeadline());
            tasks[i]->setPriority(updatedTask.getPriority());
            return;
        }
    }
}

void User::listTasks() const {
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

Task* User::searchTask(const std::string& title) {
    for (Task* task : tasks) {
        if (task->getTitle() == title) {
            return task;
        }
    }

    return nullptr;
}

Task* User::getTask(const std::string& title) {
    for (Task* task : tasks) {
        if (task->getTitle() == title) {
            return task;
        }
    }

    return nullptr;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

void User::updatePassword(const std::string& newPassword) {
    password = newPassword;
    std::cout << "Password for user " << username << " has been updated." << std::endl;
}

void User::setUsername(const std::string& newUsername) {
    username = newUsername;
    std::cout << "Username has been updated to " << username << "." << std::endl;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
    std::cout << "Password has been updated." << std::endl;
}

bool User::authenticate(const std::string& inputPassword) const {
    return password == inputPassword;
}

void User::removeTask(const std::string& title) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i]->getTitle() == title) {
            delete tasks[i];
            tasks.erase(tasks.begin() + i);
            std::cout << "Task \"" << title << "\" has been removed." << std::endl;
            return;
        }
    }
    std::cout << "Task \"" << title << "\" not found." << std::endl;
}