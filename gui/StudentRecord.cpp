//    Carl Richard Dumdum
//    BSEC-IV
//    CSC 151
//
//    StudentRecord.cpp
//    - contains the implementation of the class StudentRecord
//    - class StudentRecord can be use to modify the recorded
//      students

#include "StudentRecord.hpp"

StudentRecord::StudentRecord(string fname)
    :_fname(fname),
     _students({}){
    if (_load()) throw -1;
}

StudentRecord::~StudentRecord(){}

int StudentRecord::addStudent(Student s){
    _students.push_back(s);
    return 0;
}

int StudentRecord::deleteStudent(string idNo){
    int i = 0, error = -1;
    for (auto& s : _students){
        if (s.getStudentIDNo() == idNo){
            error = 0;
            break;
        }
        ++i;
    }
    if (!error)
        _students.erase(_students.begin()+i);

    return error;
}

int StudentRecord::updateStudent(string name, string idNo, string course){
    int i = 0, error = -1;
    for (auto& s : _students){
        if (s.getStudentIDNo() == idNo){
            error = 0;
            break;
        }
        ++i;
    }
    if (!error){
        _students[i].setStudentName(name);
        _students[i].setStudentIDNo(idNo);
        _students[i].setStudentCourse(course);
    }

    return error;
}

Student StudentRecord::getStudent(string idNo){
    for (auto& i : _students){
        if (i.getStudentIDNo() == idNo)
            return i;
    }
    return (Student("","",""));
}

vector<Student> StudentRecord::getStudents(){
    return _students;
}

int StudentRecord::getStudentCount(){
    return _students.size();
}

bool StudentRecord::isRecorded(string idNo){
    for (auto& s : _students){
        if (s.getStudentIDNo() == idNo)
            return true;
    }
    return false;
}
int StudentRecord::save(){
    fstream fle(_fname, ios::out);

    for (auto& i : _students){
        if (!i.isEmpty()){
            fle << i.getStudentName() << ";"
                << i.getStudentIDNo() << ";"
                << i.getStudentCourse() << endl;
        }
    }

    fle.close();

    return 0;
}

int StudentRecord::_load(){
    fstream fle(_fname, ios::in);
    if (!fle.is_open()) return -1;
    char buffer[256];
    string l;
    int pos1, pos2;
    Student s;

    while (!fle.eof()){
        fle.getline(buffer, 256);
        l = buffer;
        pos1 = l.find(';');
        pos2 = l.find(';', pos1+1);

        s.setStudentName(l.substr(0,pos1));
        s.setStudentIDNo(l.substr(pos1+1, pos2-pos1-1));
        s.setStudentCourse(l.substr(pos2+1, l.size()));

        if (!s.isEmpty())
            _students.push_back(s);
    }

    fle.close();
    return 0;
}
