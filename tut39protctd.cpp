//LEARNT ABOUT PRIVATE ACCESS SPECIFIER IN INHERITANCE AND WORKING OF ACCESS SPECIFIERS  WITH INHERITANCE
/*THE PROTECTED ACCESS SPECIFIER IS LIKE PRIVATE ONLY THE DIFFERENCE IS THAT IT CAN BE INHERITED BUT CANNOT BE 
ACCESSED DIRECTLY JUST LIKE PRIVATE*/
#include <iostream>
using namespace std;
class Base{
    protected:
    int a;
    private:
    int b;
};
class Derived :protected Base{

};
/*working of access specifiers with inheritance
      Visibiltiy mode:      public inheritance   Private inheritance       protected inheritance
1)Private members          Cannot be inherited    Cannot be inherited       Cannot be inherited      
2)Protected members          Remain protected         become private          Remain protected
3)Public members            Remain public           Become private           Become protected
*/
int main(){
    Derived d;
    // cout<<d.a; this will not work asa is a protected member but it is inherited unlike private members
    return 0;
}