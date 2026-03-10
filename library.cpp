#include<iostream>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
};

struct Member {
    string name;
    string id;
    string phoneNumber;
    string membershipType;
};

string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

void showMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book (By Title)\n";
    cout << "3. View All Books\n";
    cout << "4. Search Book (By ISBN)\n";
    cout << "5. Add Member\n";
    cout << "6. View All Members\n";
    cout << "7. Search Member (By Name)\n";
    cout << "8. Search Member (By ID)\n";
    cout << "9. Exit\n";
    cout << "Enter choice: ";
}

void addBook() {
    Book b;

    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, b.title);

    cout << "Enter Author: ";
    getline(cin, b.author);

    cout << "Enter ISBN: ";
    getline(cin, b.isbn);

    if (b.title.empty() || b.author.empty() || b.isbn.empty()) {
        cout << "Invalid input! Fields cannot be empty.\n";
        return;
    }

    ofstream file("books.txt", ios::app);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    file << b.title << "|" << b.author << "|" << b.isbn << endl;

    file.close();

    cout << "Book added successfully!\n";
}

void viewAllBooks() {

    ifstream file("books.txt");

    if (!file) {
        cout << "No books found.\n";
        return;
    }

    string line;

    cout << "\n----- Book List -----\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchBookByTitle() {

    cin.ignore();
    string term;

    cout << "Enter book title: ";
    getline(cin, term);

    ifstream file("books.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool found = false;

    string lowerTerm = toLowerCase(term);

    while (getline(file, line)) {

        string lowerLine = toLowerCase(line);

        if (lowerLine.find(lowerTerm) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Book not found.\n";

    file.close();
}

void searchBookByISBN() {

    cin.ignore();
    string isbn;

    cout << "Enter ISBN: ";
    getline(cin, isbn);

    ifstream file("books.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {

        if (line.find(isbn) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";

    file.close();
}

void addMember() {

    Member m;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, m.name);

    cout << "Enter ID: ";
    getline(cin, m.id);

    cout << "Enter Phone Number: ";
    getline(cin, m.phoneNumber);

    cout << "Enter Membership Type: ";
    getline(cin, m.membershipType);

    if (m.name.empty() || m.id.empty()) {
        cout << "Invalid input!\n";
        return;
    }

    ofstream file("members.txt", ios::app);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    file << m.name << "|" << m.id << "|" << m.phoneNumber << "|" << m.membershipType << endl;

    file.close();

    cout << "Member added successfully!\n";
}

void viewAllMembers() {

    ifstream file("members.txt");

    if (!file) {
        cout << "No members found.\n";
        return;
    }

    string line;

    cout << "\n----- Member List -----\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchMemberByName() {

    cin.ignore();
    string term;

    cout << "Enter member name: ";
    getline(cin, term);

    ifstream file("members.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool found = false;

    string lowerTerm = toLowerCase(term);

    while (getline(file, line)) {

        string lowerLine = toLowerCase(line);

        if (lowerLine.find(lowerTerm) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Member not found.\n";

    file.close();
}

void searchMemberByID() {

    cin.ignore();
    string id;

    cout << "Enter Member ID: ";
    getline(cin, id);

    ifstream file("members.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {

        if (line.find(id) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Member not found.\n";

    file.close();
}

int main() {

    int choice;

    do {

        showMenu();
        cin >> choice;

        switch (choice) {

        case 1:
            addBook();
            break;

        case 2:
            searchBookByTitle();
            break;

        case 3:
            viewAllBooks();
            break;

        case 4:
            searchBookByISBN();
            break;

        case 5:
            addMember();
            break;

        case 6:
            viewAllMembers();
            break;

        case 7:
            searchMemberByName();
            break;

        case 8:
            searchMemberByID();
            break;

        case 9:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 9);

    return 0;
}