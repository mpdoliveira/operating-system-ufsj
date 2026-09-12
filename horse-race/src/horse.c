#include <stdio.h>

#include "terminal_control.h"
#include "horse.h"

static const char *HORSE_LEGS[] = {
    "  // // ",
    "   \\\\// ",
    "   \\\\ \\\\",
    "  //  \\\\"
};

static const char *HORSE_COLORS[] = {
    TC_GRN,
    TC_RED,
    TC_BLU,
    TC_YEL,
    TC_MGT,
    TC_CYA,
};

void print_horse( int row, int col, int leg, int color_key) {

    printf("%s", HORSE_COLORS[color_key % 6]); //set horse color

    tc_mv_cursor(row, col);
    printf("%s", HORSE_HEAD); //print head

    tc_mv_cursor(row + 1, col);
    printf("%s", HORSE_BODY); //print body

    tc_mv_cursor(row + 2, col);
    printf("%s", HORSE_LEGS[leg % HORSE_FRAMES]); //print legs (1 of frames)

    printf("%s", TC_RST); //reset terminal color
}