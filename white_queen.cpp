#include "white_queen.h"
#include <QImage>


White_queen::White_queen()
{

}


void White_queen::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int* datas)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));
        QImage* img=new QImage("Gui/white_queen.png");
        QTableWidgetItem* picture=new QTableWidgetItem;
        picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img).scaled(70,70));
        ui->tableWidget->setItem(row,column,picture);
        datas[row*8+column]=8;
        datas[RowOld*8+ColumnOld]=0;

        piece=0;
        BlackOrWhite=-1;
        check.green_cell_disappear(ui);
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            if(check.step_white_up_and_down_check(datas,row,column)){
                step_up(ui,row, column, datas);
                step_down(ui,row, column,datas);

            }
            if(check.step_white_right_and_left_check(datas,row,column)){
                step_left(ui,row, column, datas);
                step_right(ui,row, column, datas);

            }
            if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                step_left_up(ui,row,column, datas);
                step_right_down(ui,row,column, datas);
            }
            if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                step_right_up(ui,row,column,datas);
                step_left_down(ui,row,column, datas);
            }
            piece=8;
        }
        else{
            piece=0;
        }

        ColumnOld=column;
        RowOld=row;
    }
}




void White_queen::check_step(Ui::Game* ui,const int &row,const int &column,int &piece,int &OldRow, int &OldColumn, const int &AttackerRow, const int &AttackerColumn,int &BlackOrWhite,const int &king_row,const int &king_column,int* datas)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));
        QImage* img=new QImage("Gui/white_queen.png");
        QTableWidgetItem* picture=new QTableWidgetItem;
        picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img).scaled(70,70));
        ui->tableWidget->setItem(row,column,picture);
        datas[row*8+column]=8;
        datas[OldRow*8+OldColumn]=0;

        check.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=8;
            OldRow=row;
            OldColumn=column;

            //column
            if(king_column==AttackerColumn){
                column_equal_check_step(ui,row, column, king_column, king_row,AttackerRow, datas);
                king_column_black_queen_rook_column_equal_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column, datas);
            }
            //row
            if(king_row==AttackerRow){
                row_equal_check_step(ui,row, column, king_column, king_row,AttackerColumn, datas);
                king_row_black_queen_rook_row_equal_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column, datas);
            }
            //dialog
            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                dialog_left_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow, datas);
                king_dialog_black_queen_pawn_equal_left_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column, datas);
            }
            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                dialog_right_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow, datas);
                king_dialog_black_queen_pawn_equal_right_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column, datas);
            }
            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                dialog_right_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow, datas);
                king_dialog_black_queen_pawn_equal_right_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column, datas);
            }
            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                dialog_left_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow, datas);
                king_dialog_black_queen_pawn_equal_left_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column, datas);
            }
        }
        else{
            piece=0;
        }
    }
}


void White_queen::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int* datas)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));
        QImage* img=new QImage("Gui/white_queen.png");
        QTableWidgetItem* picture=new QTableWidgetItem;
        picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img).scaled(70,70));
        ui->tableWidget->setItem(row,column,picture);
        datas[row*8+column]=8;
        datas[OldRow*8+OldColumn]=0;

        check.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=8;
            OldRow=row;
            OldColumn=column;

            if(row==AttackerRow){
                right_check_step(ui,row,column,AttackerColumn, datas);
                left_check_step(ui,row,column,AttackerColumn, datas);
            }
            if(column==AttackerColumn){
                up_check_step(ui,row,column,AttackerRow, datas);
                down_check_step(ui,row,column,AttackerRow, datas);
            }

            std::vector<std::pair<int,int>> v;
            v.push_back(std::make_pair(AttackerRow,AttackerColumn));

            if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                up_left_check_step(ui,row,column,v, datas);
                down_right_check_step(ui,row,column,v, datas);
            }

            if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                up_right_check_step(ui,row,column,v, datas);
                down_left_check_step(ui,row,column,v, datas);
            }
        }
        else{
         piece=0;
        }
    }
}




bool White_queen::get_checkmate_CanMove(int* datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop)
{
    int row, column,king_row,king_column;
    Check check;
    bool CanMove=false;
    if(KnightBishop==0){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==8){
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

                    //column
                    if(king_column==AttackerColumn){
                        column_equal_check_step(datas,row, column, king_column, king_row,AttackerRow,CanMove);
                        king_column_black_queen_rook_column_equal_step(datas,row,column,AttackerColumn,AttackerRow,CanMove,king_row,king_column);
                    }
                    //row
                    if(king_row==AttackerRow){
                        row_equal_check_step(datas,row, column, king_column, king_row,AttackerColumn,CanMove);
                        king_row_black_queen_rook_row_equal_step(datas,row,column,AttackerColumn,AttackerRow,CanMove,king_row,king_column);
                    }
                    //dialog
                    if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                        dialog_left_up(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        king_dialog_black_queen_pawn_equal_left_down_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                    }
                    if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                        dialog_right_down(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        king_dialog_black_queen_pawn_equal_right_up_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                    }
                    if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                        dialog_right_up(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        king_dialog_black_queen_pawn_equal_right_down_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                    }
                    if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                        dialog_left_down(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                        king_dialog_black_queen_pawn_equal_left_up_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                    }
                }
            }
        }

    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==8){
                    row=i;
                    column=j;

                    if(row==AttackerRow){
                        right_check_step(datas,row,column,AttackerColumn,CanMove);
                        left_check_step(datas,row,column,AttackerColumn,CanMove);
                    }
                    if(column==AttackerColumn){
                        up_check_step(datas,row,column,AttackerRow,CanMove);
                        down_check_step(datas,row,column,AttackerRow,CanMove);
                    }

                    std::vector<std::pair<int,int>> v;
                    v.push_back(std::make_pair(AttackerRow,AttackerColumn));

                    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                        up_left_check_step(datas,row,column,v,CanMove);
                        down_right_check_step(datas,row,column,v,CanMove);
                    }

                    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                        up_right_check_step(datas,row,column,v,CanMove);
                        down_left_check_step(datas,row,column,v,CanMove);
                    }
                }
            }
        }
    }
    return CanMove;
}



bool White_queen::get_draw_CanMove(int* datas)
{
    Check check;
    int row, column;
    bool CanMove=false;;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(*(datas+i*8+j)==8){
                row=i;
                column=j;

                if(check.step_white_up_and_down_check(datas,row,column)){
                    step_up(datas,row, column,CanMove);
                    step_down(datas,row, column,CanMove);
                }

                if(check.step_white_right_and_left_check(datas,row,column)){
                    step_left(datas,row, column,CanMove);
                    step_right(datas,row, column,CanMove);
                }

                if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                    step_left_up(datas,row,column,CanMove);
                    step_right_down(datas,row,column,CanMove);
                }
                if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                    step_right_up(datas,row,column,CanMove);
                    step_left_down(datas,row,column,CanMove);
                }
            }
        }
    }

    return CanMove;
}






void White_queen::step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int>> &MoveAndPoint,const int &row, const int &column)
{
    int king_row,king_column;
    Check check;

    if(KnightBishop==0){
        for(int f=0;f<8;f++){
            for(int l=0;l<8;l++){
                if(*(datas+f*8+l)==-10){
                    king_column=l;
                    king_row=f;
                }
            }
        }

        //column
        if(king_column==AttackerColumn){
            column_equal_check_step_machine(datas,row, column, king_column, king_row,AttackerRow,MoveAndPoint);
            king_column_black_queen_rook_column_equal_step_machine(datas,row,column,AttackerColumn,AttackerRow,MoveAndPoint,king_row,king_column);
        }
        //row
        if(king_row==AttackerRow){
            row_equal_check_step_machine(datas,row, column, king_column, king_row,AttackerColumn,MoveAndPoint);
            king_row_black_queen_rook_row_equal_step_machine(datas,row,column,AttackerColumn,AttackerRow,MoveAndPoint,king_row,king_column);
        }
        //dialog
        if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
            dialog_left_up_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            king_dialog_black_queen_pawn_equal_left_down_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
        }
        if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
            dialog_right_down_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            king_dialog_black_queen_pawn_equal_right_up_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
        }
        if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
            dialog_right_up_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            king_dialog_black_queen_pawn_equal_right_down_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
        }
        if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
            dialog_left_down_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
            king_dialog_black_queen_pawn_equal_left_up_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
        }

    }
    else{
        if(row==AttackerRow){
            right_check_step_machine(datas,row,column,AttackerColumn,MoveAndPoint);
            left_check_step_machine(datas,row,column,AttackerColumn,MoveAndPoint);
        }
        if(column==AttackerColumn){
            up_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
            down_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
        }

        std::vector<std::pair<int,int>> v;
        v.push_back(std::make_pair(AttackerRow,AttackerColumn));

        if(check.step_black_left_up_and_right_down_check(datas,row,column)){
            up_left_check_step_machine(datas,row,column,v,MoveAndPoint);
            down_right_check_step_machine(datas,row,column,v,MoveAndPoint);
        }

        if(check.step_black_right_up_and_left_down_check(datas,row,column)){
            up_right_check_step_machine(datas,row,column,v,MoveAndPoint);
            down_left_check_step_machine(datas,row,column,v,MoveAndPoint);
        }
    }
}



void White_queen::step_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int> > &MoveAndPoint)
{
    Check check;

    if(check.step_black_up_and_down_check(datas,row,column)){
        step_up_machine(datas,row, column,MoveAndPoint);
        step_down_machine(datas,row, column,MoveAndPoint);
    }

    if(check.step_black_right_and_left_check(datas,row,column)){
        step_left_machine(datas,row, column,MoveAndPoint);
        step_right_machine(datas,row, column,MoveAndPoint);
    }

    if(check.step_black_left_up_and_right_down_check(datas,row,column)){
        step_left_up_machine(datas,row,column,MoveAndPoint);
        step_right_down_machine(datas,row,column,MoveAndPoint);
    }

    if(check.step_black_right_up_and_left_down_check(datas,row,column)){
        step_right_up_machine(datas,row,column,MoveAndPoint);
        step_left_down_machine(datas,row,column,MoveAndPoint);
    }
}





