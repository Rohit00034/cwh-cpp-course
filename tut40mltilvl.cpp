//LEARNT ABOUT MULTILEVEL INHERITANCE
#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_number;

public:
    void setrollnum(int r)
    {
        roll_number = r;
    }
    void getrollnum(void);
};
void Student ::getrollnum()
{
    cout << "Roll number is : " << roll_number << endl;
}
class Exam : public Student
{
protected:
    float mathsmarks, physicsmarks, chemmarks;

public:
    void setmarks(float, float, float);
    void getmarks();
};
void Exam ::setmarks(float m1, float p1, float c1)
{
    mathsmarks = m1;
    physicsmarks = p1;
    chemmarks = c1;
}
void Exam ::getmarks()
{
    cout << "Marks in maths are : " << mathsmarks << endl;
    cout << "Marks in physics are : " << physicsmarks << endl;
    cout << "Marks in chem are : " << chemmarks << endl;
}
class Result : public Exam
{
public:
    void getresult()
    {
        cout << "Your result is: " << (mathsmarks + physicsmarks + chemmarks) / 3 << endl;
    }
};
/*Notes:-
If we are inheriting B from A and C from B [A-->B-->C]
1)A is the base class for B and B is the base class for C
2)A-->B-->C is called the inheritance path
*/
int main()
{
    Result harry;
    harry.setrollnum(40);
    harry.setmarks(90.3, 96.2, 94.8);
    harry.getrollnum();
    harry.getmarks();
    harry.getresult();
    return 0;
}