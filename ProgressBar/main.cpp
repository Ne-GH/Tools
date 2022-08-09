/*
*    Time: 05/09/22 11:32:49
*    Create By yongheng
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

#if defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
    #include "./windows_lib.h"
#elif defined(__linux__) || defined(__unix__)
    #include "./linux_lib.h"
#endif
// #include "./ProgressBar.h"

using namespace std;

int main(int argc,char *argv[]){

    
    int num = 0;
    string str(101,'_');
    str[0] = '[';
    str[str.size()-1] = ']';

    int max = 100;
    for(int i = 1;i <= 100; ++i){
        SetColor(i % 16);
        cout << left << setw(110) << i << endl;
        cout << setw(103) << str << " " << i << "%" << "\r";
        str[i] = '#';
        // printf("%-100s %-2d\r",str,i);
        Sleep(50);
    }
    cout << endl;
    SetColor(NONE);
    cout << 100 ;

    cin >> num;
    return 0;
}
