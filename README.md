# 📚 Online Book Reader

A simple **command-line Book Reader system** written in **C++**.  

Supports **user and admin accounts**, **book management**, **reading tracking with resume**, and now includes **file-backed storage**, **admin management**, and **tabular list views**.

---

## 👤 User Features

- **Sign Up / Login**  
  Create a new account or log in with existing credentials.

- **View Profile**  
  Display personal details: name, email, and username.

- **Browse Available Books**  
  List all books in the system, view details, and choose a book to read.

- **Read Books**  
  - Read books page-by-page.  
  - Navigate pages (next / previous).  
  - Resume reading from where you left off.

- **Reading History**  
  - View a list of previously read books and last read time.  
  - Resume from any book in the history.

---

## 🛠️ Admin Features

- **Admin Login**  
  Dedicated admin accounts for management tasks.

- **View Admin Profile**  
  Display name, email, username, and password.

- **Add Books**  
  Enter details: ISBN, title, author, and pages.

- **Remove Books**  
  Delete a book by its ISBN.

- **Remove Users**  
  Delete a user account by username.

- **Add Admins**  
  Create new admin accounts to delegate management.

- **Tabular Listings**  
  View formatted tables for users, admins, and books for easier management.

---

## ⚙️ System Features

- **File-Backed Storage**  
  Persist books and admins to files so data is retained across runs.

- **Session Tracking**  
  User reading position is saved per book, per user (resume where you left off).

- **Input Validation**  
  Safe input routines to prevent crashes and invalid entries.

- **Unique Usernames**  
  Usernames are guaranteed to be unique across users and admins.

- **Admin/User Separation**  
  Different menus and capabilities for users and admins.
  
---

## 🧭 Usage Overview

- **Start the app and choose:**
  - Login  
  - Sign Up  
  - Exit  

- **As a User:**
  - View profile  
  - List & select from your reading history  
  - List & select from available books  
  - Read with next/previous page navigation and auto-resume  

- **As an Admin:**
  - View profile  
  - Add books  
  - Remove books  
  - Remove users  
  - Add admins  
  - View tabular lists of users, admins, and books  

---

## 🗂️ Data Persistence

- Books and Admins are read from and written back to files.  
- This enables the system to retain the library and admin accounts across runs.  
- If the files do not exist, the system can initialize with defaults and then persist changes.  

> **Note:** File locations and formats are simple text-based structures suitable for quick inspection and manual editing if needed.

---

## ⚠️ Notes and Tips

- Use the exact ranges shown in menus for valid input (robust input validation is included).  
- Usernames are unique across both users and admins.  
- Reading sessions are tracked per user and per book, enabling resume capability.  
