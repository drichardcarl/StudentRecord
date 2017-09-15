//    Carl Richard Dumdum
//    BSEC-IV
//    CSC 151
//
//    Student.cpp
//    - contains the implementation of the class Student
//    - and instance of class Student holds the necessary information
//      about a student, i.e. Name, ID No. and Course

#include "Student.hpp"

/** CONSTRUCTOR/DESTRUCTOR **/
Student::Student()
    :_studentName(""),
     _studentIDNo(""),
     _studentCourse(""){
    ;
}

Student::Student(string studentName,
                 string studentIDNo,
                 string studentCourse)
    :_studentName(studentName),
     _studentIDNo(studentIDNo),
     _studentCourse(studentCourse){
    ;
}

Student::~Student(){}

/** GETTERS **/
string Student::getStudentName(){
    return _studentName;
}

string Student::getStudentIDNo(){
    return _studentIDNo;
}

string Student::getStudentCourse(){
    return _studentCourse;
}

/** SETTERS **/
void Student::setStudentName(string newName){
    _studentName = newName;
}

void Student::setStudentIDNo(string newIDNo){
    _studentIDNo = newIDNo;
}

void Student::setStudentCourse(string newCourse){
    _studentCourse = newCourse;
}

bool Student::isEmpty(){
    return ((_studentName == "" ||
             _studentIDNo == "" ||
             _studentCourse == "") ? true : false);
}
