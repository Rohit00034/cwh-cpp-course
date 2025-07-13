//LEARNT about classes and diff between class and structures.
//Note:use structures when security is not a concern and use classes when you need security
#include <iostream>
#include <string>

using namespace std;
typedef struct Student{  //data inside a structure is by def public in class it is private
string name;
private:        //structs now can have private variables
int rollno;
public:
char div;
void cartwheel(){  //we can define functions in a structure and inherit just like classes
    cout<<name<<" Performed a cartwheel\n";
}
}stu;
class Gamedevteam{
private: //these members are private and cannot be accessed directly
int devsalary,marketleadsalary,designersal,sfxartistsal,vfxartistsal;
public:
string CompanyEstNetWorth="1200000$";
int devnum=12,marketleadnum=3,designernum=4,sfxartistnum=3,vfxartistnum=2;
void setpridata(int ds,int mls,int dgs,int sfs,int vfs);//declaration
void getdata(){
    cout<<"There are "<<devnum<<" developers working on game\n";
    cout<<"There are "<<marketleadnum<<" marketers for marketing the game\n";
    cout<<"There are "<<designernum<<" marketers for marketing the game\n";
    //etc etc
};

};
void Gamedevteam::setpridata(int ds,int mls,int dgs,int sfs,int vfs){  //definition
devsalary=ds;
marketleadsalary=mls;
designersal=dgs;
sfxartistsal=sfs;
vfxartistsal=vfs;
}
int main(){
    struct Student s1;  //or stu s1,structures are typedefed by def in c++
    s1.name="Ramesh";
    s1.cartwheel();
    Gamedevteam horrorgame;  //horrogame is object of class gamedevteam
horrorgame.setpridata(24000,18000,21000,18000,23000);
    horrorgame.getdata();
    //cout<<horrorgame.devsalary; won't work as devsalary is private
  cout<<horrorgame.CompanyEstNetWorth; //works because Company... is public member
    return 0;
}