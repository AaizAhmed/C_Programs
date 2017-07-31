#include "board.h"

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

int get_column()
{
    char num[20];

    while(true)
    {
        printf("Enter a number between 1 and %d: ", COLUMNS);
        gets(num);
        printf("\n");

        int check = atoi(num);

        if (check >= 1 && check <= COLUMNS)
        {
            if (is_full(check))
            {
                printf("This column is already full. Try a different one\n");
            }
            else
               break;
        }
        else
            printf("Wrong Input! Enter a valid numbers\n\n");
    }

    return atoi(num);
}

void play_game()
{
    int col_num;

    for (int i = 0; i < ROWS*COLUMNS; i++)
    {
        if (i % 2 == 0)
        {
            printf("\nPlayer 1: What is your choice?\n");

            int num = get_column();

            make_move(0, num);
            print_board();

            if (is_win())
            {
                printf("\nPlayer 1: Congratulations!! You won!\n");
                return;
            }
        }
        else
        {
            printf("\nPlayer 2: What is your choice?\n");

            int num = get_column();

            make_move(1, num);
            print_board();

            if (is_win())
            {
                printf("\nPlayer 2: Congratulations!! You won!\n");
                return;
            }
        }
    }

    printf("\nThere was a draw!\n");
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

        printf("\nDo you want to play again? y or n\n");
        scanf(" %c", &quit);
    }

    free_board();

    return 0;
}
