#include "electomenage_impl.h"

ELECTOMENAGE_IMPL::ELECTOMENAGE_IMPL()
{

}
ELECTOMENAGE_IMPL::ELECTOMENAGE_IMPL(QString i,QString q)
{
     ETAT_ELECTRO=i;
     NOM_ELECTRO=q;



}
bool ELECTOMENAGE_IMPL::ajouter()
{

    QSqlQuery qry;

            qry.prepare("INSERT INTO ELECTOMENAGE (ETAT_ELECTRO, NOM_ELECTRO) "
                                "VALUES (:ETAT_ELECTRO, :NOM_ELECTRO)");


  qry.bindValue(":ETAT_ELECTRO",ETAT_ELECTRO);
    qry.bindValue(":NOM_ELECTRO",NOM_ELECTRO);
    return qry.exec();

}
QSqlTableModel *ELECTOMENAGE_IMPL::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("ELECTOMENAGE");
    mmodel->select();
    return mmodel;

}
 QSqlTableModel *ELECTOMENAGE_IMPL::supprimer ()
{
    QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("ELECTOMENAGE");
     mmodel->select();
     return mmodel;

}


 QSqlTableModel *ELECTOMENAGE_IMPL::tri(int num )
{

    QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("ELECTOMENAGE");
    mmodel->setSort(num,Qt::DescendingOrder);
    mmodel->select();
    return mmodel;



}
 void ELECTOMENAGE_IMPL :: rechercher(QTableView * table ,QString cas )
 {
     QSqlQueryModel *model= new QSqlQueryModel();

     QSqlQuery *query=new QSqlQuery;
     query->prepare("select * from ELECTOMENAGE where ETAT_ELECTRO like '%"+cas+"%' ;");

     query->exec();
     model->setQuery(*query);
     table->setModel(model);
     table->show();

 }
 void ELECTOMENAGE_IMPL::cleartable(QTableView * table)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     model->clear();
     table->setModel(model);
 }
