/*learnt about structures and unions*/
/*Main diff in class and struct is the data in the struct is by default public and in class it is private
ALSO DIFF BETWEEN STRUCTURE AND UNION IS THAT 
1)IN UNION WE CAN USE MEMORY EFFICIENTLY ,WE CAN ONLY USE ONE DATA TYPE OUT OF THE ONES DECLARED SO THAT EXCESSIVE MEMORY 
IS NOT USED FOR UNUSED DATA TYPES (Memory is allocated once, and all members use the same memory block
In a union, all members share the same memory location, and only the size of the largest 
member determines the total memory allocated for the union..)
2)A structure can include all types of data but in unions only trivial data types can be used like int ,float ,char.
data types such as strings which require a constructor & destructor cannot be used directly*/
#include <iostream>
#include <string>

using namespace std;
int main(){
    /*typedef*/ struct student{
        int RollNo;   //4Bytes used
        string name;   //4Bytes used
         float sgpa;   //4Bytes used
    }/*stu*/;          //by using typedef and stu we can call student as stu and can do like stu Rohandas(giving it a shortform)
    student RohanDas;    //we can also use struct student RohanDas
    RohanDas.RollNo=22;
    RohanDas.name="Rohan Das";
    RohanDas.sgpa=8.55;
    cout<<"Value is:"<<RohanDas.name<<endl;
    cout<<"Value is:"<<RohanDas.RollNo<<endl;
    cout<<"Value is:"<<RohanDas.sgpa<<endl;
    typedef struct newclgstudent : public student  {           //inheritance in structures 
       //string newname; 
    }ncs;
    ncs nigga;
    nigga.name="Premiumnigga";
    cout<<"value of inherited structure member is: "<<nigga.name<<endl; 
    /* 
   UNION: In a union, you can declare multiple members of different data types,
   but only one member can contain a valid value at a time.

   All members share the same memory location, and memory is allocated only once,
   equal to the size of the largest member.

   In the example below, we might use 'rice', 'car', or 'pounds' for exchanging products
   or money. If we assign a value to 'rice', it occupies the shared memory. 
   Later, if we assign a value to 'pounds', it will overwrite the value of 'rice', 
   since both use the same memory space.
*/

    cout<<"UNIONS:"<<endl;
    union money{
        int rice;
       char car;   //1byte used as only car is used
        float pounds;
    };
    union money nkj;
    nkj.car='B';
    cout<<nkj.car<<endl;
    nkj.pounds=2.33;
    cout<<nkj.pounds<<endl;
    cout<<nkj.car<<endl;     //gives gibberish value ╕
    //ENUMS  ENUMS ARE SPECIAL DATA TYPES
    cout<<"ENUMS"<<endl;
    enum rollno{               /*if no value is assigned to the first elemnet in enum then the enum will satrt from 0*/
      RAM,                     //if it is given then it will increment that value by one
      SHYAM,                    //only integers can be assigned
      BABURAO
    };
    cout<<RAM<<endl;
    cout<<SHYAM<<endl;
    cout<<BABURAO<<endl;
    rollno s1=RAM; cout<<s1<<endl;     //TREATING IT AS A DATA TYPE
     int s2=SHYAM;
     //rollno s3=23.11; can't asssign as float
     cout<<(s2==1)<<endl;    //give 1(true)
    //ANOTHER EXAMPLE FOR UNION
    cout<<"\nANOTHER EXAMPLE FOR UNION\n";
    union storedat{      /*inside structures and unions when we declare the variables without any value cpp 
                            compiler assigns it garbage value? and also can we give it a default value?
                            the answer is yes for both*/
      int pendrive;
      float HDD;
      float SSD;
        
    };
 union storedat sd;
 sd.pendrive=64;
 cout<<sd.pendrive<<"GB"<<endl;
 sd.HDD=256;
 cout<<sd.pendrive<<"GB"<<endl;  //gives garbage value
 cout<<sd.HDD<<"GB"<<endl;
     return 0;
}