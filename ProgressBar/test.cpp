/*
*    Time: 05/09/22 11:32:49
*    Create By yongheng
*/

#include <iostream>
#include "./ProgressBar.h"

using namespace std;

int main(int argc,char *argv[]){

    ProgressBar pb;
    pb.amount = 70;
    pb.now = 7;
    pb.Show();



    return 0;
}
