
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
    static void delete_courses();
    static void finalizing_courses();
    void add_students_to_iith();
    void store_rollnumbers_in_file();
    static void remove_students_from_iith();
    static void create_files_for_registration();
    static void edit_course_available_for_registration_file();
    static void see_students_registered_for_a_course();
    static void store_courses_in_file_edit(const vector<string>& A);
    static void store_rollnumbers_in_file_edited(const vector<string>& A);
};

#endif
