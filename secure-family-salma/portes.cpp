#include "portes.h"
#include "ui_portes.h"
#include "porte_impl.h"
#include "notifications.h"
#include <QMessageBox>
portes::portes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::portes)
{
    ui->setupUi(this);

}

portes::~portes()
{
    delete ui;
}



void portes::on_pushButton_Ajouter_clicked()
{


      int num = ui->spinBox_NUMPORT->text().toInt()   ;
      int code = ui->spinBox_CODEPORT->text().toInt()   ;
      int temp_ouvert = ui->spinBox_TEMPOUVERT->text().toInt()   ;
      int temp_ferme = ui->spinBox_TEMPFERME->text().toInt()   ;

      if (num < 1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem num"),
                      QObject::tr("Problem num."), QMessageBox::Cancel);
      }
      else if  (code <1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem code"),
                      QObject::tr("Problem code."), QMessageBox::Cancel);
      }
      else if (temp_ouvert <1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem temp_ouvert"),
                      QObject::tr("Problem temp_ouvert."), QMessageBox::Cancel);
      }
      else if  (temp_ferme < 1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem temp_ferme"),
                      QObject::tr("Problem temp_ferme."), QMessageBox::Cancel);
      }
      else
      {

          Notifications N;
          N.notifications_ajouterPortes();
          porte_impl p (num,code,temp_ouvert,temp_ferme);
          p.ajouter();
                      ui->tableView_port->setModel(p.afficher());
      }



}

void portes::on_pushButton_Afficher_clicked()
{

    porte_impl p;
  ui->tableView_port->setModel(p.afficher());
}

void portes::on_pushButton_supprimer_clicked()
{
    porte_impl r;
          r.supprimer()->removeRow(ui->tableView_port->currentIndex().row());

            ui->tableView_port->setModel(r.afficher());
}

void portes::on_pushButton_TRI_clicked()
{

    porte_impl r;
    ui->tableView_port->setModel(r.tri(ui->tableView_port->currentIndex().column()));
}

void portes::on_txt_search_textChanged(const QString &arg1)
{
    porte_impl c ;


        c.cleartable(ui->tableView_port);
        int numero =ui->txt_search->text().toInt();
        c.rechercher(ui->tableView_port,numero);

        if(ui->txt_search->text().isEmpty())
        {
            ui->tableView_port->setModel(c.afficher());
        }
}
