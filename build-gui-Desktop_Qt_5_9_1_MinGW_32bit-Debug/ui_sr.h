/********************************************************************************
** Form generated from reading UI file 'sr.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SR_H
#define UI_SR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SR
{
public:

    void setupUi(QWidget *SR)
    {
        if (SR->objectName().isEmpty())
            SR->setObjectName(QStringLiteral("SR"));
        SR->resize(400, 300);

        retranslateUi(SR);

        QMetaObject::connectSlotsByName(SR);
    } // setupUi

    void retranslateUi(QWidget *SR)
    {
        SR->setWindowTitle(QApplication::translate("SR", "SR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SR: public Ui_SR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SR_H
