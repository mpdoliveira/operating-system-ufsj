#include <stdio.h>

void tc_clear() {
    puts("\x1b[2J");
}

void tc_mv_cursor(int row, int col) {
    printf("\x1b[%d;%dH", row, col);
}