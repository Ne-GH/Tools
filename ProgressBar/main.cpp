/*
*    Time: 05/09/22 11:32:49
*    Create By yongheng
*/

#include <iostream>
#include "./ProgressBar.h"

using namespace std;

int main(int argc,char *argv[]){

    ProgressBar pb(100,10);

    for(int i = 0;i < 10; ++i){
        pb.Show();
        pb._now ++;
    }



    return 0;
}
