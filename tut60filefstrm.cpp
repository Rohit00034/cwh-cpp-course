//LEARNT ABOUT BASIC READING AND WRITING FROM AND INTO FILES
#include <iostream>
#include <fstream> //used for file handling THIS IS A HEADER FILE WHICH HAS VARIOUS CLASSES IN IT
using namespace std;
/*The sueful classes for working with files are
1)fstreambase
2)ifstream(INPUT FILE STREAM) -->derived from fstreambase
3)ofstream(OUTPUT FILE STREAM) -->derived from fstreambase
*/
/*In order to work with files you will have to open them. There are two ways to open a file
1)using the constructor
2)using the member function open() of the class*/
int main(){
    //opening a file using constructor of the class and writing to it
    string str="NUCLEAR CODES ARE #2@!312*&&%@#";
    ofstream out("tut60text.txt"); //this can open a file and if it doesn't exist it can create and open it
    out<<str; //writing operation
    //opening file using constructor and reading from it
    string strin;
    ifstream in("tut60sample.txt");
in>>strin;
cout<<strin<<endl;/*here we can see that only the first word is here ,words after the space are 
not taken in beacuse >> does not take escape characters so to get full line we will use getline()*/
getline(in,strin);
cout<<strin; 
    return 0;
}