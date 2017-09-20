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

class DbManager
{
public:
    int open(const QString& path);
    bool addStudent(const QString& lname,
                   const QString& fname,
                   const QString& mname,
                   const QString& idNo,
                   const QString& course);
    bool updateStudent(const QString& lname,
                   const QString& fname,
                   const QString& mname,
                   const QString& idNo,
                   const QString& course);
    bool deleteStudent(const QString& idNo);

    bool idNoIsTaken(const QString& idNo);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_HPP
