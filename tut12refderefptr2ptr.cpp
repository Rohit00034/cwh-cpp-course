//learnt referencing &(address of)p,dereferencing *(value at)p, pointer *p.pointer to pointer **p
//NOTE: the pointer of a variable should be same as the type of variable
#include <iostream>
using namespace std;
int main(){
     int a=99;
     int *b=&a;
     cout<<"Value of a is:"<<a<<endl;
     cout<<"Value(address of a) of b is:"<<b<<endl;
     cout<<"Address of b is:"<<&b<<endl;
     int **c=&b;            //a pointer to pointer stores the address of a pointer
     cout<<"Address of pointer b is :"<<c<<endl;
     cout<<"Address at pointer b(address of variable a) is :"<<*c<<endl;
     cout<<"value of pointer b is :"<<**c<<endl;
     cout<<"Address of the pointer to pointer c is:"<<&c<<endl;
     //int **d=&c; we cannot store the address of the pointer to pointer in another pointer
return 0;
}

