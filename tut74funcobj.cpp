//LEARNT ABOUT FUNCTORS(FUNCTION OBJECTS)
#include <iostream>
#include <functional> //contains the functors(function objects)
#include <algorithm>
using namespace std;
//template function to display any type of array
template <class T>
void disparr(T arrt,int size){
cout<<"[";
 //NOTE: in the function the arrt is treated as an int* pointer
    for (int i=0; i < size; i++) 
     {
        cout<<arrt[i]<<",";
        
     } 
     cout<<"]"<<endl;
}

int main(){
    /*Function objects(functors) are functions wrapped in classes so that they can be 
    accessed like an object,It is an object which is like a function here the () operator 
    is overloaded*/
    int arr[]={43,76,12,3,1,6,60,56,34};
    int size=(sizeof(arr)/sizeof(arr[0])); 
    sort(arr,arr+5/*means sort the arr array till index 5*/);//this method is from the STL <algorithm> header file/lib
    disparr(arr,size);
    //sorting the array in descending order
    sort(arr,arr+size,greater<int>());//here the greater<int>() is a functor
    //the sort method takes an object in argument in place of greater<int>() which is also an obvject that we gave 
    disparr(arr,size);
    //check cppreference site for more info
    //multithreading in cpp can be done using the <thread> header file
     
      
    return 0;
}