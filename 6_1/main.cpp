#include <iostream>
#include <cstring>

using namespace std;

class Covek{
private:
    char ime[20];
    char prezime[20];
    char adresa[20];
    char telefon[10];
public:
    Covek(char *i=(char*)"", char *p=(char*)"", char *a=(char*)"", char *t=(char*)""){
        strncpy(ime,i,20);
        strncpy(prezime,p,20);
        strncpy(adresa,a,20);
        strncpy(telefon,t,10);
    }
    void print(){
        cout<<"Ime i prezime: "<<ime<<" "<<prezime<<endl;
        cout<<"Adresa: "<<adresa<<endl;
        cout<<"Telefon: "<<telefon<<endl;
    }
    ~Covek(){}
};

class Stedac{
private:
    static float kamata;
    static int brojStedaci;
    float bilans;
    float kredit;
    Covek ID;
public:
    Stedac(float k, Covek C){
        kredit=k;
        bilans=kredit+kredit*kamata;
        ID=C;
    brojStedaci++;
    }
    static int getbrojStedaci(){
        return brojStedaci;
    }
    void print(){
        ID.print();
        cout<<"Kredit vo bankata: "<<kredit<<endl;
        cout<<"Vkupen bilans: "<<bilans<<endl;
    }
    ~Stedac(){}
};

int Stedac::brojStedaci=0;
float Stedac::kamata=0.05;

int main()
{
    char i[20], p[20], a[20], t[10];
    cout<<"Vnesi ime, prezime, adresa and telefon na klientot"<<endl;
    cin>>i>>p>>a>>t;
    Covek C1(i,p,a,t);
    float k;
    cout<<"Vnesi kredit:"<<endl;
    cin>>k;
    Stedac S1(k,C1);
    cout<<"Vkupen broj na stedaci: "<<Stedac::getbrojStedaci()<<endl;
    S1.print();
    cout<<"Vnesi ime, prezime, adresa and telefon na klientot"<<endl;
    cin>>i>>p>>a>>t;
    Covek C2(i,p,a,t);
    cout<<"Vnesi kredit:"<<endl;
    cin>>k;
    Stedac S2(k,C2);
    cout<<"Vkupen broj na stedaci: "<<Stedac::getbrojStedaci()<<endl;
    S2.print();
    return 0;
}
