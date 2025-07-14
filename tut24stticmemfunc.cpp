//LEARNT ABOUT STATIC CLASS MEMBERS AND STATIC MEMBER FUNCTIONS
#include <iostream>
using namespace std;
class Employee
{
    int empid;
    static int count; /* here the default value of count(static variable) is not a garbage 
    value it's 0,the memory of the count is a class memory and it is accessed by all the 
    objects it is not seperately allocated for each objects so it is called as class variable
    ,it's lifetuime is till program execution*/
public:
    void setid()
    {
        cout << "Enter the Empid: ";
        cin >> empid;
        count++;
    }
    void displayemp()
    {
        cout << "The employee id is " << empid << "and is " << count << "th" << " employee\n";
    }
    static void getcount(){  /*this is a static member function which can only access static members and
        other static functions*/   //we can also access a static member with a simple function
        //cout<<empid; this throws an error 
        cout<<"The value of count is "<<count<<endl;
    }
};
int Employee ::count;//we can initialize it here as count=100 if we want it to start from 100 instead of 0 
/*static variable is written outside the class ,this line is written
because we need to associate the count variable with the Employee class so we cna use it in
the setid()function to increment it*/
int main()
{
    Employee emp1harry, emp2hairy,emp3rohan;
    
    emp1harry.setid();
    emp1harry.displayemp();
    Employee::getcount(); //a static member can be accessed without using an object ,directly by using class
    emp1harry.getcount();//it can also be done in the traditional way
    emp2hairy.setid();
    emp2hairy.displayemp();
    Employee::getcount();
    emp3rohan.setid(); 
    emp3rohan.displayemp();
    Employee::getcount();
    return 0;
}