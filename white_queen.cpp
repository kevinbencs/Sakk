#include "white_queen.h"

White_queen::White_queen()
{

}


void White_queen::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(8)));

        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if((i+j)%2==0){
                    ui->tableWidget->item(i,j)->setBackground(Qt::gray);
                }
                else{
                    ui->tableWidget->item(i,j)->setBackground(Qt::white);
                }
            }
        }

        piece=0;
        BlackOrWhite=-1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="8"){

            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if((i+j)%2==0){
                        ui->tableWidget->item(i,j)->setBackground(Qt::gray);
                    }
                    else{
                        ui->tableWidget->item(i,j)->setBackground(Qt::white);
                    }
                }
            }

            if(piece==0){
                for(int i=row+1;i>=0 && i<8;i++){
                    piece=8;
                    if(ui->tableWidget->item(i,column)->text()==""){
                        ui->tableWidget->item(i,column)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(i,column)->text().toInt()<0){
                            ui->tableWidget->item(i,column)->setBackground(Qt::green);
                        }
                        break;
                    }
                }

                for(int i=column+1;i>=0 && i<8; i++){
                    piece=8;
                    if(ui->tableWidget->item(row,i)->text()==""){
                        ui->tableWidget->item(row,i)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row,i)->text().toInt()<0){
                            ui->tableWidget->item(row,i)->setBackground(Qt::green);
                        }
                        break;
                    }
                }

                for(int i=row-1;i>=0 && i<8; i--){
                    piece=8;
                    if(ui->tableWidget->item(i,column)->text()==""){
                        ui->tableWidget->item(i,column)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(i,column)->text().toInt()<0){
                            ui->tableWidget->item(i,column)->setBackground(Qt::green);
                        }
                        break;
                    }
                }

                for(int i=column-1;i>=0 && i<8;i--){
                    piece=8;
                    if(ui->tableWidget->item(row,i)->text()==""){
                        ui->tableWidget->item(row,i)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row,i)->text().toInt()<0){
                            ui->tableWidget->item(row,i)->setBackground(Qt::green);
                        }
                        break;
                    }
                }

                for(int i=row+1, j=column+1;i>=0 && i<8 && j>=0 && j<8;j++, i++){
                    piece=8;
                    if(ui->tableWidget->item(i,j)->text()==""){
                        ui->tableWidget->item(i,j)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(i,j)->text().toInt()<0){
                            ui->tableWidget->item(i,j)->setBackground(Qt::green);
                        }
                        break;
                    }
                }

                for(int i=row+1, j=column-1;i>=0 && i<8 && j>=0 && j<8;j--, i++){
                    piece=8;
                    if(ui->tableWidget->item(i,j)->text()==""){
                        ui->tableWidget->item(i,j)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(i,j)->text().toInt()<0){
                            ui->tableWidget->item(i,j)->setBackground(Qt::green);
                        }
                        break;
                    }
                }

                for(int i=row-1, j=column+1;i>=0 && i<8 && j>=0 && j<8;j++, i--){
                    piece=8;
                    if(ui->tableWidget->item(i,j)->text()==""){
                        ui->tableWidget->item(i,j)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(i,j)->text().toInt()<0){
                            ui->tableWidget->item(i,j)->setBackground(Qt::green);
                        }
                        break;
                    }
                }

                for(int i=row-1, j=column-1;i>=0 && i<8 && j>=0 && j<8;i--, j--){
                    piece=8;
                    if(ui->tableWidget->item(i,j)->text()==""){
                        ui->tableWidget->item(i,j)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(i,j)->text().toInt()<0){
                            ui->tableWidget->item(i,j)->setBackground(Qt::green);
                        }
                        break;
                    }
                }


            }
            else{
                piece=0;
            }

            ColumnOld=column;
            RowOld=row;

        }
    }
}
