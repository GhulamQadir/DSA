#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {0, 4, 7, 10};
    cout << "Starting address of arr: " << &arr[0] << endl;

    // printing element at first location
    cout << *arr << endl;

    // access address and value
    cout << "\nAddress at 2nd Index = " << arr + 2 << " and Value = " << *(arr + 2);
    cout << "\nAddress at 3rd Index = " << &arr[3] << " and Value = " << *(arr + 3);
    cout << "\n"
         << 3 [arr] << " = " << *(3 + arr);

    int *p = &arr[0];
    cout << "\n\nAddress of arr: " << p;
    cout << "\nAddress of p where the address of arr is stored: " << &p;

    // updating pointer to next address (shift 4 bytes)
    p += 1;
    cout << "\n\nUpdated Address of p: " << p;
}