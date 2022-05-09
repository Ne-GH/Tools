/*
*    Time: 04/19/22 22:14:49
*    Create By yongheng
*/


#include "./domain.h"

int main(int argc,char *argv[]){

    Domain domain("www.baidu.com");
    domain = Domain("www.bing.com");

    vector<string>ip = domain.Ip();
    vector<string>name = domain.Name();
    vector<string>officename = domain.Official_Name();
    cout << "domain:" << endl;
    for(auto _: name){
        cout << _ << endl;
    }
    cout << endl;

    cout << "office name:" << endl;
    for(auto _: officename){
        cout << _ << endl;
    }
    cout << endl;

    cout << "ip:" << endl;
    for(auto _: ip){
        cout << _ << endl;
    }


    return 0;
}

