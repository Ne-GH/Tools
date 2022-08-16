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
    #include "./windows_lib.h"
#elif defined(__linux__) || defined(__unix__)
    #include <unistd.h>
    #include "./linux_lib.h"
#endif

class ProgressBar{
    int _total ;
    int _now ;
    int _wide ;
    int _percentage = 0;

public:
    ProgressBar(int now,int total){ 
        _total = total;
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
    int GetPercentage(int now ,int total ){
        return now * 100 / total;
    }

    void Show(int now,int total){
        int percentage = GetPercentage(now,total);
        String progressbar(_wide>2?_wide:2,'_');
        progressbar[0] = '[';
        progressbar[progressbar.size()-1] = ']';
        for(int i = 1;i < _now*percentage/100; ++i){
            progressbar[i] = '#';
        }
        std::cout << std::setw(_wide) << progressbar << "\r";
        std::fflush(stdout);
    }
    void Show(){
        Show(_now,_total);
    }
    

};



#endif
