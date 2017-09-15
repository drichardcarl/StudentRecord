#include "dbmanager.hpp"

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

bool DbManager::addPerson(const QString& lname,
                          const QString& fname,
                          const QString& mname,
                          const QString& idNo,
                          const QString& course)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO "
                 "students (lastName, firstName, middleName, idNo, course) "
                 "VALUES (?, ?, ?, ?, ?)");
   query.addBindValue(lname);
   query.addBindValue(fname);
   query.addBindValue(mname);
   query.addBindValue(idNo);
   query.addBindValue(course);

   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  "
                 << query.lastError();
   }

   return success;
}
