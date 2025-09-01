//LEARNT ABOUT ABSTRACT BASE CLASS AND PURE VIRTUAL FUNCTION 
/*Abstract base class:-An abstarct base class is a class whose purpose of creation is to 
use it to derive other classes from it. AND ALSO A ABSTRACT BASE CLASS IS A CLASS WHICH HAS
ATLEAST ONE PURE VIRTUAL FUNCTION
Pure virtual function:- A pure virtual function is a function in the abstract base class 
which is compulsorily defined/overwritten in the derived class ,and it is also a do-nothing
function*/ 
#include <iostream>
#include <string>
using namespace std;
class Splyr
{
protected:
    string title;
    float rating;

public:
    Splyr(string t, float r)
    {
        title = t;
        rating = r;
    }
    virtual void display()=0;//this is a pure virtual function a do nothing function just compulsory for all classes to overwrite/define
    // {
    //     cout << "Virtual nahi lagaya bkl";
    // }
};
class Splyr_vid : public Splyr
{
protected:
    float vid_length;

public:
    Splyr_vid(string s, float r, float vl) : Splyr(s, r)
    {
        vid_length = vl;
    }
    /*IF I COMMMENT OUT THIS FUNCTION MEANING NOT OVERWRITTEN IN THIS CLASS THEN IT WILL THROW
    AN ERROR*/
    void display()
    {
        cout << "The title of the video is " << title << endl;
        cout << "The rating of the video is " << rating << endl;
        cout << "The lenght of the video is  " << vid_length << " minutes" << endl;
    }
};
class Splyr_vidscript : public Splyr
{
protected:
    int scriptwords;

public:
    Splyr_vidscript(string s, float r, int scrw) : Splyr(s, r)
    {
        scriptwords = scrw;
    }
    void display()
    {
        cout << "The title of the video script is " << title << endl;
        cout << "The rating of the video script is " << rating << endl;
        cout << "The length of the video script is " << scriptwords << " words" << endl;
    }
};
int main()
{
    string s1 = "Analog horror";
    float rating1 = 4.59;
    float vidlen = 8.6;
    string s2 = "Analog horror script";
    float rating2 = 4.9;
    int len = 976;
    Splyr_vid vidobj(s1, rating1, vidlen);
    Splyr_vidscript vrsobj(s2, rating2, len);
    Splyr *ptr[2]; // making 2 pointer of the base class
    ptr[0] = &vidobj;
    ptr[1] = &vrsobj;
    ptr[0]->display();
    ptr[1]->display();
    /*IF THE BASE CLASS DISPLAY FUNCTION IS NOT VIRTUAL IT WILL BE CALLED ABOVE OTHERWISE
    THE FUNCTIONS OF THE OJECTS OF RESPECTIVE CLASSES WILL BE CALLED*/
    return 0;
}
/*RULES FOR VIRTUAL FUNCTIONS
1)They cannot be static
2)They are accessed by object pointers
3)Virtual functions can be frineed of another class
4)A virtual function in base class might not be used
5)If a virtual function is defined in a base class,there is no necessity to define it again
in derived class
*/