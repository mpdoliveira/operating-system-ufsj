#ifndef TC_H
#define TC_H

//basic terminal colors
#define TC_RST "\x1b[0m"
#define TC_BLK "\x1b[30m"
#define TC_RED "\x1b[31m"
#define TC_GRN "\x1b[32m"
#define TC_YEL "\x1b[33m"
#define TC_BLU "\x1b[34m"
#define TC_MGT "\x1b[35m"
#define TC_CYA "\x1b[36m"
#define TC_WHT "\x1b[37m"
#define TC_GRY "\x1b[38;5;235m"

//clear terminal
void tc_clear();

//move cursor to row and column
void tc_mv_cursor(int row, int col);

#endif