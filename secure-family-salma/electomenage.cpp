#include "electomenage.h"
#include "statistique.h"
#include "ui_electomenage.h"
#include "electomenage_impl.h"
#include <QMessageBox>
ELECTOMENAGE::ELECTOMENAGE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ELECTOMENAGE)
{
    ui->setupUi(this);
}

ELECTOMENAGE::~ELECTOMENAGE()
{
    delete ui;
}

void ELECTOMENAGE::on_pushButton_Afficher_clicked()
{
    ELECTOMENAGE_IMPL p;
  ui->tableView_electro->setModel(p.afficher());
}

void ELECTOMENAGE::on_pushButton_clicked()
{
    ELECTOMENAGE_IMPL r;
          r.supprimer()->removeRow(ui->tableView_electro->currentIndex().row());

            ui->tableView_electro->setModel(r.afficher());
}

void ELECTOMENAGE::on_pushButton_TRI_clicked()
{
    ELECTOMENAGE_IMPL r;
    ui->tableView_electro->setModel(r.tri(ui->tableView_electro->currentIndex().column()));
}

void ELECTOMENAGE::on_pushButton_Ajouter_clicked()
{

      QString etat = ui->lineEdit_etat->text()  ;
      QString nom = ui->lineEdit_nom->text()  ;
       if (etat=="")
      {
          QMessageBox::information(nullptr, QObject::tr("Problem etat"),
                      QObject::tr("Problem etat."), QMessageBox::Cancel);
      }
      else if  (nom=="")
      {
          QMessageBox::information(nullptr, QObject::tr("Problem nom"),
                      QObject::tr("Problem nom."), QMessageBox::Cancel);
      }
      else
      {


           ELECTOMENAGE_IMPL p (etat,nom);
           p.ajouter();
                           ui->tableView_electro->setModel(p.afficher());
      }



}

void ELECTOMENAGE::on_pushButton_stat_clicked()
{
    statistique * s = new statistique();
    s->show();
}
