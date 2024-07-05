#include <iostream>

using namespace std;

inline double circleArea(double radius){
    return radius*radius*3.14;
}

int main()
{
    double radius;
    cout<<"Vnesi go radiusot na krugot:"<<endl;
    cin>>radius;
    cout<<"Povrsinata na krugot e "<<circleArea(radius)<<endl;
    return 0;
}
