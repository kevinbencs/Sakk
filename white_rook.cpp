#include "white_rook.h"


White_rook::White_rook()
{

}




///////////////////////////////////////////
//////////////////////////////////////////
/// Human
///////////////////////////////////////////
///////////////////////////////////////////




////////////////////////////////////////
/// Step when there is no check
////////////////////////////////////////


////////////////////////////////////////
/// Paint green the cells where the rook and queen can step
////////////////////////////////////////
void White_rook::step_up(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=row-1;i>=0 && i<8; i--){
        if(*(datas+i*8+column)==0){
            ui->tableWidget->item(i,column)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+column)<0){
                ui->tableWidget->item(i,column)->setBackground(Qt::green);
            }
            break;
        }
    }
}




void White_rook::step_down(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=row+1;i>=0 && i<8;i++){
        if(*(datas+i*8+column)==0){
            ui->tableWidget->item(i,column)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+column)<0){
                ui->tableWidget->item(i,column)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_rook::step_left(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=column-1;i>=0 && i<8;i--){
        if(*(datas+row*8+i)==0){
            ui->tableWidget->item(row,i)->setBackground(Qt::green);
        }
        else{
            if(*(datas+row*8+i)<0){
                ui->tableWidget->item(row,i)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_rook::step_right(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=column+1;i>=0 && i<8; i++){
        if(*(datas+row*8+i)==0){
            ui->tableWidget->item(row,i)->setBackground(Qt::green);
        }
        else{
            if(*(datas+row*8+i)<0){
                ui->tableWidget->item(row,i)->setBackground(Qt::green);
            }
            break;
        }
    }
}


///////////////////////////////////////////
/// Change the cell of piece
///////////////////////////////////////////
void White_rook::change_piece_cell(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas,const int &WhiteOrBlackMachine,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight)
{
    Check check;
    QImage* img;

    ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));
    datas[RowOld*8+ColumnOld]=0;

    if(WhiteOrBlackMachine==-1){
        img=new QImage("Gui/black_rook.png");
    }
    else{
        img=new QImage("Gui/white_rook.png");
    }

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(row,column,picture);
    datas[row*8+column]=5;

    if(ColumnOld==7 && RowOld==7){
        WhiteKingRookDidNotMoveRight=false;
    }
    if(ColumnOld==0 && RowOld==7){
        WhiteKingRookDidNotMoveLeft=false;
    }

    check.green_cell_disappear(ui);
    piece=0;
    BlackOrWhite=-1;
}




void White_rook::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight,int *datas,const int &WhiteOrBlackMachine)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        change_piece_cell(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas,WhiteOrBlackMachine,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);
    }
    else{
        check.green_cell_disappear(ui);

        if(piece!=5 && *(datas+row*8+column)==5){
            if(check.step_white_up_and_down_check(datas,row,column)){
                step_up(ui,row, column,datas);
                step_down(ui,row, column,datas);
            }

            if(check.step_white_right_and_left_check(datas,row,column)){
                step_left(ui,row, column,datas);
                step_right(ui,row, column,datas);
            }
            piece=5;
        }
        else{
            piece=100;
        }

        ColumnOld=column;
        RowOld=row;
    }
}





////////////////////////
/// Step when there is check
////////////////////////
void White_rook::left_check_step(Ui::Game* ui, const int &row, const int &column,const int &AttackerColumn,int *datas)
{
    for(int i=column+1;i<=AttackerColumn;i++){
        if(i!=AttackerColumn){
            if(*(datas+row*8+i)!=0){
                break;
            }
        }
        else{
            if(*(datas+row*8+i)==0 || *(datas+row*8+i)<0){
                ui->tableWidget->item(row,AttackerColumn)->setBackground(Qt::green);
            }
        }
    }
}


void White_rook::right_check_step(Ui::Game* ui, const int &row, const int &column,const int &AttackerColumn,int *datas)
{
    for(int i=column-1;i>=AttackerColumn;i--){
        if(i!=AttackerColumn){
            if(*(datas+row*8+i)!=0){
                break;
            }
        }
        else{
            if(*(datas+row*8+i)==0 || *(datas+row*8+i)<0){
                ui->tableWidget->item(row,AttackerColumn)->setBackground(Qt::green);
            }
        }
    }
}





void White_rook::up_check_step(Ui::Game* ui,const int &row, const int &column,const int &AttackerRow,int *datas)
{
    for(int i=row-1;i>=AttackerRow;i--){
        if(i!=AttackerRow){
            if(*(datas+i*8+column)!=0){
                break;
            }
        }
        else{
            if(*(datas+i*8+column)==0 || *(datas+i*8+column)<0){
                ui->tableWidget->item(AttackerRow,column)->setBackground(Qt::green);
            }
        }
    }
}



void White_rook::down_check_step(Ui::Game* ui,const int &row, const int &column,const int &AttackerRow,int *datas)
{
    for(int i=row+1;i<=AttackerRow;i++){
        if(i!=AttackerRow){
            if(*(datas+i*8+column)!=0){
                break;
            }
        }
        else{
            if(*(datas+i*8+column)==0 || *(datas+i*8+column)<0){
                ui->tableWidget->item(AttackerRow,column)->setBackground(Qt::green);
            }
        }
    }
}




void White_rook::king_column_black_queen_rook_column_equal_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow, const int &king_row, const int &king_column,int *datas)
{
    Check check;

    if(check.step_white_right_and_left_check(datas,row,column)){
        if((row>king_row && row<=AttackerRow) || (row<king_row && row>=AttackerRow)){
            if(column>AttackerColumn){
                right_check_step(ui, row, column,AttackerColumn,datas);
            }
            if(column<AttackerColumn){
                left_check_step(ui,row, column,AttackerColumn,datas);
            }
        }
    }

    if(check.step_white_up_and_down_check(datas,row,column)){
        if(column==AttackerColumn){
            if(row<AttackerRow){
                down_check_step(ui,row,column,AttackerRow,datas);
            }
            else{
                up_check_step(ui,row,column,AttackerRow,datas);
            }
        }
    }
}



void White_rook::king_row_black_queen_rook_row_equal_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow, const int &king_row, const int &king_column,int *datas)
{
    Check check;

    if(check.step_white_up_and_down_check(datas,row,column)){
        if((column>king_column && column<=AttackerColumn) || (column<king_column && column>=AttackerColumn)){
            if(row>AttackerRow){
                up_check_step(ui,row,column,AttackerRow,datas);
            }
            if(row<AttackerRow){
                down_check_step(ui,row,column,AttackerRow,datas);
            }
        }
    }

    if(check.step_white_right_and_left_check(datas,row,column)){
        if(row==AttackerRow){
            if(column<AttackerColumn){
                left_check_step(ui,row,column,AttackerColumn,datas);
            }
            if(column>AttackerColumn){
                right_check_step(ui,row,column,AttackerColumn,datas);
            }
        }
    }
}




void White_rook::king_dialog_black_queen_pawn_equal_left_down_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,int *datas)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column-king_row+row){
                right_check_step(ui,row,column,king_column-king_row+row,datas);
            }
            if(column<king_column-king_row+row){
                left_check_step(ui,row,column,king_column-king_row+row,datas);
            }
        }
    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row-king_column+column){
                up_check_step(ui,row,column,king_row-king_column+column,datas);
            }
            if(row<king_row-king_column+column){
                down_check_step(ui,row,column,king_row-king_column+column,datas);
            }
        }
    }
}



void White_rook::king_dialog_black_queen_pawn_equal_left_up_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,int *datas)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column+king_row-row){
                right_check_step(ui,row,column,king_column+king_row-row,datas);
            }
            if(column<king_column+king_row-row){
                left_check_step(ui,row,column,king_column+king_row-row,datas);
            }
        }
    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row+king_column-column){
                up_check_step(ui,row,column,king_row+king_column-column,datas);
            }
            if(row<king_row+king_column-column){
                down_check_step(ui,row,column,king_row+king_column-column,datas);
            }
        }
    }
}




void White_rook::king_dialog_black_queen_pawn_equal_right_down_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,int *datas)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column+king_row-row){
                right_check_step(ui,row,column,king_column+king_row-row,datas);
            }
            if(column<king_column+king_row-row){
                left_check_step(ui,row,column,king_column+king_row-row,datas);
            }
        }
    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row+king_column-column){
                up_check_step(ui,row,column,king_row+king_column-column,datas);
            }
            if(row<king_row+king_column-column){
                down_check_step(ui,row,column,king_row+king_column-column,datas);
            }
        }
    }
}



void White_rook::king_dialog_black_queen_pawn_equal_right_up_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,int *datas)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column-king_row+row){
                right_check_step(ui,row,column,king_column-king_row+row,datas);
            }
            if(column<king_column-king_row+row){
                left_check_step(ui,row,column,king_column-king_row+row,datas);
            }
        }
    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row-king_column+column){
                up_check_step(ui,row,column,king_row-king_column+column,datas);
            }
            if(row<king_row-king_column+column){
                down_check_step(ui,row,column,king_row-king_column+column,datas);
            }
        }
    }
}


void White_rook::check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight,int *datas,const int &WhiteOrBlackMachine)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        change_piece_cell(ui,row,column,OldRow,OldColumn,piece,BlackOrWhite,datas,WhiteOrBlackMachine,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece!=5 && *(datas+row*8+column)==5){
            piece=5;
            if((king_row<=row && row<=AttackerRow) || (king_row>=row && row>=AttackerRow) || (king_column<=column && column<=AttackerColumn) || (king_column>=column && column>=AttackerColumn)){
                //column
                if(king_column==AttackerColumn){
                    king_column_black_queen_rook_column_equal_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column,datas);
                }
                //row
                if(king_row==AttackerRow){
                    king_row_black_queen_rook_row_equal_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column,datas);
                }
                //diagonal
                if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)>0){
                    king_dialog_black_queen_pawn_equal_left_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column,datas);
                }
                if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)>0){
                    king_dialog_black_queen_pawn_equal_left_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column,datas);
                }
                if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)<0){
                    king_dialog_black_queen_pawn_equal_right_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column,datas);
                }
                if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)<0){
                    king_dialog_black_queen_pawn_equal_right_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column,datas);
                }
            }
        }
        else{
            piece=100;
        }

        OldRow=row;
        OldColumn=column;
    }
}



void White_rook::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight,int *datas,const int &WhiteOrBlackMachine)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        change_piece_cell(ui,row,column,OldRow,OldColumn,piece,BlackOrWhite,datas,WhiteOrBlackMachine,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece!=5 && *(datas+row*8+column)==5){
            piece=5;
            if(row==AttackerRow){
                if(check.step_white_right_and_left_check(datas,row,column)){
                    right_check_step(ui,row,column,AttackerColumn,datas);
                    left_check_step(ui,row,column,AttackerColumn,datas);
                }
            }

            if(column==AttackerColumn){
                if(check.step_white_up_and_down_check(datas,row,column)){
                    up_check_step(ui,row,column,AttackerRow,datas);
                    down_check_step(ui,row,column,AttackerRow,datas);
                }
            }
        }
        else{
            piece=100;
        }

        OldRow=row;
        OldColumn=column;
    }
}



////////////////////////
/// Rook can step when there is check
///////////////////////


void White_rook::left_check_step(int *datas, const int &row, const int &column,const int &AttackerColumn,bool &CanMove)
{
    for(int i=column+1;i<=AttackerColumn;i++){
        if(i!=AttackerColumn){
            if(*(datas+row*8+i)!=0){
                break;
            }
        }
        else{
            if(*(datas+row*8+i)==0 || *(datas+row*8+i)<0){
                CanMove=true;
            }
        }
    }
}


void White_rook::right_check_step(int *datas, const int &row, const int &column,const int &AttackerColumn,bool &CanMove)
{
    for(int i=column-1;i>=AttackerColumn;i--){
        if(i!=AttackerColumn){
            if(*(datas+row*8+i)!=0){
                break;
            }
        }
        else{
            if(*(datas+row*8+i)==0 || *(datas+row*8+i)<0){
                CanMove=true;
            }

        }
    }
}





void White_rook::up_check_step(int *datas,const int &row, const int &column,const int &AttackerRow,bool &CanMove)
{
    for(int i=row-1;i>=AttackerRow;i--){
        if(i!=AttackerRow){
            if(*(datas+i*8+column)!=0){
                break;
            }
        }
        else{
            if(*(datas+i*8+column)==0 || *(datas+i*8+column)<0){
                CanMove=true;
            }
        }
    }
}



void White_rook::down_check_step(int *datas,const int &row, const int &column,const int &AttackerRow,bool &CanMove)
{
    for(int i=row+1;i<=AttackerRow;i++){
        if(i!=AttackerRow){
            if(*(datas+i*8+column)!=0){
                break;
            }
        }
        else{
            if(*(datas+i*8+column)==0 || *(datas+i*8+column)<0){
                CanMove=true;
            }
        }
    }
}




void White_rook::king_column_black_queen_rook_column_equal_step(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,bool &CanMove, const int &king_row, const int &king_column)
{
    Check check;

    if(check.step_white_right_and_left_check(datas,row,column)){
        if((row>king_row && row<=AttackerRow) || (row<king_row && row>=AttackerRow)){
            if(column>AttackerColumn){
                right_check_step(datas, row, column,AttackerColumn,CanMove);
            }
            if(column<AttackerColumn){
                left_check_step(datas,row, column,AttackerColumn,CanMove);
            }
        }
    }

    if(check.step_white_up_and_down_check(datas,row,column)){
        if(column==AttackerColumn){
            if(row<AttackerRow){
                down_check_step(datas,row,column,AttackerRow,CanMove);
            }
            else{
                up_check_step(datas,row,column,AttackerRow,CanMove);
            }
        }
    }

}



void White_rook::king_row_black_queen_rook_row_equal_step(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,bool &CanMove, const int &king_row, const int &king_column)
{
    Check check;

    if(check.step_white_up_and_down_check(datas,row,column)){
        if((column>king_column && column<=AttackerColumn) || (column<king_column && column>=AttackerColumn)){
            if(row>AttackerRow){
                up_check_step(datas,row,column,AttackerRow,CanMove);
            }
            if(row<AttackerRow){
                down_check_step(datas,row,column,AttackerRow,CanMove);
            }
        }
    }

    if(check.step_white_right_and_left_check(datas,row,column)){
        if(row==AttackerRow){
            if(column<AttackerColumn){
                left_check_step(datas,row,column,AttackerColumn,CanMove);
            }
            if(column>AttackerColumn){
                right_check_step(datas,row,column,AttackerColumn,CanMove);
            }
        }
    }

}




void White_rook::king_dialog_black_queen_pawn_equal_left_down_step(int *datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,bool &CanMove)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column-king_row+row){
                right_check_step(datas,row,column,king_column-king_row+row,CanMove);
            }
            if(column<king_column-king_row+row){
                left_check_step(datas,row,column,king_column-king_row+row,CanMove);
            }
        }

    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row-king_column+column){
                up_check_step(datas,row,column,king_row-king_column+column,CanMove);
            }
            if(row<king_row-king_column+column){
                down_check_step(datas,row,column,king_row-king_column+column,CanMove);
            }
        }

    }
}



void White_rook::king_dialog_black_queen_pawn_equal_left_up_step(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,bool &CanMove)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column+king_row-row){
                right_check_step(datas,row,column,king_column+king_row-row,CanMove);
            }
            if(column<king_column+king_row-row){
                left_check_step(datas,row,column,king_column+king_row-row,CanMove);
            }
        }

    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row+king_column-column){
                up_check_step(datas,row,column,king_row+king_column-column,CanMove);
            }
            if(row<king_row+king_column-column){
                down_check_step(datas,row,column,king_row+king_column-column,CanMove);
            }
        }

    }
}




void White_rook::king_dialog_black_queen_pawn_equal_right_down_step(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,bool &CanMove)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column+king_row-row){
                right_check_step(datas,row,column,king_column+king_row-row,CanMove);
            }
            if(column<king_column+king_row-row){
                left_check_step(datas,row,column,king_column+king_row-row,CanMove);
            }
        }

    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row+king_column-column){
                up_check_step(datas,row,column,king_row+king_column-column,CanMove);
            }
            if(row<king_row+king_column-column){
                down_check_step(datas,row,column,king_row+king_column-column,CanMove);
            }
        }

    }
}



void White_rook::king_dialog_black_queen_pawn_equal_right_up_step(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,bool &CanMove)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column-king_row+row){
                right_check_step(datas,row,column,king_column-king_row+row,CanMove);
            }
            if(column<king_column-king_row+row){
                left_check_step(datas,row,column,king_column-king_row+row,CanMove);
            }
        }

    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row-king_column+column){
                up_check_step(datas,row,column,king_row-king_column+column,CanMove);
            }
            if(row<king_row-king_column+column){
                down_check_step(datas,row,column,king_row-king_column+column,CanMove);
            }
        }

    }
}





bool White_rook::get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop)
{
    Check check;
    int row, column,king_row,king_column;
    bool CanMove=false;;
    if(KnightBishop==0){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==5){
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

                    if((king_row<=row && row<=AttackerRow) || (king_row>=row && row>=AttackerRow) || (king_column<=column && column<=AttackerColumn) || (king_column>=column && column>=AttackerColumn)){
                        if(king_column==AttackerColumn){
                            king_column_black_queen_rook_column_equal_step(datas,row,column,AttackerColumn,AttackerRow,CanMove,king_row,king_column);
                        }
                        if(king_row==AttackerRow){
                            king_row_black_queen_rook_row_equal_step(datas,row,column,AttackerColumn,AttackerRow,CanMove,king_row,king_column);
                        }
                        if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)>0){
                            king_dialog_black_queen_pawn_equal_left_down_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                        }
                        if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)>0){
                            king_dialog_black_queen_pawn_equal_left_up_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                        }
                        if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)<0){
                            king_dialog_black_queen_pawn_equal_right_down_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                        }
                        if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)<0){
                            king_dialog_black_queen_pawn_equal_right_up_step(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,CanMove);
                        }
                    }


                }
            }
        }
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==5){
                    row=i;
                    column=j;

                    if(row==AttackerRow){
                        if(check.step_white_right_and_left_check(datas,row,column)){
                            right_check_step(datas,row,column,AttackerColumn,CanMove);
                            left_check_step(datas,row,column,AttackerColumn,CanMove);
                        }

                    }

                    if(column==AttackerColumn){
                        if(check.step_white_up_and_down_check(datas,row,column)){
                            up_check_step(datas,row,column,AttackerRow,CanMove);
                            down_check_step(datas,row,column,AttackerRow,CanMove);
                        }

                    }
                }
            }
        }


    }

    return CanMove;
}



////////////////////////
/// Rook can step when there is no check (for draw)
///////////////////////

void White_rook::step_up(int *datas, const int &row, const int &column,bool &CanMove)
{
    if(row-1>=0){
        if(*(datas+(row-1)*8+column)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-1)*8+column)<0){
                CanMove=true;
            }
        }
    }

}




void White_rook::step_down(int *datas, const int &row, const int &column,bool &CanMove)
{
    if(row+1<8){
        if(*(datas+(row+1)*8+column)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+1)*8+column)<0){
                CanMove=true;
            }
        }
    }

}



void White_rook::step_left(int *datas, const int &row, const int &column,bool &CanMove)
{
    if(column-1>=0){
        if(*(datas+row*8+column-1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+row*8+column-1)<0){
                CanMove=true;
            }
        }
    }

}



void White_rook::step_right(int *datas, const int &row, const int &column,bool &CanMove)
{
    if(column+1<8){
        if(*(datas+row*8+column+1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+row*8+column+1)<0){
                CanMove=true;
            }
        }
    }

}




bool White_rook::get_draw_CanMove(int *datas)
{
    Check check;
    int row, column;
    bool CanMove=false;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(*(datas+i*8+j)==5){
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
            }
        }
    }

    return CanMove;
}






///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/// Machine
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


void White_rook::step_up_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1;i>=0;i--){
        point=0;
        if(*(datas+i*8+column)>0){
            break;
        }
        else{
            if(*(datas+i*8+column)==0){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(column);
                if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+i*8+column)<0){
                    std::vector<int> v;
                    v.push_back(i);
                    v.push_back(column);
                    if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,column);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}




void White_rook::step_down_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1;i<8;i++){
        point=0;
        if(*(datas+i*8+column)>0){
            break;
        }
        else{
            if(*(datas+i*8+column)==0){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(column);
                if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+i*8+column)<0){
                    std::vector<int> v;
                    v.push_back(i);
                    v.push_back(column);
                    if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,column);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}



void White_rook::step_left_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=column-1;i>=0;i--){
        point=0;
        if(*(datas+row*8+i)>0){
            break;
        }
        else{
            if(*(datas+row*8+i)==0){
                std::vector<int> v;
                v.push_back(row);
                v.push_back(i);
                if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+row*8+i)<0){
                    std::vector<int> v;
                    v.push_back(row);
                    v.push_back(i);
                    if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,row,i);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}



void White_rook::step_right_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=column+1;i<8;i++){
        point=0;
        if(*(datas+row*8+i)>0){
            break;
        }
        else{
            if(*(datas+row*8+i)==0){
                std::vector<int> v;
                v.push_back(row);
                v.push_back(i);
                if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+row*8+i)<0){
                    std::vector<int> v;
                    v.push_back(row);
                    v.push_back(i);
                    if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,row,i);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}




void White_rook::step_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(check.step_white_up_and_down_check(datas,row,column)){
        step_up_machine(datas,row, column,MoveAndPoint);
        step_down_machine(datas,row, column,MoveAndPoint);
    }

    if(check.step_white_right_and_left_check(datas,row,column)){
        step_left_machine(datas,row, column,MoveAndPoint);
        step_right_machine(datas,row, column,MoveAndPoint);
    }
}












void White_rook::left_check_step_machine(int *datas, const int &row, const int &column,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=column+1;i<=AttackerColumn;i++){
        point=0;
        if(i!=AttackerColumn){
            if(*(datas+row*8+i)!=0){
                break;
            }
        }
        else{
            if(*(datas+row*8+i)==0 || *(datas+row*8+i)<0){
                std::vector<int> v;
                v.push_back(row);
                v.push_back(i);

                if(*(datas+row*8+i)==0){
                    if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,row,i);
                    v.push_back(point);
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}


void White_rook::right_check_step_machine(int *datas, const int &row, const int &column,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=column-1;i>=AttackerColumn;i--){
        point=0;
        if(i!=AttackerColumn){
            if(*(datas+row*8+i)!=0){
                break;
            }
        }
        else{
            if(*(datas+row*8+i)==0 || *(datas+row*8+i)<0){
                std::vector<int> v;
                v.push_back(row);
                v.push_back(i);

                if(*(datas+row*8+i)==0){
                    if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(check.check_check(datas,row,i,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,row,i);
                    v.push_back(point);
                }

                MoveAndPoint.push_back(v);
            }

        }
    }
}





void White_rook::up_check_step_machine(int *datas,const int &row, const int &column,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1;i>=AttackerRow;i--){
        point=0;
        if(i!=AttackerRow){
            if(*(datas+i*8+column)!=0){
                break;
            }
        }
        else{
            if(*(datas+i*8+column)==0 || *(datas+i*8+column)<0){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(column);

                if(*(datas+i*8+column)==0){
                    if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,column);
                    v.push_back(point);
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}



void White_rook::down_check_step_machine(int *datas,const int &row, const int &column,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1;i<=AttackerRow;i++){
        point=0;
        if(i!=AttackerRow){
            if(*(datas+i*8+column)!=0){
                break;
            }
        }
        else{
            if(*(datas+i*8+column)==0 || *(datas+i*8+column)<0){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(column);

                if(*(datas+i*8+column)==0){
                    if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(check.check_check(datas,i,column,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,column);
                    v.push_back(point);
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}




void White_rook::king_column_black_queen_rook_column_equal_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint, const int &king_row, const int &king_column)
{
    Check check;

    if(check.step_white_right_and_left_check(datas,row,column)){
        if((row>king_row && row<=AttackerRow) || (row<king_row && row>=AttackerRow)){
            if(column>AttackerColumn){
                right_check_step_machine(datas, row, column,AttackerColumn,MoveAndPoint);
            }
            if(column<AttackerColumn){
                left_check_step_machine(datas,row, column,AttackerColumn,MoveAndPoint);
            }
        }
    }

    if(check.step_white_up_and_down_check(datas,row,column)){
        if(column==AttackerColumn){
            if(row<AttackerRow){
                down_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
            }
            else{
                up_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
            }
        }
    }
}



void White_rook::king_row_black_queen_rook_row_equal_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint, const int &king_row, const int &king_column)
{
    Check check;

    if(check.step_white_up_and_down_check(datas,row,column)){
        if((column>king_column && column<=AttackerColumn) || (column<king_column && column>=AttackerColumn)){
            if(row>AttackerRow){
                up_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
            }
            if(row<AttackerRow){
                down_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
            }
        }
    }

    if(check.step_white_right_and_left_check(datas,row,column)){
        if(row==AttackerRow){
            if(column<AttackerColumn){
                left_check_step_machine(datas,row,column,AttackerColumn,MoveAndPoint);
            }
            if(column>AttackerColumn){
                right_check_step_machine(datas,row,column,AttackerColumn,MoveAndPoint);
            }
        }
    }
}




void White_rook::king_dialog_black_queen_pawn_equal_left_down_step_machine(int *datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column-king_row+row){
                right_check_step_machine(datas,row,column,king_column-king_row+row,MoveAndPoint);
            }
            if(column<king_column-king_row+row){
                left_check_step_machine(datas,row,column,king_column-king_row+row,MoveAndPoint);
            }
        }
    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row-king_column+column){
                up_check_step_machine(datas,row,column,king_row-king_column+column,MoveAndPoint);
            }
            if(row<king_row-king_column+column){
                down_check_step_machine(datas,row,column,king_row-king_column+column,MoveAndPoint);
            }
        }
    }
}



void White_rook::king_dialog_black_queen_pawn_equal_left_up_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column+king_row-row){
                right_check_step_machine(datas,row,column,king_column+king_row-row,MoveAndPoint);
            }
            if(column<king_column+king_row-row){
                left_check_step_machine(datas,row,column,king_column+king_row-row,MoveAndPoint);
            }
        }
    }

    if(column>=AttackerColumn && column<king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row+king_column-column){
                up_check_step_machine(datas,row,column,king_row+king_column-column,MoveAndPoint);
            }
            if(row<king_row+king_column-column){
                down_check_step_machine(datas,row,column,king_row+king_column-column,MoveAndPoint);
            }
        }
    }
}




void White_rook::king_dialog_black_queen_pawn_equal_right_down_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(row>=AttackerRow && row<king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column+king_row-row){
                right_check_step_machine(datas,row,column,king_column+king_row-row,MoveAndPoint);
            }
            if(column<king_column+king_row-row){
                left_check_step_machine(datas,row,column,king_column+king_row-row,MoveAndPoint);
            }
        }
    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row+king_column-column){
                up_check_step_machine(datas,row,column,king_row+king_column-column,MoveAndPoint);
            }
            if(row<king_row+king_column-column){
                down_check_step_machine(datas,row,column,king_row+king_column-column,MoveAndPoint);
            }
        }
    }
}



void White_rook::king_dialog_black_queen_pawn_equal_right_up_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(row<=AttackerRow && row>king_row){
        if(check.step_white_right_and_left_check(datas,row,column)){
            if(column>king_column-king_row+row){
                right_check_step_machine(datas,row,column,king_column-king_row+row,MoveAndPoint);
            }
            if(column<king_column-king_row+row){
                left_check_step_machine(datas,row,column,king_column-king_row+row,MoveAndPoint);
            }
        }
    }

    if(column<=AttackerColumn && column>king_column){
        if(check.step_white_up_and_down_check(datas,row,column)){
            if(row>king_row-king_column+column){
                up_check_step_machine(datas,row,column,king_row-king_column+column,MoveAndPoint);
            }
            if(row<king_row-king_column+column){
                down_check_step_machine(datas,row,column,king_row-king_column+column,MoveAndPoint);
            }
        }
    }
}





void White_rook::step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int>> &MoveAndPoint,const int &row, const int &column)
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

        if((king_row<=row && row<=AttackerRow) || (king_row>=row && row>=AttackerRow) || (king_column<=column && column<=AttackerColumn) || (king_column>=column && column>=AttackerColumn)){
            //column
            if(king_column==AttackerColumn){
                king_column_black_queen_rook_column_equal_step_machine(datas,row,column,AttackerColumn,AttackerRow,MoveAndPoint,king_row,king_column);
            }
            //row
            if(king_row==AttackerRow){
                king_row_black_queen_rook_row_equal_step_machine(datas,row,column,AttackerColumn,AttackerRow,MoveAndPoint,king_row,king_column);
            }
            //diagonal
            if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)>0){
                king_dialog_black_queen_pawn_equal_left_down_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
            }
            if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)>0){
                king_dialog_black_queen_pawn_equal_left_up_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
            }
            if((king_row-AttackerRow)>0 && (king_column-AttackerColumn)<0){
                king_dialog_black_queen_pawn_equal_right_down_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
            }
            if((king_row-AttackerRow)<0 && (king_column-AttackerColumn)<0){
                king_dialog_black_queen_pawn_equal_right_up_step_machine(datas,row,column,AttackerColumn,AttackerRow,king_row,king_column,MoveAndPoint);
            }
        }
    }
    else{
        if(row==AttackerRow){
            if(check.step_white_right_and_left_check(datas,row,column)){
                right_check_step_machine(datas,row,column,AttackerColumn,MoveAndPoint);
                left_check_step_machine(datas,row,column,AttackerColumn,MoveAndPoint);
            }
        }

        if(column==AttackerColumn){
            if(check.step_white_up_and_down_check(datas,row,column)){
                up_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
                down_check_step_machine(datas,row,column,AttackerRow,MoveAndPoint);
            }
        }
    }
}



