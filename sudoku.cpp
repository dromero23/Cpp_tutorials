#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

static int sudoku[9][9]={0};
int fillNum(int column, int row);
bool tryRow(int number, int column);
bool tryColumn(int number, int row);
bool trySquare(int number, int column, int row);
void printSudoku(void);

int main(int argc, char **argv){
    bool isSolved=1;
    bool filledRow[9]={0};
    int emptyCount =0;
    fstream myfile;
    if(argc>1)
        myfile.open(argv[1]);
    else
        myfile.open("sudoku.txt");
    
    for(int column=0; column<9; column++){
        for(int row=0; row<9; row++){
            myfile>>sudoku[column][row];
            if(sudoku[column][row]== 0)
                emptyCount++;
        }
    }   
    cout<< "Text file: "<<endl;
    printSudoku();
    cout<<"\n\n\n"<<endl;
    int rowComplete=9;
    while(emptyCount && isSolved){
        isSolved=0;
        for(int column=0; column<9; column++){
            rowComplete=9;
            if(filledRow[column])
                continue;
            for(int row=0; row<9; row++)
            {
                if (sudoku[column][row]!=0)
                {
                    if(--rowComplete == 0)
                        filledRow[column]=1;
                    continue;
                }
                sudoku[column][row]=fillNum(column,row);
                if(sudoku[column][row]!=0){
                    isSolved=1;
                    emptyCount--;
                }
            }
        }
    }
    if(emptyCount){
        cout<<"Sudoku not solvable"<<endl;
        return 0;
    }
    cout<< "After: "<<endl;
    printSudoku();
    return 0;    
}


int fillNum(int column, int row){
   bool isUnique = 0;
   int temp=0;
   
   for(int number=1;number<=9;number++){
        if (tryRow(number,column) && tryColumn(number,row) && trySquare(number, column, row)) 
        {
            if (!isUnique)
            {
                temp = number;
                isUnique=1;
            }
            else
            {
                isUnique=0;
                return 0;
            }
        }
   }
   return temp;   
}

bool tryRow(int number, int column){
    for(int row=0; row<9;row++)
        if(sudoku[column][row]==number)
            return false;
    return true;
}

bool tryColumn(int number, int row){
    for(int column=0; column<9;column++)
        if(sudoku[column][row]==number)
            return false;
    return true;
}

bool trySquare(int number, int column, int row){
    int startColumn= static_cast<int>(floor(column/3))*3;
    int startRow = static_cast<int>(floor(row/3))*3;
    for (int col=0;col<3;col++)
    {
        for (int r=0;r<3;r++)
        {
            if(sudoku[startColumn+col][startRow+r]==number)
                return false;
        }
    }
    return true;
}

void printSudoku(void){
    for(int column=0; column<9; column++){
        for(int row=0; row<9; row++)
            cout<<sudoku[column][row]<<' ';
        cout<<endl;
    }   
}