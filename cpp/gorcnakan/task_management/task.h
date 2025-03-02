#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class Priority { Low = 1, Medium = 2, High = 3};

class Task {
    private:
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    Priority m_priority;
    bool m_completed;
    

    public:

    Task(std::string title, std::string description, std::string deadline, std::string category, Priority priority);

    Task(const Task& other);

    std::string getTitle() const;
    std::string getDescription() const;
    std::string getDeadline() const;
    std::string getCategory() const;
    Priority getPriority() const;
    bool isCompleted() const;


    void setCompleted(bool status);
    
    void setPriority(Priority priority);

    void setDeadline(const std::string& deadline);

    void setCategory(const std::string& category);

    void setDescription(const std::string& description);

    void display() const;
};