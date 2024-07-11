#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Datum{
private:
    int den, mesec, godina;
public:
    Datum(int d=1, int m=1, int g=2024){
        den=d;
        mesec=m;
        godina=g;
    }
    int getDen(){
        return den;
    }
    int getMesec(){
        return mesec;
    }
    int getGodina(){
        return godina;
    }
    void print(){
        cout<<den<<"/"<<mesec<<"/"<<godina<<endl;
    }
};

class Zivotno{
protected:
    Datum datum_na_ragjanje;
    Datum datum_na_donesuvanje_vo_zoo;
    Datum datum_na_vakcinacija;
    char pol; // m - maski, z - zenski
    char ime[20];
public:
    Zivotno(char p='m', char *i=(char*)"Ime", Datum r=Datum(), Datum pr=Datum(), Datum v=Datum()){
        datum_na_ragjanje=r;
        datum_na_donesuvanje_vo_zoo=pr;
        datum_na_vakcinacija=v;
        pol=p;
        strcpy(ime,i);
    }

    void prikaziPodatoci(){
        cout<<"Ime na zivotnoto: "<<ime<<endl;
        cout<<"Pol: "<<pol<<endl;
        cout<<"Datum na ragjanje: ";
        datum_na_ragjanje.print();
        cout<<"Datum na donesuvanje vo zoo: ";
        datum_na_donesuvanje_vo_zoo.print();
        cout<<"Datum na posledna vakcinacija: ";
        datum_na_vakcinacija.print();
    }
    virtual int Vakcinacija(Datum D)=0;
};

class Vlekac:public Zivotno{
private:
    Datum sledna_vakcinacija;
public:
    Vlekac(char p='m', char *i=(char*)"Ime", Datum r=Datum(), Datum pr=Datum(), Datum v=Datum(), Datum s=Datum()):Zivotno(p,i,r,pr,v){
        sledna_vakcinacija=s;
    }
    void print(){
        prikaziPodatoci();
        cout<<"Datum na sledna vakcinacija: ";
        sledna_vakcinacija.print();
    }
    int Vakcinacija(Datum D){
        int d1, m1, g1, d2, m2, g2;
        d1=sledna_vakcinacija.getDen();
        m1=sledna_vakcinacija.getMesec();
        g1=sledna_vakcinacija.getGodina();
        d2=D.getDen();
        m2=D.getMesec();
        g2=D.getGodina();
        if(g1==g2 && m1==m2){
            if(abs(d1-d2)<=7) return 1;
            else return 0;
        }else
            return 0;
    }
};

class Ptica:public Zivotno{
private:
    bool letac;
public:
    Ptica(char p='m', char *i=(char*)"Ime", Datum r=Datum(), Datum pr=Datum(), Datum v=Datum(), bool l=false):Zivotno(p,i,r,pr,v){
        letac=l;
    }
    void print(){
        prikaziPodatoci();
        if(letac==true) cout<<"Pticata e letac"<<endl;
        else cout<<"Pticata ne e letac"<<endl;
    }
    int Vakcinacija(Datum Today){
        int d1, m1, g1, d2, m2, g2;
        d1=datum_na_vakcinacija.getDen();
        m1=datum_na_vakcinacija.getMesec();
        g1=datum_na_vakcinacija.getGodina();
        d2=Today.getDen();
        m2=Today.getMesec();
        g2=Today.getGodina();
        if(g2-g1>1)
            return 1;
        else if(g2-g1==1){
            if(m2>(m1-6))
                return 1;
            else if(m2==(m1-6)){
                if(d2>=d1)
                    return 1;
                else
                    return 0;
            }else
                return 0;
        }
        else{
            if(m2-m1>6)
                return 1;
            else if(m2-m1==6){
                if(d1>=d2)
                    return 1;
                else
                    return 0;
            }else
                return 0;
        }
    }
};

class Cicac:public Zivotno{
private:
    bool prezivar;
public:
    Cicac(char p='m', char *i=(char*)"Ime", Datum r=Datum(), Datum pr=Datum(), Datum v=Datum(), bool prezivar=false):Zivotno(p,i,r,pr,v){
        this->prezivar=prezivar;
    }
    void print(){
        prikaziPodatoci();
        if(prezivar==true) cout<<"Cicacot e prezivar"<<endl;
        else cout<<"Cicacot ne e prezivar"<<endl;
    }
    int Vakcinacija(Datum Today){
        int d1, m1, g1, d2, m2, g2;
        d1=datum_na_vakcinacija.getDen();
        m1=datum_na_vakcinacija.getMesec();
        g1=datum_na_vakcinacija.getGodina();
        d2=Today.getDen();
        m2=Today.getMesec();
        g2=Today.getGodina();
        if(g2-g1>1)
            return 1;
        else if(g2-g1==1){
            if(m2>m1)
                return 1;
            else if(m2==m1){
                if(d2>=d1)
                    return 1;
                else
                    return 0;
            }else
                return 0;
        }else
            return 0;
    }
};

int main()
{
    Vlekac V[5];
    Ptica P[5];
    Cicac C[5];
    int izbor, count=0;
    int brv=0, brp=0, brc=0;
    cout<<"Napravi izbor:"<<endl;
    cout<<"0 - Dodadi zivotno"<<endl;
    cout<<"1 - Prikazi go brojot na zivotni vo zooloskata"<<endl;
    cout<<"2 - Prikazi gi site zivotni od dadena grupa"<<endl;
    cout<<"3 - Prikazi gi site zivotni vo zooloskata"<<endl;
    cout<<"4 - Prikazi gi site zivotni koi treba da se vakciniraat"<<endl;
    cout<<"5 - Kraj"<<endl;
    cin>>izbor;
    while(izbor>=0 && izbor<=4){
        if(izbor==0){
            cin.ignore();
            char t, p, ime[20];
            int ragjanje_den, ragjanje_mesec, ragjanje_godina;
            int donesuvanje_den, donesuvanje_mesec, donesuvanje_godina;
            int v_den, v_mesec, v_godina;
            int izbor2;
            cout<<"Vnesi pol na zivotnoto:"<<endl;
            cin>>p;
            cout<<"Vnesi ime na zivotnoto:"<<endl;
            cin>>ime;
            cout<<"Vnesi datum na ragjanje na zivotnoto:"<<endl;
            cin>>ragjanje_den>>ragjanje_mesec>>ragjanje_godina;
            Datum ragjanje(ragjanje_den,ragjanje_mesec,ragjanje_godina);
            cout<<"Vnesi datum an donesuvanje vo zooloska:"<<endl;
            cin>>donesuvanje_den>>donesuvanje_mesec>>donesuvanje_godina;
            Datum donesuvanje(donesuvanje_den,donesuvanje_mesec,donesuvanje_godina);
            cout<<"Vnesi datum na posledna vakcinacija"<<endl;
            cin>>v_den>>v_mesec>>v_godina;
            Datum posledna_vak(v_den,v_mesec,v_godina);
            cout<<"Ako zivotnoto e vlekac vnesi 1, za ptica vnesi 2, za cicac vnesi 3"<<endl;
            cin>>izbor2;
            if(izbor2==1){
                int ds, ms, gs;
                cout<<"Vnesi datum na sledna vakcinacija:"<<endl;
                cin>>ds>>ms>>gs;
                Datum datum_sledna(ds, ms, gs);
                V[brv]=Vlekac(p,ime,ragjanje,donesuvanje,posledna_vak,datum_sledna);
                brv++;
            }if(izbor2==2){
                int l;
                cout<<"Dali pticata e letac(1-da, 0-ne):"<<endl;
                cin>>l;
                if(l==1) P[brp]=Ptica(p,ime,ragjanje,donesuvanje,posledna_vak,true);
                else P[brp]=Ptica(p,ime,ragjanje,donesuvanje,posledna_vak,false);
                brp++;
            }if(izbor2==3){
                int prezivar;
                cout<<"Dali cicacot e prezivar(1-da, 0-ne):"<<endl;
                cin>>prezivar;
                if(prezivar==1) C[brc]=Cicac(p,ime,ragjanje,donesuvanje,posledna_vak,true);
                else C[brc]=Cicac(p,ime,ragjanje,donesuvanje,posledna_vak,false);
                brc++;
            }
            count++; //brojac za vkupniot brojna zivotni vo zoolockata
        }else if(izbor==1){
            cout<<"Vkupniot broj na zivotni vo zooloskata e: "<<count<<endl;
        }else if(izbor==2){
            int t;
            cout<<"Koj tip na zivotni sakate da go pregledate:"<<endl;
            cin>>t;
            if(t==1){ //vlekaci
                for(int i=0;i<brv;i++)
                    V[i].print();
            }else if(t==2){ //ptici
                for(int i=0;i<brp;i++)
                    P[i].print();
            }else if(t==3){ //cicaci
                for(int i=0;i<brc;i++)
                    C[i].print();
            }
        }else if(izbor==3){
            cout<<"Vlekaci"<<endl;
            for(int i=0;i<brv;i++)
                V[i].print();
            cout<<"Ptici"<<endl;
            for(int i=0;i<brp;i++)
                P[i].print();
            cout<<"Cicaci:"<<endl;
            for(int i=0;i<brc;i++)
                C[i].print();
        }else if(izbor==4){
            Datum Today(11,7,2024);
            cout<<"Vlekaci za vakcinacija:"<<endl;
            for(int i=0;i<brv;i++){
                if(V[i].Vakcinacija(Today))
                    V[i].print();
            }
            Today=Datum(11,7,2024);
            cout<<"Ptici za vakcinacija:"<<endl;
            for(int i=0;i<brp;i++){
                if(P[i].Vakcinacija(Today))
                    P[i].print();
            }
            cout<<"Cicaci za vakcinacija:"<<endl;
            for(int i=0;i<brc;i++){
                if(C[i].Vakcinacija(Today))
                    C[i].print();
            }
        }
        cout<<"Napravi izbor:"<<endl;
        cout<<"0 - Dodadi zivotno"<<endl;
        cout<<"1 - Prikazi go brojot na zivotni vo zooloskata"<<endl;
        cout<<"2 - Prikazi gi site zivotni od dadena grupa"<<endl;
        cout<<"3 - Prikazi gi site zivotni vo zooloskata"<<endl;
        cout<<"4 - Prikazi gi site zivotni koi treba da se vakciniraat"<<endl;
        cout<<"5 - Kraj"<<endl;
        cin >> izbor;
    }
    return 0;
}

