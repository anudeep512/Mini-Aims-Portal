// In this file, we are going to define all the Operations which we use Teacher class

#include <iostream>
#include <fstream>
#include "headers/starter_func.h"
#include "headers/Teacher.h"
#include <string>
#include <ios>

// This function is used to inform admin about the grade submission done by the teacher
void Teacher::inform_admin_about_grade_submission()
{ // after grade submission is done, admin should be informed about the grade submission
    ofstream file;
    file.open("Info_about_course_grade_submission.txt", ios_base::app);
    file << "Grade submission for the course " << course_code_private << " is done"
         << "\n";
}

// This Function is used to submit grades for the student
void Teacher::grade_submission()
{
    cout << "---> For exiting this mode give input as \"Done\" " << endl;
    ofstream gradesfile;
    string S;
    S = course_code_private + "_Course_grade_list.txt";

    gradesfile.open(S, ios_base::app);

    string roll_number;
    string grade;

    while (true)
    {
        cout << "Enter the ROLL NUMBER of the student for whom you want to assign his/her grade : ";
        cin >> roll_number;

        if (roll_number == "Done")
        {
            cout << "Out of Grade submission mode " << endl;
            break;
        }
        else
        {

            cout << "Enter the grade achieved by the student : ";
            cin >> grade;

            gradesfile << roll_number << " - " << grade << "\n";
        }
    }

    inform_admin_about_grade_submission();
}

// Ny using this function teacher gets to know about that who registered for this course
void Teacher::See_the_registered_students()
{

    ifstream see;
    see.open(course_code_private + "_Course_registration_file.txt");
    string g;
    cout << "Here is the list who have registered for " << course_code_private << " Course" << endl;
    while (getline(see, g))
        cout << g << endl;
}
