#ifndef HUMANORMACHINE_H
#define HUMANORMACHINE_H

#include <QDialog>
#include "difficulty.h"
#include "game.h"

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

private:
    Ui::HumanOrMachine *ui;
};

#endif // HUMANORMACHINE_H
