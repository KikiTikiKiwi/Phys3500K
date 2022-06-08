/*
Kieran MacDonald
PHYS 3500K
Dr. Guzzi
Feb 10, 2022
Goal: Let’s write a C++ code that uses structures for a PHYS3500K class of
two students: (firstname1, lastname1), etc.,
•Student #1 data are assigned in the code
•Student #2 data are inserted by keyboard
•The code must represent/reproduce the diagram below
*/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct StudentName{
  string first;
  string last;
  string full;
};

struct Student{
  StudentName fullName;
  int age;
  string course;
  string grade;
  int rollNo;
};

void user_prompt(Student * stud){

  cout<<"Please enter in the student's information"<<endl;
  cout<<"Enter first name"<<endl;
  cin>>stud->fullName.first;
    cout<<"Enter last name"<<endl;
  cin>>stud->fullName.last;
  cout<<"Enter age"<<endl;
  cin>>stud->age;
  cout<<"Enter Course"<<endl;
  cin>>stud->course;
  cout<<"Enter Grade"<<endl;
  cin>>stud->grade;
  cout<<"Enter roll number"<<endl;
  cin>>stud->rollNo;

  stud->fullName.full = stud->fullName.first + " " + stud->fullName.last;

}

/*
void printOutStruct(Student *stud){
  cout<<"Student's First Name: "<<stud->fullName.first<<endl;
  cout<<"Student's Last Name: "<<stud->fullName.last<<endl;
  cout<<"Student's Full Name: "<<stud->fullName.full<<endl;
  cout<<"Student's age: "<<stud->age<<endl;
  cout<<"Student's enrolled course: "<<stud->course<<endl;
  cout<<"Student's grade: "<<stud->grade<<endl;
  cout<<"Student's roll number: "<<stud->rollNo<<endl;

} */

void printOutStruct(Student stud){
  cout<<"Student's First Name: "<<stud.fullName.first<<endl;
  cout<<"Student's Last Name: "<<stud.fullName.last<<endl;
  cout<<"Student's Full Name: "<<stud.fullName.full<<endl;
  cout<<"Student's age: "<<stud.age<<endl;
  cout<<"Student's enrolled course: "<<stud.course<<endl;
  cout<<"Student's grade: "<<stud.grade<<endl;
  cout<<"Student's roll number: "<<stud.rollNo<<endl;

}


int main(){
  Student studentOne;
  studentOne.fullName.first = "James";
  studentOne.fullName.last = "Odel";
  studentOne.fullName.full = studentOne.fullName.first + " " + studentOne.fullName.last;
  studentOne.age = 22;
  studentOne.course = "PHYS 3500k";
  studentOne.grade = "A";
  studentOne.rollNo = 1908032;

  //pointer are getting fun
  Student a_student;
  Student* a_student_ptr;
  a_student_ptr = &a_student;

  user_prompt(a_student_ptr);
  printOutStruct(a_student);
  cout<<"_______________________________________________________________"<<endl;
  printOutStruct(studentOne);



  return 0;
}
