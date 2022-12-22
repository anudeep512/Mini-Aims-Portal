
#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "starter_func.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Admin
{

    vector<string> student_rollnum;
    vector<string> course_numbers;

public:
    void store_courses_in_file();
    void add_courses();
    void delete_courses();
    void finalizing_courses();
    void add_students_to_iith();
    void store_rollnumbers_in_file();
    void remove_students_from_iith();
    void create_files_for_registration();
    void edit_course_available_for_registration_file();
    void see_students_registered_for_a_course();
    void store_courses_in_file_edit(vector<string> A);
    void store_rollnumbers_in_file_edited(vector<string> A);
};

#endif
