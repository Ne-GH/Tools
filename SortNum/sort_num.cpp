/*
*    Time: 04/09/22 13:48:12
*    Create By yongheng
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Help(){
    cout << 
        "such as:\n" << 
        "input:     ./Sort_Num 3 1 5 12 8 0\n" <<
        "output:    0 1 3 5 8 12\n" << endl;
}

int main(int argc,char *argv[]){

    argc--;
    argv++;

    for(int i = 0;i < argc; ++i){
        string str = argv[i];
        if(str == "-h" || str == "--h" || str == "-help" || str == "--help"){
            Help();
            return 0;
        }
        else if(str == "-H" || str == "--H" || str == "-Help" || str == "--Help"){
            Help();
            return 0;
        }
    }

    vector<int> vec;
    if(argc > 1){
        for(int i = 0;i < argc; ++i){
            vec.push_back(stoi(argv[i]));
        }
    }

    else{
        int nums_len = 0;
        cout << "please input nums len:";
        cin >> nums_len;
        for(int i = 0;i < nums_len; ++i){
            int num;
            cin >> num;
            vec.push_back(num);
        }
    }


    sort(vec.begin(),vec.end());

    for(auto _ : vec){
        cout << _ << " ";
    }
    cout << endl;



    return 0;
}
