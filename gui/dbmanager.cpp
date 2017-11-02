#include "dbmanager.hpp"

// * alerts the user when the database is not found on the current directory
// * opens the database if it is present in the current directory
int DbManager::open(const QString& path){
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    if (!QFile::exists(path))
    {
         QString msg =
            QObject::tr("Unable to establish a database connection.\n"
                        "Make sure that the *.db file is in [");
         msg += QDir::currentPath();
         msg += QObject::tr("].");

         alert(2,QObject::tr("Failure to connect to database"), msg);
         return -1;
    }
    else
    {
       m_db.open();
       return 0;
    }
}

bool DbManager::addStudent(const QString& lname,
                          const QString& fname,
                          const QString& mname,
                          const QString& idNo,
                          const QString& course,
                          const QString& gender)
{
   bool success = false;
   QSqlQuery query;
   query.prepare("INSERT INTO "
                 "students (lastName, firstName, middleName, idNo, course, gender) "
                 "VALUES (?, ?, ?, ?, ?, ?)");
   query.addBindValue(lname);
   query.addBindValue(fname);
   query.addBindValue(mname);
   query.addBindValue(idNo);
   query.addBindValue(course);
   query.addBindValue(gender);

   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addStudent error:  "
                 << query.lastError();
   }

   return success;
}

bool DbManager::updateStudent(const QString& lname,
                          const QString& fname,
                          const QString& mname,
                          const QString& idNo,
                          const QString& course,
                          const QString& gender)
{
   bool success = false;
   QSqlQuery query;
   query.prepare("UPDATE students "
                 "SET lastName=?, firstName=?, middleName=?, course=?, gender=?"
                 "WHERE idNo=?");
   query.addBindValue(lname);
   query.addBindValue(fname);
   query.addBindValue(mname);
   query.addBindValue(course);
   query.addBindValue(gender);
   query.addBindValue(idNo);

   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "updatePerson error:  "
                 << query.lastError();
   }

   return success;
}

bool DbManager::deleteStudent(const QString& idNo)
{
   bool success = false;
   QSqlQuery query;
   query.prepare("DELETE FROM students "
                 "WHERE idNo=?");
   query.addBindValue(idNo);

   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "deleteStudent error:  "
                 << query.lastError();
   }

   return success;
}

bool DbManager::idNoIsTaken(const QString& idNo){
    int count = 0;
    QSqlQuery q;
    q.prepare("SELECT * FROM students WHERE idNo = ?");
    q.addBindValue(idNo);
    q.exec();

    while(q.next())
        ++count;

    return ((count) ? true : false);
}

QStringList DbManager::getAllCourses(){
    QStringList sl;
    QSqlQuery q;
    q.prepare("SELECT courseName FROM courses");
    q.exec();
    while(q.next())
        sl.append(q.value(0).toString());

    return sl;
}
void DbManager::addCourse(const QString& course){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO "
                  "courses (courseName) "
                  "VALUES (?)");
    query.addBindValue(course);

    if(query.exec())
    {
        success = true;
    }
    else
    {
         qDebug() << "addStudent error:  "
                  << query.lastError();
    }
}

bool DbManager::deleteCourse(const QString& course)
{
   bool success = false;
   QSqlQuery query;
   query.prepare("DELETE FROM courses "
                 "WHERE courseName=?");
   query.addBindValue(course);

   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "deleteStudent error:  "
                 << query.lastError();
   }

   return success;
}
