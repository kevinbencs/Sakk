#include "white_queen.h"

White_queen::White_queen()
{

}


void White_queen::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    White_rook white_rook;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(8)));
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);
        piece=0;
        BlackOrWhite=-1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="8"){

            White_pawn white_pawn;
            Check check;

            white_rook.green_cell_disappear(ui);

            if(piece==0){

                if(check.step_white_up_and_down_check(ui,row,column)){
                    white_rook.step_up(ui,row, column,piece);
                    white_rook.step_down(ui,row, column,piece);
                    piece=8;
                }
                if(check.step_white_right_and_left_check(ui,row,column)){
                    white_rook.step_left(ui,row, column,piece);
                    white_rook.step_right(ui,row, column,piece);
                    piece=8;
                }
                if(check.step_white_left_up_and_right_down_check(ui,row,column)){
                    white_pawn.step_left_up(ui,row,column);
                    white_pawn.step_right_down(ui,row,column);
                    piece=8;
                }
                if(check.step_white_right_up_and_left_down_check(ui,row,column)){
                    white_pawn.step_left_down(ui,row,column);
                    white_pawn.step_right_up(ui,row,column);
                    piece=8;
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




void White_queen::check_step(Ui::Game* ui,const int &row,const int &column,int &piece,int &OldRow, int &OldColumn, const int &AttackerRow, const int &AttackerColumn,int &BlackOrWhite,const int &king_row,const int &king_column)
{
    White_rook white_rook;
    White_pawn white_pawn;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(8)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        white_rook.green_cell_disappear(ui);

        if(piece==0){
            piece=8;
            OldRow=row;
            OldColumn=column;

            //column
            if(king_column==AttackerColumn){
                white_pawn.column_equal_check_step(ui,row, column, king_column, king_row,AttackerRow);
                white_rook.king_column_black_queen_rook_column_equal_step(ui,row,column,AttackerColumn,AttackerRow);
            }
            //row
            if(king_row==AttackerRow){
                white_pawn.row_equal_check_step(ui,row, column, king_column, king_row,AttackerColumn);
                white_rook.king_row_black_queen_rook_row_equal_step(ui,row,column,AttackerColumn,AttackerRow);
            }
            //dialog
            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                white_pawn.dialog_left_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                white_rook.king_dialog_black_queen_pawn_equal_left_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                white_pawn.dialog_right_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                white_rook.king_dialog_black_queen_pawn_equal_right_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                white_pawn.dialog_right_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                white_rook.king_dialog_black_queen_pawn_equal_right_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                white_pawn.dialog_left_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                white_rook.king_dialog_black_queen_pawn_equal_left_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
        }
        else{
            piece=0;
        }
    }
}


void White_queen::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite)
{
    White_rook white_rook;
    White_pawn white_pawn;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(8)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        white_rook.green_cell_disappear(ui);

        if(piece==0){
            piece=8;
            OldRow=row;
            OldColumn=column;

            if(row==AttackerRow){
                white_rook.right_check_step(ui,row,column,AttackerColumn);
                white_rook.left_check_step(ui,row,column,AttackerColumn);
            }
            if(column==AttackerColumn){
                white_rook.up_check_step(ui,row,column,AttackerRow);
                white_rook.down_check_step(ui,row,column,AttackerRow);
            }

            std::vector<std::pair<int,int>> v;
            v.push_back(std::make_pair(AttackerRow,AttackerColumn));

            white_pawn.up_left_check_step(ui,row,column,v);
            white_pawn.up_right_check_step(ui,row,column,v);
            white_pawn.down_left_check_step(ui,row,column,v);
            white_pawn.down_right_check_step(ui,row,column,v);
        }
        else{
         piece=0;
        }
    }
}

