//LEARNT ABOUT TEMPLATE WITH MULTIPLE PARAMETERS
#include <iostream>
using namespace std;
//CLASS TEMPLATE WITH MULTIPLE PARAMETERS
template <class T1,class T2> //template with multiple parameters//can't do like <class T1,T2>
class PrintTwo{
public:
T1 data1;
T2 data2;
PrintTwo(T1 d1,T2 d2){
    data1=d1;
    data2=d2;
}
void display(){
    cout<<"VALUE OF DATA1 IS: "<<data1<<endl;
    cout<<"VALUE OF DATA2 IS: "<<data2<<endl;
}
};
int main(){
    PrintTwo<int,char> obj1(2,'H');
    obj1.display();
    PrintTwo<int,string> obj2(2,"Hello");
    obj2.display();
    return 0;
}

/*i meant  we can use anything instead of 'typename' word right? beacues i have seen people use 'class' there*/
/*Yes, you are absolutely correct. In the context of declaring a template parameter, **`class` and `typename` are completely interchangeable**.

There is **no semantic difference** between them when used to define a type parameter. The compiler treats `template <class T>` and `template <typename T>` exactly the same way.

**Why two keywords?**
*   **History**: `class` was the original keyword used in early C++ because template authors initially expected to use mostly user-defined classes.
*   **Clarity**: `typename` was introduced later to make it clear that the parameter can be *any* type (including built-in types like `int` or `double`), not just a class. This avoids the misconception that `T` must be a class.

**The One Critical Exception**
While they are interchangeable for *declaring* the parameter, you **must** use `typename` (and cannot use `class`) when referring to a **dependent nested type** inside the template definition. This tells the compiler that a scoped name refers to a type.

```cpp
template <class T> // 'class' works fine here (same as 'typename')
void func() {
    // ERROR: 'class' cannot be used here. 
    // You MUST use 'typename' to tell the compiler T::value_type is a type.
    typename T::value_type x; 
}
```

**Recommendation**
Modern C++ style guides generally prefer **`typename`** for template parameters because it is more explicit and consistent, especially since you are forced to use it for dependent types anyway. However, seeing `class` in older code or simple templates is perfectly valid.

*/