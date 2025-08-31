#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){

    ofstream fp("Day.txt",ios::app);
    if(fp.is_open()){
        char name[50];
        char age[3];
        char city[30];

        cout<<"Enter Full Name : ";
        cin.getline(name,sizeof(name));
        cout<<"Enter City Name : ";
        cin.getline(city,sizeof(city));
        cout<<"Enter Age : ";
        cin.getline(age,sizeof(age));
        fp<<"Name : "<<name<<endl;
       fp<<" City : "<<city<<endl;
       fp<<" Age : "<<age<<endl;
    
       cout<<" Successfully added";
      fp.close();
    }
    else{
        cout<<"Unable to opened \n";
    }

    return 0;
}