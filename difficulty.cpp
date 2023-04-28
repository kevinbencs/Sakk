#include "difficulty.h"
#include "ui_difficulty.h"

Difficulty::Difficulty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Difficulty)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);
}

Difficulty::~Difficulty()
{
    delete ui;
}

void Difficulty::on_pushButton_clicked()
{
    hide();
    Game game;
    game.show();
    game.exec();
}

