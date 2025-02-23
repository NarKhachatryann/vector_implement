#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <string>
#include <vector>

class Task {
    private:
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    int m_priority;
    bool m_completed;
    

    public:

    Task(std::string title, std::string description, std::string deadline, std::string category, int priority)
        : m_title(title), m_description(description), m_deadline(deadline), m_category(category), m_priority(priority), m_completed(false) {}

        Task(const Task& other) {
            m_category = other.m_category;
            m_completed = other.m_completed;
            m_deadline = other.m_deadline;
            m_description = other.m_description;
            m_priority = other.m_priority;
            m_title = other.m_title;
        }

    std::string getTitle() const { return m_title; }
    std::string getDescription() const { return m_description; }
    std::string getDeadline() const { return m_deadline; }
    std::string getCategory() const { return m_category; }
    int getPriority() const { return m_priority; }
    bool isCompleted() const { return m_completed; }


    void setCompleted(bool status) { m_completed = status; }
    
    void setPriority(int priority) {
        m_priority = priority;
    }

    void setDeadline(const std::string& deadline) {
        m_deadline = deadline;
    }

    void setCategory(const std::string& category) {
        m_category = category;
    }

    void setDescription(const std::string& description) {
        m_description = description;
    }

    void display() const {
        std::cout << "Title: " << m_title << std::endl;
        std::cout << "Description: " << m_description << std::endl;
        std::cout << "Deadline: " << m_deadline << std::endl;
        std::cout << "Category: " << m_category << std::endl;
        std::cout << "Priority: " << m_priority << std::endl;
        std::cout << "Completed: " << (m_completed ? "Yes" : "No") << std::endl;
        std::cout << std::endl;
    }
};

#endif