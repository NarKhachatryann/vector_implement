#include "library.h"
#include <iostream>

typedef struct {
    char title[100];
    char author[100];
    char isbn[20];
    int available;
}book;

const int max_books = 100;
book library[max_books];
int bookCount = 0; 

void addBook() {
    if(bookCount >= max_books) {
        std::cout << "The library is full" << std::endl;
    }

    book newBook;
    std::cout << "Enter the title of the book: ";
    std::cin.ignore();
    std::cin.getline(newBook.title, 100);
    std::cout << "Enter the author of the book: ";
    std::cin.getline(newBook.author, 100);
    std::cout << "Enter the ISBN of the book: ";
    std::cin.getline(newBook.isbn, 20);
    newBook.available = 1;

    library[bookCount++] = newBook;
    std::cout << "The book succesfully entered" << std::endl;
}

void listBooks() {
    if(bookCount == 0) {
        std::cout << "\nThere are no books\n" << std::endl;
    }
    for (int i = 0; i < bookCount; ++i) {
        std::cout << "Title: " << library[i].title << std::endl;
        std::cout << "Author: " << library[i].author << std::endl;
        std::cout << "ISBN: " << library[i].isbn << std::endl;
        if(library[i].available == 1) {
            std::cout << "Available" << std::endl;
        } else {
            std::cout << "Not Available" << std::endl;
        }
        std::cout << std::endl;
    }
}

void searchBook() {
    char title[100];
    std::cout << "Enter Title: " << std::endl;
    std::cin.ignore();
    std::cin.getline(title,100);

    for(int i = 0; i < bookCount; ++i) {
        if(strcmp(library[i].title, title) == 0) {
            std::cout << "\nBook found!" << std::endl;
            std::cout << "Title: " << library[i].title << std::endl;
            std::cout << "Author: " << library[i].author << std::endl;
            std::cout << "ISBN: " << library[i].isbn << std::endl;
            if(library[i].available == 1) {
                std::cout << "Available\n" << std::endl;
            } else {
                std::cout << "Not Available\n" << std::endl;
            }
            std::cout << std::endl;
            return;
        }
    }
}

void borrowBook() {
    char isbn[20];
    std::cout << "Enter isbn: " << std::endl;
    std::cin.ignore();
    std::cin.getline(isbn,20);

    for(int i = 0; i < bookCount; ++i) {
        if(strcmp(library[i].isbn,isbn) == 0) {
            if(library[i].available == 1) {
                library[i].available--;
                std::cout << "Book borrowed successfully!" << std::endl;
                return;
            } else {
                std::cout << "Not available!" << std::endl;
                return;
            }
        }
    }
    std::cout << "Book not found!" << std::endl;
}

void returnBook() {
    char isbn[20];
    std::cout << "Enter ISBN for return the book: " << std::endl;
    std::cin.ignore();
    std::cin.getline(isbn,20);

    for(int i = 0; i < bookCount; ++i) {
        if(strcmp(library[i].isbn, isbn) == 0) {
            if(library[i].available == 1) {
                std::cout << "Book is Available" << std::endl;
            } else {
                std::cout << "Book is borrowed" << std::endl;
                library[i].available = 1;
            }
        }
    }
}

void menu() {
    int count = 0;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. List Books\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Borrow Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter the option: ";
        std::cin >> count;

        switch (count)
        {
        case 1:
            addBook();
            break;

        case 2:
            listBooks();
            break;
        
        case 3:
            searchBook();
            break;

        case 4:
            borrowBook();
            break;

        case 5:
        returnBook();
            break;

        default:
            if(count == 6) break;
            std::cout << "Incorrect choice. Try again." << std::endl;
            break;
        }
    } while(count != 6);
    std::cout << "Exit" << std::endl;
}