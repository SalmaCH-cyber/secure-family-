#include "statistique.h"
#include "ui_statistique.h"
#include "connection.h"
#include <QMap>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QDebug>
#include <QPieSeries>
#include <QtCharts>
statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    QVector <QPieSlice *> tab;
        QPieSeries *series = new QPieSeries();
        QSqlQuery qry;
        double tous=0;

        qry.prepare("select COUNT(*) as nbr, etat_electro from ELECTOMENAGE group by etat_electro");
        if (qry.exec())
        {

            while (qry.next())
            {


    tous+= qry.value(0).toDouble();
    ajouter (qry.value(1).toString() ,qry.value(0).toDouble() );
            }
        }


    qDebug () << quantite.size();
    qDebug () << nom.size();
    qDebug () << tous;
    QVector <QString>::iterator i=nom.begin();
    for (QVector <double>::iterator it =quantite.begin();it!=quantite.end();++it )
    {

    series ->append((*i),((*it)/tous));
    ++i;


    }





    for (int i=0;i<quantite.size();i++)
    {

    tab.push_back( series->slices().at(i) );

    }


    for (QVector  <QPieSlice *> ::iterator it =tab.begin();it!=tab.end();++it )
    {
    (*it)->setLabelVisible();
    }
    int n=recherche();

    tab[n]->setExploded();
    tab[n]->setPen(QPen(Qt::darkGreen,2));
    tab[n]->setBrush(Qt::green);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(" Etat de Electromenage  : ");
    chart->legend()->hide();



                QChartView *chartview = new QChartView (chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QGridLayout *mainLayout = new QGridLayout;
            mainLayout->addWidget(chartview, 1, 1);
            setLayout(mainLayout);
}
void statistique::ajouter (QString n ,double quan )
 {
     quantite.push_back(quan);
      nom.push_back(n);

 }
int statistique::recherche()
{
double rech=(*quantite.begin());
int n=0;
int max=0;
for (QVector <double>::iterator it =quantite.begin();it!=quantite.end();++it )
{
if (rech<(*it))
{
    max=n;
    rech=(*it);

}

qDebug () <<"nnn : " <<n << "it : " << (*it) ;
n++;
}
qDebug () <<"max" <<max;
return max;
}
statistique::~statistique()
{
    delete ui;
}
