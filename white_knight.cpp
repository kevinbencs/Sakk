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
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(4)));
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        check.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="4"){

            check.green_cell_disappear(ui);

            if(piece==0){

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





void White_knight::step_1_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row+1)<8 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column+2)==v[i].second){
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
    }
}





void White_knight::step_2_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row-1)>=0 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column+2)==v[i].second){
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
    }
}





void White_knight::step_3_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row+1)<8 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column-2)==v[i].second){
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
    }
}



void White_knight::step_4_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row-1)>=0 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column-2)==v[i].second){
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
    }
}




void White_knight::step_5_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row+2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column+1)==v[i].second){
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
    }
}




void White_knight::step_6_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row-2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column+1)==v[i].second){
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
    }
}





void White_knight::step_7_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row+2)<8 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column-1)==v[i].second){
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
    }
}




void White_knight::step_8_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    if((row-2)>=0 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column-1)==v[i].second){
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
    }
}


void White_knight::column_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    if(king_row>AttackerRow){
        for(int i=king_row;i>=AttackerRow;i--){
            v.push_back(std::make_pair(i,king_column));
        }
    }
    else{
        for(int i=king_row;i<=AttackerRow;i++){
            v.push_back(std::make_pair(i,king_column));
        }
    }

    step_1_check(ui,row,column,v);
    step_2_check(ui,row,column,v);
    step_3_check(ui,row,column,v);
    step_4_check(ui,row,column,v);
    step_5_check(ui,row,column,v);
    step_6_check(ui,row,column,v);
    step_7_check(ui,row,column,v);
    step_8_check(ui,row,column,v);
}




void White_knight::row_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn)
{
    std::vector<std::pair<int,int>> v;

    if(king_column>AttackerColumn){
        for(int i=king_column;i>=AttackerColumn;i--){
            v.push_back(std::make_pair(king_row,i));
        }
    }
    else{
        for(int i=king_column;i<=AttackerColumn;i++){
            v.push_back(std::make_pair(king_row,i));
        }
    }

    step_1_check(ui,row,column,v);
    step_2_check(ui,row,column,v);
    step_3_check(ui,row,column,v);
    step_4_check(ui,row,column,v);
    step_5_check(ui,row,column,v);
    step_6_check(ui,row,column,v);
    step_7_check(ui,row,column,v);
    step_8_check(ui,row,column,v);
}



void White_knight::dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v);
    step_2_check(ui,row,column,v);
    step_3_check(ui,row,column,v);
    step_4_check(ui,row,column,v);
    step_5_check(ui,row,column,v);
    step_6_check(ui,row,column,v);
    step_7_check(ui,row,column,v);
    step_8_check(ui,row,column,v);
}


void White_knight::dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v);
    step_2_check(ui,row,column,v);
    step_3_check(ui,row,column,v);
    step_4_check(ui,row,column,v);
    step_5_check(ui,row,column,v);
    step_6_check(ui,row,column,v);
    step_7_check(ui,row,column,v);
    step_8_check(ui,row,column,v);
}




void White_knight::dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v);
    step_2_check(ui,row,column,v);
    step_3_check(ui,row,column,v);
    step_4_check(ui,row,column,v);
    step_5_check(ui,row,column,v);
    step_6_check(ui,row,column,v);
    step_7_check(ui,row,column,v);
    step_8_check(ui,row,column,v);
}




void White_knight::dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v);
    step_2_check(ui,row,column,v);
    step_3_check(ui,row,column,v);
    step_4_check(ui,row,column,v);
    step_5_check(ui,row,column,v);
    step_6_check(ui,row,column,v);
    step_7_check(ui,row,column,v);
    step_8_check(ui,row,column,v);
}






void White_knight::check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn,const int &AttackerRow, const int &AttackerColumn, int &BlackOrWhite,const int &king_row,const int &king_column)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(4)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        check.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="4"){

            check.green_cell_disappear(ui);

            if(piece==0){

                if(check.step_white_knight_check(ui,row,column)){
                    //column
                    if(king_column==AttackerColumn){
                        column_equal_check_step(ui,row, column, king_column, king_row,AttackerRow);
                    }

                    //row
                    if(king_row==AttackerRow){
                        row_equal_check_step(ui,row, column, king_column, king_row,AttackerColumn);
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

                    piece=4;
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

void White_knight::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite)
{

}
