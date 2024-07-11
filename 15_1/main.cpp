#include <iostream>

using namespace std;

class Oblik{
public:
    virtual int Plostina(){
        return 0;
    }
    virtual int Volumen(){
        return 0;
    }
    virtual void print()=0;
};

class DvoDimenzionalni:public Oblik{
protected:
    int x, y;
public:
    DvoDimenzionalni(int m, int n){
        x=m;
        y=n;
    }
    void print(){
        cout<<"Dvodimenzionalna figura: ";
    }
};

class TroDimenzionalni:public Oblik{
protected:
    int x, y, z;
public:
    TroDimenzionalni(int m, int n, int q){
        x=m;
        y=n;
        z=q;
    }
    void print(){
        cout<<"Trodimenzionalna figura: ";
    }
};


class Kvadrat:public DvoDimenzionalni{
public:
    Kvadrat(int m):DvoDimenzionalni(m,m){}
    void print(){
        DvoDimenzionalni::print();
        cout<<"Kvadrat"<<endl;
        cout<<"x="<<x<<endl;
    }
    int Plostina(){
        return (x*x);
    }
    int Volumen(){
        return 0;
    }

};

class Pravoagolnik:public DvoDimenzionalni{
public:
    Pravoagolnik(int m, int n):DvoDimenzionalni(m,n){}
    void print(){
        DvoDimenzionalni::print();
        cout<<"Pravoagolnik"<<endl;
        cout<<"x="<<x<<", y="<<y<<endl;
    }
    int Plostina(){
        return (x*y);
    }
    int Volumen(){
        return 0;
    }
};

class Kocka:public TroDimenzionalni{
public:
    Kocka(int m):TroDimenzionalni(m,m,m){}
    void print(){
        TroDimenzionalni::print();
        cout<<"Kocka"<<endl;
        cout<<"x="<<x<<endl;
    }
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
    void print(){
        TroDimenzionalni::print();
        cout<<"Kvadar"<<endl;
        cout<<"x="<<x<<", y="<<y<<", z="<<z<<endl;
    }
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
    K.print();
    cout<<"Plostina: "<<K.Plostina()<<endl;
    cout<<"Volumen: "<<K.Volumen()<<endl<<endl;


    Pravoagolnik P(2,4);
    P.print();
    cout<<"Plostina: "<<P.Plostina()<<endl;
    cout<<"Volumen: "<<P.Volumen()<<endl<<endl;


    Kocka A(3);
    A.print();
    cout<<"Plostina: "<<A.Plostina()<<endl;
    cout<<"Volumen: "<<A.Volumen()<<endl<<endl;

    Kvadar B(3,4,5);
    B.print();
    cout<<"Plostina: "<<B.Plostina()<<endl;
    cout<<"Volumen: "<<B.Volumen()<<endl<<endl;

    return 0;
}
