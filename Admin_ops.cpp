// In this file, we are going to define all the Operations which we use for Admin class

#include <iostream>
#include <string>
#include <fstream>
#include "headers/Admin.h"
#include <ios>
#include <limits>
#include <vector>

using namespace std;

// This function is used when we need to edit the course file after the professor submits grades

void Admin::store_courses_in_file_edit(const vector<string>& A)
{
  ofstream edit;
  edit.open("Courses_available_for_registration.txt");
  for (const auto & i : A)
    edit << i << "\n";
}

// This function is used to store courses in file
void Admin::store_courses_in_file()
{
  ofstream courses_available;
  courses_available.open("Courses_available_for_registration.txt", ios_base::app);
  for (const auto & course_number : course_numbers)
    courses_available << course_number << "\n";
}

// This function is used to add courses to the file
void Admin::add_courses()
{

  string check_;
  ifstream see_;
  see_.open("Courses_available_for_registration.txt");
  getline(see_, check_);
  if (check_ == "This is the list of finalized courses : ")
    cout << "Course list is finalised furthur addition of courses is not accepted" << endl;
  else
  {
    cout << "---> Enter the COURSE CODES for courses which you want to add" << endl;
    cout << "---> To exit this mode give input as \"Done\"" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true)
    {

      string A;
      cout << "Enter the COURSE CODE of the course which you want to add : " << endl;
      getline(cin, A);
      if (A == "Done")
      {
        cout << "You are out of the mode ADDING COURSES";
        break;
      }
      else
        course_numbers.push_back(A);
    }
    store_courses_in_file();
  }

  }

// function is used to edit students from a student list
void Admin::store_rollnumbers_in_file_edited(const vector<string>& A)
{
  ofstream edit;
  edit.open("List_of_students_part_of_iith.txt");
  for (const auto & i : A)
    edit << i << "\n";
}

// Function used to delete courses from the course list
void Admin::delete_courses()
{

  string check_;
  ifstream see_;
  see_.open("Courses_available_for_registration.txt");
  getline(see_, check_);
  if (check_ == "This is the list of finalized courses : ")
    cout << "Course list is finalised furthur deletion of courses is not accepted" << endl;
  else
  {

    string B;
    ifstream courses_available_see;
    courses_available_see.open("Courses_available_for_registration.txt");
    vector<string> new_vec;
    while (getline(courses_available_see, B))
    {
      cout << B << "\n";
      new_vec.push_back(B);
    }

    cout << "Enter the line number of the course which you want to remove : ";

    int i;
    cin >> i;

    new_vec.erase(new_vec.begin() + i - 1);
    store_courses_in_file_edit(new_vec);
  }

  }

// This function is used for finalizing the course list
void Admin::finalizing_courses()
{
  string B;
  ifstream courses_available_see;

  courses_available_see.open("Courses_available_for_registration.txt");
  vector<string> new_vec;
  while (getline(courses_available_see, B))
  {

    new_vec.push_back(B);
  }
  ofstream courses_available_;
  courses_available_.open("Courses_available_for_registration.txt");
  courses_available_ << "This is the list of finalized courses : "
                     << "\n";
  for (const auto & i : new_vec)
    courses_available_ << i << "\n";
}

void Admin::store_rollnumbers_in_file()
{
  ofstream student_file_ptr;
  student_file_ptr.open("List_of_students_part_of_iith.txt", ios_base::app);
  for (const auto & i : student_rollnum)
    student_file_ptr << i << "\n";
}

// This function is used to remove students from iith
void Admin::remove_students_from_iith()
{
  string B;
  ifstream studentlist;
  int i;

  studentlist.open("List_of_students_part_of_iith.txt");
  vector<string> new_vec;
  while (getline(studentlist, B))
  {
    cout << B << "\n";
    new_vec.push_back(B);
  }

  cout << "Enter the line number of the student whom you want to remove : ";
  cin >> i;
  new_vec.erase(new_vec.begin() + i - 1);

  store_rollnumbers_in_file_edited(new_vec);
}

// This function is used to add students to iith
void Admin::add_students_to_iith()
{
    cout << "---> Enter the Roll numbers of the students whom you want to add to iith" << endl;
  cout << "---> To exit this mode give input as \"Done\"" << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (true)
  {

    string A;
    cout << "Enter the ROLL NUMBER of the student whom you want to add to IITH" << endl;
    getline(cin, A);

    if (A == "Done")
    {
      cout << "You are out of the mode ADDING STUDENTS TO IITH";
      break;
    }
    else
      student_rollnum.push_back(A);
  }
  store_rollnumbers_in_file();
}

// This function creates files for courses in which students' roll numbers are stored as soon as they register for the course
void Admin::create_files_for_registration()
{

  string B;

  cout << "---> For using this mode the course list must be finalized" << endl;
  ifstream see;
  see.open("Courses_available_for_registration.txt");
  vector<string> new_vec;
  while (getline(see, B))
    new_vec.push_back(B);
  if (new_vec[0] == "This is the list of finalized courses : ")
  {
    for (size_t i = 1; i < new_vec.size(); i++)
    {
      ofstream file_creator;
      string S;
      S = new_vec[i] + "_Course_registration_file.txt";
      file_creator.open(S);
    }
    cout << "Files are created successfully" << endl;
  }
  else
    cout << "The course list must be finalized first then only the files will be created" << endl;
}

void Admin::edit_course_available_for_registration_file()
{
  ifstream see;
  cout << "The following is the info about grade submissions for a course" << endl;
  see.open("Info_about_course_grade_submission.txt");
  string b;

  while (getline(see, b))
    cout << b << "\n";
  ifstream dd;
  cout << "---> Here is the course list which is needed to be modified as per the state of the course :" << endl;
  dd.open("Courses_available_for_registration.txt");
  vector<string> new_vec;
  while (getline(dd, b))
  {
    cout << b << "\n";
    new_vec.push_back(b);
  }

  cout << "---> For exiting from this mode give input as -1" << endl;
  int z;
  while (true)
  {

    cout << "Enter the line number of the course which you want to modify its state : ";
    cin >> z;

    if (z == -1)
      break;
    else
    {
      string course_co;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Enter the COURSE CODE of the course which you want to modify its state : ";
      getline(cin, course_co);

      new_vec[z - 1] = course_co + " - grades submitted";
    }
  }

  store_courses_in_file_edit(new_vec);
}

// This function is used to see students registered for a course
void Admin::see_students_registered_for_a_course()
{
  string s;
  cout << "Enter the course code of the course for which you want to see the students registered list : ";
  cin >> s;
  ifstream see;
  see.open(s + "_Course_registration_file.txt");
  string g;
  cout << "These are students registered for the course " << s << endl;
  while (getline(see, g))
    cout << g << endl;
}
