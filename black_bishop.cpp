#include "black_bishop.h"

Black_bishop::Black_bishop()
{

}

void Black_bishop::step_down(Ui::Game* ui, const int &row, const int &column, int *datas)
{
    if(row!=7){
        if(*(datas+(row+1)*8+column)==0){
            ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
            if(row==1 && *(datas+(row+2)*8+column)==0){
                ui->tableWidget->item(row+2,column)->setBackground(Qt::green);
            }
        }
    }

}


void Black_bishop::step_down_right(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    if(column!=7 && row!=7){
        if(*(datas+(row+1)*8+column+1)>0){
            ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
        }
    }
}




void Black_bishop::step_down_left(Ui::Game* ui, const int &row, const int &column, int *datas)
{
    if(column!=0 && row!=7){
        if(*(datas+(row+1)*8+column-1)>0){
            ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
        }
    }
}


void Black_bishop::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));
        datas[RowOld*8+ColumnOld]=0;

        if(row==7){
            QImage* img=new QImage("Gui/black_queen.png");

            QTableWidgetItem* picture=new QTableWidgetItem;
            picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
            ui->tableWidget->setItem(row,column,picture);
            datas[row*8+column]=-8;
        }
        else{
            QImage* img=new QImage("Gui/black_bishop.png");

            QTableWidgetItem* picture=new QTableWidgetItem;
            picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
            ui->tableWidget->setItem(row,column,picture);

            datas[row*8+column]=-1;
        }

        check.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=1;
    }
    else{
        if(datas[row*8+column]==-1){

            check.green_cell_disappear(ui);

            if(piece==0){
                piece=-1;
                if(check.step_black_up_and_down_check(datas,row,column)){
                    step_down(ui, row, column,datas);
                }
                if(check.step_black_left_up_and_right_down_check(datas,row,column)){
                    step_down_right(ui, row, column,datas);
                }
                if(check.step_black_right_up_and_left_down_check(datas,row,column)){
                    step_down_left(ui, row, column,datas);
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


void Black_bishop::check_step_move(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow,int* datas)
{
    Check check;
    if(check.step_black_left_up_and_right_down_check(datas,row,column)){
        if(row+1==AttackerRow && AttackerColumn==column+1 && *(datas+(row+1)*8+column+1)>0){
            ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
        }
    }
    if(check.step_black_right_up_and_left_down_check(datas,row,column)){
        if(AttackerRow==row+1 && AttackerColumn==column-1 && *(datas+(row+1)*8+column-1)>0){
            ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
        }
    }
}



void Black_bishop::check_step_move(Ui::Game* ui, const int &row, const int &column, std::vector<std::pair<int,int>> v, const int &AttackerColumn, const int &AttackerRow, int *datas)
{
    Check check;
    if(check.step_black_up_and_down_check(datas,row,column)){
        for(int i=0;i<v.size();i++){
            if(v[i].first==row+1 && v[i].second==column && *(datas+(row+1)*8+column)==0){
                ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
            }
            if(row==1 && v[i].first==row+2 && v[i].second==column && *(datas+(row+2)*8+column)==0){
                ui->tableWidget->item(row+2,column)->setBackground(Qt::green);
            }
        }
    }
    check_step_move(ui,row,column,AttackerColumn,AttackerRow,datas);
}



void Black_bishop::row_equal_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn, int *datas)
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

    check_step_move(ui,row,column,v,AttackerColumn,king_row,datas);
}



void Black_bishop::dialog_left_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn, const int &AttackerRow, int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow,datas);
}




void Black_bishop::dialog_right_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow, int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow,datas);
}




void Black_bishop::dialog_left_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow, int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow,datas);
}



void Black_bishop::dialog_right_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow, int *datas)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(ui,row,column,v,AttackerColumn,AttackerRow,datas);
}





void Black_bishop::check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column, int *datas)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));
        datas[OldRow*8+OldColumn]=0;

        if(row==7){
            QImage* img=new QImage("Gui/black_queen.png");

            QTableWidgetItem* picture=new QTableWidgetItem;
            picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
            ui->tableWidget->setItem(row,column,picture);
            datas[row*8+column]=-8;
        }
        else{
            QImage* img=new QImage("Gui/black_bishop.png");

            QTableWidgetItem* picture=new QTableWidgetItem;
            picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
            ui->tableWidget->setItem(row,column,picture);

            datas[OldRow*8+OldColumn]=-1;
        }

        check.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=-1;
            //column
            if(king_column==AttackerColumn){
                check_step_move(ui,row,column,king_column,AttackerRow,datas);
            }
            //row
            if(king_row==AttackerRow){
                row_equal_check_step(ui,row,column,king_column,king_row,AttackerColumn,datas);
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
        }
        else{
            piece=0;
        }


        OldColumn=column;
        OldRow=row;
    }
}






void Black_bishop::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite, int *datas)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));
        datas[OldRow*8+OldColumn]=0;

        if(row==7){
            QImage* img=new QImage("Gui/black_queen.png");

            QTableWidgetItem* picture=new QTableWidgetItem;
            picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
            ui->tableWidget->setItem(row,column,picture);
            datas[row*8+column]=-8;
        }
        else{
            QImage* img=new QImage("Gui/black_bishop.png");

            QTableWidgetItem* picture=new QTableWidgetItem;
            picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
            ui->tableWidget->setItem(row,column,picture);

            datas[OldRow*8+OldColumn]=-1;
        }

        check.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=-1;
            check_step_move(ui,row,column,AttackerColumn,AttackerRow,datas);
        }
        else{
            piece=0;
        }

        OldColumn=column;
        OldRow=row;
    }
}








void Black_bishop::check_step_move(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow,bool &CanMove)
{
    Check check;
    if(check.step_black_left_up_and_right_down_check(datas,row,column)){
        if(AttackerRow==row+1 && AttackerColumn==column-1 && *(datas+(row+1)*8+column-1)>0){
            CanMove=true;
        }
    }
    if(check.step_black_right_up_and_left_down_check(datas,row,column)){
        if(row+1==AttackerRow && AttackerColumn==column+1 && *(datas+(row+1)*8+column+1)>0){
            CanMove=true;
        }
    }


}



void Black_bishop::check_step_move(int *datas, const int &row, const int &column, std::vector<std::pair<int,int>> v, const int &AttackerColumn, const int &AttackerRow, bool &CanMove)
{
    Check check;
    if(check.step_black_up_and_down_check(datas,row,column)){
        for(int i=0;i<v.size();i++){
            if(v[i].first==row+1 && v[i].second==column && *(datas+(row+1)*8+column)==0){
                CanMove=true;
            }
            if(row==1 && v[i].first==row+2 && v[i].second==column && *(datas+(row+2)*8+column)==0){
                CanMove=true;
            }
        }
    }
    check_step_move(datas,row,column,AttackerColumn,AttackerRow,CanMove);
}



void Black_bishop::row_equal_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,bool &CanMove)
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

    check_step_move(datas,row,column,v,AttackerColumn,king_row,CanMove);
}



void Black_bishop::dialog_left_up(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(datas,row,column,v,AttackerColumn,AttackerRow,CanMove);
}




void Black_bishop::dialog_right_down(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(datas,row,column,v,AttackerColumn,AttackerRow,CanMove);
}




void Black_bishop::dialog_left_down(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(datas,row,column,v,AttackerColumn,AttackerRow,CanMove);
}



void Black_bishop::dialog_right_up(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move(datas,row,column,v,AttackerColumn,AttackerRow,CanMove);
}



bool Black_bishop::get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop)
{
    int row, column,king_row,king_column;
    bool CanMove=false;;
    if(KnightBishop==0){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==-1){
                    row=i;
                    column=j;

                    for(int f=0;f<8;f++){
                        for(int l=0;l<8;l++){
                            if(*(datas+f*8+l)==-10){
                                king_column=l;
                                king_row=f;
                            }
                        }
                    }

                    if(king_column==AttackerColumn){
                        check_step_move(datas,row,column,king_column,AttackerRow,CanMove);
                    }
                    //row
                    if(king_row==AttackerRow){
                        row_equal_check_step(datas,row,column,king_column,king_row,AttackerColumn,CanMove);
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
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==-1){
                    row=i;
                    column=j;

                    check_step_move(datas,row,column,AttackerColumn,AttackerRow,CanMove);
                }
            }
        }


    }

    return CanMove;
}







void Black_bishop::step_down(int *datas, const int &row, const int &column,bool &CanMove)
{
    if(row<8){
        if(*(datas+(row+1)*8+column)==0){
            CanMove=true;
        }
    }
}


void Black_bishop::step_down_right(int* datas, const int &row, const int &column,bool &CanMove)
{
    if(column!=7 && row<8){
        if(*(datas+(row+1)*8+column+1)>0){
            CanMove=true;
        }
    }
}




void Black_bishop::step_down_left(int* datas, const int &row, const int &column,bool &CanMove)
{
    if(column!=0 && row<8){
        if(*(datas+(row+1)*8+column-1)>0){
            CanMove=true;
        }
    }
}





bool Black_bishop::get_draw_CanMove(int* datas)
{
    Check check;
    int row, column;
    bool CanMove=false;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(*(datas+i*8+j)==-1){
                row=i;
                column=j;

                if(check.step_white_up_and_down_check(datas,row,column)){
                    step_down(datas, row, column,CanMove);
                }
                if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                    step_down_left(datas, row, column,CanMove);
                }
                if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                    step_down_right(datas, row, column,CanMove);
                }


            }
        }
    }

    return CanMove;
}


void Black_bishop::step_down_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint)
{
    if(row<8){
        if(*(datas+(row+1)*8+column)==0){
            std::vector<int> v;
            v.push_back(row+1);
            v.push_back(column);
            v.push_back(0);
            MoveAndPoint.push_back(v);
            if(*(datas+(row+2)*8+column)==0 && row==1){
                std::vector<int> f;
                f.push_back(row+2);
                f.push_back(column);
                f.push_back(0);
                MoveAndPoint.push_back(f);
            }
        }
    }
}


void Black_bishop::step_down_right_machine(int* datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    if(column!=7 && row<8){
        if(*(datas+(row+1)*8+column+1)>0){
            std::vector<int> v;
            v.push_back(row+1);
            v.push_back(column+1);
            v.push_back(10);
            MoveAndPoint.push_back(v);
        }
    }
}




void Black_bishop::step_down_left_machine(int* datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint)
{
    if(column!=0 && row<8){
        if(*(datas+(row+1)*8+column-1)>0){
            std::vector<int> v;
            v.push_back(row+1);
            v.push_back(column-1);
            v.push_back(10);
            MoveAndPoint.push_back(v);
        }
    }
}







void Black_bishop::check_step_move_machine(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    if(check.step_black_left_up_and_right_down_check(datas,row,column)){
        if(AttackerRow==row+1 && AttackerColumn==column-1 && *(datas+(row+1)*8+column-1)>0){
            std::vector<int> v;
            v.push_back(row+1);
            v.push_back(column-1);
            v.push_back(10);
            MoveAndPoint.push_back(v);
        }
    }
    if(check.step_black_right_up_and_left_down_check(datas,row,column)){
        if(row+1==AttackerRow && AttackerColumn==column+1 && *(datas+(row+1)*8+column+1)>0){
            std::vector<int> v;
            v.push_back(row+1);
            v.push_back(column+1);
            v.push_back(10);
            MoveAndPoint.push_back(v);
        }
    }
}



void Black_bishop::check_step_move_machine(int *datas, const int &row, const int &column, std::vector<std::pair<int,int>> v, const int &AttackerColumn, const int &AttackerRow,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    if(check.step_black_up_and_down_check(datas,row,column)){
        for(int i=0;i<v.size();i++){
            if(v[i].first==row+1 && v[i].second==column && *(datas+(row+1)*8+column)==0){
                std::vector<int> f;
                f.push_back(row+1);
                f.push_back(column);
                f.push_back(0);
                MoveAndPoint.push_back(f);
            }
            if(row==1 && v[i].first==row+2 && v[i].second==column && *(datas+(row+2)*8+column)==0){
                std::vector<int> f;
                f.push_back(row+2);
                f.push_back(column);
                f.push_back(0);
                MoveAndPoint.push_back(f);
            }
        }
    }
    check_step_move_machine(datas,row,column,AttackerColumn,AttackerRow,MoveAndPoint);
}



void Black_bishop::row_equal_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
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

    check_step_move_machine(datas,row,column,v,AttackerColumn,king_row,MoveAndPoint);
}



void Black_bishop::dialog_left_up_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move_machine(datas,row,column,v,AttackerColumn,AttackerRow,MoveAndPoint);
}




void Black_bishop::dialog_right_down_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move_machine(datas,row,column,v,AttackerColumn,AttackerRow,MoveAndPoint);
}




void Black_bishop::dialog_left_down_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move_machine(datas,row,column,v,AttackerColumn,AttackerRow,MoveAndPoint);
}



void Black_bishop::dialog_right_up_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    check_step_move_machine(datas,row,column,v,AttackerColumn,AttackerRow,MoveAndPoint);
}



void Black_bishop::step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int> > &MoveAndPoint,const int &row, const int &column)
{
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

        if(king_column==AttackerColumn){
            check_step_move_machine(datas,row,column,king_column,AttackerRow,MoveAndPoint);
        }
        //row
        if(king_row==AttackerRow){
            row_equal_check_step_machine(datas,row,column,king_column,king_row,AttackerColumn,MoveAndPoint);
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
    else{
        check_step_move_machine(datas,row,column,AttackerColumn,AttackerRow,MoveAndPoint);
    }
}




