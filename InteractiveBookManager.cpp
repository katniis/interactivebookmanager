#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
    string overview;
    string status; 
    string startdate;
    string enddate;
    string progress; 
};

vector<Book> books;

void displaymenu();
void addbook();
void viewbook();
void viewbook2();
void updatebook();
void deletebook();

int main (){

    int choice;
    do {
        displaymenu();
        cout << "Choose Number to Enter: ";
        cin >> choice;
        cout << endl;
        cin.ignore();

        switch (choice){
            case 1: 
                addbook();
                break;
            case 2: 
                viewbook();
                break;
            case 3:
                updatebook();
                break;
            case 4:
                deletebook();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
        }

    } while (choice != 5);
    return 0;
}

void displaymenu(){
    cout << "\n|=====Interactive Book Manager=====|" << endl;\
    cout << " 1. Add a Book" << endl;
    cout << " 2. View Books" << endl;
    cout << " 3. Update Book" << endl;
    cout << " 4. Delete Book" << endl;
    cout << " 5. Exit" << endl;
    cout << endl;
}

void addbook(){
    Book newbook;
    cout << "\nEnter book title: ";
    getline(cin, newbook.title);
    cout << "Enter book author: ";
    getline(cin, newbook.author);
    cout << "Enter book genre: ";
    getline(cin, newbook.genre);
    cout << "Enter book progress (e.g., 'Chapter 5'): ";
    getline(cin, newbook.progress);
    cout << "Enter book status ('Not Started', 'In progress', 'Completed' or 'Dropped'): ";
    getline(cin, newbook.status);
    cout << "Enter date started reading (YYYY-MM-DD): ";
    getline(cin, newbook.startdate);
    cout << "Enter target end date reading (YYYY-MM-DD): ";
    getline(cin, newbook.enddate);
    cout << "Enter book overview: ";
    getline(cin, newbook.overview);

    books.push_back(newbook);
    cout << endl;
    cout << newbook.title << " has been added on the book list" << endl;
    system("PAUSE");
}

void viewbook(){
    if (books.empty()) {
        cout << "\nNo books in the list." << endl;
        return;
    }
    
    cout << "|=====Current Book List=====|" << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i].title << " | " << "by "<< books[i].author << endl;
        cout  << " Genre: " << books[i].genre << " | " << books[i].progress << " | " << books[i].status << endl; 
        cout << "Date Started Reading: " << books[i].startdate << " | " << "Target End Reading: " << books[i].enddate << endl;
    }

    cout << endl;
    cout << "Enter the book number to see overview (0 to return): ";
    int selection;
    cin >> selection;
    
    if (selection == 0){
        return;
    } else {
        cout << endl;
        cout << selection << ". " << books[selection - 1].title << " | " << "by "<< books[selection - 1].author << endl;
        cout << "Genre: " << books[selection - 1].genre << " | " << books[selection - 1].progress <<  " | " << books[selection - 1].status << endl; 
        cout << "Date Started Reading: " << books[selection - 1].startdate << " | " << "Target End Reading: " << books[selection - 1].enddate << endl;
        cout << "Overview: " << books[selection - 1].overview << endl;
    }
    system("PAUSE");
}

void viewbook2(){
    if (books.empty()) {
        cout << "\nNo books in the list." << endl;
        return;
    }
    
    cout << "|=====Current Book List=====|" << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i].title << " | " << "by "<< books[i].author << endl;
        cout  << "Genre: " << books[i].genre << " | " << books[i].progress << " | " << books[i].status << endl; 
        cout << "Date Started Reading: " << books[i].startdate << " | " << "Target End Reading: " << books[i].enddate << endl;
    }
}

void updatebook(){
    if (books.empty()) {
        cout << "\nNo books in the list." << endl;
        return;
    }

    viewbook2();
    cout << endl;
    cout << "Select a book number to update: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > books.size()) {
        cout << "Invalid selection." << endl;
        return;
    }

    cout << "\nUpdating " << books[index - 1].title << endl;
    cout << "1. Update progress" << endl;
    cout << "2. Update status" << endl;
    cout << "Enter your choice: ";
    int updchoice;
    cin >> updchoice;
    cin.ignore();
    
    if (updchoice == 1){
        cout << "Enter new progress (e.g., 'Chapter 5'): ";
        getline(cin, books[index - 1].progress);
        cout << "Progress updated to: " << books[index - 1].progress << endl;
    } else if (updchoice == 2){
        cout << "Enter new status ('Not Started', 'In prgress', 'Completed' or 'Dropped')): ";
        getline(cin, books[index - 1].status);
        cout << "Status updated to: " << books[index - 1].status << endl;
    } else {
        cout << "Invalid Input" << endl;
        return;
    }
    system("PAUSE");
}

void deletebook() {
    if (books.empty()) {
        cout << "\nNo books available to delete." << endl;
        return;
    }

    viewbook2();
    cout << "Select a book number to delete: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > books.size()) {
        cout << "Invalid selection." << endl;
        return;
    }

    cout << "Are you sure you want to delete '" << books[index - 1].title << "'? (Y/N): ";
    char confirm;
    cin >> confirm;
    cin.ignore();

    if (tolower(confirm) == 'y') {
        books.erase(books.begin() + index - 1);
        cout << "Book deleted successfully!" << endl;
    } else {
        cout << "Deletion canceled." << endl;
    }
}