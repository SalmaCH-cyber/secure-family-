#ifndef PORTES_H
#define PORTES_H

#include <QDialog>

namespace Ui {
class portes;
}

class portes : public QDialog
{
    Q_OBJECT

public:
    explicit portes(QWidget *parent = nullptr);
    ~portes();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_TRI_clicked();

    void on_txt_search_textChanged(const QString &arg1);

private:
    Ui::portes *ui;
};

#endif // PORTES_H
