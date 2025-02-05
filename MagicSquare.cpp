#include <iostream>

using namespace std;

#define SIZE 5

void generateMagicSquare(int square[SIZE][SIZE])
{
    int row = 0, col = SIZE / 2;

    for (int num = 1; num <= SIZE * SIZE; num++)
    {
        square[row][col] = num; 
        int newRow = (row - 1 + SIZE) % SIZE;
        int newCol = (col + 1) % SIZE;

        if (square[newRow][newCol] != 0)
        {                           
            row = (row + 1) % SIZE;
        }
        else
        {
            row = newRow;
            col = newCol;
        }
    }
}

void printMagicSquare(int square[SIZE][SIZE])
{
    cout << "Magic Square of size " << SIZE << " x " << SIZE << ":\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << square[i][j] << "\t"; 
        }
        cout << endl;
    }
}

int main()
{
    int magicSquare[SIZE][SIZE] = {0}; 

    generateMagicSquare(magicSquare); 
    printMagicSquare(magicSquare);    

    return 0;
}
