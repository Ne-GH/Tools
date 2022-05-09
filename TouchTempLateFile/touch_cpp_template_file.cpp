#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

fstream file;
time_t cur_time = time(0);
tm t = *localtime(&cur_time);
string str;
string filename;

int headfile = 0;
int maplib = 0;
int filelib = 0;
int vectorlib = 0;
int stringlib = 0;
int algorithmlib = 0;
int stacklib = 0;
int queuelib = 0;
int randomlib = 0;
int no_main = 0;

string GetHeadMagic(){
    string str;
    for(auto ch : filename){
        if(ch >= 'a' && ch <= 'z')
            ch -= 32;
        else if(ch == '.')
            return str;

        str += ch;
    }

    return str;
}
void Create_Head_File(){
    file << 
    "#ifndef "  << GetHeadMagic()+"_H" << endl <<
    "#define "  << GetHeadMagic()+"_H"
                << endl
                << endl
                << endl
                << endl     << 
    "#endif";

}

void Scan_Parameter(vector<string>argv){

    for(int i = 0;i < argv.size(); ++i){
        str = argv[i];
        if(str == "-no" || str == "-nom" || str == "nomain")
            no_main = 1;
        else if(str == "-f" || str == "-file")
            filelib = 1;
        else if(str == "-str" || str == "-string")
            stringlib = 1;
        else if(str == "-v" || str == "-vec" || str == "-vector")
            vectorlib = 1;
        else if(str == "-a" || str == "-alg" || str == "-algorithm")
            algorithmlib = 1;
        else if(str == "-m" || str == "-map")
            maplib = 1;
        else if(str == "-sta" || str == "-stack")
            stacklib = 1;
        else if(str == "-que" || str == "-queue")
            queuelib = 1;
        else if(str == "-r" || str == "-rand" || str == "-random")
            randomlib = 1;

        else if(str == "-h" || str == "-head"){
            headfile = 1;
            no_main = 1;
        }
        
        else{
            filename = argv[i];
        }

    }
    if(headfile != 1)
        filename += ".cpp";
    else 
        filename += ".h";
}

void Create_Comment(){

    file << 
        "/*"                                        << endl <<
        "*    Time: " << put_time(&t, "%D %T")      << endl <<
        "*    Create By yongheng"                   << endl <<
        "*/"                                        << endl <<
        ""                                          << endl;
}

void Create_Head(){

    file << "#include <iostream>"   << endl;
    if(stringlib == 1)
        file << "#include <string>" << endl;
    if(vectorlib == 1)
        file << "#include <vector>" << endl;
    if(maplib == 1)
        file << "#include <map>"    << endl;
    if(stacklib == 1)
        file << "#include <stack>"  << endl;
    if(queuelib == 1)
        file << "#include <queue>"  << endl;
    if(filelib == 1)
        file << "#include <fstream>" << endl;
    if(algorithmlib == 1)
        file << "#include <algorithm>"<< endl;
    if(randomlib == 1)
        file << "#include <random>" << endl;
}

void Create_Main(){

    file << ""                                      << endl <<
        "using namespace std;"                      << endl <<
        "";
        file << endl << 
        "int main(int argc,char *argv[]){"          << endl <<
        ""                                          << endl <<
        ""                                          << endl <<
        ""                                          << endl <<
        ""                                          << endl <<
        "    return 0;"                             << endl <<
        "}";

}


int main(int argc,char *argv[]){
    argc --;
    argv ++;
    

    vector<string>parameters;
    for(int i = 0;i < argc; ++i){
        parameters.push_back(argv[i]);
    }
    Scan_Parameter(parameters);
    

    file.open(filename);
    if(file){
        file.close();
        cout << "文件存在" << endl;
        exit (1);
    }
    else{
        file.open(filename,ios::out);

        Create_Comment();

        if(no_main != 1){
            Create_Head();
            Create_Main();
        }
        else{
            Create_Head_File();
        }

    }
    
    return 0;
}
