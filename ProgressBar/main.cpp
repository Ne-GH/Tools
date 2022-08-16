/*
*    Time: 05/09/22 11:32:49
*    Create By yongheng
*/

#include "./ProgressBar.h"
#include <unistd.h>

int main(){

    ProgressBar pb(0,100);
    pb.SetWide(50);
    
    for(int i = 0;i < 100; ++i,++ pb){
        String bar = pb.GetProgressBar();
        std::cout << bar << " " << pb.GetPercentage() << "\r";
        Sleep(1);
    }

    std::cout << std::endl;
    return 0;
}
