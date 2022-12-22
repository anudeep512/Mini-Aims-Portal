#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "starter_func.h"
#include "Admin.h"
#include "Teacher.h"

using namespace std;

class Student
{

    string roll_number{};

public:
    Student(string S)
    {
        roll_number = S;
    }
    void register_for_courses();
    void look_into_registered_courses();
    void store_my_courses_in_file(vector<string> A);
    void delete_courses_registered();
    void reset_course_registration_list(string a, vector<string> b);
    void check_grade_for_a_course();
    void store_my_courses_in_file_for_deletion(vector<string> A);
};

#endif