/*
*    Time: 10/22/22 23:48:42
*    Create By yongheng
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string,int> mp;
string srcnum;
string match;
string srcbase;
string desbase;
string tohex;
string todec;
string tobin;

void InitMap(){
    mp["0"] = 0;
    mp["1"] = 1;
    mp["2"] = 2;
    mp["3"] = 3;
    mp["4"] = 4;
    mp["5"] = 5;
    mp["6"] = 6;
    mp["7"] = 7;
    mp["8"] = 8;
    mp["9"] = 9;
    mp["A"] = mp["a"] = 10;
    mp["B"] = mp["b"] = 11;
    mp["C"] = mp["c"] = 12;
    mp["D"] = mp["d"] = 13;
    mp["E"] = mp["e"] = 14;
    mp["F"] = mp["f"] = 15;

}

int ToDec(){
    
    int ret = 0;

    for(int i = 0;i < srcnum.size(); ++i){
        ret += pow(srcbase,i);
    }

}




int main(int argc,char *argv[]){



    match = string(argv[1]);
    srcnum = string(argv[2]);
    reverse(srcnum.begin(),srcnum.end());


    InitMap();

    if(match == "BTD"){
        srcbase = 2;
        desbase = 10;

    }
    else if(match == "BTH"){
        srcbase = 2;
        desbase = 16;

    }
    else if(match == "DTB"){
        srcbase = 10;
        desbase = 2;

    }
    else if(match == "DTH"){
        srcbase = 10;
        desbase = 16;

    }
    else if(match == "HTB"){
        srcbase = 16;
        desbase = 2;

    }
    else if(match == "HTD"){
        srcbase = 16;
        desbase = 10;

    }
    else if(match == "FTB"){
        srcbase = 10;
        desbase = 2;

    }
    else if(match == "FTH"){
        srcbase = 10;
        desbase = 16;

    }







    return 0;
}
