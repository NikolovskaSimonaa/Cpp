#include <iostream>

using namespace std;

class Oblik{
protected:
    int x;
public:
    Oblik(int n){
        x=n;
    }
    void print(){
        cout<<"x="<<x<<endl;
    }
};

class DvoDimenzionalni:public Oblik{
protected:
    int y;
public:
    DvoDimenzionalni(int m, int n):Oblik(m){
        y=n;
    }
    void print(){
        Oblik::print();
        cout<<"y="<<y<<endl;
    }
};

class TroDimenzionalni:public DvoDimenzionalni{
protected:
    int z;
public:
    TroDimenzionalni(int m, int n, int q):DvoDimenzionalni(m,n){
        z=q;
    }
    void print(){
        DvoDimenzionalni::print();
        cout<<"z="<<z<<endl;
    }
};

class Kvadrat:public DvoDimenzionalni{
public:
    Kvadrat(int m):DvoDimenzionalni(m,m){}
    int Perimetar(){
        return (4*x);
    }
    int Plostina(){
        return (x*x);
    }
};

class Pravoagolnik:public DvoDimenzionalni{
public:
    Pravoagolnik(int m, int n):DvoDimenzionalni(m,n){}
    int Perimetar(){
        return (2*x+2*y);
    }
    int Plostina(){
        return (x*y);
    }
};

class Kocka:public TroDimenzionalni{
public:
    Kocka(int m):TroDimenzionalni(m,m,m){}
    int Plostina(){
        return 6*x*x;
    }
    int Volumen(){
        return x*x*x;
    }
};

class Kvadar:public TroDimenzionalni{
public:
    Kvadar(int m, int n, int q):TroDimenzionalni(m,n,q){}
    int Plostina(){
        return 2*(x*y+x*z+y*z);
    }
    int Volumen(){
        return x*y*z;
    }
};

int main()
{
    Kvadrat K(5);
    cout<<"Kvadrat"<<endl;
    K.print();
    cout<<"Perimetar: "<<K.Perimetar()<<endl;
    cout<<"Plostina: "<<K.Plostina()<<endl<<endl;


    Pravoagolnik P(2,4);
    cout<<"Pravoagolnik"<<endl;
    P.print();
    cout<<"Perimetar: "<<P.Perimetar()<<endl;
    cout<<"Plostina: "<<P.Plostina()<<endl<<endl;


    Kocka A(3);
    cout<<"Kocka"<<endl;
    A.print();
    cout<<"Plostina: "<<A.Plostina()<<endl;
    cout<<"Volumen: "<<A.Volumen()<<endl<<endl;

    Kvadar B(3,4,5);
    cout<<"Kvadar"<<endl;
    B.print();
    cout<<"Plostina: "<<B.Plostina()<<endl;
    cout<<"Volumen: "<<B.Volumen()<<endl<<endl;

    return 0;
}
