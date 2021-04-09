#include "notifications.h"
#include <QSystemTrayIcon>
#include<QString>
Notifications::Notifications()
{

}

void Notifications::notifications_ajouterPortes()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon(":/new/prefix1/check-512.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Portes ","Nouveau Porte ajouté ",QSystemTrayIcon::Information,15000);
}

