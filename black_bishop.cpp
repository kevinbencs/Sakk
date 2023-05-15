#include "black_bishop.h"

Black_bishop::Black_bishop()
{

}

void Black_bishop::step_down(Ui::Game* ui, const int &row, const int &column)
{
    if(row!=7){
        if(ui->tableWidget->item(row+1,column)->text()==""){
            ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
            if(row==1 && ui->tableWidget->item(row+2,column)->text()==""){
                ui->tableWidget->item(row+2,column)->setBackground(Qt::green);
            }
        }
    }

}


void Black_bishop::step_down_right(Ui::Game* ui, const int &row, const int &column)
{
    if(column!=7 && row!=7){
        if(ui->tableWidget->item(row+1,column+1)->text().toInt()<0){
            ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
        }
    }
}




void Black_bishop::step_down_left(Ui::Game* ui, const int &row, const int &column)
{
    if(column!=0 && row!=7){
        if(ui->tableWidget->item(row+1,column-1)->text().toInt()<0){
            ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
        }
    }
}


void Black_bishop::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));
        if(row==7){
            ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-8)));
        }
        else{
            ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-1)));
        }

        check.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="-1"){

            check.green_cell_disappear(ui);

            if(piece==0){
                piece=-1;
                if(check.step_black_up_and_down_check(ui,row,column)){
                    step_down(ui, row, column);
                }
                if(check.step_black_left_up_and_right_down_check(ui,row,column)){
                    step_down_right(ui, row, column);
                }
                if(check.step_black_right_up_and_left_down_check(ui,row,column)){
                    step_down_left(ui, row, column);
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


void Black_bishop::check_step_move(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow)
{
    Check check;
    if(check.step_black_left_up_and_right_down_check(ui,row,column)){
        if(row+1==AttackerRow && AttackerColumn==column+1){
            ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
        }
    }
    if(check.step_black_right_up_and_left_down_check(ui,row,column)){
        if(AttackerRow==row+1 && AttackerColumn==column-1){
            ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
        }
    }
}



void Black_bishop::check_step_move(Ui::Game* ui, const int &row, const int &column, std::vector<std::pair<int,int>> v, const int &AttackerColumn, const int &AttackerRow)
{
    Check check;
    if(check.step_black_up_and_down_check(ui,row,column)){
        for(int i=0;i<v.size();i++){
            if(v[i].first==row+1 && v[i].second==column){
                ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
            }
            if(row==6 && v[i].first==row+2 && v[i].second==column){
                ui->tableWidget->item(row+2,column)->setBackground(Qt::green);
            }
        }
    }
    check_step_move(ui,row,column,AttackerColumn,AttackerRow);
}



void Black_bishop::row_equal_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
{
    std::vector<std::pair<int,int>> v;

    if(king_column>AttackerColumn){
        for(int i=AttackerColumn;i<king_column;i++){
            v.push_back(std::make_pair(king_row,i));
        }
    }
    else{
        for(int i=AttackerColumn;i>king_column;i--){
            v.push_back(std::make_pair(king_row,i));
        }
    }

    check_step_move(ui,row,column,v,AttackerColumn,king_row);
}



void Black_bishop::dialog_left_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow);
}




void Black_bishop::dialog_right_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow);
}




void Black_bishop::dialog_left_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow);
}



void Black_bishop::dialog_right_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow);
}





void Black_bishop::check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));
        if(row==7){
            ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-8)));
        }
        else{
            ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-1)));
        }

        check.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="-1"){

            check.green_cell_disappear(ui);

            if(piece==0){
                piece=-1;
                //column
                if(king_column==AttackerColumn){
                    check_step_move(ui,row,column,king_column,AttackerRow);
                }
                //row
                if(king_row==AttackerRow){
                    row_equal_check_step(ui,row,column,king_column,king_row,AttackerColumn);
                }
                //dialog
                if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                    dialog_left_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                }

                if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                    dialog_right_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                }

                if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                    dialog_right_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                }

                if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                    dialog_left_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                }
            }
            else{
                piece=0;
            }


            OldColumn=column;
            OldRow=row;

        }
    }
}






void Black_bishop::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));
        if(row==7){
            ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-8)));
        }
        else{
            ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-1)));
        }

        check.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="-1"){

            check.green_cell_disappear(ui);

            if(piece==0){
                piece=-1;
                check_step_move(ui,row,column,AttackerColumn,AttackerRow);
            }
            else{
                piece=0;
            }

            OldColumn=column;
            OldRow=row;

        }
    }
}
