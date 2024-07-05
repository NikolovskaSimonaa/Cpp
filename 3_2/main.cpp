#include <iostream>
#include <string.h>

using namespace std;

class Stedac
{
private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;

public:
    void vnesi_podatoci(int br, char ip[], char adresa[], unsigned long s){
        broj=br;
        strcpy(imeprezime,ip);
        strcpy(adresa,adresa);
        saldo=s;
    }
    void prikazi_podatoci(){
        cout<<"ID: "<<broj<<", Ime i prezime: "<<imeprezime<<", Adresa: "<<adresa<<", Saldo: "<<saldo<<endl;
    }
    void uplata(unsigned long i){
        saldo+=i;
    }
    void isplata(unsigned long i){
        if(saldo>=i)
            saldo=saldo-i;
        else
            cout<<"Ne e mozna takva isplata"<<endl;
    }
    long sostojba(){
        return saldo;
    }
};

int main()
{
    Stedac s;
    int id;
    char ip[30], adresa[50];
    long saldo;
    cout<<"Vnesi podatoci:"<<endl;
    cin>>id;
    cin.ignore();
    gets(ip);
    gets(adresa);
    cin>>saldo;
    s.vnesi_podatoci(id,ip,adresa,saldo);
    s.prikazi_podatoci();
    long uplata;
    cout<<"Vnesi suma za uplata:"<<endl;
    cin>>uplata;
    s.uplata(uplata);
    long isplata;
    cout<<"Vnesi suma za isplata"<<endl;
    cin>>isplata;
    s.isplata(isplata);
    cout<<"Tekovno saldo: "<<s.sostojba()<<endl;
    s.prikazi_podatoci();
    return 0;
}

