#ifndef ELECTOMENAGE_IMPL_H
#define ELECTOMENAGE_IMPL_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QTableView>

class ELECTOMENAGE_IMPL
{
public:

    ELECTOMENAGE_IMPL();
    ELECTOMENAGE_IMPL(QString,QString);
    QSqlTableModel *afficher();

    bool ajouter();
    QSqlTableModel *supprimer ();
    bool recherche(int );
     QSqlTableModel *tri (int );

     void cleartable(QTableView * table);
      void rechercher(QTableView * table ,QString );


    private:
     QString ETAT_ELECTRO;
     QString NOM_ELECTRO;

};

#endif // ELECTOMENAGE_IMPL_H
