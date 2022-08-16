/*
*    Time: 05/09/22 11:32:49
*    Create By yongheng
*/

#include "./ProgressBar.h"
#include <unistd.h>

using std::cout;
using std::endl;
using std::setw;
int main(){

    ProgressBar pb(0,100);
    pb.SetWide(50);
    
    for(int i = 0;i < 100; ++i,++ pb){
        String bar = pb.GetProgressBar();
        cout << setw(55) << i << endl;
        std::cout << bar << " " << pb.GetPercentage() << "\r";
        Sleep(1);
    }

    std::cout << std::endl;
    return 0;
}
