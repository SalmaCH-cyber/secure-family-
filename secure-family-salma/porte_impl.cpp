#include "porte_impl.h"
#include "connection.h"
#include <QMessageBox>



porte_impl::porte_impl()
{

    num_porte=0;
    code_porte=0;
    temps_ferme=0;
    temps_ouvert=0;



}

porte_impl::porte_impl(int n  , int c , int tf, int to )
{
    num_porte=n;
       code_porte=c;
       temps_ferme=tf;
       temps_ouvert=to;




}
void porte_impl :: rechercher(QTableView * table ,int NUM )
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QString NUMS =  QString::number(NUM);
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PORTE where regexp_like(NUM_PORTE,:NUMS) OR regexp_like(CODE_PORTE,:NUMS) OR regexp_like(TEMPS_FERME,:NUMS) OR regexp_like(TEMPS_OUVERT,:NUMS);");
 query->bindValue(":NUMS",NUMS);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}

//ajout
bool porte_impl::ajouter()
{

    QSqlQuery qry;


         qry.prepare("INSERT INTO PORTE (NUM_PORTE, CODE_PORTE, TEMPS_OUVERT,TEMPS_FERME) "
         "VALUES (:NUM_PORTE, :CODE_PORTE, :TEMPS_OUVERT, :TEMPS_FERME)");


  qry.bindValue(":NUM_PORTE",num_porte);
    qry.bindValue(":CODE_PORTE",code_porte);
    qry.bindValue(":TEMPS_OUVERT",temps_ouvert);
    qry.bindValue(":TEMPS_FERME",temps_ferme);

    return qry.exec();

}
QSqlTableModel *porte_impl::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("PORTE");
    mmodel->select();
    return mmodel;

}
 QSqlTableModel *porte_impl::supprimer ()
{
    QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("PORTE");
     mmodel->select();
     return mmodel;

}


 QSqlTableModel *porte_impl::tri(int num )
{

    QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("PORTE");
    mmodel->setSort(num,Qt::DescendingOrder);
    mmodel->select();
    return mmodel;



}

 void porte_impl::cleartable(QTableView * table)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     model->clear();
     table->setModel(model);
 }


