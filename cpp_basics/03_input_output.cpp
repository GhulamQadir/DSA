#include <iostream>
using namespace std;

int main()
{
    string name;
    cout << "Enter your name: "; // output statement
    // getline() reads the complete line until Enter is pressed
    getline(cin, name);

    int age;
    cout << "Enter your age: "; // output statement
    cin >> age;                 // Reads integer input

    cout << "Your name is " << name << " and your age is " << age;

    return 0;
}