#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <QDialog>
#include "white_or_black.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

namespace Ui {
class Difficulty;
}

class Difficulty : public QDialog
{
    Q_OBJECT

public:
    explicit Difficulty(QWidget *parent = nullptr);
    ~Difficulty();

private slots:
    void on_pushButton_clicked();

    void on_Action_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Difficulty *ui;
    QMenuBar* menuBar;
    QMenu* menu;
    QAction* Action;
    int theme;
};

#endif // DIFFICULTY_H
