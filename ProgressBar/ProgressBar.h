/*
*    Time: 05/09/22 11:29:07
*    Create By yongheng
*/

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <iostream>


class ProgressBar{
public:
    int total = 0;
    int now = 0;


    

    void Show(){
        int finish = now*100/total;
        std::cout << "[" ;

        while(finish --){
            std::cout << "\033[31m#" << "\033[0m";
        }

        std::cout << "]";
    }
};


#endif
