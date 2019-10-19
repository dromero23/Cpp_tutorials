#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int a[9][9];

int main( int argc, char **argv)
{
    int un=0, r,c,tmp;
    bool b=1;
    const char *filename = "sudoku.txt"
    ifstream in(filename);
    if (!in.isopen())
    {
        cout<< "Problem with the file\n";
        return 0;
    }
    for (int i=0;i<9;i++)
    {
        for (int j =0;j<9;j++)
        {
            in >> a[i][j];
            if(!a[i][j])
                un++;
        }
    }
    in.close();
    //main loop 
    while (un && b)
    {
        b = 0; 
        for (int i =0; i<9; i++){
            for (int j =0; j<9; j++)
            {
                if (a[j][i])
                    continue;
                tmp = 0;
                for (int x = 1; x<10; x++)
                {
                    if (row(i,j,x) && columns (i,j,x) && square (i,j,x)
                }
            }
        }
    }
    return 0;
}