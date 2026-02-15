# 🎓 Student-Course Nexus

A high-performance **Course Management System** built using **Nested (Multi-level) Linked Lists** in C++. This project demonstrates advanced pointer manipulation and efficient memory management.

---

## 🧐 What is a Multi-level Linked List?

In this project, I have implemented a **Multi-level Linked List** (also known as a Nested Linked List). Instead of a simple linear chain, each node in the primary list represents a **Course**, and it contains a pointer to the head of another independent linked list representing **Students**.



* **Level 1 (Courses):** A linked list of `CNode` objects.
* **Level 2 (Students):** Each course node hosts its own linked list of `SNode` objects.
* **Architecture:** It follows a "One-to-Many" relationship where one course can contain multiple student enrollments.

---

## 🚀 Key Features

* **Dynamic Course Management:** Add or delete courses without size constraints.
* **Student Enrollment:** Enroll students into specific courses with unique Seat Numbers.
* **Duplicate Prevention:** Optimized logic to ensure no duplicate Course IDs or Student IDs within a course.
* **Global Search:** A powerful feature to locate a student across all enrolled courses.
* **Memory Safety (Deep Deletion):** Unlike basic implementations, this system prevents memory leaks. When a course is deleted, the system first traverses and frees all associated student nodes before removing the course itself.

---

## 🛠️ Technical Implementation

### Data Structures
The core of the system relies on two nested structures:
- `SNode`: Stores student data and a pointer to the next student.
- `CNode`: Stores course data and a pointer to the nested student list.



### Performance & Optimization
1.  **Insertion (O(n)):** Nodes are appended at the tail to maintain entry order.
2.  **Modular Deletion:** Uses a helper function `clear_students()` for deep memory cleanup.
3.  **No Redundancy:** Logic is streamlined to handle head, middle, and tail cases efficiently.
