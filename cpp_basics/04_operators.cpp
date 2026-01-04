#include <iostream>
using namespace std;

int main()
{
    cout << "Operators: \n";
    int a = 20;
    int b = 8;

    // 1) Arithmetic Operators
    cout << "1)Arithmetic Operators\n";
    cout << "Addition = " << a + b << "\n";
    cout << "Subtraction = " << a - b << "\n";
    cout << "Multiplication = " << a * b << "\n";

    // Integer division (decimal part is discarded)
    cout << "Division = " << a / b << "\n";

    // Type casting to get decimal result
    cout << "Float Division = " << (float)a / b << "\n";
    cout << "Modulus = " << a % b << "\n\n";

    // 2) Relational Operators (result is true/false -> 1/0)
    cout << "2)Relational Operators:\n";
    cout << "Greater than: " << (5 > 4) << endl;
    cout << "Less than: " << (5 < 4) << endl;
    cout << "Greater than or equal to: " << (5 >= 4) << endl;
    cout << "Less than or equal to: " << (5 <= 4) << endl;
    cout << "Equals to: " << (4 == 4) << endl;
    cout << "Not Equals to: " << (5 != 4) << "\n\n";

    // 3) Logical Operators
    cout << "3)Logical Operators:\n";
    cout << "AND: " << ((3 > 2) && (1 < 4)) << endl;
    cout << "OR: " << ((3 > 2) || (10 < 4)) << endl;
    cout << "NOT: " << (!(3 > 2) && (1 < 4)) << "\n\n";

    // 4) Unary Operators (Increment / Decrement)
    cout << "4)Unary Operators\n";
    int y = 7;

    // Post-increment: assign first, then increase
    int post = y++;
    cout << "Post Increment(first assign): " << post << endl;
    cout << "Updated value of y: " << y << endl;

    // Pre-increment: increase first, then assign
    int pre = ++y;
    cout << "Pre Increment(first update): " << pre << endl;
    cout << "Updated value of y: " << y;

    cout << "\nSame concept applies to decrement (--)\n";
    return 0;
}