#ifndef LOAD_H
#define LOAD_H

#include <QDialog>
#include "game.h"
#include <QListWidgetItem>
#include "mainwindow.h"
#include <QMainWindow>
namespace Ui {
class Load;
}

class Load : public QDialog
{
    Q_OBJECT

public:
    explicit Load(QWidget *parent = nullptr);
    ~Load();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_Action_triggered();

private:
    void write_saved_datas(QString s);
    void write_saved_datas_to_list();

    QMenuBar* menuBar;
    QMenu* menu;
    QAction* Action;
    int theme;

    Ui::Load *ui;

    QByteArray arr;
};

#endif // LOAD_H
