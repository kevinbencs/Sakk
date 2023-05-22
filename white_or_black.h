#ifndef WHITE_OR_BLACK_H
#define WHITE_OR_BLACK_H

#include <QDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "game.h"

namespace Ui {
class White_or_black;
}

class White_or_black : public QDialog
{
    Q_OBJECT

public:
    explicit White_or_black(QWidget *parent = nullptr);
    ~White_or_black();

private slots:
    void on_Action_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::White_or_black *ui;
    QMenuBar* menuBar;
    QMenu* menu;
    QAction* Action;
    int theme;
};

#endif // WHITE_OR_BLACK_H
