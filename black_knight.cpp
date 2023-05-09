#include "black_knight.h"

Black_knight::Black_knight()
{

}

void Black_knight::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-4)));

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
        BlackOrWhite=1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="-4"){

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

                if((row+1)<8 && (column+2)<8){
                    piece=-4;
                    if(ui->tableWidget->item(row+1,column+2)->text()==""){
                        ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row+1,column+2)->text().toInt()>0){
                            ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
                        }
                    }
                }

                if((row-1)>=0 && (column+2)<8){
                    piece=-4;
                    if(ui->tableWidget->item(row-1,column+2)->text()==""){
                        ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row-1,column+2)->text().toInt()>0){
                            ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
                        }
                    }
                }

                if((row+1)<8 && (column-2)>=0){
                    piece=-4;
                    if(ui->tableWidget->item(row+1,column-2)->text()==""){
                        ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row+1,column-2)->text().toInt()>0){
                            ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
                        }
                    }
                }

                if((row-1)>=0 && (column-2)>=0){
                    piece=-4;
                    if(ui->tableWidget->item(row-1,column-2)->text()==""){
                        ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row-1,column-2)->text().toInt()>0){
                            ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
                        }
                    }
                }

                if((row+2)<8 && (column+1)<8){
                    piece=-4;
                    if(ui->tableWidget->item(row+2,column+1)->text()==""){
                        ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row+2,column+1)->text().toInt()>0){
                            ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
                        }
                    }
                }

                if((row-2)>=0 && (column+1)<8){
                    piece=-4;
                    if(ui->tableWidget->item(row-2,column+1)->text()==""){
                        ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row-2,column+1)->text().toInt()>0){
                            ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
                        }
                    }
                }

                if((row+2)<8 && (column-1)>=0){
                    piece=-4;
                    if(ui->tableWidget->item(row+2,column-1)->text()==""){
                        ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row+2,column-1)->text().toInt()>0){
                            ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
                        }
                    }
                }

                if((row-2)>=0 && (column-1)>=0){
                    piece=-4;
                    if(ui->tableWidget->item(row-2,column-1)->text()==""){
                        ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
                    }
                    else{
                        if(ui->tableWidget->item(row-2,column-1)->text().toInt()>0){
                            ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
                        }
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

