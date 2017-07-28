#include "board.h"

void set_board(int rows, int cols)
{
    ROWS = rows;
    COLUMNS = cols;

    // Allocating memory for the board as a 2D array
    board = (char**) malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (char*) malloc(cols * sizeof(char));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = '-';
        }
    }
}

void print_board()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c", board[i][j] );
        }

        printf("\n");
    }
}

void free_board()
{
    for(int i = 0; i < ROWS; i++)
    {
        free(board[i]);
    }

    free(board);
}

bool horizontal_win()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS-3; j++)
        {
            if ( board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]
                && board[i][j+2] == board[i][j+3] )
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool vertical_win()
{
    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < ROWS-3; j++)
        {
            if ( board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i]
                && board[j+2][i] == board[j+3][i] )
            {
                if (board[j][i] == 'X' || board[j][i] == 'O')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool diagonal_one_win()
{
    for(int i = 0; i < ROWS-3; i++)
    {
        for(int j = 0; j < COLUMNS-3; j++)
        {
            if ( board[i][j] == board[i+1][j+1] && board[i+1][j+1]  == board[i+2][j+2]
                && board[i+2][j+2] == board[i+3][j+3] )
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    return true;
                }
            }

        }
    }
    return false;
}

bool diagonal_two_win()
{
    for (int i = ROWS-1; i >= 3; i--)
    {
        for (int j = 0; j < COLUMNS-3; j++)
        {
            if ( board[i][j] == board[i-1][j+1] && board[i-1][j+1] == board[i-2][j+2]
                && board[i-2][j+2] == board[i-3][j+3] )
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool is_win()
{
    if (horizontal_win() == true || vertical_win() == true ||
        diagonal_one_win() == true || diagonal_two_win() == true)
    {
        return true;
    }
    return false;
}

bool is_draw()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS-3; j++)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

bool is_full(int col)
{
    if (col > 0 && col <= COLUMNS)
    {
        col = col - 1;

        if (board[0][col] == 'X' || board[0][col] == 'O')
        {
            return true;
        }
    }
    return false;
}

bool make_move(int player, int col)
{
    if (col > 0 && col <= COLUMNS)
    {
        col = col - 1;

        for (int i = ROWS-1; i >= 0; i--)
        {
            if (board[i][col] == '-')
            {
                if (player == 0)
                {
                    board[i][col] = 'X';
                }
                else if (player == 1)
                {
                    board[i][col] = 'O';
                }
                return true;
            }
        }
    }
}

//int main()
//{
//    bool x = true;
//    printf(x ? "true\n" : "false\n");
//
//    return 0;
//}



