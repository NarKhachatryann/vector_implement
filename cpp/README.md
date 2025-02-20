# Library Management System

This is a simple library management system developed in C++, which allows users to manage a collection of books. Users can perform various operations such as adding new books, borrowing and returning books, and searching for books by title or author.

## Data Structures

The program uses a structure (`struct Book`) to represent a book, with the following fields:

```cpp
typedef struct {
    char title[100];
    char author[100];
    char isbn[20];
    int available; // 1 for available, 0 for borrowed
} book;
The library is stored in an array of book structures with a maximum capacity of 100 books.

Functional Requirements
The program provides a text-based menu with the following options:

Add a New Book: Prompts the user to enter the book details (title, author, ISBN) and adds the book to the collection.

List All Books: Displays the list of all books along with their current status (available/borrowed).

Search for a Book: Allows the user to search for a book by title or author and displays the matching book(s) with their details.

Borrow a Book: Asks the user to enter an ISBN to identify the book, and if the book is available, marks it as borrowed.

Return a Book: Asks the user for the ISBN of the book, and if the book is currently borrowed, marks it as available.

Exit: Terminates the program.

Implementation Details
Functions
void addBook(): Adds a new book to the library.

void listBooks(): Lists all the books in the library.

void searchBook(): Searches for a book by title or author.

void borrowBook(): Allows the user to borrow a book by its ISBN.

void returnBook(): Allows the user to return a borrowed book by its ISBN.

void menu(): Displays the menu and handles user input to perform different operations.

Usage
To use the program, compile the source code and run the executable. The menu will prompt you to select an option, and you can follow the instructions to perform different operations.

Example
g++ library.cpp -o library
./library

Notes
The library has a maximum capacity of 100 books.

The program uses C++'s standard input and output functions to interact with the user.

The program checks for the availability of books before borrowing and returning them.

License
This project is licensed under the MIT License.
