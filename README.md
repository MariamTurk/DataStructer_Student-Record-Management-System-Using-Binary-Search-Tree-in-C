# 🎓 Student Record Management System Using Binary Search Tree in C

### 👤 Author: Mariam Turk  


## 📚 Overview

This C program implements a **Student Record Management System** using a **Binary Search Tree (BST)**. It allows insertion, search, deletion, and listing of student records based on various attributes such as ID, name, city, and class. Records can also be saved to a file.

---

## 🧰 Features

- ✅ Insert new student records
- 🔍 Search student by **ID**
- 📃 List all students in **lexicographic order** by name
- 🏙️ List students by **city**
- 🏫 List students by **class ID**
- ❌ Delete student by ID
- 💾 Save all records to `students.txt`
- 🧾 Menu-based interactive interface

---

## 🌲 Data Structure

All student records are stored in a **Binary Search Tree (BST)** sorted by **student ID**.

Each node contains:
- `student ID (int)`
- `student name (char[])`
- `city (char[])`
- `class ID (int)`
- `enrollment date (char[])`

---

## 📁 Project Structure

. ├── main.c # Complete source code ├── students.txt # Output file with saved records └── README.md # Project documentation


## 🧪 Example Student Record

ID: 1001 Name: Alice City: Ramallah Class ID: 3 Enrollment Date: 2023-09-01

yaml
Copy
Edit


🧭 Menu Options
pgsql
Copy
Edit
1- Insert a student with all its associated data
2- Find student by their ID
3- List all students in lexicographic order of their names
4- Search for a city and list all students from that city
5- List all students by their class
6- Delete a student given their ID
7- Save all students in a file
8- Exit

🔍 Key Functions
Function	Purpose
insert()	Insert new student into the BST
Find_By_ID()	Search for a student by ID
LIST_S_NAME()	List all student names in lexicographic order
SEARCH_BY_CITY()	Filter students based on city
LIST_BY_CLASS()	Show all students from a specific class
DELETE_BY_ID()	Remove student record by ID
traversal()	Save student data in in-order format to a text file

📄 Output File (students.txt)
Example content:
Edit
1001 Alice Ramallah 3 2023-09-01
1002 Basil Nablus 2 2023-08-15
1003 Lina Hebron 1 2023-09-10
🛠️ To Do
 Allow updating a student's record

 Add input validation (e.g., max string lengths)

 Enhance sorting by multiple fields (name, date, etc.)
