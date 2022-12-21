// In this file we are gonna define all the Operations which we use for Student class

#include <iostream>
#include <vector>
#include <fstream>
#include "starter_func.h"
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
#include <string>
#include <ios>
#include <limits>

using namespace std;

void Student::reset_course_registration_list(string a, vector<string> b)
{
    ofstream dfg;

    dfg.open(a + "_Course_registration_file.txt");
    for (size_t i = 0; i < b.size(); i++)
        dfg << b[i] << "\n";

    return;
}

void Student::store_my_courses_in_file_for_deletion(vector<string> A)
{
    ofstream fp;
    string D;
    D = roll_number + "_courses_registered.txt";
    fp.open(D);
    for (size_t i = 0; i < A.size(); i++)
        fp << A[i] << "\n";

    return;
}

void Student::store_my_courses_in_file(vector<string> A)
{
    ofstream fp;
    string D;
    D = roll_number + "_courses_registered.txt";
    fp.open(D, ios_base::app);
    for (size_t i = 0; i < A.size(); i++)
        fp << A[i] << "\n";

    return;
}

// FUnction used for registration of courses
void Student::register_for_courses()
{

    ifstream see_course_list;
    vector<string> my_courses;

    cout << "Precautions before registration" << endl;
    cout << "---> Students are requested to register for the course only after the course list is finalized" << endl;
    cout << "---> Please give the course code of the course which you want to register" << endl;
    cout << "---> Remainder : You are only supposed to register for the courses for which grades are not submitted yet " << endl;
    cout << "---> To exit this mode give input as \"Done\" " << endl;
    see_course_list.open("Courses_available_for_registration.txt");
    string s;
    cout << "The courses available for registration is as follows : " << endl;

    while (getline(see_course_list, s))
        cout << s << endl; // By seeing this list the student should register only for the courses for which the courses grades are not submitted yet
    int i = 0;
    string course_code_input;
    string R;

    while (i >= 0)
    {

        cout << "Give the course code of the course for which you want to register for : ";
        cin >> course_code_input;

        if (course_code_input == "Done")
            break;
        else
        {
            ifstream see_course_list_;
            see_course_list_.open("Courses_available_for_registration.txt");
            int t = 0, g = 0;
            while (see_course_list_ >> R)
            {

                t++;
                if (R.find(course_code_input) != string::npos)
                {

                    ofstream edit_in_other_file;

                    string f;
                    f = course_code_input + "_Course_registration_file.txt";

                    edit_in_other_file.open(f, ios_base::app);
                    edit_in_other_file << roll_number << "\n";

                    my_courses.push_back(course_code_input);
                }
                else
                    g++;
            }

            if (t == g)
                cout << "The course code given as input is incorrect . Enter the correct course code" << endl;
        }
    }

    store_my_courses_in_file(my_courses);

    return;
}

// Function used to delete courses which are registered
void Student::delete_courses_registered()
{

    ifstream u;
    u.open(roll_number + "_courses_registered.txt");
    vector<string> my_courses;
    string S;
    cout << "Here is the list of courses for which you have registered :" << endl;
    while (getline(u, S))
    {
        my_courses.push_back(S);
        cout << S << "\n";
    }
    int n;
    cout << "# There are going to be some problems in this mode which are addressed below" << endl;
    cout << "---> Sometimes we should delete the courses multiple times because of multiple storage of course names please look into this and for dergistration one must do this process as many times as the course has appeared in his courses registered list " << endl;
    cout << "---> While giving input as the line number of the course you should even count the blank line (in case if you encounter with any of these) as a line . So your input line number value chnages accordingly" << endl;
    cout << "Give the line number of the course which you want to deregister for : ";

    cin >> n;

    string course_which_is_deregistered;
    course_which_is_deregistered = my_courses[n - 1];
    my_courses.erase(my_courses.begin() + n - 1);

    store_my_courses_in_file_for_deletion(my_courses);
    ifstream new_see;
    new_see.open(roll_number + "_courses_registered.txt");

    vector<string> new_vec;
    cout << "Here is the modified personal course list :" << endl;
    while (getline(new_see, S))
    {
        new_vec.push_back(S);
        cout << S << "\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> temp_student_info_storage;
    ifstream dfg;
    string g;
    dfg.open(course_which_is_deregistered + "_Course_registration_file.txt");

    while (getline(dfg, g))
    {
        temp_student_info_storage.push_back(g);
    }

    for (size_t i = 0; i < temp_student_info_storage.size(); i++)
    {
        if (temp_student_info_storage[i].find(roll_number) != string::npos)
        {
            temp_student_info_storage.erase(temp_student_info_storage.begin() + i);
        }
    }
    reset_course_registration_list(course_which_is_deregistered, temp_student_info_storage);

    return;
}

// This function is used to look into courses registered by the student
void Student::look_into_registered_courses()
{
    ifstream see;
    see.open(roll_number + "_courses_registered.txt");
    string r;
    while (getline(see, r))
        cout << r << "\n";

    return;
}

// This function is used to check gardes of a course
void Student::check_grade_for_a_course()
{
    string S;
    cout << "Enter the COURSE CODE for course which for which you want to check the grade sheet : ";
    cin >> S;

    ifstream check;
    check.open(S + "_Course_grade_list.txt");
    string D;
    while (getline(check, D))
        cout << D << "\n";

    return;
}
