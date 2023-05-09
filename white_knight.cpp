#include "white_knight.h"

White_knight::White_knight()
{

}



void White_knight::step_1(Ui::Game* ui, const int &row, const int &column)
{
    if((row+1)<8 && (column+2)<8){
        if(ui->tableWidget->item(row+1,column+2)->text()==""){
            ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row+1,column+2)->text().toInt()<0){
                ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
            }
        }
    }
}




void White_knight::step_2(Ui::Game* ui, const int &row, const int &column)
{
    if((row-1)>=0 && (column+2)<8){
        if(ui->tableWidget->item(row-1,column+2)->text()==""){
            ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row-1,column+2)->text().toInt()<0){
                ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
            }
        }
    }
}



void White_knight::step_3(Ui::Game* ui, const int &row, const int &column)
{
    if((row+1)<8 && (column-2)>=0){
        if(ui->tableWidget->item(row+1,column-2)->text()==""){
            ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row+1,column-2)->text().toInt()<0){
                ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
            }
        }
    }
}




void White_knight::step_4(Ui::Game* ui, const int &row, const int &column)
{
    if((row-1)>=0 && (column-2)>=0){
        if(ui->tableWidget->item(row-1,column-2)->text()==""){
            ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row-1,column-2)->text().toInt()<0){
                ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
            }
        }
    }
}


void White_knight::step_5(Ui::Game* ui, const int &row, const int &column)
{
    if((row+2)<8 && (column+1)<8){
        if(ui->tableWidget->item(row+2,column+1)->text()==""){
            ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row+2,column+1)->text().toInt()<0){
                ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
            }
        }
    }
}


void White_knight::step_6(Ui::Game* ui, const int &row, const int &column)
{
    if((row-2)>=0 && (column+1)<8){
        if(ui->tableWidget->item(row-2,column+1)->text()==""){
            ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row-2,column+1)->text().toInt()<0){
                ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
            }
        }
    }
}



void White_knight::step_7(Ui::Game* ui, const int &row, const int &column)
{
    if((row+2)<8 && (column-1)>=0){
        if(ui->tableWidget->item(row+2,column-1)->text()==""){
            ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row+2,column-1)->text().toInt()<0){
                ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
            }
        }
    }
}



void White_knight::step_8(Ui::Game* ui, const int &row, const int &column)
{
    if((row-2)>=0 && (column-1)>=0){
        if(ui->tableWidget->item(row-2,column-1)->text()==""){
            ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row-2,column-1)->text().toInt()<0){
                ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
            }
        }
    }
}




void White_knight::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    White_rook white_rook;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(4)));
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="4"){

            white_rook.green_cell_disappear(ui);

            if(piece==0){
                Check check;

                if(check.step_white_knight_check(ui,row,column)){
                    step_1(ui,row,column);
                    step_2(ui,row,column);
                    step_3(ui,row,column);
                    step_4(ui,row,column);
                    step_5(ui,row,column);
                    step_6(ui,row,column);
                    step_7(ui,row,column);
                    step_8(ui,row,column);
                    piece=4;
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




void White_knight::check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn,const int &AttackerRow, const int &AttackerColumn, int &BlackOrWhite,const int &king_row,const int &king_column)
{
    White_rook white_rook;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(4)));
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="4"){

            white_rook.green_cell_disappear(ui);

            if(piece==0){
                Check check;

                if(check.step_white_knight_check(ui,row,column)){
                    step_1(ui,row,column);
                    step_2(ui,row,column);
                    step_3(ui,row,column);
                    step_4(ui,row,column);
                    step_5(ui,row,column);
                    step_6(ui,row,column);
                    step_7(ui,row,column);
                    step_8(ui,row,column);
                    piece=4;
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



