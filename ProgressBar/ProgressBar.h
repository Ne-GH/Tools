/*
*    Time: 05/09/22 11:29:07
*    Create By yongheng
*/

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using String = std::string;

#if defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
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


#elif defined(__linux__) || defined(__unix__)
    #include <unistd.h>
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

class ProgressBar{
    int _total ;
    int _now ;
    int _wide ;
    int _percentage = 0;

public:
    ProgressBar(int now,int total){ 
        _total = total-1 < 0 ? 0: total-1;
        _now = now;
        _wide = 100;
    }
    void SetWide(int wide){
        _wide = wide;
    }
    void SetTotal(int total){
        _total = total;
    }
    void SetNow(int now){
        _now = now;
    }
    int GetPercentage(){
        return _now * 100 / _total;
    }
    String GetProgressBar(){
        int percentage = GetPercentage();
        String progressbar(_wide>2?_wide:2,'_');
        
        for(int i = 1;i < _wide*percentage/100; ++i){
            progressbar[i] = '#';
        }
        progressbar[0] = '[';
        progressbar[progressbar.size()-1] = ']';
        return progressbar;
    }
    void Show(int now,int total){
        int percentage = GetPercentage();
        String progressbar = GetProgressBar();
        std::cout << std::setw(_wide) << progressbar << "\r";
        std::fflush(stdout);
    }
    void Show(){
        Show(_now,_total);
    }
    
    ProgressBar operator ++(){
        this->_now ++;
        if(_now > _total)
            _now = _total;
        return *this;
    }
};



#endif
