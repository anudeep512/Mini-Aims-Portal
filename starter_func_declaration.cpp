// In this file we are gonna define all the Operations which we use Starter Function class
// In this file we are gonna define functions which are called as starter functions where our class object is created
// And here we choose the rquired mode which want to enter into .

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

// When we choose the ADMIN mode in main function we end up at this function from which our program proceeds based on choice of modes

void Admin_func()
{

    Admin admin;
    cout << "Welcome Admin" << endl;

    int i = 0;
    while (i >= 0)
    {
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Choose the mode which you want to enter" << endl;
        cout << "1)Add courses" << endl;
        cout << "2)Delete courses" << endl;
        cout << "3)Finalizing the courses" << endl;
        cout << "4)Adding students to iith" << endl;
        cout << "5)Removing students from iith" << endl;
        cout << "6)Create files for registration of students into that" << endl;
        cout << "7)Edit the Courses available for registration file based on grade submission by professor" << endl;
        cout << "8)See the students registered for a course" << endl;
        cout << "9)Exit Admin mode" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        int n;
        cout << "Enter the Serial Number of the mode which you want to enter : ";
        cin >> n;

        if (n == 1)
            admin.add_courses();
        else if (n == 2)
            admin.delete_courses();
        else if (n == 3)
            admin.finalizing_courses();
        else if (n == 4)
            admin.add_students_to_iith();
        else if (n == 5)
            admin.remove_students_from_iith();
        else if (n == 6)
            admin.create_files_for_registration();
        else if (n == 7)
            admin.edit_course_available_for_registration_file();
        else if (n == 8)
            admin.see_students_registered_for_a_course();
        else
        {
            cout << "Thank you for visiting MINI AIMS" << endl;
            return;
        }
    }
    return;
}

// When we choose the TEACHER mode in main function we end up at this function from which our program proceeds based on choice of modes

void Teacher_func()
{

    cout << "Welcome to MINI AIMS" << endl;

    string course_code_or_name_input;
    cout << " Enter the COURSE CODE of your course : " << endl;
    getline(cin, course_code_or_name_input);

    ifstream search_teacher;
    search_teacher.open("Courses_available_for_registration.txt");
    string s;
    int t = 0, g = 0;
    while (getline(search_teacher, s))
    {
        t++;
        if (s == course_code_or_name_input)
        {
            cout << " Verification successful please choose a mode out of the following " << endl;

            break;
        }
        else
            g++;
    }

    if (t == g)
        cout << " The COURSE CODE which you have entered is either wrong or not existant in the courses offered by the institute please check again" << endl;

    else
    {
        Teacher teacher(course_code_or_name_input);
        int i = 0;
        while (i >= 0)
        {
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Enter the Serial Number of the mode which you want to enter : " << endl;
            cout << "  1)See the students registered for your course" << endl;
            cout << "  2)Submit grades for your course" << endl;
            cout << "  3)Exit Teacher mode" << endl;
            cout << "-------------------------------------------------------------------------" << endl;

            int n;
            cin >> n;
            if (n == 1)
                teacher.See_the_registered_students();
            else if (n == 2)
                teacher.grade_submission();
            else
            {
                cout << "Thank you for visiting MINI AIMS" << endl;
                return;
            }
        }
    }
    return;
}

// When we choose the STUDENT mode in main function we end up at this function from which our program proceeds based on choice of modes

void Student_func()
{

    cout << "Welcome to MINI AIMS" << endl;
    string roll_num;
    cout << "Please enter your roll number : ";
    cin >> roll_num;

    ifstream search_student;
    search_student.open("List_of_students_part_of_iith.txt");
    string s;
    int t = 0, g = 0;
    while (getline(search_student, s))
    {
        t++;
        if (s == roll_num)
        {
            cout << "Verification successful please choose a mode out of the following " << endl;
            break;
        }
        else
            g++;
    }

    if (t == g)
        cout << "The roll number which you have entered is either wrong or not existant in the institute please check again" << endl;

    else
    {
        Student student(roll_num);
        int i = 0;
        while (i >= 0)
        {
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Choose the mode which you want to enter : " << endl;
            cout << "  1)Register for courses" << endl;
            cout << "  2)See your registered courses" << endl;
            cout << "  3)Check grade for a Course" << endl;
            cout << "  4)Deregister from a course" << endl;
            cout << "  5)Exit Student mode" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            int n;
            cout << "Enter the Serial Number of the mode which you want to enter : ";
            cin >> n;

            if (n == 1)
                student.register_for_courses();
            else if (n == 2)
                student.look_into_registered_courses();
            else if (n == 3)
                student.check_grade_for_a_course();
            else if (n == 4)
                student.delete_courses_registered();
            else
            {
                cout << "Thank you for visiting MINI AIMS" << endl;
                return;
            }
        }
    }

    return;
}
