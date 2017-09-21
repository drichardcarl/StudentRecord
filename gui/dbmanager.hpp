#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

#include "alert.hpp"

// a database manager (not so obvious!)
// * handles the connection and modification of the database
class DbManager
{
public:
    // opens a connection to a database
    int open(const QString& path);
    // adds a student into the database
    bool addStudent(const QString& lname,
                   const QString& fname,
                   const QString& mname,
                   const QString& idNo,
                   const QString& course);
    // updates an existing record of a student in the database
    bool updateStudent(const QString& lname,
                   const QString& fname,
                   const QString& mname,
                   const QString& idNo,
                   const QString& course);
    // removes an existing record of a student from the database
    bool deleteStudent(const QString& idNo);
    // checks if a student has been recorded with the same ID No.
    bool idNoIsTaken(const QString& idNo);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_HPP
