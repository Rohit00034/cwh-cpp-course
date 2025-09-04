//Learnt about list(doubly linked list) in STL and it's methods
/* std::list is a doubly linked list. 
   Insertion and deletion are faster than in arrays/vectors 
   (no shifting or reallocation needed). 
   However, accessing an element is slower because random access is not supported 
   and you must use iterators to traverse. */
#include <iostream>
#include <list>
using namespace std;
template <class T>
void displaylst(list<T> &list1){
    typename list<T> ::iterator iter;  /*here we needed to use the typename because the 
    compiler does not know what a list<T> is so we told the compiler that it is a type of 
    data,detailed explanation at the end of the code*/
    cout<<"[";
    for (iter=list1.begin(); iter!=list1.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<"]"<<endl;
    
}
int main(){
    list<int> list1; //list of len 0
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(5);
    list1.push_back(3);
    displaylst(list1);
    //Removing elements from the list
    // list1.pop_back();//same function like vector removes one element from back
    // list1.pop_front();//same function like vector removes one element from front
    // list1.remove(5);//we can also remove specific values
    //sorting the list
    list1.sort();
    displaylst(list1);
    //reversing the list
    list1.reverse();displaylst(list1);

    list<int> list2(4); // empty list of size 4 
    //now here the list2 has the 4 elements but has no value to those elements
    displaylst(list2); //so here we will get 0 values (null)
    //inserting elements into the list using iterator not push_back()
    list<int> ::iterator iter;
    iter=list2.begin();
    *iter=7;iter++; //dereferencing the iter and incrementing it just like tut13
    *iter=32;iter++;
    *iter=6;iter++;
    *iter=4;iter++; //also list is resizable so we can insert more elements
    displaylst(list2);
    //Merging two list
    list1.merge(list2);
    cout<<"list1 after merging";displaylst(list1);
//look cppreference site for more info 

    return 0;
}

/*The problem

Inside a template, list<T>::iterator depends on the template parameter T.
The compiler doesn’t know if list<T>::iterator is a type or something else (like a static member).

So you must explicitly tell the compiler:
👉 “Yes, this is a type.”

That’s what the typename keyword is for.

🔹 Fix
template <class T>
void displaylst(list<T> &list1) {
    typename list<T>::iterator iter;  // 👈 add 'typename'

    for (iter = list1.begin(); iter != list1.end(); iter++) {
        cout << *iter << " ";
    }
}

🔹 Why your error happened

Without typename, the compiler sees list<T>::iterator and says:
“Wait, is iterator a variable? a static constant? I don’t know, because it depends on T.”

typename clears that up.*/

/*i meant in list<int> :: iterator iter; what is ti for an iterartor?
ChatGPT said:

Ahh got it 👍 you’re asking specifically:

👉 In list<int>::iterator iter; what exactly is list<int> here for the iterator?

🔹 Breaking it down
list<int>::iterator iter;


list<int> → this is the class template specialization of std::list where the stored type is int.

::iterator → this is a nested type defined inside std::list<int>.

So you’re telling the compiler:
“Give me the iterator type that belongs to the class list<int>.”

🔹 What is list<int>::iterator?

It’s a type alias defined inside the list class, like:

template<class T>
class list {
public:
    class iterator { 
        // implementation details...
    };
};


So when you write list<int>::iterator, you’re saying:
➡️ “Use the iterator type from the list<int> specialization.”

🔹 Why do we need it?

STL containers (vector, list, map, etc.) don’t use raw pointers directly.
They define their own iterator types so you can traverse the container safely.

For vector<int>, vector<int>::iterator is usually just a raw pointer int*.

For list<int>, list<int>::iterator is a class object that knows how to move along a doubly linked list.*/