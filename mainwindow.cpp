#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>

/////////////////////////////////////////////////////////////////
/// Mainwindow
/// This is the first window
/// You can choose the new game or the saved game
////////////////////////////////////////////////////////////////
///
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("Gui/Chess.jpg"));


    ///////////////////////////////////////////////////////////////
    /// Loading the theme of appearance
    //////////////////////////////////////////////////////////////

    std::ifstream in("Theme");
    in>>theme;
    in.close();

    if(theme==0){
        qApp->setStyleSheet("MainWindow{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->actionBekapcsol->setText("Kikapcsol");
        ui->menubar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
    }
    else{
        qApp->setStyleSheet("MainWindow{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->actionBekapcsol->setText("Bekapcsol");
        ui->menubar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////////
///New game
///////////////
void MainWindow::on_pushButton_clicked()
{
    hide();
    HumanOrMachine humanOrMachine;
    humanOrMachine.show();
    humanOrMachine.exec();
}

//////////////////////////
/// Load the saved game
//////////////////////////
void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Load load;
    load.show();
    load.exec();
}

////////////////////////////////////////////////////////////////
/// This is the menu where you can select the window appearance.
////////////////////////////////////////////////////////////////
void MainWindow::on_actionBekapcsol_triggered()
{
    if(ui->actionBekapcsol->text()=="Bekapcsol"){
        qApp->setStyleSheet("MainWindow{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->actionBekapcsol->setText("Kikapcsol");
        ui->menubar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
        theme=0;
    }
    else{
        qApp->setStyleSheet("MainWindow{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->actionBekapcsol->setText("Bekapcsol");
        ui->menubar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
        theme=1;
    }

    std::ofstream out("Theme");
    out<<theme;
    out.close();
}

