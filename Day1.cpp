#include<iostream>
#include<fstream>
using namespace std;

int main(){


    ifstream fp ("Day.txt",ios::in);
    if(! fp.is_open()){
        cout<<" No file is available ";
        return 1;
    }
    
    string ch;
    while(getline(fp,ch)){
        cout<<ch<<endl;
    }
    fp.close();



    return 0;
}