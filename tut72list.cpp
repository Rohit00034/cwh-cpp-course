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

/*Question:- the difference between a stl::list and vector is that in list the elements do not occupy contiguous blocks of memory and in vector they do am i right? and a vector is resizable they say so if it occupies contiguous blocks of memory then when resized i.e an element is added so the new element is just at the continuous end of the contiguous block?*/
/*You are **partially correct**, but there is a crucial nuance regarding how `std::vector` handles resizing that distinguishes it from a simple array.

### 1. Memory Layout: Contiguous vs. Non-Contiguous
*   **`std::vector`**: You are correct. Elements are stored in a **single contiguous block** of memory. This allows for pointer arithmetic and cache-friendly access.
*   **`std::list`**: You are correct. Elements are stored in **non-contiguous nodes** scattered across memory. Each node contains the data plus pointers to the previous and next nodes (doubly linked).

### 2. How Resizing Works in `std::vector`
Your assumption that "the new element is just at the continuous end" is **only true if there is pre-allocated spare space**.

`std::vector` manages two distinct metrics:
*   **Size**: The number of elements currently holding data.
*   **Capacity**: The total number of elements the currently allocated memory block can hold.

**Scenario A: Capacity > Size (Fast)**
If you add an element and the vector has spare capacity (e.g., Size is 5, Capacity is 10), the new element is indeed placed **directly at the continuous end** of the existing block. This is an $O(1)$ operation.

**Scenario B: Capacity == Size (Reallocation)**
If you add an element and the vector is full (Size equals Capacity), it cannot simply extend the block because the adjacent memory might be occupied by other variables. Instead, it must:
1.  **Allocate** a completely **new, larger contiguous block** of memory (typically 1.5x or 2x the old size).
2.  **Move/Copy** all existing elements from the old block to the new block.
3.  **Destroy** the old block and return its memory to the system.
4.  Place the new element at the end of the **new** block.

This reallocation process is expensive ($O(n)$) and invalidates all pointers, references, and iterators to the elements.

### Summary Comparison

| Feature | `std::vector` | `std::list` |
| :--- | :--- | :--- |
| **Memory Layout** | **Contiguous** (single block) | **Non-contiguous** (scattered nodes) |
| **Adding Element** | Fast if capacity exists; **Slow** if reallocation is needed. | Always **Fast** (allocates one new node). |
| **Reallocation** | **Yes**: Moves entire block to new location when full. | **No**: Nodes are independent; no moving required. |
| **Access Speed** | **Fast** ($O(1)$ random access via index). | **Slow** ($O(n)$ traversal required). |

**Recommendation**: If you know the approximate number of elements beforehand, use `vector.reserve(n)` to pre-allocate memory. This forces the vector to allocate a large enough block initially, ensuring that subsequent additions simply place elements at the continuous end without triggering expensive reallocations.

*/