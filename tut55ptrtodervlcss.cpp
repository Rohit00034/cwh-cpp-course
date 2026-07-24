//LEARNT ABOUT POINTER TO DERIVED CLASSES AND DEMONSTRATED RUNTIME POLYMORPHISM
#include <iostream>
using namespace std;
class Base_class{
public:
int basevar;
void display(){
    cout<<"The value of base class var is "<<basevar<<endl;
}
};
class Derived_class:public Base_class{
public:
int derivedvar;
void display(){
    cout<<"The value of base class var is "<<basevar<<endl;
    cout<<"The value of derived class var is "<<derivedvar<<endl;
}
};
int main(){
    Base_class* base_class_pointer; //base calss pointer
    Derived_class derivedobj;//object of drived class
    base_class_pointer=&derivedobj;//base class pointer pointing to the derived class object
    /*now here we can only use the attribute fo the base class using the base class pointer
    even though the pointer is pointing the derived class object*/
    base_class_pointer->basevar=43;//we can acces the base class varr
    base_class_pointer->display();/*will run the base class function as the pointer is of 
    base class ,late binding occurs here*/
    // base_class_pointer->derivedvar=98;//will throw a error
    Derived_class * derived_class_pointer;
    derived_class_pointer=&derivedobj;
    derived_class_pointer->basevar=90; //we can acces the attrivbutes of the base class too
    derived_class_pointer->derivedvar=178;
    derived_class_pointer->display(); //here the derived class funciton will run
    derived_class_pointer->Base_class::display(); //we can also acces hte base class fucntion using the scope resoultion operator
    //THIS ABOVE DECIDING OF WHICH FUNCTION WILL BE USED IS DONE IN RUNTIME 
    return 0;
}
/*Your code demonstrates **pointers to derived classes**, but it **does not actually demonstrate runtime polymorphism or late binding** because the `display()` function is **not declared as `virtual`**.

Let's break it down.

---

# What is Runtime Polymorphism?

Runtime polymorphism means

> The decision of **which overridden function to call** is made **while the program is running**, not during compilation.

This is also called

* Dynamic Binding
* Late Binding
* Dynamic Dispatch

It requires:

1. Inheritance
2. Function overriding
3. **virtual** keyword
4. Base class pointer/reference

---

# What your code currently has

```cpp
class Base_class{
public:
    void display(){
        cout<<"Base display";
    }
};

class Derived_class : public Base_class{
public:
    void display(){
        cout<<"Derived display";
    }
};
```

Now,

```cpp
Base_class* base_class_pointer;
Derived_class derivedobj;

base_class_pointer = &derivedobj;
```

The pointer is

```
Base_class*
      |
      v
+----------------------+
| Derived_class object |
+----------------------+
```

---

Then you do

```cpp
base_class_pointer->display();
```

Since `display()` is **not virtual**, the compiler looks only at

> What is the type of the pointer?

Pointer type is

```
Base_class*
```

So it directly generates code to call

```
Base_class::display()
```

This decision is made during compilation.

This is called

## Early Binding (Static Binding)

Not runtime polymorphism.

Output:

```
The value of base class var is 43
```

---

# Why isn't this runtime polymorphism?

Because there is no `virtual`.

Compiler already knows

```
base_class_pointer
```

is a `Base_class*`

so it fixes the function call while compiling.

Nothing is decided during runtime.

---

# What should the code be?

```cpp
class Base_class{
public:
    int basevar;

    virtual void display(){
        cout<<"Base class "<<basevar<<endl;
    }
};
```

Now everything changes.

---

Suppose

```cpp
Derived_class obj;

Base_class* ptr = &obj;

ptr->display();
```

Compiler now says

> "I don't know which object this pointer will point to while the program runs."

So instead of directly calling

```
Base_class::display()
```

it inserts code like

```
Check actual object
↓
If Base object
    call Base display
If Derived object
    call Derived display
```

This checking happens **while the program is executing**.

This is

* Runtime Polymorphism
* Dynamic Binding
* Late Binding

---

# What actually happens internally?

Every class having a virtual function gets a hidden pointer called

```
vptr
```

which points to a table called

```
vtable
```

Imagine

```
Base class

+-------------+
| basevar     |
| vptr ------+--------+
+-------------+        |
                        |
                        V
                  Base vtable
                 +------------------+
                 | display() ------>| Base::display()
                 +------------------+
```

Derived object

```
+----------------+
| basevar        |
| derivedvar     |
| vptr --------+-----------+
+----------------+          |
                             |
                             V
                       Derived vtable
                      +----------------------+
                      | display() ---------->| Derived::display()
                      +----------------------+
```

---

Now

```
Base_class* ptr = &derivedobj;
```

actually looks like

```
ptr
 |
 V
+----------------------+
| Derived Object       |
|                      |
| vptr--------------------------+
+----------------------+         |
                                 |
                                 V
                           Derived vtable
                           display()
                                 |
                                 V
                     Derived_class::display()
```

So

```cpp
ptr->display();
```

works like

```
ptr
↓

Find vptr

↓

Find display()

↓

Call Derived display
```

This lookup happens during execution.

Hence

**Late Binding.**

---

# Difference between Early and Late Binding

Without virtual

```
Base* ptr = &derived;

ptr->display();
```

Compiler decides

```
Pointer type = Base*

↓

Call Base display
```

Output

```
Base display
```

Decision made at compile time.

---

With virtual

```
Base* ptr = &derived;

ptr->display();
```

Compiler generates

```
Pointer

↓

Actual object?

↓

Derived

↓

Call Derived display
```

Output

```
Derived display
```

Decision made at runtime.

---

# Your comment is incorrect

You wrote

```cpp
base_class_pointer->display(); // late binding occurs here
```

This is **incorrect**.

It should be

```cpp
base_class_pointer->display();
// Calls Base_class::display() because display() is NOT virtual.
// This is compile-time (early/static) binding.
```

---

# Correct code demonstrating runtime polymorphism

```cpp
#include <iostream>
using namespace std;

class Base_class{
public:
    int basevar;

    virtual void display(){      // virtual
        cout << "Base variable = " << basevar << endl;
    }
};

class Derived_class : public Base_class{
public:
    int derivedvar;

    void display() override{
        cout << "Base variable = " << basevar << endl;
        cout << "Derived variable = " << derivedvar << endl;
    }
};

int main(){

    Base_class* ptr;
    Derived_class obj;

    ptr = &obj;

    ptr->basevar = 50;

    obj.derivedvar = 100;

    ptr->display();   // Calls Derived_class::display()

    return 0;
}
```

Output:

```
Base variable = 50
Derived variable = 100
```

This is a true demonstration of **runtime polymorphism**, where the base-class pointer invokes the derived-class implementation because `display()` is declared `virtual`.
*/