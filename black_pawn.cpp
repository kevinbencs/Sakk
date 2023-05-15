#include "black_pawn.h"

Black_pawn::Black_pawn()
{

}


void Black_pawn::step_left_up(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row-1, j=column-1;i>=0 && j>=0;i--, j--){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()>0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void Black_pawn::step_left_down(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row+1, j=column-1;i<8 && j>=0;j--, i++){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()>0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void Black_pawn::step_right_up(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row-1, j=column+1;i>=0 && j<8;j++, i--){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()>0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void Black_pawn::step_right_down(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row+1, j=column+1; i<8 && j<8;j++, i++){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()>0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}




void Black_pawn::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-3)));

        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        check.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="-3"){

            check.green_cell_disappear(ui);

            if(piece==0){

                if(check.step_black_left_up_and_right_down_check(ui,row,column)){
                    step_left_up(ui,row,column);
                    step_right_down(ui,row,column);
                    piece=-3;
                }
                if(check.step_black_right_up_and_left_down_check(ui,row,column)){
                    step_left_down(ui,row,column);
                    step_right_up(ui,row,column);
                    piece=-3;
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



void Black_pawn::column_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
{
    for(int i=row-1,j=column+1; j<=king_column && i>=0 ;i--,j++){
        if(j!=king_column){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void Black_pawn::column_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
{
    for(int i=row+1,j=column+1;j<=king_column && i<8;i++,j++){
        if(j!=king_column){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}





void Black_pawn::column_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
{
    for(int i=row-1,j=column-1; j>=king_column && i>=0 ;i--,j--){
        if(j!=king_column){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void Black_pawn::column_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
{
    for(int i=row+1,j=column-1;j>=king_column && i<8;i++,j--){
        if(j!=king_column){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void Black_pawn::column_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
{
    Check check;

    if(column<king_column){
        if(check.step_black_left_up_and_right_down_check(ui,row,column)){
            column_down_right_check_step(ui,row, column, king_column, king_row,AttackerRow);
        }
        if(check.step_black_right_up_and_left_down_check(ui,row,column)){
            column_up_right_check_step(ui,row, column, king_column, king_row,AttackerRow);
        }
    }
    if(column>king_column){
        if(check.step_black_right_up_and_left_down_check(ui,row,column)){
            column_down_left_check_step(ui,row, column, king_column, king_row,AttackerRow);
        }
        if(check.step_black_left_up_and_right_down_check(ui,row,column)){
            column_up_left_check_step(ui,row, column, king_column, king_row,AttackerRow);
        }

    }
}




void Black_pawn::row_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn)
{
    for(int i=row-1,j=column+1; j<8 && i>=king_row ;i--,j++){
        if(i!=king_row){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void Black_pawn::row_down_right_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
{
    for(int i=row+1,j=column+1;j<8 && i<=king_row;i++,j++){
        if(i!=king_row){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}





void Black_pawn::row_up_left_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
{
    for(int i=row-1,j=column-1; j>=0 && i>=king_row ;i--,j--){
        if(i!=king_row){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void Black_pawn::row_down_left_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
{
    for(int i=row+1,j=column-1;j>=0 && i<=king_row;i++,j--){
        if(i!=king_row){
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void Black_pawn::row_equal_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
{
    Check check;

    if(row>king_row){
        if(check.step_black_left_up_and_right_down_check(ui,row,column)){
            row_up_left_check_step(ui,row, column, king_column, king_row,AttackerColumn);
        }
        if(check.step_black_right_up_and_left_down_check(ui,row,column)){
            row_up_right_check_step(ui,row, column, king_column, king_row,AttackerColumn);
        }
    }
    if(row<king_row){
        if(check.step_black_right_up_and_left_down_check(ui,row,column)){
            row_down_left_check_step(ui,row, column, king_column, king_row,AttackerColumn);
        }
        if(check.step_black_left_up_and_right_down_check(ui,row,column)){
            row_down_right_check_step(ui,row, column, king_column, king_row,AttackerColumn);
        }
    }
}




void Black_pawn::helper_down_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
{
    for(int i=row+1,j=column-1;i<=x && j>=y;i++,j--){
        if(i==x && j==y){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
    }
}



void Black_pawn::down_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column-1;i<8 && j>=0 && ThereIsOnCell==false;i++,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_left_check_step(ui,row, column,x, y);
    }
}





void Black_pawn::helper_down_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
{
    for(int i=row+1,j=column+1;i<=x && j<=y;i++,j++){
        if(i==x && j==y){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
    }
}



void Black_pawn::down_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column+1;i<8 && j<8 && ThereIsOnCell==false;i++,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_right_check_step(ui,row, column,x, y);
    }
}



void Black_pawn::helper_up_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
{
    for(int i=row-1,j=column+1;i>=x && j<=y;i--,j++){
        if(i==x && j==y){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
    }
}



void Black_pawn::up_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column+1;i>=0 && j<8 && ThereIsOnCell==false;i--,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_right_check_step(ui,row, column,x, y);
    }
}






void Black_pawn::helper_up_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
{
    for(int i=row-1,j=column-1;i>=x && j>=y;i--,j--){
        if(i==x && j==y){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                break;
            }
        }
    }
}



void Black_pawn::up_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column-1;i>=0 && j>=0 && ThereIsOnCell==false;i--,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_left_check_step(ui,row, column,x, y);
    }
}




void Black_pawn::dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_black_right_up_and_left_down_check(ui,row,column)){
        down_left_check_step(ui,row,column,v);
        up_right_check_step(ui,row,column,v);
    }
}



void Black_pawn::dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_black_right_up_and_left_down_check(ui,row,column)){
        down_left_check_step(ui,row,column,v);
        up_right_check_step(ui,row,column,v);
    }
}



void Black_pawn::dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_black_left_up_and_right_down_check(ui,row,column)){
        up_left_check_step(ui,row,column,v);
        down_right_check_step(ui,row,column,v);
    }
}



void Black_pawn::dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_black_left_up_and_right_down_check(ui,row,column)){
        up_left_check_step(ui,row,column,v);
        down_right_check_step(ui,row,column,v);
    }
}




void Black_pawn::check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-3)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        check.green_cell_disappear(ui);

        BlackOrWhite=1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece==0){
            piece=-3;
            OldRow=row;
            OldColumn=column;

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

        }
        else{
            piece=0;


        }
    }
}



void Black_pawn::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-3)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        check.green_cell_disappear(ui);

        BlackOrWhite=1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);
        if(piece==0){
            piece=-3;
            OldRow=row;
            OldColumn=column;

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
