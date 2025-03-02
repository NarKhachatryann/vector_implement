#include "task.h"

Task::Task(std::string title, std::string description, std::string deadline, std::string category, Priority priority)
        : m_title(title), m_description(description), m_deadline(deadline), m_category(category), m_priority(priority), m_completed(false) {}

Task::Task(const Task& other) {
    m_category = other.m_category;
    m_completed = other.m_completed;
    m_deadline = other.m_deadline;
    m_description = other.m_description;
    m_priority = other.m_priority;
    m_title = other.m_title;
}

std::string Task::getTitle() const { return m_title; }
std::string Task::getDescription() const { return m_description; }
std::string Task::getDeadline() const { return m_deadline; }
std::string Task::getCategory() const { return m_category; }
Priority Task::getPriority() const { return m_priority; }
bool Task::isCompleted() const { return m_completed; }


void Task::setCompleted(bool status) { 
    m_completed = status; 
}

void Task::setPriority(Priority priority) { 
    m_priority = priority; 
}

void Task::setDeadline(const std::string& deadline) {
    m_deadline = deadline;
}

void Task::setCategory(const std::string& category) {
    m_category = category;
}

void Task::setDescription(const std::string& description) {
    m_description = description;
}

void Task::display() const {
    std::cout << "Title: " << m_title << std::endl;
    std::cout << "Description: " << m_description << std::endl;
    std::cout << "Deadline: " << m_deadline << std::endl;
    std::cout << "Category: " << m_category << std::endl;
    if(m_priority == Priority::Low) {
        std::cout << "Priority: Low" << std::endl;
    } else if(m_priority == Priority::Medium) {
        std::cout << "Priority: Medium" << std::endl;
    } else {
        std::cout << "Priority: High" << std::endl;
    }
    std::cout << "Completed: " << (m_completed ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

}