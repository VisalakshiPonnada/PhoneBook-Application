# Phone Book Application in C

## 📖 Table of Contents

- 📌 Project Overview
- 🎯 Objectives
- 🖼️ Application Workflow
- 🏗️ System Architecture
- ⚙️ Technical Requirements
- 💻 Software Requirements
- 📂 Repository Structure
- ✨ Features
- ▶️ Build Instructions
- 🧪 Testing and Demonstration
- 📈 Future Enhancements
- 👤 Author

---

## 📌 Project Overview

The Phone Book Application is a menu-driven application developed using C programming. It is designed to manage contact information efficiently using a **Singly Linked List** and file handling concepts.

The application allows users to create, display, search, edit, and delete contacts. Each contact can store multiple phone numbers, email addresses, and other personal details.

The application uses a structure to maintain contact information and dynamically allocates memory for storing contacts. File handling is used to save contact details so that previously stored information can be accessed when the application is launched again.

The project is implemented using multiple source files, user-defined functions, a header file, and a Makefile to maintain modularity and simplify compilation.

## 🎯 Objectives

- ✅ Develop a menu-driven Phone Book Application using C.
- ✅ Store contact information using structures.
- ✅ Implement a Singly Linked List for dynamic contact management.
- ✅ Allow users to create new contacts.
- ✅ Support multiple phone numbers for a single contact.
- ✅ Store email addresses and other contact details.
- ✅ Display all existing contacts.
- ✅ Search contacts based on name.
- ✅ Edit existing contact information.
- ✅ Delete contacts from the phone book.
- ✅ Save contact information into a file.
- ✅ Retrieve previously saved contact information.
- ✅ Prevent duplicate contacts.
- ✅ Use separate user-defined functions for different operations.
- ✅ Organize the project using multiple source files and a header file.
- ✅ Use Makefile to automate compilation.

## 🖼️ Application Workflow

```text
             Start Application
                    |
                    v
              Load Saved Data
                    |
                    v
                Display Menu
                    |
        +-----------+-----------+
        |           |           |
        v           v           v
      Create      Display     Search
      Contact     Contacts    Contact
        |           |           |
        v           v           v
    Add Contact   Show All   Find by Name
     Details      Details
        |
        v
   Store in Linked List

        +-----------+-----------+
        |           |           |
        v           v           v
       Edit       Delete       Save
      Contact     Contact      Data
        |           |           |
        v           v           v
   Update Details Remove      Store in
                   Contact     File
                    |
                    v
                Quit App
```

## 🏗️ System Architecture

| Module / Component | Function |
|---|---|
| Main Module | Displays the menu and controls application flow |
| Contact Module | Creates and manages contact information |
| Display Module | Displays all existing contacts |
| Search Module | Searches for contacts based on name |
| Edit Module | Modifies existing contact information |
| Delete Module | Removes contacts from the linked list |
| File Module | Saves and retrieves contact information |
| Header File | Maintains structure definitions and function declarations |
| Makefile | Automates compilation of multiple source files |

## ⚙️ Technical Requirements

| Requirement | Purpose |
|---|---|
| C Programming | Implements the application logic |
| Structures | Stores contact information |
| Singly Linked List | Maintains dynamic contact records |
| Dynamic Memory Allocation | Allocates and releases memory for contacts |
| Pointers | Connects linked-list nodes |
| Functions | Implements individual operations |
| File Handling | Stores and retrieves contact information |
| String Handling | Processes names, phone numbers, and other details |
| Makefile | Manages compilation of multiple source files |

## 💻 Software Requirements

| Software | Purpose |
|---|---|
| Ubuntu / Linux | Development and execution environment |
| GCC | Compiles C source files |
| GNU Make | Automates compilation |
| Vi | Source code editing |
| Terminal | Application execution and testing |

## 📂 Repository Structure

```text
Phone-Book-Application/
│
├── main.c
├── contact.c
├── display.c
├── search.c
├── delete.c
├── edit.c
├── file.c
├── phonebook.h
├── Makefile
└── README.md
```

## ✨ Features

- ✅ Menu-driven user interface.
- ✅ Create new contacts.
- ✅ Store multiple phone numbers for one contact.
- ✅ Store email addresses and additional contact details.
- ✅ Display all saved contacts.
- ✅ Search contacts using their names.
- ✅ Edit existing contact details.
- ✅ Delete contacts from the phone book.
- ✅ Dynamic memory management using a Singly Linked List.
- ✅ File-based storage of contact information.
- ✅ Retrieve previously saved contact information.
- ✅ Modular implementation using separate C source files.
- ✅ Automated compilation using Makefile.

## ▶️ Build Instructions

### 1. Open the Terminal

Open the Ubuntu/Linux terminal.

### 2. Navigate to the Project Directory

```bash
cd ~/C-Programming/Phone-Book-Application
```

Replace the path with your actual project directory.

### 3. Compile Using Makefile

```bash
make
```

### 4. Execute the Application

```bash
./phonebook
```

### 5. Clean Generated Object Files

```bash
make clean
```

## 🧪 Testing and Demonstration

### 1. Create a New Contact

Select:

```text
c/C: Create a new contact
```

Enter the contact name and first phone number. Choose whether to add additional phone numbers, email addresses, and other details.

### 2. Display All Contacts

Select:

```text
p/P: Print all contacts
```

Expected behavior: Displays all existing contact information.

### 3. Search for a Contact

Select:

```text
f/F: Find contact
```

Enter the contact name to search for the corresponding record.

### 4. Edit a Contact

Select:

```text
e/E: Edit a contact
```

Enter the contact name and modify the required information.

### 5. Delete a Contact

Select:

```text
d/D: Delete contact
```

Enter the contact name to remove the corresponding contact.

### 6. Save Contact Information

Select:

```text
s/S: Save the contacts in the file
```

Expected behavior: Saves the contact information for future use.

### 7. Quit the Application

Select:

```text
q/Q: Quit from app
```

### 8. Verify File Persistence

Run the application again and verify that previously saved contact information is available.

## 📈 Future Enhancements

- 🔍 Add search functionality using phone number and email address.
- 📱 Improve contact management with additional fields.
- 🔐 Add password-based access to the application.
- 📊 Implement sorting contacts alphabetically.
- 🧹 Improve memory management and error handling.
- 💾 Improve file storage and data validation.
- 🖥️ Develop a graphical user interface.
- 📤 Add contact import and export functionality.

## 👤 Author

**Visalakshi Ponnada**

C Programming | Data Structures | Singly Linked List | File Handling | Dynamic Memory Allocation
