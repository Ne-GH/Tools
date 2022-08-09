#ifndef _WINDOWS_LIB_H_
#define _WINDOWS_LIB_H_
#include <windows.h>


// void SetTitle(char title[]){
//     SetConsoleTitle(title);
//     return;
// }

void SetColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    return;
}

#endif