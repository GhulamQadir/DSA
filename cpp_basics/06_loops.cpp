#include <iostream>
using namespace std;

int main()
{
    int count = 0;

    // while loop: use when number of iterations is not fixed
    while (count <= 5)
    {
        cout << count << " ";
        count++;
    }

    // for loop: use when range and steps are known
    for (int i = 11; i >= 1; i--)
    {
        cout << i << endl;
    }

    // sum of numbers from 1 to n
    cout << "Enter any positive integer: ";
    int num;
    cin >> num;
    if (num <= 0)
    {
        cout << "enter any positive integer greater than 1";
        return 0; // Exit program for invalid input
    }
    else
    {
        int sum = 0;
        for (int i = 1; i <= num; i++)
        {
            sum += i;// Add numbers one by one
        }
        cout << "Sum = " << sum << "\n\n";
    }

    // do-while loop: runs at least once
    count = 0;
    do
    {
        cout << "I will run for atleast one time\n";
    } while (count > 1);

    // Finding factors of a number
    int number;
    cout << "Enter positive integer: ";
    cin >> number;
    count = 2;
    while (count * count <= number)
    {
        if (number % count == 0)
        {
            cout << count << "," << (number / count) << endl;
        }
        count++;
    }
    return 0;
}