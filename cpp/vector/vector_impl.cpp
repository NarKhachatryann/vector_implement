#include "vector_impl.h"

void Vector::realocate(int new_capacity) {
    int *new_data = new int(new_capacity);
    for(int i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;

    m_data = new_data;
    m_capacity = new_capacity;
}

Vector::Vector(const Vector& other) {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new int [other.m_capacity];
    for(int i = 0; i < other.m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

int Vector::at(size_t index) const {
    if(index > m_size) {
        std::cout << "index is not invalid \n" << std::endl;
        return -1;
    }

    return m_data[index];
}

void Vector::push_back(int value) {
    if(m_capacity == 0 && m_size == 0) {
        realocate(10);
        m_data[m_size] = value;
        m_size++;
        return;
    }
    if(m_size == m_capacity) {
        realocate(m_capacity * 2);
    }
    m_data[m_size] = value;
    m_size++;
}

void Vector::pop_back() {
    if(m_size == 0) {
        std::cout << "Vector is empty" << std::endl;
        return;
    }
    m_size--;
}

size_t Vector::get_size() const {
    return m_size;
}

size_t Vector::get_cap() const {
    return m_capacity;
}

void Vector::resize (size_t newSize) {
    if(newSize > m_capacity) {
        realocate(newSize);
    }
    m_size = newSize;
}

void Vector::reserve(size_t cap) {
    if (cap >= m_capacity)
    {
        realocate(cap);
    }
}

int Vector::front () const {
    if(m_size == 0) {
        std::cout << "Vector is empty" << std::endl;
        return -1;
    }

    return m_data[0];
}

int Vector::back () const {
    if(m_size == 0) {
        std::cout << "Vector is empty" << std::endl;
        return -1;
    }
    return m_data[m_size - 1];
}

bool Vector::isEmpty() const {
    if(m_size == 0) {
        return false;
    }
    return true;
}

void Vector::shrink_to_fit() {
    m_capacity = m_size;
    realocate(m_capacity);
}

void Vector::insert (size_t index, int value) {
    if(index >= m_size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if(m_capacity == m_size) {
        realocate(m_capacity * 2);
    }
    
    for(int i = m_size; i > index; --i) {
        m_data[i] = m_data[i - 1];
    }
    m_data[index] = value;
    m_size++;
}

void Vector::erase (size_t index) {
    if(index >= m_size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    m_data[index] = 0;

    for(int i = index; i < m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    m_size--;
}

void Vector::clear () {
    m_size = 0;
}