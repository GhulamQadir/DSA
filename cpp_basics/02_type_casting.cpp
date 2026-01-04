#include <iostream>
using namespace std;

int main()
{
    cout << "Type Conversion(Implicit)" << "\n\n";
    // Stores ASCII value of P in memory
    char grade = 'P';
    cout << "Grade: " << grade << "\n";

    // Converted type from char to int and returns its ACII value
    // means converting small datatype into big datatype
    int value = grade;
    cout << "Value: " << value << "\n\n";

    // converting big datatype into small datatype
    cout << "Type Conversion(Explicit)" << "\n\n";
    double d_val = 90.8774928374;
    int int_val = (int)d_val;
    cout << d_val << "\n";
    cout << int_val << "\n\n";

    cout << "Converting type from double to string" << "\n";
    string convert_type = to_string(d_val);
    cout<<convert_type;

    return 0;
}