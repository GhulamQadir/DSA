#include <iostream>
using namespace std;

int main()
{
    char ch_arr[6] = "world";
    cout << ch_arr;

    char *p1 = &ch_arr[0];
    // prints entire string
    cout << "\n"
         << p1;

    cout << "\n"
         << (void *)p1; // can print the address of char type like this
}