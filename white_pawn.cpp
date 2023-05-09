#include "white_pawn.h"

White_pawn::White_pawn()
{

}



void White_pawn::step_left_up(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row-1, j=column-1;i>=0 && j>=0;i--, j--){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_pawn::step_left_down(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row+1, j=column-1;i<8 && j>=0;j--, i++){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_pawn::step_right_up(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row-1, j=column+1;i>=0 && j<8;j++, i--){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_pawn::step_right_down(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row+1, j=column+1; i<8 && j<8;j++, i++){
        if(ui->tableWidget->item(i,j)->text()==""){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(i,j)->text().toInt()<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}




void White_pawn::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    White_rook white_rook;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(3)));

        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);

        piece=0;
        BlackOrWhite=-1;
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="3"){

            white_rook.green_cell_disappear(ui);

            Check check;

            if(piece==0){

                if(check.step_white_left_up_and_right_down_check(ui,row,column)){
                    step_left_up(ui,row,column);
                    step_right_down(ui,row,column);
                    piece=3;
                }
                if(check.step_white_right_up_and_left_down_check(ui,row,column)){
                    step_left_down(ui,row,column);
                    step_right_up(ui,row,column);
                    piece=3;
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



void White_pawn::column_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
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



void White_pawn::column_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
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





void White_pawn::column_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
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



void White_pawn::column_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
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



void White_pawn::column_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow)
{
    if(column<king_column){
        column_down_right_check_step(ui,row, column, king_column, king_row,AttackerRow);
        column_up_right_check_step(ui,row, column, king_column, king_row,AttackerRow);
    }
    if(column>king_column){
        column_down_left_check_step(ui,row, column, king_column, king_row,AttackerRow);
        column_up_left_check_step(ui,row, column, king_column, king_row,AttackerRow);
    }
}




void White_pawn::row_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn)
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



void White_pawn::row_down_right_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
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





void White_pawn::row_up_left_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
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



void White_pawn::row_down_left_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
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



void White_pawn::row_equal_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn)
{
    if(row>king_row){
        row_up_left_check_step(ui,row, column, king_column, king_row,AttackerColumn);
        row_up_right_check_step(ui,row, column, king_column, king_row,AttackerColumn);
    }
    if(row<king_row){
        row_down_left_check_step(ui,row, column, king_column, king_row,AttackerColumn);
        row_down_right_check_step(ui,row, column, king_column, king_row,AttackerColumn);
    }
}




void White_pawn::helper_down_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
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



void White_pawn::down_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
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





void White_pawn::helper_down_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
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



void White_pawn::down_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
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



void White_pawn::helper_up_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
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



void White_pawn::up_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
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






void White_pawn::helper_up_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y)
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



void White_pawn::up_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v)
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




void White_pawn::dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    down_left_check_step(ui,row,column,v);
    up_right_check_step(ui,row,column,v);

}



void White_pawn::dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    down_left_check_step(ui,row,column,v);
    up_right_check_step(ui,row,column,v);

}



void White_pawn::dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    up_left_check_step(ui,row,column,v);
    down_right_check_step(ui,row,column,v);

}



void White_pawn::dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow)
{
    std::vector<std::pair<int,int>> v;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    up_left_check_step(ui,row,column,v);
    down_right_check_step(ui,row,column,v);

}




void White_pawn::check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column)
{

    White_rook white_rook;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(3)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        white_rook.green_cell_disappear(ui);

        if(piece==0){
            piece=3;
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



void White_pawn::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite)
{
    White_rook white_rook;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(3)));
        ui->tableWidget->setItem(OldRow,OldColumn,new QTableWidgetItem(""));

        white_rook.green_cell_disappear(ui);

        BlackOrWhite=-1;
        piece=0;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        white_rook.green_cell_disappear(ui);

        if(piece==0){
            piece=3;
            OldRow=row;
            OldColumn=column;

            std::vector<std::pair<int,int>> v;
            v.push_back(std::make_pair(AttackerRow,AttackerColumn));

            up_left_check_step(ui,row,column,v);
            up_right_check_step(ui,row,column,v);
            down_left_check_step(ui,row,column,v);
            down_right_check_step(ui,row,column,v);
        }
        else{
            piece=0;


        }
    }
}

