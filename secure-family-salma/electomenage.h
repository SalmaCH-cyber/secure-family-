#ifndef ELECTOMENAGE_H
#define ELECTOMENAGE_H

#include <QDialog>

namespace Ui {
class ELECTOMENAGE;
}

class ELECTOMENAGE : public QDialog
{
    Q_OBJECT

public:
    explicit ELECTOMENAGE(QWidget *parent = nullptr);
    ~ELECTOMENAGE();

private slots:
    void on_pushButton_Afficher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_TRI_clicked();

    void on_pushButton_Ajouter_clicked();

    void on_pushButton_stat_clicked();

private:
    Ui::ELECTOMENAGE *ui;
};

#endif // ELECTOMENAGE_H
