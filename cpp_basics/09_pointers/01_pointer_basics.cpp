#include <iostream>
using namespace std;

int main()
{
     // 1. Basic Variable and Address
     int num = 999;
     cout << "Address of num: " << &num << endl; // address operator (&)

     // 2. Pointer Initialization
     // int means the address of the value which we stored is integer typed
     int *p1 = &num;
     cout << "Value of p1 (Address of num): " << p1 << endl;
     // p1 is a pointer to int datatype

     // 3. Float Pointer & Value Access (Dereferencing)
     float num1 = 12.4573;
     float *p2 = &num1;
     // ptr1 is apointer to float datatype
     cout << "\nValue = "
          << *p2 << " and Adress = " << p2 << endl;
     // Post increment
     // Dereferencing: Accessing or modifying the value stored at the address held by the pointer
     cout << ++(*p2);

     // Size of a pointer depends on system architecture (usually 8 bytes on 64-bit systems)
     cout << "\nSize of pointer is: " << sizeof(p1) << "\n\n";

     // Null pointer: A pointer that points to nothing (memory address 0)
     int *p3 = 0; // pointing to nothing
     int i = 4;
     p3 = &i; // // Re-assigning p3 to point to the address of 'i'
     cout << p3;
     (*p3)++; // Incrementing the value at the address p3 is pointing to
     cout << "\nValue of i after incrementing through p3: " << i << endl;

     // Pointer Copying: Both pointers now hold the same memory address
     int *q = p3;
     cout << "\np3 = " << p3;
     cout << "\nq = " << q;

     // Pointer Arithmetic: Adding 1 moves the pointer to the NEXT memory block of that type
     // Since 'q' is int, q+1 jumps 4 bytes forward in memory
     cout << "\nOld Address of q: " << q << endl;
     q = q + 1;
     cout << "New Address of q (after +1 move): " << q << endl;
}