/*A library needs to manage a collection of books (data fields such
as book title, author, ISBN, availability status, and other relevant
information), maintain information about each book, support
operations like adding, removing, and searching for books, and
provide efficient access to library resources. Use the Concept of
Linked List for implementation of Library Management system.*/


#include <iostream>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    Book* next;
};

class Library {
public:
    Book* head;
    Library() {
        head = NULL;
    }


  void addBook(string title, string author, string ISBN, bool isAvailable) {
    Book* newBook = new Book;  // Create a new Book object
    newBook->title = title;    // Initialize the members directly
    newBook->author = author;
    newBook->ISBN = ISBN;
    newBook->isAvailable = isAvailable;
    newBook->next = head;
    head = newBook;
    cout << "Book added: " << title << endl;
}




    void removeBook(string ISBN) {
    if (head==NULL) {
        cout << "Library is empty." << endl;
        return;
    }

    // If the first book has the ISBN we want to remove
    if (head->ISBN == ISBN) {
        Book* temp = head;
        head = head->next;
        delete temp;
        cout << "Book with ISBN " << ISBN << " removed." << endl;
        return;
    }

    Book* current = head;
    while (current->next!=NULL) {
        if (current->next->ISBN == ISBN) {//check ISBN of next book 
            Book* temp = current->next; //store next book in temp
            current->next = current->next->next;  //remove book 
            delete temp;
            cout << "Book with ISBN " << ISBN << " removed." << endl;
            return;
        }
        current = current->next;//the loop then continues checking the next book
    }

    cout << "Book with ISBN " << ISBN << " not found." << endl;
}


    void searchBook(string title) {
        Book* current = head;
        while (current!=NULL) {
            if (current->title == title) {
                cout << "Book found: " << endl;
                cout << "Title: " << current->title << ", Author: " << current->author
                     << ", ISBN: " << current->ISBN
                     << ", Available: " << (current->isAvailable ? "Yes" : "No") << endl;
                return;
            }
            current = current->next;//continues to the next element in a loop

        }
        cout << "Book with title \"" << title << "\" not found." << endl;
    }

    void displayBooks() {
        if (head==NULL) {
            cout << "Library is empty." << endl;
            return;
        }

        Book* current = head;
        while (current!=NULL) {
            cout << "Title: " << current->title << ", Author: " << current->author
                 << ", ISBN: " << current->ISBN
                 << ", Available: " << (current->isAvailable ? "Yes" : "No") << endl;
            current = current->next;
        }
    }

    ~Library() {
        while (head!=NULL) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Library myLibrary;
    int choice;
    string title, author, ISBN;
    bool isAvailable;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin>>title;
                cout << "Enter author: ";
                cin>>author;
                cout << "Enter ISBN: ";
                cin>>ISBN;
                cout << "Is the book available (1 for Yes, 0 for No): ";
                cin >> isAvailable;
                myLibrary.addBook(title, author, ISBN, isAvailable);
                break;

            case 2:
                cout << "Enter ISBN of the book to remove: ";
                getline(cin, ISBN);
                myLibrary.removeBook(ISBN);
                break;

            case 3:
                cout << "Enter title of the book to search: ";
                getline(cin, title);
                myLibrary.searchBook(title);
                break;

            case 4:
                cout << "\nDisplaying all books:\n";
                myLibrary.displayBooks();
                break;

            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
