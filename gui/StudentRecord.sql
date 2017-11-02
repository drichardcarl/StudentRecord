PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE students(idx integer primary key, lastName text not null, firstName text not null, middleName text, idNo text not null, course text not null, gender text not null);
CREATE TABLE courses(idx integer primary key, courseName text not null);
COMMIT;
