//LEARNT ABOUT FILE I/O AND CLOSING A FILE
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    //writing into file
    ofstream opfile("tut61sample.txt");
    string name;
    cout<<"Enter your name: "<<endl;
    getline(cin,name); //to get name with blank spaces
    opfile<<"The name is "+name;
    opfile.close();//closing the file
    //reading from file
    ifstream ipfile("tut61sample.txt");
    string data;
    getline(ipfile,data);
    cout<<"The data in file is: "<<endl<<data;
ipfile.close();
    return 0;
}