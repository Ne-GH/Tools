#ifndef _WINDOWS_LIB_H_
#define _WINDOWS_LIB_H_
#include <windows.h>

// void SetTitle(char title[]){
//     SetConsoleTitle(title);
//     return;
// }

enum COLORS{
    BLACK,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LAKE_BLUE,
    REDDISH,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    BLUE,
    GREEN,
    SHALLOW_LIGHT_GREEN,
    RED,
    LAVENDER,
    SHALLOW_YELLOW,
    LIGHT_WHITE,
    NONE = LIGHT_WHITE
};

void SetColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    return;
}

#endif