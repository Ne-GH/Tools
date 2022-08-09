/*
*    Time: 05/09/22 11:32:49
*    Create By yongheng
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
// #include "./ProgressBar.h"

using namespace std;

int main(int argc,char *argv[]){

int num = 0;
    string str(101,'_');
    str[0] = '[';
    str[str.size()-1] = ']';

    int max = 100;
    for(int i = 1;i <= 100; ++i){
        
        cout << left << setw(110) << i << endl;
        cout << setw(103) << str << " " << i << "%" << "\r";
        str[i] = '#';
        // printf("%-100s %-2d\r",str,i);
        Sleep(100);
    }
    cout << endl;
    cout << hex << 100 << endl;
    cout << dec << 16 << endl;
    return 0;
}
