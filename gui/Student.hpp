//    Carl Richard Dumdum
//    BSEC-IV
//    CSC 151
//
//    Studenthpp
//    - header file
//    - contains the definitions of the class Student
//    - and instance of class Student holds the necessary information
//      about a student, i.e. Name, ID No. and Course

#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <iostream>

using namespace std;


class Student{
public:
    Student();
    Student(string, string, string);
    ~Student();

    string getStudentName();
    string getStudentIDNo();
    string getStudentCourse();

    void setStudentName(string);
    void setStudentIDNo(string);
    void setStudentCourse(string);

    bool isEmpty();

private:
    string _studentName;
    string _studentIDNo;
    string _studentCourse;
};

#endif // __STUDENT_HPP__
