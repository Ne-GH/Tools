/*
*    Time: 04/06/22 22:26:06
*    Create By yongheng
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc,char *argv[]){

    argc --;
    argv ++;
    
    string str;
    int mod = 0;
    str = argv[0];
    mod = stoi(str);
    argc--;
    argv++;

    for(int i = 0;i < argc; ++i){
        cout << argv[i] << ":" << stoi(argv[i])%mod << endl;
    }




    return 0;
}
