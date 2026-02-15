#include <iostream>
using namespace std;

// Structure for Student nodes (Inner Linked List)
struct SNode
{
    string seat_no;
    SNode *next;
};

// Structure for Course nodes (Outer Linked List)
struct CNode
{
    string course_no;
    CNode *next;
    SNode *stu_list; // Pointer to the head of the student list for this course
};

// Global head pointer for the Course List
CNode *c_list = NULL;

//  Function to add a new course at the end of the course list.
void addCourse(string course_no)
{
    CNode *current = c_list;
    CNode *lastNode = NULL;

    // Traverse the list to check for duplicates and find the last node
    while (current != NULL)
    {
        if (current->course_no == course_no)
        {
            cout << "Duplicate course found";
            return;
        }
        lastNode = current; // Keep track of the previous node (Trailing Pointer)
        current = current->next;
    }

    // Allocate memory only if the course is unique
    CNode *new_node = new CNode();
    new_node->course_no = course_no;
    new_node->stu_list = NULL;
    new_node->next = NULL;

    // If list is empty, make new node the head
    if (c_list == NULL)
    {
        c_list = new_node;
        return;
    }

    // Link the new node to the end of the list
    lastNode->next = new_node;
}

// Function to enroll a student in a specific course.
void addStudent(string course_no, string seat_no)
{
    CNode *current_course = c_list;

    // Find the course node where the student should be added
    while (current_course != NULL)
    {
        if (current_course->course_no == course_no)
        {
            break;
        }
        current_course = current_course->next;
    }
    if (current_course == NULL)
    {
        cout << "Course not found";
        return;
    }

    // Traverse student list to check for duplicates and find the last student
    SNode *current_student = current_course->stu_list;
    SNode *prev_student = NULL;
    while (current_student != NULL)
    {
        if (current_student->seat_no == seat_no)
        {
            cout << "Duplicate student found";
            return;
        }
        prev_student = current_student;
        current_student = current_student->next;
    }
    // Create new student node
    SNode *new_student = new SNode();
    new_student->seat_no = seat_no;
    new_student->next = NULL;

    // Handle empty student list for the course
    if (current_course->stu_list == NULL)
    {
        current_course->stu_list = new_student;
        return;
    }
    prev_student->next = new_student;
}

// Display only the course IDs
void display_courses()
{
    CNode *current = c_list;
    while (current != NULL)
    {
        cout << current->course_no << "   ";
        current = current->next;
    }
}

// Display all courses along with their enrolled students
void display_all()
{
    CNode *temp = c_list;
    while (temp != NULL)
    {
        cout << temp->course_no << ":  ";
        SNode *std_temp = temp->stu_list;
        while (std_temp != NULL)
        {
            cout << std_temp->seat_no << "->";
            std_temp = std_temp->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

// helper function to clear student list from memory
void clear_students(SNode *stu_list)
{
    while (stu_list != NULL)
    {
        SNode *temp = stu_list;
        stu_list = stu_list->next;
        delete temp;
    }
}

//  Delete a course and its node from the list.
void delete_course(string course_no)
{
    if (c_list == NULL)
    {
        cout << "Course List is empty";
        return;
    }

    // Case 1: Course to delete is at the head
    if (c_list->course_no == course_no)
    {
        CNode *temp = c_list;
        c_list = c_list->next;
        clear_students(temp->stu_list);
        delete temp;
        cout << "Course deleted successfully\n";
        display_courses();
        return;
    }

    // Case 2: Course is in the middle or end
    CNode *current = c_list->next;
    CNode *previous = c_list;
    while (current != NULL)
    {
        if (current->course_no == course_no)
        {
            clear_students(current->stu_list);
            previous->next = current->next;
            delete current;
            cout << "Course deleted successfully\n";
            display_courses();
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Course Not Found";
    return;
}

// Basic search to find course index
void search_course(string course_no)
{
    if (c_list == NULL)
    {
        cout << "Course List is empty";
        return;
    }
    CNode *current = c_list;
    int i = 0;
    while (current != NULL)
    {
        if (current->course_no == course_no)
        {
            cout << "Course found at index " << i;
            return;
        }
        current = current->next;
        i++;
    }
    cout << "Course not found";
    return;
}

// Remove a specific student from a specific course.
string delete_stud_from_course(string course_no, string seat_no)
{
    if (c_list == NULL)
    {
        return "Course List is empty";
    }
    CNode *current_course = c_list;
    while (current_course != NULL)
    {
        if (current_course->course_no == course_no)
        {
            if (current_course->stu_list == NULL)
            {
                return "Student List is Empty";
            }

            // Case 1: Student is at the head of the course's list
            if (current_course->stu_list->seat_no == seat_no)
            {
                SNode *temp = current_course->stu_list;
                current_course->stu_list = temp->next;
                delete temp;
                return "Student Deleted Successfully";
            }

            // Case 2: Student is in middle or end
            SNode *current_student = current_course->stu_list->next;
            SNode *previous = current_course->stu_list;
            while (current_student != NULL)
            {
                if (current_student->seat_no == seat_no)
                {
                    previous->next = current_student->next;
                    delete current_student;
                    return "Student Deleted Successfully";
                }
                previous = current_student;
                current_student = current_student->next;
            }
            return "Student not found";
        }
        current_course = current_course->next;
    }
    return "Course not found";
}

// Remove a student record from every course they are enrolled in
string delete_student_from_all_courses(string seat_no)
{
    if (c_list == NULL)
    {
        return "Course List is empty";
    }
    CNode *current_course = c_list;
    bool student_found = false;
    while (current_course != NULL)
    {
        // Reuse the single course deletion logic
        string status = delete_stud_from_course(current_course->course_no, seat_no);
        if (status == "Student Deleted Successfully")
        {
            student_found = true;
        }
        current_course = current_course->next;
    }
    if (!student_found)
    {
        return "Student not found in any of the course";
    }
    return "Student successfully deleted from all courses";
}

// Display students enrolled in a specific course ID
void display_stud_list_of_course(string course_no)
{
    if (c_list == NULL)
    {
        cout << "Course List is empty";
        return;
    }
    CNode *current_course = c_list;
    while (current_course != NULL)
    {
        if (current_course->course_no == course_no)
        {
            cout << "Course No " << course_no << ": ";
            if (current_course->stu_list != NULL)
            {
                SNode *current_student = current_course->stu_list;
                while (current_student != NULL)
                {
                    cout << current_student->seat_no << "->";
                    current_student = current_student->next;
                }
                return;
            }
            cout << "No student is enrolled in this course";
            return;
        }
        current_course = current_course->next;
    }
}

// Internal search helper to find a student's index within a specific course
int search_student_in_course(string courseNo, string seatNo)
{
    int result = -1; // -1 for empty course list
    if (c_list == NULL)
    {
        return -1;
    }
    CNode *current_course = c_list;
    while (current_course != NULL)
    {
        if (current_course->course_no == courseNo)
        {
            if (current_course->stu_list == NULL)
            {
                return -2;
            }
            SNode *current_student = current_course->stu_list;
            int i = 0;
            while (current_student != NULL)
            {
                if (current_student->seat_no == seatNo)
                {
                    return i;
                }
                i++;
                current_student = current_student->next;
            }
            return -3;
        }
        current_course = current_course->next;
    }
    return -4;
}

// Searches for a student across all courses and prints matches.
void search_student_in_all_courses(string seatNo)
{
    if (c_list == NULL)
    {
        cout << "Course List is empty";
        return;
    }
    bool studentFound = false;
    CNode *current_course = c_list;

    while (current_course != NULL)
    {
        int result = search_student_in_course(current_course->course_no, seatNo);
        if (result >= 0)
        {
            studentFound = true;
            cout << "Course: " << current_course->course_no << ", Index: " << result << endl;
        }
        current_course = current_course->next;
    }
    if (!studentFound)
    {
        cout << "Student not found in any course\n";
    }
}

// Helper to get string input
string input_val(string fieldVal)
{
    string field;
    cout << fieldVal;
    cin >> field;
    return field;
}

int main()
{
    cout << "\nStudent Course Nexus(Multi-level Linked List)";
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Add Course\n2. Add Student\n3. Display Courses\n4. Display all\n5. Delete a Course\n6. Search a course\n7. Delete Student From Course\n8. Delete Student from All Courses\n9. Display Student List of Course\n10. Search student in a Course\n11. Search Student(including all courses)\n12. Exit:\n";
        cin >> num;

        switch (num)
        {
        case 1:
        {
            string course_no = input_val("Enter Course No to Add: ");
            addCourse(course_no);
            break;
        }
        case 2:
        {
            string course_no = input_val("Enter Course No: ");
            string seat_no = input_val("Enter Seat No: ");
            addStudent(course_no, seat_no);
            break;
        }
        case 3:
        {
            display_courses();
            break;
        }
        case 4:
        {
            display_all();
            break;
        }
        case 5:
        {
            string course_no = input_val("Enter Course No to delete: ");
            delete_course(course_no);
            break;
        }
        case 6:
        {
            string course_no = input_val("Enter Course No to Search: ");
            search_course(course_no);
            break;
        }
        case 7:
        {
            string course_no = input_val("Enter Course No: ");
            string seat_no = input_val("Enter Seat No of student to delete: ");
            string result = delete_stud_from_course(course_no, seat_no);
            cout << result;
            break;
        }
        case 8:
        {
            string seat_no = input_val("Enter Seat No of student: ");
            string result = delete_student_from_all_courses(seat_no);
            cout << result;
            break;
        }
        case 9:
        {
            string course_no = input_val("Enter Course No: ");
            display_stud_list_of_course(course_no);
            break;
        }
        case 10:
        {
            string course_no = input_val("Enter Course No: ");
            string seat_no = input_val("Enter Seat No of Student to Search: ");

            int result = search_student_in_course(course_no, seat_no);
            if (result == -1)
            {
                cout << "Course List is empty";
            }
            else if (result == -3)
            {
                cout << "Student not found";
            }
            else if (result == -4)
            {
                cout << "Course not found";
            }
            else if (result >= 0)
            {
                cout << "Student found at index: " << result;
            }
            break;
        }
        case 11:
        {
            string seat_no = input_val("Enter Seat No of Student to search: ");
            search_student_in_all_courses(seat_no);
            break;
        }
        default:
            return 0;
        }
    }
    return 0;
}