//Learnt about Object memory allocation and Use of arrays in classes
/*The memory allocation of class is not done until an object is created ,the 
data(maybe variables or functions ) common for all the objects use a common memory block
for instance we can say functions that are used by all the objects are assigned a common
memory block,and the variables like name and roll no which are diff for every object are 
assigned diff memory refer tut23.img for diagram*/
#include <iostream>
using namespace std;
class Shop{
int counter;
public:
int itemid[100];
int itemprice[100];
void inicounter();
void setprice();
void displayprice();

};
void Shop::inicounter(){  //sets the counter to zero
    counter=0;
}
void Shop::setprice(){
    cout<<"Enter the itemid: ";
    cin>>itemid[counter];
    cout<<"Enter the price of the item: ";
    cin>>itemprice[counter];
    counter++;
}
void Shop::displayprice(){
cout<<"Displaying items\n";
    for (int i = 0; i < counter; i++)
{
    cout<<"Item id: "<<itemid[i]<<" Item Price: "<<itemprice[i];
}

}
int main(){
    Shop dukaan;
    dukaan.inicounter();
    dukaan.setprice();
    dukaan.setprice();
    dukaan.setprice();
    dukaan.displayprice();
    return 0;
}