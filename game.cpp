#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    for(int i=0;i<8;i++){
        ui->tableWidget->setColumnWidth(i,80);
        ui->tableWidget->setRowHeight(i,80);
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i+j)%2==0){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(""));
                ui->tableWidget->item(i,j)->setBackground(Qt::black);

            }
        }
    }

}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_clicked()
{
    hide();
    Difficulty difficulty;
    difficulty.show();
    difficulty.exec();
}

