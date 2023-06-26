/*
NAME : ANUDEEP RAO PERALA
ROLL NUMBER : CS21BTECH11043
*/

#include <iostream>
#include "headers/starter_func.h"
#include <limits>

using namespace std;

int main()
{
    cout << "Welcome to Mini Aims" << endl;
    cout << "Choose your role of intrest" << endl;
    cout << "1)Admin" << endl;
    cout << "2)Teacher" << endl;
    cout << "3)Student" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    int n;
    cout << "Enter the number of the role which you want to enter : ";
    cin >> n;

    if (n == 1)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Admin_func();
    }
    else if (n == 2)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Teacher_func();
    }

    if (n == 3)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Student_func();
    }

    return 0;
}
