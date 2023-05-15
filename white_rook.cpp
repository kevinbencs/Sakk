#include "white_rook.h"


White_rook::White_rook()
{

}







void White_rook::step_up(Ui::Game* ui,const int &row, const int &column,int &piece)
{
    for(int i=row-1;i>=0 && i<8; i--){
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
}




void White_rook::step_down(Ui::Game* ui, const int &row, const int &column, int &piece)
{
    for(int i=row+1;i>=0 && i<8;i++){
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
}



void White_rook::step_left(Ui::Game* ui,const int &row, const int &column,int &piece)
{
    for(int i=column-1;i>=0 && i<8;i--){
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
}



void White_rook::step_right(Ui::Game* ui, const int &row, const int &column, int &piece)
{
    for(int i=column+1;i>=0 && i<8; i++){
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
}




void White_rook::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(5)));
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        if(ColumnOld==7){
            WhiteKingRookDidNotMoveRight=false;
        }
        if(ColumnOld==0){
            WhiteKingRookDidNotMoveLeft=false;
        }

        check.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="5"){

            check.green_cell_disappear(ui);

            if(piece==0){

                if(check.step_white_up_and_down_check(ui,row,column)){
                    step_up(ui,row, column,piece);
                    step_down(ui,row, column,piece);
                    piece=5;
                }

                if(check.step_white_right_and_left_check(ui,row,column)){
                    step_left(ui,row, column,piece);
                    step_right(ui,row, column,piece);
                    piece=5;
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






void White_rook::left_check_step(Ui::Game* ui, const int &row, const int &column,const int &AttackerColumn)
{
    for(int i=column+1;i<=AttackerColumn;i++){
        if(i!=AttackerColumn){
            if(ui->tableWidget->item(row,i)->text()!=""){
                break;
            }
        }
        else{
            if(ui->tableWidget->item(row,i)->text()=="" || ui->tableWidget->item(row,i)->text().toInt()<0){
                ui->tableWidget->item(row,AttackerColumn)->setBackground(Qt::green);
            }
        }
    }
}


void White_rook::right_check_step(Ui::Game* ui, const int &row, const int &column,const int &AttackerColumn)
{
    for(int i=column-1;i>=AttackerColumn;i--){
        if(i!=AttackerColumn){
            if(ui->tableWidget->item(row,i)->text()!=""){
                break;
            }
        }
        else{
            if(ui->tableWidget->item(row,i)->text()=="" || ui->tableWidget->item(row,i)->text().toInt()<0){
                ui->tableWidget->item(row,AttackerColumn)->setBackground(Qt::green);
            }

        }
    }
}





void White_rook::up_check_step(Ui::Game* ui,const int &row, const int &column,const int &AttackerRow)
{
    for(int i=row-1;i>=AttackerRow;i--){
        if(i!=AttackerRow){
            if(ui->tableWidget->item(i,column)->text()!=""){
                break;
            }
        }
        else{
            if(ui->tableWidget->item(i,column)->text()=="" || ui->tableWidget->item(i,column)->text().toInt()<0){
                ui->tableWidget->item(AttackerRow,column)->setBackground(Qt::green);
            }
        }
    }
}



void White_rook::down_check_step(Ui::Game* ui,const int &row, const int &column,const int &AttackerRow)
{
    for(int i=row+1;i<=AttackerRow;i++){
        if(i!=AttackerRow){
            if(ui->tableWidget->item(i,column)->text()!=""){
                break;
            }
        }
        else{
            if(ui->tableWidget->item(i,column)->text()=="" || ui->tableWidget->item(i,column)->text().toInt()<0){
                ui->tableWidget->item(AttackerRow,column)->setBackground(Qt::green);
            }
        }
    }
}




void White_rook::king_column_black_queen_rook_column_equal_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow)
{
    Check check;

    if(check.step_white_right_and_left_check(ui,row,column)){
        if(column>AttackerColumn){
            right_check_step(ui, row, column,AttackerColumn);
        }
        if(column<AttackerColumn){
            left_check_step(ui,row, column,AttackerColumn);
        }
    }

    if(check.step_white_up_and_down_check(ui,row,column)){
        if(column==AttackerColumn){
            if(row<AttackerRow){
                down_check_step(ui,row,column,AttackerRow);
            }
            else{
                up_check_step(ui,row,column,AttackerRow);
            }
        }
    }

}



void White_rook::king_row_black_queen_rook_row_equal_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow)
{
    Check check;

    if(check.step_white_up_and_down_check(ui,row,column)){
        if(row>AttackerRow){
            up_check_step(ui,row,column,AttackerRow);
        }
        if(row<AttackerRow){
            down_check_step(ui,row,column,AttackerRow);
        }
    }

    if(check.step_white_right_and_left_check(ui,row,column)){
        if(row==AttackerRow){
            if(column<AttackerColumn){
                left_check_step(ui,row,column,AttackerColumn);
            }
            if(column>AttackerColumn){
                right_check_step(ui,row,column,AttackerColumn);
            }
        }
    }

}




void White_rook::king_dialog_black_queen_pawn_equal_left_down_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(ui,row,column)){
            if(column>king_column-king_row+row){
                right_check_step(ui,row,column,king_column-king_row+row);
            }
            if(column<king_column-king_row+row){
                left_check_step(ui,row,column,king_column-king_row+row);
            }
        }

    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(ui,row,column)){
            if(row>king_row-king_column+column){
                up_check_step(ui,row,column,king_row-king_column+column);
            }
            if(row<king_row-king_column+column){
                down_check_step(ui,row,column,king_row-king_column+column);
            }
        }

    }
}



void White_rook::king_dialog_black_queen_pawn_equal_left_up_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(ui,row,column)){
            if(column>king_column+king_row-row){
                right_check_step(ui,row,column,king_column+king_row-row);
            }
            if(column<king_column+king_row-row){
                left_check_step(ui,row,column,king_column+king_row-row);
            }
        }

    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(ui,row,column)){
            if(row>king_row+king_column-column){
                up_check_step(ui,row,column,king_row+king_column-column);
            }
            if(row<king_row+king_column-column){
                down_check_step(ui,row,column,king_row+king_column-column);
            }
        }

    }
}




void White_rook::king_dialog_black_queen_pawn_equal_right_down_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(ui,row,column)){
            if(column>king_column+king_row-row){
                right_check_step(ui,row,column,king_column+king_row-row);
            }
            if(column<king_column+king_row-row){
                left_check_step(ui,row,column,king_column+king_row-row);
            }
        }

    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(ui,row,column)){
            if(row>king_row+king_column-column){
                up_check_step(ui,row,column,king_row+king_column-column);
            }
            if(row<king_row+king_column-column){
                down_check_step(ui,row,column,king_row+king_column-column);
            }
        }

    }
}



void White_rook::king_dialog_black_queen_pawn_equal_right_up_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(ui,row,column)){
            if(column>king_column-king_row+row){
                right_check_step(ui,row,column,king_column-king_row+row);
            }
            if(column<king_column-king_row+row){
                left_check_step(ui,row,column,king_column-king_row+row);
            }
        }

    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(ui,row,column)){
            if(row>king_row-king_column+column){
                up_check_step(ui,row,column,king_row-king_column+column);
            }
            if(row<king_row-king_column+column){
                down_check_step(ui,row,column,king_row-king_column+column);
            }
        }

    }
}


void White_rook::check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(5)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        if(OldColumn==7){
            WhiteKingRookDidNotMoveRight=false;
        }
        if(OldColumn==0){
            WhiteKingRookDidNotMoveLeft=false;
        }

        check.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            if((king_row<=row && row<=AttackerRow) || (king_row>=row && row>=AttackerRow) || (king_column<=column && column<=AttackerColumn) || (king_column>=column && column>=AttackerColumn)){
                //column
                if(king_column==AttackerColumn){
                    king_column_black_queen_rook_column_equal_step(ui,row,column,AttackerColumn,AttackerRow);
                }
                //row
                if(king_row==AttackerRow){
                    king_row_black_queen_rook_row_equal_step(ui,row,column,AttackerColumn,AttackerRow);
                }
                //diagonal
                if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)>0){
                    king_dialog_black_queen_pawn_equal_left_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
                }
                if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)>0){
                    king_dialog_black_queen_pawn_equal_left_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
                }
                if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)<0){
                    king_dialog_black_queen_pawn_equal_right_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
                }
                if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)<0){
                    king_dialog_black_queen_pawn_equal_right_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
                }

                piece=5;
                OldRow=row;
                OldColumn=column;
            }
        }
        else{
            piece=0;
        }


    }
}



void White_rook::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(5)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        if(OldColumn==7){
            WhiteKingRookDidNotMoveRight=false;
        }
        if(OldColumn==0){
            WhiteKingRookDidNotMoveLeft=false;
        }

        check.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){

            if(row==AttackerRow){
                if(check.step_white_right_and_left_check(ui,row,column)){
                    right_check_step(ui,row,column,AttackerColumn);
                    left_check_step(ui,row,column,AttackerColumn);
                }

            }

            if(column==AttackerColumn){
                if(check.step_white_up_and_down_check(ui,row,column)){
                    up_check_step(ui,row,column,AttackerRow);
                    down_check_step(ui,row,column,AttackerRow);
                }

            }

            piece=5;
            OldRow=row;
            OldColumn=column;

        }
        else{
            piece=0;
        }


    }
}


