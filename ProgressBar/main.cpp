/*
*    Time: 05/09/22 11:32:49
*    Create By yongheng
*/

#include "./ProgressBar.h"
#include <unistd.h>

int main(){

    ProgressBar pb(0,100);
    pb.SetWide(100);

    for(int i = 0;i < 100; ++i){
        pb.SetNow(i);
        std::cout << std::setw(100) << i << std::endl;
        pb.Show();
        usleep(50000);
    }


    return 0;
}
