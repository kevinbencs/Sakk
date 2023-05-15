#include "black_queen.h"

Black_queen::Black_queen()
{

}



void Black_queen::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-8)));
        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        piece=0;
        BlackOrWhite=1;
        check.green_cell_disappear(ui);
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="-8"){

            check.green_cell_disappear(ui);

            if(piece==0){
                if(check.step_black_up_and_down_check(ui,row,column)){
                    step_up(ui,row, column,piece);
                    step_down(ui,row, column,piece);
                    piece=-8;
                }
                if(check.step_black_right_and_left_check(ui,row,column)){
                    step_left(ui,row, column,piece);
                    step_right(ui,row, column,piece);
                    piece=-8;
                }
                if(check.step_black_left_up_and_right_down_check(ui,row,column)){
                    step_left_up(ui,row,column);
                    step_right_down(ui,row,column);
                    piece=-8;
                }
                if(check.step_black_right_up_and_left_down_check(ui,row,column)){
                    step_right_up(ui,row,column);
                    step_left_down(ui,row,column);
                    piece=-8;
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




void Black_queen::check_step(Ui::Game* ui,const int &row,const int &column,int &piece,int &OldRow, int &OldColumn, const int &AttackerRow, const int &AttackerColumn,int &BlackOrWhite,const int &king_row,const int &king_column)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-8)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        check.green_cell_disappear(ui);

        BlackOrWhite=1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=-8;
            OldRow=row;
            OldColumn=column;

            //column
            if(king_column==AttackerColumn){
                column_equal_check_step(ui,row, column, king_column, king_row,AttackerRow);
                king_column_black_queen_rook_column_equal_step(ui,row,column,AttackerColumn,AttackerRow);
            }
            //row
            if(king_row==AttackerRow){
                row_equal_check_step(ui,row, column, king_column, king_row,AttackerColumn);
                king_row_black_queen_rook_row_equal_step(ui,row,column,AttackerColumn,AttackerRow);
            }
            //dialog
            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                dialog_left_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                king_dialog_black_queen_pawn_equal_left_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                dialog_right_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                king_dialog_black_queen_pawn_equal_right_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                dialog_right_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                king_dialog_black_queen_pawn_equal_right_down_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                dialog_left_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow);
                king_dialog_black_queen_pawn_equal_left_up_step(ui,row,column,AttackerColumn,AttackerRow,king_row,king_column);
            }
        }
        else{
            piece=0;
        }
    }
}


void Black_queen::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-8)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        check.green_cell_disappear(ui);

        BlackOrWhite=1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=-8;
            OldRow=row;
            OldColumn=column;

            if(row==AttackerRow){
                right_check_step(ui,row,column,AttackerColumn);
                left_check_step(ui,row,column,AttackerColumn);
            }
            if(column==AttackerColumn){
                up_check_step(ui,row,column,AttackerRow);
                down_check_step(ui,row,column,AttackerRow);
            }

            std::vector<std::pair<int,int>> v;
            v.push_back(std::make_pair(AttackerRow,AttackerColumn));

            if(check.step_black_left_up_and_right_down_check(ui,row,column)){
                up_left_check_step(ui,row,column,v);
                down_right_check_step(ui,row,column,v);
            }

            if(check.step_black_right_up_and_left_down_check(ui,row,column)){
                up_right_check_step(ui,row,column,v);
                down_left_check_step(ui,row,column,v);
            }
        }
        else{
         piece=0;
        }
    }
}


