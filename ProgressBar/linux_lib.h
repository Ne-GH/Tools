#ifndef _LINUX_LIB_H_
#define  _LINUX_LIB_H_

#include <cstdio>

enum COLORS{
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    WHITE = 37,
    NONE = 0
};

void SetColor(int color){
    printf("\033[%dm",color);
}

void HideCursor(){
    printf("\033[?25l");
}
void ShowCursor(){
    printf("\033[?25h");
}


#endif
