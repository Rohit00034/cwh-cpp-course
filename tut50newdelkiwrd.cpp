/*LEARNT ABOUT NEW AND DELETE KEYWRD/OPERATOR ,HOW TO ALLOCATE/DEALLOCATED SINGLE MEMORY OR
BLOCK OF MEMORY*/
#include <iostream>
using namespace std;
int main(){
    //REVIEW TUT12 AND 13 FOR POINTER CLARITY
    //NEW KEYWORD/OPERATOR
    int* intptr=new int(10); //dynamically allocated a value for int 10 in the memory //we can also do floatand other data types here 
    /*here the new keyword returns a pointer which has the address of int value 10.
    here we are basically equating one int pointer to another*/
    cout<<"Value at address "<<intptr<<" is "<<*(intptr)<<endl; //() is optional for single variables ,compulsory for *(ptr+1) as done in tut13
    /*allocating memory dynamically means doing it at runtime or depending on user input
    */
   //allocating block of contigous memory for multiple ints
   int* arr= new int[3]; //allocated memory for 3 int variables
   arr[0]=2;//assigned values at the arr[0] 
   *(arr+1)=3; 
   arr[2]=6;
   cout<<"Value of arr[0] is "<<arr[0]<<endl;
   //PROOF THAT IT IS CONTIGOus block of memory
   cout<<arr<<endl; //we will get starting of the block of memory
   cout<<&arr[0]<<endl;//we will get the same address as this is the first element at start of block of memory 
   cout<</*can do like we did in tut13*/arr+1<<endl;//here we can see that the address calculation formula is applicable (address(new)=address(old/at index 0)+i*sizeof datatype)   
   cout<<&arr[2]<<endl;//end of the memory block
   //DELETE KEYWORD/OPERATOR
   //it is used to dynamically deallcoate the memory 
   delete intptr; //deleted intptr
//    cout<<*intptr; we will get a garbage value 
//to delete a block of memory
delete [] arr; 
    return 0;
}