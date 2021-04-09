#ifndef PORTE_IMPL_H
#define PORTE_IMPL_H
#include "connection.h"
#include <QMainWindow>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QTableView>
class porte_impl
{
public:
    porte_impl();
    porte_impl(int,int,int,int);
    QSqlTableModel *afficher();

    bool ajouter();
    QSqlTableModel *supprimer ();
    bool recherche(int );
     QSqlTableModel *tri (int );

     void cleartable(QTableView * table);
      void rechercher(QTableView * table ,int );


    private:
     int num_porte;
     int code_porte;
    int temps_ferme , temps_ouvert ;




};

#endif // PORTE_IMPL_H
