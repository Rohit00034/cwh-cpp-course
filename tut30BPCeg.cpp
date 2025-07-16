//SAW EXAMPLE OF PARAMETRIZED CONSTRUCTOR
#include <iostream>
#include <cmath>
using namespace std;
class Point{
int x,y;
public:
Point(int a,int b){
    x=a;
    y=b;
}
void displaypoint(){
cout<<"The point is at ("<<x<<","<<y<<")\n";
}
friend float distbetpts(Point,Point);
};
/*CHALLENGE create a function that take 2 point class objects and return the distance 
between the 2 points*/
//formula =sqrtof(square of(x2-x1)+square of(y2-y1))
float distbetpts(Point o1,Point o2){
float result =sqrt(((o2.x-o1.x)*(o2.x-o1.x))+((o2.y-o1.y)*(o2.y-o1.y)));
return result;
}
int main(){
    Point p(1,3);
    p.displaypoint();
    Point q(2,6);
    q.displaypoint();
    cout<<"The distance between these points is:"<<distbetpts(p,q);
    return 0;
}