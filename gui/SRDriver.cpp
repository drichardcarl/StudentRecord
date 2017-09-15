//    Carl Richard Dumdum
//    BSEC-IV
//    CSC 151
//
//    SRDriver.cpp
//    - driver program to facilitate adding, removing, updating
//      and finding Student Record
//
//    *Main Interface*
//    Enter Option (number) accordingly:
//        1 - To display the list recorded students
//        2 - To modify records
//            1 - To add a student to the record
//            2 - To update a record of a student
//            3 - To delete a record of a student
//            4 - To go back to previous menu
//        3 - To find a student given the student's ID No.
//            1 - To enter student's ID No.
//            2 - To go back to previous menu
//        4 - To quit the program
//
//    *Program Flow*
//    1 - When the program starts, it loads the data
//        -- following the correct format -- specified by the macro
//        RECORD into the memory.
//    2 - The user can then freely modify what's in the memory
//        with the help of the Interface
//    3 - When the user exits the program, it saves what's in the
//        memory to the external file specified by the macro RECORD
// ***************************************
#include <iostream>
#include <string>
#include <algorithm>
// ---------------------------------------
#include "Student.hpp"
#include "StudentRecord.hpp"
#include "clrscr.hpp"
#include "sleep.hpp"

// ***************************************
#define RECORD "StudentRecord.dat"

// ***************************************
using namespace std;

// ***************************************
void displayStudents(StudentRecord&);
// ---------------------------------------
void modifyRecords(StudentRecord&);
void addStudent(StudentRecord&);
void updateStudent(StudentRecord&);
void deleteStudent(StudentRecord&);
// ---------------------------------------
void studentLookup(StudentRecord&);
int searchStudent(StudentRecord&);
// ---------------------------------------
void printIns(int);
void printHead(int);
int getInput(int);
inline void def(int);
inline void str2upper(string&);

// ***************************************
int main (int argc, char* argv[]){
    try{
        StudentRecord SR(RECORD);

        printHead(1);
        string RES;
        int res;
        while (1){
            res = getInput(1);
            if (res == -1) continue;
            switch (res){
            case 1:
                CLRSCR();
                printHead(1);
                displayStudents(SR);
                break;
            case 2:
                CLRSCR();
                modifyRecords(SR);
                break;
            case 3:
                CLRSCR();
                studentLookup(SR);
                break;
            case 4:
                CLRSCR();
                return SR.save();
            default:
                def(1);
                break;
            }
        }
    }catch(int e){
        cout << '\7';
        cout << "Error. <" << RECORD << "> is missing." << endl;
        cout << "Program exiting ..." << endl;
        SLEEP(3000);
        return -1;
    }
}

// ***************************************
void displayStudents(StudentRecord& SR){
    vector<Student> students = SR.getStudents();
    cout << "[---- RECORDED STUDENTS ("
         << students.size()
         << " entries) ----]\n";

    for (auto& i : students){\
        cout << "NAME\t: " << i.getStudentName() << endl;
        cout << "ID NO.\t: " << i.getStudentIDNo() << endl;
        cout << "COURSE\t: " << i.getStudentCourse() << endl;
        cout << endl;
    }
    cout << "[---------------------------------------]\n\n";
}
// ---------------------------------------
void modifyRecords(StudentRecord& SR){
    printHead(2);

    string RES;
    int res;
    while (1){
        res = getInput(2);
        if (res == -1) continue;
        switch (res){
        case 1:
            addStudent(SR);
            printHead(2);
            break;
        case 2:
            updateStudent(SR);
            printHead(2);
            break;
        case 3:
            displayStudents(SR);
            deleteStudent(SR);
            printHead(2);
            break;
        case 4:
            CLRSCR();
            printHead(1);
            return;
        default:
            def(2);
            break;
        }
    }
}
// ---------------------------------------
void addStudent(StudentRecord& SR){
    string record;
    char buffer[256];
    string id;
    int p, pos1, pos2;

    // can't add if wrong # of semicolon
    while (1){
        CLRSCR();
        fflush(stdin);
        cout << " ----------------------------------------\n";
        cout << "|           ADD STUDENT RECORD           |\n";
        cout << " ----------------------------------------\n";
        cout << "ENTER RECORD (<NAME>;<ID_NO>;<COURSE>)\n[>] ";
        cin.getline(buffer,256);
        record = buffer;

        if (count(record.begin(), record.end(), ';') !=2){
            cout << "[*] INVALID INPUT.\n\n";
            SLEEP(1000);
            continue;
        }

        p = record.find(';');
        id = record.substr(p+1,record.find(';',p+1)-p-1);
        if (SR.isRecorded(id)){
            cout << "[*] ID NO. IS ALREADY TAKEN.\n\n";
            SLEEP(1000);
            continue;
        }
        break;
    }


    str2upper(record);
    pos1 = record.find(';');
    pos2 = record.find(';', pos1+1);
    SR.addStudent(Student(record.substr(0,pos1),
                          record.substr(pos1+1, pos2-pos1-1),
                          record.substr(pos2+1, record.size())));

    cout << "[*] STUDENT SUCCESSFULLY ADDED.";

    SLEEP(1000);
    CLRSCR();
}
// ---------------------------------------
void updateStudent(StudentRecord& SR){
    string record;
    char buffer[256];
    string id;
    int p, pos1, pos2;

    // can't add if wrong # of semicolon
    while (1){
        CLRSCR();
        fflush(stdin);
        cout << " ----------------------------------------\n";
        cout << "|         UPDATE STUDENT RECORD          |\n";
        cout << " ----------------------------------------\n";
        displayStudents(SR);
        cout << "ENTER RECORD (<NAME>;<ID_NO>;<COURSE>)\n[>] ";
        cin.getline(buffer,256);
        record = buffer;

        if (count(record.begin(), record.end(), ';') !=2){
            cout << "[*] INVALID INPUT.\n\n";
            SLEEP(1000);
            continue;
        }

        p = record.find(';');
        id = record.substr(p+1,record.find(';',p+1)-p-1);
        if (!SR.isRecorded(id)){
            cout << "[*] UNRECOGNIZED ID NO.\n\n";
            SLEEP(1000);
            continue;
        }
        break;
    }

    str2upper(record);

    pos1 = record.find(';');
    pos2 = record.find(';', pos1+1);
    SR.updateStudent(record.substr(0,pos1),
                     record.substr(pos1+1, pos2-pos1-1),
                     record.substr(pos2+1, record.size()));

    cout << "[*] STUDENT SUCCESSFULLY UPDATED.";

    SLEEP(1000);
    CLRSCR();
}
// ---------------------------------------
void deleteStudent(StudentRecord& SR){
    if (SR.getStudentCount() == 0){
        cout << "[*] CANNOT PROCEED, RECORD IS EMPTY.";
        SLEEP(1500);
        CLRSCR();
        return;
    }

    fflush(stdin);
    char buffer[256];
    string idNo;

    CLRSCR();
    cout << " ----------------------------------------\n";
    cout << "|         DELETE STUDENT RECORD          |\n";
    cout << " ----------------------------------------\n";
    displayStudents(SR);
    cout << "ENTER STUDENT'S ID NO. [>] ";
    cin.getline(buffer, 256);

    idNo = buffer;
    if (!SR.deleteStudent(idNo)){
        cout << "[*] STUDENT RECORD SUCCESSFULLY DELETED.";
        SLEEP(1000);
    }
    else{
        cout << "[*] STUDENT WITH ID NO. <" << idNo << "> DOES NOT EXIST!" << endl;
        cout << "[*] DELETE UNSUCCESSFUL!";
        SLEEP(3000);
    }

    CLRSCR();
}
// ---------------------------------------
void studentLookup(StudentRecord& SR){
    printHead(3);

    string RES;
    int res;
    while (1){
        res = getInput(3);
        if (res == -1) continue;
        switch (res){
        case 1:
            CLRSCR();
            printHead(3);
            if (searchStudent(SR))
                printHead(2);
            break;
        case 2:
            CLRSCR();
            printHead(1);
            return;
        default:
            def(2);
            break;
        }
    }
}
// ---------------------------------------
int searchStudent(StudentRecord& SR){
    fflush(stdin);
    char buffer[256];
    cout << "ENTER STUDENT ID NO. [>] ";
    cin.getline(buffer, 256);
    string sIDN = buffer;

    Student s = SR.getStudent(sIDN);
    if (!s.isEmpty()){
        cout << endl;
        cout << "NAME\t: " << s.getStudentName() << endl;
        cout << "ID NO.\t: " << s.getStudentIDNo() << endl;
        cout << "COURSE\t: " << s.getStudentCourse() << endl;
        cout << endl;
    }
    else{
        cout << "[*] ID NO. HAS NO MATCH." << endl;
        SLEEP(1000);
        CLRSCR();
        return -1;
    }
    return 0;
}
// ---------------------------------------
void printIns(int i){
    cout << "(COMMANDS)" << endl;
    switch (i){
    case 1:
        cout << "1. DISPLAY RECORDS\n";
        cout << "2. MODIFY RECORDS\n";
        cout << "3. STUDENT LOOKUP\n";
        cout << "4. (EXIT)\n";
        break;
    case 2:
        cout << "1. ADD STUDENT\n";
        cout << "2. UPDATE STUDENT\n";
        cout << "3. DELETE STUDENT\n";
        cout << "4. (BACK)\n";
        break;
    case 3:
        cout << "1. FIND STUDENT USING ID NO.\n";
        cout << "2. (BACK)\n";
        break;
    default:
        break;
    }
}
// ---------------------------------------
void printHead(int i){
    cout << " ----------------------------------------\n";
    switch (i){
    case 1:
        cout << "|          STUDENTS' RECORDS             |\n";
        break;
    case 2:
        cout << "|             MODIFY RECORDS             |\n";
        break;
    case 3:
        cout << "|             STUDENT LOOKUP             |\n";
        break;
    default:
        break;
    }
    cout << " ----------------------------------------\n";
}
// ---------------------------------------
int getInput(int no){
    int res;
    string RES;
    printIns(no);
    cout << "\n\n";
    cout << "[>] ";
    cin >> RES;

    // check if input is integer or not
    try {
        res = stoi(RES);
    }
    catch (exception& e){
        cout << "[*] ERROR. INPUT INTEGERS ONLY.";
        SLEEP(1000);
        CLRSCR();
        printHead(no);
            return -1;
    }
    return res;
}
// ---------------------------------------
inline void def(int no){
    cout << "[*] INVALID INPUT.";
    SLEEP(1000);
    CLRSCR();
    printHead(no);
}
// ---------------------------------------
inline void str2upper(string& str){
    for(int i=0; i<str.size(); ++i)
        str[i] = (char)toupper(str[i]);
}






