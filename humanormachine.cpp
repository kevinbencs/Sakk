#include "humanormachine.h"
#include "ui_humanormachine.h"

HumanOrMachine::HumanOrMachine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HumanOrMachine)
{
    ui->setupUi(this);
}

HumanOrMachine::~HumanOrMachine()
{
    delete ui;
}

void HumanOrMachine::on_pushButton_clicked()
{
    hide();
    Game game;
    game.show();
    game.exec();
}


void HumanOrMachine::on_pushButton_2_clicked()
{
    hide();
    Difficulty difficulty;
    difficulty.show();
    difficulty.exec();
}

