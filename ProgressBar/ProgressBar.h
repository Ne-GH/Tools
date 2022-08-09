/*
*    Time: 05/09/22 11:29:07
*    Create By yongheng
*/

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#if defined(_WIN32) || defined(_WIN64)
    #include "windows_lib.h"
#elif defined(__unix__) || defined(__linux__)
    #define "linux_lib.h"
#endif

class ProgressBar{
public:
    int _total = 0;
    int _now = 0;

    ProgressBar(int total,int now):_total(total),_now(now){

    }

    void Show(){
        SetColor(0x9);
        int completed = _now * 70 / _total;
        cout << "[";
        for(int i = 0;i < completed; ++i){
            cout << "#";
        }
        for(int i = completed;i < 70; ++i){
            cout << "_";
        }
        cout << "]";

        printf("%4d%\n",completed);

        SetColor(0x7);
    }
    

};


#endif
