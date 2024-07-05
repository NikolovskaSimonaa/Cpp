#include <iostream>

using namespace std;

int tripleCallByValue(int count){
    return 3*count;
}

void tripleCallByReference(int &count){
    count=count*3;
}

int main()
{
    int count;
    cout<<"Vnesi broj:"<<endl;
    cin>>count;
    cout<<"Rezultat od funkcijata tripleCallByValue(count): "<<tripleCallByValue(count)<<endl;
    tripleCallByReference(count);
    cout<<"Rezultat od funkcijata tripleCallByReference(count): "<<count<<endl;
    return 0;
}
