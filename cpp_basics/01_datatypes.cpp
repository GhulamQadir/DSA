#include <iostream>  // Header file for input-output operations (cout, cin, endl)
using namespace std; // Use std library names without 'std::'

int main()
{
    // Printing heading
    cout << "Primitive DataTypes" << endl
         << "\n";

    /*
        Integer Data Type
        - Stores whole numbers (without decimal)
        - Takes 4 bytes (32 bits) of memory
    */
    int age = 20;
    cout << "Age = " << age << "\n";
    cout << "Size of int: " << sizeof(age) << " bytes" << "\n\n";

    /*
        Character Data Type
        - Stores a single character
        - Must be enclosed in single quotes (' ')
        - Takes 1 byte of memory
        - Uses ASCII values internally
    */
    char status = 'S';
    cout << "Character: " << status << "\n";
    cout << "Size of char: " << sizeof(status) << " bytes" << "\n\n";

    /*
        Floating Point Data Type (float)
        - Stores decimal values
        - Takes 4 bytes of memory
        - By default, decimal values are considered double
        - 'f' is used to explicitly store value as float
    */
    float price = 14.54f;
    cout << "Float: " << price << "\n";
    cout << "Size of float: " << sizeof(price) << " bytes" << "\n\n";

    /*
        Boolean Data Type
        - Stores only two values: true or false
        - Internally stored as:
            true  -> 1
            false -> 0
        - Takes 1 byte logically
    */
    bool is_checked = false;
    cout << "Boolean: " << is_checked << "\n";
    cout << "Size of boolean: " << sizeof(is_checked) << " bytes" << "\n\n";

    /*
        Double Data Type
        - Used to store decimal (floating-point) values with higher precision
        - Takes 8 bytes (64 bits) of memory
        - Provides more accuracy than float
        - By default, decimal values in C++ are stored as double
    */
    double value = 23.4349;
    cout << "Double: " << value << "\n";
    cout << "Size of double: " << sizeof(value) << " bytes" << "\n\n";

    // String stores a sequence of characters; can hold text
    string language = "Cplusplus";
    cout << "String: " << language << "\n";
    // Note: sizeof gives the size of the string object (not the characters inside)
    cout << "Size of string: " << sizeof(language) << " bytes";

    return 0;
}