/*LEARNT ABOUT ARRAY OF OBJECTS USING POINTERS AND USING THEM , AND HOW TO MANIPULATE 
POINTERS*/
//Before doing this revise tut13 pointer arithmetic or array access using pointers
#include <iostream>
using namespace std;
class ShopItem{
int itemId;
float itemPrice;
    public:
    void setdata(int i,float a){
itemId=i;
itemPrice=a;
    }
    void getData(){
        cout<<"Id of item is: "<<itemId<<endl;
        cout<<"Price of item is: "<<itemPrice<<endl;
    }

};
int main(){
    int itmid,size,i;
    float itmprice;
    size=3;
    ShopItem *ptr=new ShopItem[size];/*creating an array of 3 objects and equating pointer 
    returned by the new keyword whihc points to the array of the objects to the ptr pointer*/
    ShopItem *ptrtemp=ptr;//creating a temp pointer for using in loops 
    for(int i=0;i<size;i++){
        cout<<"Enter ID and Price of the item "<<i+1<<endl;
        cin>>itmid>>itmprice;
        ptr->setdata(itmid,itmprice);
        ptr++;
    }/*now at the end of this for loop the ptr is pointing to the last object but we need it
     to point to the first object so we will create a temp pointer at start*/
     //the porblem occuring above will occur same for ptr+1
     //in below loop we can use the temp pointer 
for(i=0;i<size;i++){
    cout<<"The ID and price of the item "<<i+1<<" is "<<endl;
    ptrtemp->getData();
    ptrtemp++;
}
    return 0;
}