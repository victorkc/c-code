#ifndef __GENERAL_H__
#define __GENERAL_H__

#define _GNU_SOURCE
#include <errno.h>

#define BOARD_FN "whites_board"
#define SIZE     8

#define USAGE "\
    Usage: %s \n\
           Shows the board contained in <" BOARD_FN "> \n\
           and checks for tower possibilities.\n\
"
#endif

