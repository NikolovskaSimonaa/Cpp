#include <iostream>

using namespace std;

template <class T>
T minimum(T variable1, T variable2){
    T min=variable1;
    if(min>variable2)
        min=variable2;
    return min;
}

int main(){
    int int1, int2;
    cout<<"Vnesi dva celi broja:"<<endl;
    cin>>int1>>int2;
    cout<<"Pomal broj e brojot: "<<minimum(int1, int2)<<endl;
    double double1, double2;
    cout<<"Vnesi dve double vrednosti:"<<endl;
    cin>>double1>>double2;
    cout<<"Pomal broj e brojot: "<<minimum(double1,double2)<<endl;
    char char1, char2;
    cout<<"Vnesi dva karakteri:"<<endl;
    cin>>char1>>char2;
    cout<<"Pomaliot karakter e: "<<minimum(char1,char2)<<endl;
    return 0;
}
