//    Carl Richard Dumdum
//    BSEC-IV
//    CSC 151
//
//    StudentRecord.hpp
//    - header file
//    - contains the definitions of the class StudentRecord
//    - class StudentRecord can be use to modify the recorded
//      students

#ifndef __STUDENTRECORD_HPP__
#define __STUDENTRECORD_HPP__

#include <iostream>
#include <fstream>
#include <vector>

#include "Student.hpp"

using namespace std;


class StudentRecord{
public:
    StudentRecord(string);
    ~StudentRecord();

    Student getStudent(string);
    std::vector<Student> getStudents();

    int addStudent(Student);
    int deleteStudent(string);
    int updateStudent(string, string, string);
    int getStudentCount();
    bool isRecorded(string);

    int save();

private:
    string _fname;
    std::vector<Student> _students;

    int _load();

};

#endif // __STUDENTRECORD_HPP__
