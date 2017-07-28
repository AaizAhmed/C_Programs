#include "board.h"

int is_valid(char str[]);

void play_game()
{
    int col_num;

    for (int i = 0; i < ROWS*COLUMNS; i++)
    {
        if (i % 2 == 0)
        {
            printf("Player 1: What is your choice?\n");
            scanf("%d", &col_num);

            make_move(0, col_num);
            print_board();

            if (is_win())
            {
                printf("Player 1: Congratulations!! You won!\n");
                return;
            }
        }
        else
        {
            printf("Player 2: What is your choice?\n");
            scanf("%d", &col_num);

            make_move(1, col_num);
            print_board();

            if (is_win())
            {
                printf("Player 2: Congratulations!! You won!\n");
                return;
            }
        }
    }

    printf("There was a draw!\n");
}

int is_valid(char str[])
{
    char num[20];

    while(true)
    {
        printf("Enter the number of %s.\nMinimum accepted value is 5: ", str);
        gets(num);
        printf("\n");

        if (atoi(num) >= 5)
        {
            break;
        }
        else
            printf("Wrong Input! Enter a valid numbers\n\n");
    }

    return atoi(num);
}

int main()
{
    char quit = 'y';

    while (quit != 'n')
    {
        ROWS = is_valid("Rows");
        COLUMNS = is_valid("Columns");

        set_board(ROWS, COLUMNS);
        print_board();

        play_game();

        printf("Do you want to play again? y or n\n");
        scanf(" %c", &quit);
    }

    free_board();

    return 0;
}
