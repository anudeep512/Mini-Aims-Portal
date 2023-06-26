#ifndef _TEACHER_H_
#define _TEACHER_H_

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include "starter_func.h"
#include "Admin.h"
#include "Student.h"

using namespace std;

class Teacher
{

    string course_code_private;

public:
    Teacher(string s)
    {
        course_code_private = std::move(s);
    }
    void grade_submission();
    void See_the_registered_students();
    void inform_admin_about_grade_submission();
};

#endif