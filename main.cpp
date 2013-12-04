//Вариант 10. В каждой строке массива A(N,M) найти и удалить максимальный элемент.
#include <iostream>
#include <stdlib.h>
using namespace std;
const int Columns = 7;
void InputStartMatrix( int Matrix[][Columns] , int Rows);
void OutputStartMatrix( int Matrix[][Columns], int Rows);
int FindMaxOfString ( int Rows , int Matrix[][Columns], int NumRow);
void MaxToLast( int Rows, int Matrix[][Columns], int NumRow);
void OutputFinishedMatrix( int Matrix[][Columns], int Rows );
int main()
{
    const int Rows = 10;
    int Matrix[Rows][Columns];
    InputStartMatrix( Matrix, Rows );
    OutputStartMatrix( Matrix, Rows );
    for( int i = 0; i < Rows; ++i)
    {
        MaxToLast( Rows, Matrix, i );
    }
    OutputFinishedMatrix( Matrix, Rows );
    return 0;
}
void InputStartMatrix( int Matrix[][Columns], int Rows)
{
    for( int i = 0; i < Rows; ++i )
    {
        for( int j = 0; j < Columns; ++j )
        {
            Matrix[i][j] = rand( ) % 10;
        }
    }
}
void OutputStartMatrix( int Matrix[][Columns], int Rows )
{
    cout << " Start Matrix: \n\n";
    for( int i = 0; i < Rows; ++i )
    {
        for( int j = 0; j < Columns; ++j )
        {
            cout.width(4);
            cout << Matrix[i][j];
            if ( j == Columns - 1)
            {
                cout << endl <<endl;
            }
        }
    }
    cout << endl;
}
int FindMaxOfString ( int Rows , int Matrix[][Columns], int NumRow)
{
    int Max;
    Max = Matrix[NumRow][0];
    for (int j = 0; j < Columns; ++j)
    {
        if ( Max < Matrix[NumRow][j])
        {
            Max = Matrix[NumRow][j];
        }
    }
    return Max;
}
void MaxToLast(int Rows,int Matrix[][Columns], int NumRow )
{
    for( int j = 0; j < Columns; ++j)
    {
        int Max = FindMaxOfString ( Rows , Matrix, NumRow);
        if( Matrix[NumRow][j] == Max)
        {
            for(int k = j; k < Columns; ++k)
            {
                Matrix[NumRow][k] = Matrix[NumRow][k+1];
            }
            Matrix[NumRow][Columns - 1] = Max;
        }

    }
}
void OutputFinishedMatrix( int Matrix[][Columns], int Rows )
{
    cout << endl << " Finished Matrix: \n\n";
    for( int i = 0; i < Rows; ++i )
    {
        for( int j = 0; j < Columns-1; ++j )
        {
            cout.width(4);
            cout << Matrix[i][j];
            if ( j == Columns - 2)
            {
                cout << endl <<endl;
            }
        }
    }
}
