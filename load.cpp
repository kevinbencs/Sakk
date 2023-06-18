#include "load.h"
#include "ui_load.h"
#include <QFile>
#include <string>
#include <iostream>
#include <fstream>

Load::Load(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Load)
{
    ui->setupUi(this);


    menuBar=new QMenuBar();
    menu=new QMenu("Sötét téma");
    Action=new QAction("Bekapcsol");
    menu->addAction(Action);
    menuBar->addMenu(menu);

    this->layout()->setMenuBar(menuBar);
    connect(Action,&QAction::triggered,this,&Load::on_Action_triggered);

    std::ifstream in("Theme");
    in>>theme;
    in.close();

    if(theme==0){
        qApp->setStyleSheet("Load{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%); title-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" border-color: rgb(0%,0%,0%);background-color: rgb(0%,0%,0%); color: rgb(90%,90%,90%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(0%,0%,0%); background-color: rgb(0%,0%,0%); color: rgb(90%,90%,90%)");
        ui->pushButton_3->setStyleSheet("border-color: rgb(0%,0%,0%); background-color: rgb(0%,0%,0%); color: rgb(90%,90%,90%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
    }
    else{
        qApp->setStyleSheet("Load{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_3->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(80%,80%,80%); color: rgb(0%,0%,0%)");
    }



    QFile fin("Saved.txt");

    if(fin.size()==0){
        ui->listWidget->addItem(new QListWidgetItem("Nincs mentett adat"));
    }
    else{
        if(!fin.open(QFile::ReadOnly)){
            return;
        }
        QString s;

        while(!fin.atEnd()){
            s=fin.readLine();

            if(s[0]=='S' || s[0]=='M' || s[0]=='T' || s[0]=='W' || s[0]=='F'){
                ui->listWidget->addItem(new QListWidgetItem(s));
            }
        }
    }

    fin.close();
}


void Load::on_Action_triggered()
{
    if(Action->text()=="Bekapcsol"){
        qApp->setStyleSheet("Load{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%); title-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" border-color: rgb(0%,0%,0%);background-color: rgb(0%,0%,0%); color: rgb(90%,90%,90%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(0%,0%,0%); background-color: rgb(0%,0%,0%); color: rgb(90%,90%,90%)");
        ui->pushButton_3->setStyleSheet("border-color: rgb(0%,0%,0%); background-color: rgb(0%,0%,0%); color: rgb(90%,90%,90%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");

        theme=0;
    }
    else{
        qApp->setStyleSheet("Load{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_3->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(80%,80%,80%); color: rgb(0%,0%,0%)");

        theme=1;
    }

    std::ofstream out("Theme");
    out<<theme;
    out.close();
}



Load::~Load()
{
    delete ui;
}

void Load::on_pushButton_clicked()
{
    hide();
    Game game;
    game.saved_game_load(ui->listWidget->currentItem()->text());
    game.show();
    game.exec();
}




void Load::on_pushButton_3_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void Load::write_saved_datas_to_list()
{
    ui->listWidget->clear();

    QFile fin("Saved.txt");

    if(!fin.open(QFile::ReadOnly)){
        return;
    }

    QString s1;

    while(!fin.atEnd()){
        s1=fin.readLine();

        if(s1[0]=='S' || s1[0]=='M' || s1[0]=='T' || s1[0]=='W' || s1[0]=='F'){
            ui->listWidget->addItem(new QListWidgetItem(s1));
        }
    }

    fin.close();
}


void Load::write_saved_datas(QString s)
{
    QFile out("Saved.txt");
    QTextStream str(&out);

    if(!out.open(QFile::WriteOnly)){
        return;
    }
    for(int i=0;i<s.length();i++){
        if(i==s.length()-1){
            if(s[i]!='\n'){
                str<<s[i];
            }
        }
        else{
           str<<s[i];
        }

    }

    str.flush();
    out.close();
}


void Load::on_pushButton_2_clicked()
{
    QFile fin("Saved.txt");


    if(!fin.open(QFile::ReadOnly)){
        return;
    }

    QString s,s1;

    while(!fin.atEnd()){
        s1=fin.readLine();

        if(s1==ui->listWidget->currentItem()->text()){
            for(int i=1;i<=16;i++){
                fin.readLine();
            }
        }
        else{
           s+=s1;
        }
    }

    fin.close();

    write_saved_datas(s);
    write_saved_datas_to_list();


}

