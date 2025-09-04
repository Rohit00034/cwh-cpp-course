//LEARNT ABOUT MAPS IN STL AND ITS METHODS
//maps are associative conatianers/arrays ,they are like dictionary on python(key: value )pairs
#include <iostream>
#include <map>
using namespace std;
int main(){
    map<string,int> marksmap;
    marksmap["Kaido"]=32;
    marksmap["luffy"]=56; 
    marksmap["Zoro"]=100;
    //inserting elements in the dictionary
    marksmap.insert({{"Sanji",63},{"Usopp",10}});
    //displaying a map
    map<string,int> ::iterator iter;
    
    for (iter=marksmap.begin(); iter!=marksmap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<" "<<endl; //first refers to the key and .second to value
    }
    //size()function
    cout<<marksmap.size()<<endl;
    //max_size()function
    cout<<marksmap.max_size()<<endl;
    //empty()function
    cout<<marksmap.empty()<<endl;
    //look for more info on cppreference site
    return 0;
}