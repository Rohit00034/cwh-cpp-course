//LEARNT ABOUT VECTORS AND ITS FUNCTIONS IN STL
#include <iostream>
#include <vector>
using namespace std;
/*A vector is a sequential container in the STL (is a template as we may see has a similar
syntax as using a class template) , which is like a resizeable array */
template <class T>  //created a template to display any type of vector ;)
void displayvec(vector<T> &v){
    cout<<"Elements in the vector are: "<<"[";
for (int i = 0; i < v.size(); i++)  //size() function gives number of elements in the vector
{
    cout<<v[i]<<" ";
    // cout<<v.at(i)<<" "; can also use the at()function for same result
}
cout<<"]"<<endl;
}
int main(){
    vector<int> vec1; //we can create any type of vector
    int element,size;
    cout<<"Enter the size of the vector: ";
    cin>>size;cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the element to put in vector: ";
        cin>>element;
        vec1.push_back(element);  //is a method to insert elements in the vector
    }
    displayvec(vec1);
    vec1.pop_back();//used to rmeove the last element inserted in the vector
    cout<<"Vector after pop_back(): ";
    displayvec(vec1);
    vector<int> ::iterator iter=vec1.begin(); /*here iter is the name of the iterator (which 
    is like a pointer or an a pointer-like object that can move through the vector ) of type int pointing at the beginning
    of the vector using the begin() function */ 
    vec1.insert(iter,0);//the insert function requires an iterator(is a pointer) and the element to add
    displayvec(vec1);
    //if i want to insert it at index 2 then i can simply do iter+1 just like pointer in tut13
    vec1.insert(iter+1,0);
    displayvec(vec1);
    //if i want to insert 5 consecutive elements that can also be done as follows
    iter=vec1.begin();// re-assign after insert, to avoid invalidation //below code wasn't working without this line
    // vec1.insert(iter+1,5,21);//inserting 5 times 21 at index     
    displayvec(vec1);
    cout<<endl;
    //ways to create a vector
    // vector<int> vec1; //simple way
    vector<char> vec2(4);//4 element vector
    vector<char> vec3(vec2);//4 element vector vec3 from vec2 
    vector<int> vec4(6,15);//6 element vector of 15's
    displayvec(vec4);
    //REFER THE CPLUSPLUS.COM SITE FOR GETTING THE INFO(FUNCITONS AND OTHER INFO) AS WELL AS THE COMPLEXITY OF THESE
    return 0;
}