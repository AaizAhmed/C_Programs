#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int ROWS, COLUMNS;
char **board;

bool make_move(int player, int col);
bool vertical_win();
bool horizontal_win();
bool diagonal_one_win();
bool diagonal_two_win();
bool is_win();
bool is_draw();
bool is_full();

void set_board(int row, int col);
void print_board();
void free_board();
