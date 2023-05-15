#ifndef HUMANORMACHINE_H
#define HUMANORMACHINE_H

#include <QDialog>
#include "difficulty.h"
#include "game.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

namespace Ui {
class HumanOrMachine;
}

class HumanOrMachine : public QDialog
{
    Q_OBJECT

public:
    explicit HumanOrMachine(QWidget *parent = nullptr);
    ~HumanOrMachine();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Action_triggered();


private:
    Ui::HumanOrMachine *ui;
    QMenuBar* menuBar;
    QMenu* menu;
    QAction* Action;
    int theme;
};

#endif // HUMANORMACHINE_H
