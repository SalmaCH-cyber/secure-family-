#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QWidget>
#include <QMap>
#include <QVector>
namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
       void ajouter (QString,double);

private:
    Ui::statistique *ui;
    QVector <double> quantite;
int recherche();
        QVector <QString> nom;
};

#endif // STATISTIQUE_H
