#include "white_knight.h"
#include <QImage>

White_knight::White_knight()
{

}



void White_knight::step_1(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row+1)<8 && (column+2)<8){
        if(*(datas+(row+1)*8+column+2)==0){
            ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row+1)*8+column+2)<0){
                ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
            }
        }
    }
}




void White_knight::step_2(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row-1)>=0 && (column+2)<8){
        if(*(datas+(row-1)*8+column+2)==0){
            ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row-1)*8+column+2)<0){
                ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
            }
        }
    }
}



void White_knight::step_3(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row+1)<8 && (column-2)>=0){
        if(*(datas+(row+1)*8+column-2)==0){
            ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row+1)*8+column-2)<0){
                ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
            }
        }
    }
}




void White_knight::step_4(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row-1)>=0 && (column-2)>=0){
        if(*(datas+(row-1)*8+column-2)==0){
            ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row-1)*8+column-2)<0){
                ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
            }
        }
    }
}


void White_knight::step_5(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row+2)<8 && (column+1)<8){
        if(*(datas+(row+2)*8+column+1)==0){
            ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row+2)*8+column+1)<0){
                ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
            }
        }
    }
}


void White_knight::step_6(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row-2)>=0 && (column+1)<8){
        if(*(datas+(row-2)*8+column+1)==0){
            ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row-2)*8+column+1)<0){
                ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
            }
        }
    }
}



void White_knight::step_7(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row+2)<8 && (column-1)>=0){
        if(*(datas+(row+2)*8+column-1)==0){
            ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row+2)*8+column-1)<0){
                ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
            }
        }
    }
}



void White_knight::step_8(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if((row-2)>=0 && (column-1)>=0){
        if(*(datas+(row-2)*8+column-1)==0){
            ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row-2)*8+column-1)<0){
                ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
            }
        }
    }
}




void White_knight::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        QImage* img=new QImage("Gui/white_knight.png");
        QTableWidgetItem* picture=new QTableWidgetItem;
        picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img).scaled(70,70));

        ui->tableWidget->setItem(row,column,picture);
        datas[RowOld*8+ColumnOld]=0;
        datas[row*8+column]=4;

        check.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=4;

            if(check.step_white_knight_check(datas,row,column)){
                step_1(ui,row,column,datas);
                step_2(ui,row,column,datas);
                step_3(ui,row,column,datas);
                step_4(ui,row,column,datas);
                step_5(ui,row,column,datas);
                step_6(ui,row,column,datas);
                step_7(ui,row,column,datas);
                step_8(ui,row,column,datas);
            }

        }
        else{
            piece=0;
        }

        ColumnOld=column;
        RowOld=row;
    }
}





void White_knight::step_1_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row+1)<8 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column+2)==v[i].second){
                if(*(datas+(row+1)*8+column+2)==0){
                    ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row+1)*8+column+2)<0){
                        ui->tableWidget->item(row+1,column+2)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}





void White_knight::step_2_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row-1)>=0 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column+2)==v[i].second){
                if(*(datas+(row-1)*8+column+2)==0){
                    ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row-1)*8+column+2)<0){
                        ui->tableWidget->item(row-1,column+2)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}





void White_knight::step_3_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row+1)<8 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column-2)==v[i].second){
                if(*(datas+(row+1)*8+column-2)==0){
                    ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row+1)*8+column-2)<0){
                        ui->tableWidget->item(row+1,column-2)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}



void White_knight::step_4_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row-1)>=0 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column-2)==v[i].second){
                if(*(datas+(row-1)*8+column-2)==0){
                    ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row-1)*8+column-2)<0){
                        ui->tableWidget->item(row-1,column-2)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}




void White_knight::step_5_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row+2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column+1)==v[i].second){
                if(*(datas+(row+2)*8+column+1)==0){
                    ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row+2)*8+column+1)<0){
                        ui->tableWidget->item(row+2,column+1)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}




void White_knight::step_6_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row-2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column+1)==v[i].second){
                if(*(datas+(row-2)*8+column+1)==0){
                    ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row-2)*8+column+1)<0){
                        ui->tableWidget->item(row-2,column+1)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}





void White_knight::step_7_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row+2)<8 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column-1)==v[i].second){
                if(*(datas+(row+2)*8+column-1)==0){
                    ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row+2)*8+column-1)<0){
                        ui->tableWidget->item(row+2,column-1)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}




void White_knight::step_8_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    if((row-2)>=0 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column-1)==v[i].second){
                if(*(datas+(row-2)*8+column-1)==0){
                    ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
                }
                else{
                    if(*(datas+(row-2)*8+column-1)<0){
                        ui->tableWidget->item(row-2,column-1)->setBackground(Qt::green);
                    }
                }
            }
        }
    }
}


void White_knight::column_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas)
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

    step_1_check(ui,row,column,v,datas);
    step_2_check(ui,row,column,v,datas);
    step_3_check(ui,row,column,v,datas);
    step_4_check(ui,row,column,v,datas);
    step_5_check(ui,row,column,v,datas);
    step_6_check(ui,row,column,v,datas);
    step_7_check(ui,row,column,v,datas);
    step_8_check(ui,row,column,v,datas);
}




void White_knight::row_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,int *datas)
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

    step_1_check(ui,row,column,v,datas);
    step_2_check(ui,row,column,v,datas);
    step_3_check(ui,row,column,v,datas);
    step_4_check(ui,row,column,v,datas);
    step_5_check(ui,row,column,v,datas);
    step_6_check(ui,row,column,v,datas);
    step_7_check(ui,row,column,v,datas);
    step_8_check(ui,row,column,v,datas);
}



void White_knight::dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v,datas);
    step_2_check(ui,row,column,v,datas);
    step_3_check(ui,row,column,v,datas);
    step_4_check(ui,row,column,v,datas);
    step_5_check(ui,row,column,v,datas);
    step_6_check(ui,row,column,v,datas);
    step_7_check(ui,row,column,v,datas);
    step_8_check(ui,row,column,v,datas);
}


void White_knight::dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v,datas);
    step_2_check(ui,row,column,v,datas);
    step_3_check(ui,row,column,v,datas);
    step_4_check(ui,row,column,v,datas);
    step_5_check(ui,row,column,v,datas);
    step_6_check(ui,row,column,v,datas);
    step_7_check(ui,row,column,v,datas);
    step_8_check(ui,row,column,v,datas);
}




void White_knight::dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v,datas);
    step_2_check(ui,row,column,v,datas);
    step_3_check(ui,row,column,v,datas);
    step_4_check(ui,row,column,v,datas);
    step_5_check(ui,row,column,v,datas);
    step_6_check(ui,row,column,v,datas);
    step_7_check(ui,row,column,v,datas);
    step_8_check(ui,row,column,v,datas);
}




void White_knight::dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(ui,row,column,v,datas);
    step_2_check(ui,row,column,v,datas);
    step_3_check(ui,row,column,v,datas);
    step_4_check(ui,row,column,v,datas);
    step_5_check(ui,row,column,v,datas);
    step_6_check(ui,row,column,v,datas);
    step_7_check(ui,row,column,v,datas);
    step_8_check(ui,row,column,v,datas);
}






void White_knight::check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn,const int &AttackerRow, const int &AttackerColumn, int &BlackOrWhite,const int &king_row,const int &king_column,int *datas)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){

        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        QImage* img=new QImage("Gui/white_knight.png");
        QTableWidgetItem* picture=new QTableWidgetItem;
        picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img).scaled(70,70));

        ui->tableWidget->setItem(row,column,picture);
        datas[OldRow*8+OldColumn]=0;
        datas[row*8+column]=4;

        check.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){

            if(check.step_white_knight_check(datas,row,column)){
                //column
                if(king_column==AttackerColumn){
                    column_equal_check_step(ui,row, column, king_column, king_row,AttackerRow,datas);
                }

                //row
                if(king_row==AttackerRow){
                    row_equal_check_step(ui,row, column, king_column, king_row,AttackerColumn,datas);
                }

                //dialog
                if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                    dialog_left_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
                }

                if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                    dialog_right_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
                }

                if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                    dialog_right_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
                }

                if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                    dialog_left_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
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

void White_knight::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int *datas)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        QImage* img=new QImage("Gui/white_knight.png");
        QTableWidgetItem* picture=new QTableWidgetItem;
        picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img).scaled(70,70));

        ui->tableWidget->setItem(row,column,picture);
        datas[OldRow*8+OldColumn]=0;
        datas[row*8+column]=4;

        check.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){

            if(check.step_white_knight_check(datas,row,column)){
                std::vector<std::pair<int,int>> v;
                v.push_back(std::make_pair(AttackerRow,AttackerColumn));

                step_1_check(ui,row,column,v,datas);
                step_2_check(ui,row,column,v,datas);
                step_3_check(ui,row,column,v,datas);
                step_4_check(ui,row,column,v,datas);
                step_5_check(ui,row,column,v,datas);
                step_6_check(ui,row,column,v,datas);
                step_7_check(ui,row,column,v,datas);
                step_8_check(ui,row,column,v,datas);

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









void White_knight::step_1_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row+1)<8 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column+2)==v[i].second){
                if(*(datas+(row+1)*8+column+2)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row+1)*8+column+2)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}





void White_knight::step_2_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row-1)>=0 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column+2)==v[i].second){
                if(*(datas+(row-1)*8+column+2)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row-1)*8+column+2)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}





void White_knight::step_3_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row+1)<8 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column-2)==v[i].second){
                if(*(datas+(row+1)*8+column-2)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row+1)*8+column-2)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}



void White_knight::step_4_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row-1)>=0 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column-2)==v[i].second){
                if(*(datas+(row-1)*8+column-2)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row-1)*8+column-2)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}




void White_knight::step_5_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row+2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column+1)==v[i].second){
                if(*(datas+(row+2)*8+column+1)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row+2)*8+column+1)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}




void White_knight::step_6_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row-2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column+1)==v[i].second){
                if(*(datas+(row-2)*8+column+1)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row-2)*8+column+1)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}





void White_knight::step_7_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row+2)<8 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column-1)==v[i].second){
                if(*(datas+(row+2)*8+column-1)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row+2)*8+column-1)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}




void White_knight::step_8_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    if((row-2)>=0 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column-1)==v[i].second){
                if(*(datas+(row-2)*8+column-1)==0){
                    CanMove=true;
                }
                else{
                    if(*(datas+(row-2)*8+column-1)<0){
                        CanMove=true;
                    }
                }
            }
        }
    }
}


void White_knight::column_equal_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove)
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

    step_1_check(datas,row,column,v,CanMove);
    step_2_check(datas,row,column,v,CanMove);
    step_3_check(datas,row,column,v,CanMove);
    step_4_check(datas,row,column,v,CanMove);
    step_5_check(datas,row,column,v,CanMove);
    step_6_check(datas,row,column,v,CanMove);
    step_7_check(datas,row,column,v,CanMove);
    step_8_check(datas,row,column,v,CanMove);
}




void White_knight::row_equal_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,bool &CanMove)
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

    step_1_check(datas,row,column,v,CanMove);
    step_2_check(datas,row,column,v,CanMove);
    step_3_check(datas,row,column,v,CanMove);
    step_4_check(datas,row,column,v,CanMove);
    step_5_check(datas,row,column,v,CanMove);
    step_6_check(datas,row,column,v,CanMove);
    step_7_check(datas,row,column,v,CanMove);
    step_8_check(datas,row,column,v,CanMove);
}



void White_knight::dialog_right_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(datas,row,column,v,CanMove);
    step_2_check(datas,row,column,v,CanMove);
    step_3_check(datas,row,column,v,CanMove);
    step_4_check(datas,row,column,v,CanMove);
    step_5_check(datas,row,column,v,CanMove);
    step_6_check(datas,row,column,v,CanMove);
    step_7_check(datas,row,column,v,CanMove);
    step_8_check(datas,row,column,v,CanMove);
}


void White_knight::dialog_left_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(datas,row,column,v,CanMove);
    step_2_check(datas,row,column,v,CanMove);
    step_3_check(datas,row,column,v,CanMove);
    step_4_check(datas,row,column,v,CanMove);
    step_5_check(datas,row,column,v,CanMove);
    step_6_check(datas,row,column,v,CanMove);
    step_7_check(datas,row,column,v,CanMove);
    step_8_check(datas,row,column,v,CanMove);
}




void White_knight::dialog_right_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(datas,row,column,v,CanMove);
    step_2_check(datas,row,column,v,CanMove);
    step_3_check(datas,row,column,v,CanMove);
    step_4_check(datas,row,column,v,CanMove);
    step_5_check(datas,row,column,v,CanMove);
    step_6_check(datas,row,column,v,CanMove);
    step_7_check(datas,row,column,v,CanMove);
    step_8_check(datas,row,column,v,CanMove);
}




void White_knight::dialog_left_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check(datas,row,column,v,CanMove);
    step_2_check(datas,row,column,v,CanMove);
    step_3_check(datas,row,column,v,CanMove);
    step_4_check(datas,row,column,v,CanMove);
    step_5_check(datas,row,column,v,CanMove);
    step_6_check(datas,row,column,v,CanMove);
    step_7_check(datas,row,column,v,CanMove);
    step_8_check(datas,row,column,v,CanMove);
}







bool White_knight::get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop)
{
    Check check;
    int row, column,king_row,king_column;
    bool CanMove=false;;
    if(KnightBishop==0){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==4){
                    row=i;
                    column=j;

                    for(int f=0;f<8;f++){
                        for(int l=0;l<8;l++){
                            if(*(datas+f*8+l)==10){
                                king_column=l;
                                king_row=f;
                            }
                        }
                    }

                    if(check.step_white_knight_check(datas,row,column)){
                        //column
                        if(king_column==AttackerColumn){
                            column_equal_check_step(datas,row, column, king_column, king_row,AttackerRow,CanMove);
                        }

                        //row
                        if(king_row==AttackerRow){
                            row_equal_check_step(datas,row, column, king_column, king_row,AttackerColumn,CanMove);
                        }

                        //dialog
                        if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                            dialog_left_up(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        }

                        if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                            dialog_right_down(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        }

                        if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                            dialog_right_up(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        }

                        if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                            dialog_left_down(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        }


                    }


                }
            }
        }
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==4){
                    row=i;
                    column=j;

                    if(check.step_white_knight_check(datas,row,column)){
                        std::vector<std::pair<int,int>> v;
                        v.push_back(std::make_pair(AttackerRow,AttackerColumn));

                        step_1_check(datas,row,column,v,CanMove);
                        step_2_check(datas,row,column,v,CanMove);
                        step_3_check(datas,row,column,v,CanMove);
                        step_4_check(datas,row,column,v,CanMove);
                        step_5_check(datas,row,column,v,CanMove);
                        step_6_check(datas,row,column,v,CanMove);
                        step_7_check(datas,row,column,v,CanMove);
                        step_8_check(datas,row,column,v,CanMove);

                    }
                }
            }
        }


    }

    return CanMove;
}







void White_knight::step_1(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row+1)<8 && (column+2)<8){
        if(*(datas+(row+1)*8+column+2)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+1)*8+column+2)<0){
                CanMove=true;
            }
        }
    }
}




void White_knight::step_2(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row-1)>=0 && (column+2)<8){
        if(*(datas+(row-1)*8+column+2)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-1)*8+column+2)<0){
                CanMove=true;
            }
        }
    }
}



void White_knight::step_3(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row+1)<8 && (column-2)>=0){
        if(*(datas+(row+1)*8+column-2)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+1)*8+column-2)<0){
                CanMove=true;
            }
        }
    }
}




void White_knight::step_4(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row-1)>=0 && (column-2)>=0){
        if(*(datas+(row-1)*8+column-2)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-1)*8+column-2)<0){
                CanMove=true;
            }
        }
    }
}


void White_knight::step_5(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row+2)<8 && (column+1)<8){
        if(*(datas+(row+2)*8+column+1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+2)*8+column+1)<0){
                CanMove=true;
            }
        }
    }
}


void White_knight::step_6(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row-2)>=0 && (column+1)<8){
        if(*(datas+(row-2)*8+column+1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-2)*8+column+1)<0){
                CanMove=true;
            }
        }
    }
}



void White_knight::step_7(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row+2)<8 && (column-1)>=0){
        if(*(datas+(row+2)*8+column-1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+2)*8+column-1)<0){
                CanMove=true;
            }
        }
    }
}



void White_knight::step_8(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row-2)>=0 && (column-1)>=0){
        if(*(datas+(row-2)*8+column-1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-2)*8+column-1)<0){
                CanMove=true;
            }
        }
    }
}





bool White_knight::get_draw_CanMove(int *datas)
{
    Check check;
    int row, column;
    bool CanMove=false;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(*(datas+i*8+j)==4){
                row=i;
                column=j;

                if(check.step_white_knight_check(datas,row,column)){
                    step_1(datas,row,column,CanMove);
                    step_2(datas,row,column,CanMove);
                    step_3(datas,row,column,CanMove);
                    step_4(datas,row,column,CanMove);
                    step_5(datas,row,column,CanMove);
                    step_6(datas,row,column,CanMove);
                    step_7(datas,row,column,CanMove);
                    step_8(datas,row,column,CanMove);
                }

            }
        }
    }

    return CanMove;
}






void White_knight::step_1_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+1)<8 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column+2)==v[i].second){
                if(*(datas+(row+1)*8+column+2)==0){
                    std::vector<int> f;
                    f.push_back(row+1);
                    f.push_back(column+2);
                    if(check.check_check(datas,row+1,column+2,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row+1)*8+column+2)<0){
                        std::vector<int> f;
                        f.push_back(row+1);
                        f.push_back(column+2);
                        if(check.check_check(datas,row+1,column+2,4,row,column)){
                            point+=100;
                        }
                        point+=check.occupying_an_black_piece(datas,row+1,column+2);
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}





void White_knight::step_2_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-1)>=0 && (column+2)<8){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column+2)==v[i].second){
                if(*(datas+(row-1)*8+column+2)==0){
                    std::vector<int> f;
                    f.push_back(row-1);
                    f.push_back(column+2);
                    if(check.check_check(datas,row-1,column+2,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row-1)*8+column+2)<0){
                        std::vector<int> f;
                        f.push_back(row-1);
                        f.push_back(column+2);
                        if(check.check_check(datas,row-1,column+2,4,row,column)){
                            point+=100;
                        }
                        point+=check.occupying_an_black_piece(datas,row-1,column+2);
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}





void White_knight::step_3_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+1)<8 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row+1)==v[i].first && (column-2)==v[i].second){
                if(*(datas+(row+1)*8+column-2)==0){
                    std::vector<int> f;
                    f.push_back(row+1);
                    f.push_back(column-2);
                    if(check.check_check(datas,row-1,column-2,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row+1)*8+column-2)<0){
                        std::vector<int> f;
                        f.push_back(row+1);
                        f.push_back(column-2);
                        if(check.check_check(datas,row-1,column-2,4,row,column)){
                            point+=100;
                        }
                        point+=check.occupying_an_black_piece(datas,row+1,column-2);
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}



void White_knight::step_4_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-1)>=0 && (column-2)>=0){
        for(int i=0;i<v.size();i++){
            if((row-1)==v[i].first && (column-2)==v[i].second){
                if(*(datas+(row-1)*8+column-2)==0){
                    std::vector<int> f;
                    f.push_back(row-1);
                    f.push_back(column-2);
                    if(check.check_check(datas,row-1,column-2,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row-1)*8+column-2)<0){
                        std::vector<int> f;
                        f.push_back(row-1);
                        f.push_back(column-2);
                        point+=check.occupying_an_black_piece(datas,row-1,column-2);
                        if(check.check_check(datas,row-1,column-2,4,row,column)){
                            point+=100;
                        }
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}




void White_knight::step_5_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column+1)==v[i].second){
                if(*(datas+(row+2)*8+column+1)==0){
                    std::vector<int> f;
                    f.push_back(row+2);
                    f.push_back(column+1);
                    if(check.check_check(datas,row+2,column+1,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row+2)*8+column+1)<0){
                        std::vector<int> f;
                        f.push_back(row+2);
                        f.push_back(column+1);
                        if(check.check_check(datas,row+2,column+1,4,row,column)){
                            point+=100;
                        }
                        point+=check.occupying_an_black_piece(datas,row+2,column+1);
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}




void White_knight::step_6_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-2)<8 && (column+1)<8){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column+1)==v[i].second){
                if(*(datas+(row-2)*8+column+1)==0){
                    std::vector<int> f;
                    f.push_back(row-2);
                    f.push_back(column+1);
                    if(check.check_check(datas,row-2,column+1,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row-2)*8+column+1)<0){
                        std::vector<int> f;
                        f.push_back(row-2);
                        f.push_back(column+1);
                        if(check.check_check(datas,row-2,column+1,4,row,column)){
                            point+=100;
                        }
                        point+=check.occupying_an_black_piece(datas,row-2,column+1);
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}





void White_knight::step_7_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+2)<8 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row+2)==v[i].first && (column-1)==v[i].second){
                if(*(datas+(row+2)*8+column-1)==0){
                    std::vector<int> f;
                    f.push_back(row+2);
                    f.push_back(column-1);
                    if(check.check_check(datas,row+2,column-1,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row+2)*8+column-1)<0){
                        std::vector<int> f;
                        f.push_back(row+2);
                        f.push_back(column-1);
                        if(check.check_check(datas,row+2,column-1,4,row,column)){
                            point+=100;
                        }
                        point+=check.occupying_an_black_piece(datas,row+2,column-1);
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}




void White_knight::step_8_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-2)>=0 && (column-1)>=0){
        for(int i=0;i<v.size();i++){
            if((row-2)==v[i].first && (column-1)==v[i].second){
                if(*(datas+(row-2)*8+column-1)==0){
                    std::vector<int> f;
                    f.push_back(row-2);
                    f.push_back(column-1);
                    if(check.check_check(datas,row-2,column-1,4,row,column)){
                        point+=100;
                    }
                    f.push_back(point);
                    MoveAndPoint.push_back(f);
                }
                else{
                    if(*(datas+(row-2)*8+column-1)<0){
                        std::vector<int> f;
                        f.push_back(row-2);
                        f.push_back(column-1);
                        if(check.check_check(datas,row-2,column-1,4,row,column)){
                            point+=100;
                        }
                        point+=check.occupying_an_black_piece(datas,row-2,column-1);
                        f.push_back(point);
                        MoveAndPoint.push_back(f);
                    }
                }
            }
        }
    }
}


void White_knight::column_equal_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
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

    step_1_check_machine(datas,row,column,v,MoveAndPoint);
    step_2_check_machine(datas,row,column,v,MoveAndPoint);
    step_3_check_machine(datas,row,column,v,MoveAndPoint);
    step_4_check_machine(datas,row,column,v,MoveAndPoint);
    step_5_check_machine(datas,row,column,v,MoveAndPoint);
    step_6_check_machine(datas,row,column,v,MoveAndPoint);
    step_7_check_machine(datas,row,column,v,MoveAndPoint);
    step_8_check_machine(datas,row,column,v,MoveAndPoint);
}




void White_knight::row_equal_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
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

    step_1_check_machine(datas,row,column,v,MoveAndPoint);
    step_2_check_machine(datas,row,column,v,MoveAndPoint);
    step_3_check_machine(datas,row,column,v,MoveAndPoint);
    step_4_check_machine(datas,row,column,v,MoveAndPoint);
    step_5_check_machine(datas,row,column,v,MoveAndPoint);
    step_6_check_machine(datas,row,column,v,MoveAndPoint);
    step_7_check_machine(datas,row,column,v,MoveAndPoint);
    step_8_check_machine(datas,row,column,v,MoveAndPoint);
}



void White_knight::dialog_right_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check_machine(datas,row,column,v,MoveAndPoint);
    step_2_check_machine(datas,row,column,v,MoveAndPoint);
    step_3_check_machine(datas,row,column,v,MoveAndPoint);
    step_4_check_machine(datas,row,column,v,MoveAndPoint);
    step_5_check_machine(datas,row,column,v,MoveAndPoint);
    step_6_check_machine(datas,row,column,v,MoveAndPoint);
    step_7_check_machine(datas,row,column,v,MoveAndPoint);
    step_8_check_machine(datas,row,column,v,MoveAndPoint);
}


void White_knight::dialog_left_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check_machine(datas,row,column,v,MoveAndPoint);
    step_2_check_machine(datas,row,column,v,MoveAndPoint);
    step_3_check_machine(datas,row,column,v,MoveAndPoint);
    step_4_check_machine(datas,row,column,v,MoveAndPoint);
    step_5_check_machine(datas,row,column,v,MoveAndPoint);
    step_6_check_machine(datas,row,column,v,MoveAndPoint);
    step_7_check_machine(datas,row,column,v,MoveAndPoint);
    step_8_check_machine(datas,row,column,v,MoveAndPoint);
}




void White_knight::dialog_right_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check_machine(datas,row,column,v,MoveAndPoint);
    step_2_check_machine(datas,row,column,v,MoveAndPoint);
    step_3_check_machine(datas,row,column,v,MoveAndPoint);
    step_4_check_machine(datas,row,column,v,MoveAndPoint);
    step_5_check_machine(datas,row,column,v,MoveAndPoint);
    step_6_check_machine(datas,row,column,v,MoveAndPoint);
    step_7_check_machine(datas,row,column,v,MoveAndPoint);
    step_8_check_machine(datas,row,column,v,MoveAndPoint);
}




void White_knight::dialog_left_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    step_1_check_machine(datas,row,column,v,MoveAndPoint);
    step_2_check_machine(datas,row,column,v,MoveAndPoint);
    step_3_check_machine(datas,row,column,v,MoveAndPoint);
    step_4_check_machine(datas,row,column,v,MoveAndPoint);
    step_5_check_machine(datas,row,column,v,MoveAndPoint);
    step_6_check_machine(datas,row,column,v,MoveAndPoint);
    step_7_check_machine(datas,row,column,v,MoveAndPoint);
    step_8_check_machine(datas,row,column,v,MoveAndPoint);
}







void White_knight::step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop,std::vector<std::vector<int>> &MoveAndPoint,const int &row,const int &column)
{
    Check check;
    int king_row,king_column;
    if(KnightBishop==0){
        for(int f=0;f<8;f++){
            for(int l=0;l<8;l++){
                if(*(datas+f*8+l)==-10){
                    king_column=l;
                    king_row=f;
                }
            }
        }

        if(check.step_white_knight_check(datas,row,column)){
            //column
            if(king_column==AttackerColumn){
                column_equal_check_step_machine(datas,row, column, king_column, king_row,AttackerRow,MoveAndPoint);
            }

            //row
            if(king_row==AttackerRow){
                row_equal_check_step_machine(datas,row, column, king_column, king_row,AttackerColumn,MoveAndPoint);
            }

            //dialog
            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                dialog_left_up_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            }

            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                dialog_right_down_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            }

            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                dialog_right_up_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            }

            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                dialog_left_down_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            }
        }
    }
    else{
        if(check.step_white_knight_check(datas,row,column)){
            std::vector<std::pair<int,int>> v;
            v.push_back(std::make_pair(AttackerRow,AttackerColumn));

            step_1_check_machine(datas,row,column,v,MoveAndPoint);
            step_2_check_machine(datas,row,column,v,MoveAndPoint);
            step_3_check_machine(datas,row,column,v,MoveAndPoint);
            step_4_check_machine(datas,row,column,v,MoveAndPoint);
            step_5_check_machine(datas,row,column,v,MoveAndPoint);
            step_6_check_machine(datas,row,column,v,MoveAndPoint);
            step_7_check_machine(datas,row,column,v,MoveAndPoint);
            step_8_check_machine(datas,row,column,v,MoveAndPoint);
        }
    }
}







void White_knight::step_1_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+1)<8 && (column+2)<8){
        if(*(datas+(row+1)*8+column+2)==0){
            std::vector<int> f;
            f.push_back(row+1);
            f.push_back(column+2);
            if(check.check_check(datas,row+1,column+2,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row+1)*8+column+2)<0){
                std::vector<int> f;
                f.push_back(row+1);
                f.push_back(column+2);
                if(check.check_check(datas,row+1,column+2,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row+1,column+2);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}




void White_knight::step_2_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-1)>=0 && (column+2)<8){
        if(*(datas+(row-1)*8+column+2)==0){
            std::vector<int> f;
            f.push_back(row-1);
            f.push_back(column+2);
            if(check.check_check(datas,row-1,column+2,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row-1)*8+column+2)<0){
                std::vector<int> f;
                f.push_back(row-1);
                f.push_back(column+2);
                if(check.check_check(datas,row-1,column+2,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row-1,column+2);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}



void White_knight::step_3_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+1)<8 && (column-2)>=0){
        if(*(datas+(row+1)*8+column-2)==0){
            std::vector<int> f;
            f.push_back(row+1);
            f.push_back(column-2);
            if(check.check_check(datas,row+1,column-2,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row+1)*8+column-2)<0){
                std::vector<int> f;
                f.push_back(row+1);
                f.push_back(column-2);
                if(check.check_check(datas,row+1,column-2,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row+1,column-2);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}




void White_knight::step_4_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-1)>=0 && (column-2)>=0){
        if(*(datas+(row-1)*8+column-2)==0){
            std::vector<int> f;
            f.push_back(row-1);
            f.push_back(column-2);
            if(check.check_check(datas,row-1,column-2,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row-1)*8+column-2)<0){
                std::vector<int> f;
                f.push_back(row-1);
                f.push_back(column-2);
                if(check.check_check(datas,row-1,column-2,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row-1,column-2);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}


void White_knight::step_5_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+2)<8 && (column+1)<8){
        if(*(datas+(row+2)*8+column+1)==0){
            std::vector<int> f;
            f.push_back(row+2);
            f.push_back(column+1);
            if(check.check_check(datas,row+2,column+1,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row+2)*8+column+1)<0){
                std::vector<int> f;
                f.push_back(row+2);
                f.push_back(column+1);
                if(check.check_check(datas,row+2,column+1,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row+2,column+1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}


void White_knight::step_6_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-2)>=0 && (column+1)<8){
        if(*(datas+(row-2)*8+column+1)==0){
            std::vector<int> f;
            f.push_back(row-2);
            f.push_back(column+1);
            if(check.check_check(datas,row-2,column+1,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row-2)*8+column+1)<0){
                std::vector<int> f;
                f.push_back(row-2);
                f.push_back(column+1);
                if(check.check_check(datas,row-2,column+1,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row-2,column+1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}



void White_knight::step_7_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+2)<8 && (column-1)>=0){
        if(*(datas+(row+2)*8+column-1)==0){
            std::vector<int> f;
            f.push_back(row+2);
            f.push_back(column-1);
            if(check.check_check(datas,row+2,column-1,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row+2)*8+column-1)<0){
                std::vector<int> f;
                f.push_back(row+2);
                f.push_back(column-1);
                if(check.check_check(datas,row+2,column-1,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row+2,column-1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}



void White_knight::step_8_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-2)>=0 && (column-1)>=0){
        if(*(datas+(row-2)*8+column-1)==0){
            std::vector<int> f;
            f.push_back(row-2);
            f.push_back(column-1);
            if(check.check_check(datas,row-2,column-1,4,row,column)){
                point+=100;
            }
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row-2)*8+column-1)<0){
                std::vector<int> f;
                f.push_back(row-2);
                f.push_back(column-1);
                if(check.check_check(datas,row-2,column-1,4,row,column)){
                    point+=100;
                }
                point+=check.occupying_an_black_piece(datas,row-2,column-1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}





void White_knight::step_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(check.step_white_knight_check(datas,row,column)){
        step_1_machine(datas,row,column,MoveAndPoint);
        step_2_machine(datas,row,column,MoveAndPoint);
        step_3_machine(datas,row,column,MoveAndPoint);
        step_4_machine(datas,row,column,MoveAndPoint);
        step_5_machine(datas,row,column,MoveAndPoint);
        step_6_machine(datas,row,column,MoveAndPoint);
        step_7_machine(datas,row,column,MoveAndPoint);
        step_8_machine(datas,row,column,MoveAndPoint);
    }
}



