/*

NAME : ANUDEEP RAO PERALA
ROLL NUMBER : CS21BTECH11043

*/

// My MINI AIMS works on only Roll numbers of the students and Course codes of the courses.
// It doesnt work on Names of students or course name or faculty who teaches the courses .
// Students are basically added to iith based on iith roll numbers only .. they are not added by their names.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "headers/starter_func.h"
#include "headers/Admin.h"
#include "headers/Teacher.h"
#include "headers/Student.h"
#include <ios>
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

// unable to implement
// 1) floating courses cases
// 2) Admin having the power to remove students from a course
