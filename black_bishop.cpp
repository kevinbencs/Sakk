#include "black_bishop.h"

Black_bishop::Black_bishop()
{

}

void Black_bishop::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-1)));

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
        if(ui->tableWidget->item(row,column)->text()=="-1"){
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

            ColumnOld=column;
            RowOld=row;

            if(piece==0){
                if(ui->tableWidget->item(row+1,column)->text()==""){
                    ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
                    piece=-1;
                    if(ui->tableWidget->item(row+2,column)->text()=="" && row==1){
                        ui->tableWidget->item(row+2,column)->setBackground(Qt::green);
                    }
                }

                if(piece==0){
                    if(ui->tableWidget->item(row+1,column-1)->text().toInt()>0){
                        ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
                        piece=-1;
                    }
                }

                if(piece==8){
                    if(ui->tableWidget->item(row+1,column+1)->text().toInt()>0){
                        ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
                        piece=-1;
                    }
                }

            }
            else{
                piece=0;
            }
        }
    }
}
