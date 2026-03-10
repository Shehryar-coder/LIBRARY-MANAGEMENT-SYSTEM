# 📚 Library Management System (C++)

## 📖 Overview

The **Library Management System** is a simple console-based application written in **C++** that allows users to manage books and members in a library.

The system uses **file handling** to store data permanently in text files and provides different options to add, search, and view books and members.

This project demonstrates the use of:

* C++ structures
* File handling (`ifstream`, `ofstream`)
* String manipulation
* Menu-driven programs
* Basic searching techniques

---

## 🚀 Features

### 📘 Book Management

* Add new books to the library
* Search books by **Title**
* Search books by **ISBN**
* View all available books

### 👤 Member Management

* Add new members
* Search members by **Name**
* Search members by **ID**
* View all registered members

### 💾 Data Storage

All data is stored using **text files**:

* `books.txt` → Stores book records
* `members.txt` → Stores member records

This ensures that data is **saved even after the program closes**.

---

## 🛠 Technologies Used

* **C++**
* **File Handling**
* **Object-like Structures**
* **Standard Template Library (STL)**

Libraries used in the project:

```
<iostream>
<string>
<fstream>
<cctype>
```

---

## 📂 Project Structure

```
Library-Management-System
│
├── library.cpp        # Main source code
├── CMakeLists.txt     # CMake configuration file
├── books.txt          # Stores book records (created automatically)
├── members.txt        # Stores member records (created automatically)
└── README.md          # Project documentation
```

---

## ⚙️ How to Run the Project

### 1️⃣ Clone the repository

```
git clone https://github.com/Shehryar-coder/LIBRARY-MANAGEMENT-SYSTEM.git
```

### 2️⃣ Navigate to the project folder

```
cd LIBRARY-MANAGEMENT-SYSTEM
```

### 3️⃣ Compile the program

Using **g++ compiler**

```
g++ library.cpp -o library
```

### 4️⃣ Run the program

```
./library
```

or on Windows:

```
library.exe
```

---

## 📋 Program Menu

When the program runs, the following menu appears:

```
1. Add Book
2. Search Book (By Title)
3. View All Books
4. Search Book (By ISBN)
5. Add Member
6. View All Members
7. Search Member (By Name)
8. Search Member (By ID)
9. Exit
```

Users can select an option to perform the desired operation.

---

## ⚠️ Edge Cases Handled

The program includes handling for common issues such as:

* File not found errors
* Empty input validation
* Case-insensitive searching
* Invalid menu selections

---

## 🔮 Future Improvements

Possible enhancements for this project include:

* Book issue and return system
* Delete or update book records
* Admin authentication system
* Graphical User Interface (GUI)
* Database integration (MySQL or SQLite)

---

## 👨‍💻 Author

**Shehryar Khan**

Software Engineering Student
COMSATS University

---

## 📜 License

This project is for **educational purposes** and can be freely used or modified.
