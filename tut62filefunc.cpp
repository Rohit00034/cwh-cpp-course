//LEARNT ABOUT open()AND eof() function in file handling
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream opfile;
    //2nd way of opening a file is by using a function rather than constructor
    opfile.open("tut62sample.txt"); /*it is a function of class which opens a file and if 
    it does not exist it creates it.*/
    opfile<<"this is my file"<<endl; 
    opfile<<"this file is mine\n"; 
    opfile<<"file is owned by me\n";
    opfile<<"Kachraseth\n";

    opfile.close();
    ifstream ipfile;
    ipfile.open("tut62sample.txt");
    string str;
    while(ipfile.eof()==0){  /*eof here is end of file function eof() returns true AFTER 
        an attempt to read past the end of file*/ 
        getline(ipfile,str);
        cout<<str<<endl;
    }
    ipfile.close();//the file closes when the program ends but  this is a good practice
    return 0;
}