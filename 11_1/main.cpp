#include <iostream>
#include <cstring>

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

class Artikl{
protected:
    char ime[20];
    char golemina[3];
    int cena;
    Datum donesen_vo_prodavnica;
public:
    Artikl(char i[], char g[], int c, Datum d){
        strcpy(ime,i);
        strcpy(golemina,g);
        cena=c;
        donesen_vo_prodavnica=d;
    }
    int getCena(){
        return cena;
    }
    void print(){
        cout<<"Ime na artikl: "<<ime<<endl;
        cout<<"Golemina: "<<golemina<<endl;
        cout<<"Cena: "<<cena<<endl;
        cout<<"Datum na donesuvanje vo prodavnica: ";
        donesen_vo_prodavnica.print();
    }
    int presmetajNabavkaArtikl(){
        int n;
        cout<<"Kolku artikli ke naracuvate:"<<endl;
        cin>>n;
        return n*cena;
    }
};

class Pantaloni:public Artikl{
private:
    Datum posledna_nabavka;
public:
    Pantaloni(char i[]=(char *)"", char g[]=(char *)"", int c=0, Datum d=NULL, Datum pn=NULL):Artikl(i,g,c,d){
        posledna_nabavka=pn;
    }
    void printPantaloni(){
        print();
        cout<<"Posledna nabavka na den: ";
        posledna_nabavka.print();
    }
    int presmetajNabavka(){
        int d1, m1, g1, d2, m2, g2, proverka=0;
        d1=posledna_nabavka.getDen();
        m1=posledna_nabavka.getMesec();
        g1=posledna_nabavka.getGodina();

        d2=donesen_vo_prodavnica.getDen();
        m2=donesen_vo_prodavnica.getMesec();
        g2=donesen_vo_prodavnica.getGodina();

        if(m2-m1>1 || g2>g1){
            proverka=presmetajNabavkaArtikl();
        }
        else if(m2-m1==1){
            if(d2>=d1) proverka=presmetajNabavkaArtikl();
        }
        return proverka;
    }
};

class Kosuli:public Artikl{
public:
    Kosuli(char i[]=(char *)"", char g[]=(char *)"", int c=0, Datum d=NULL):Artikl(i,g,c,d){}
};

int main()
{
    Pantaloni P[10];
    Kosuli K[10];
    int izbor;
    int i=0, j=0;
    cout<<"Napravete izbor:"<<endl;
    cout<<"0 - Dodadi artikl"<<endl;
    cout<<"1 - Prikazi gi artiklite od dadena grupa"<<endl;
    cout<<"2 - Prikazi ja celata lista"<<endl;
    cout<<"3 - Prikazuvanje na artiklite koi treba da se nabavar vo rok od 1 nedela"<<endl;
    cout<<"4 - Kraj"<<endl;
    cin>>izbor;

    while(izbor>=0 && izbor<=3){
        if(izbor==0){
            char ime[20], g[3];
            int c, d, m, god, izbor2;
            cout<<"Ime na proizvodot:"<<endl;
            cin.ignore();
            cin>>ime;
            cout<<"Golemina:"<<endl;
            cin.ignore();
            cin>>g;
            cout<<"Cena:"<<endl;
            cin>>c;
            cout <<"Datum na donesuvanje:"<<endl;
            cin>>d>>m>>god;
            Datum D(d,m,god);
            cout<<"Vnesi 1 ako artiklot e pantaloni, 2 ako e kosula:"<<endl;
            cin>>izbor2;
            if(izbor2==1){ //pantaloni
                int den, mesec, godina;
                cout<<"Posledna nabavka na den:"<<endl;
                cin>>den>>mesec>>godina;
                Datum PN(den, mesec, godina);
                P[i]=Pantaloni(ime,g,c,D,PN);
                i++;
            }else{ //kosula
                K[j]=Kosuli(ime,g,c,D);
                j++;
            }
        }else if(izbor==1){
            int izbor2, counter;
            cout<<"Za da se prikazat podatoci za pantaloni vnesete 1, za kosuli 2:"<<endl;
            cin>>izbor2;
            if(izbor2==1){ //pantaloni
                for(counter=0;counter<i;counter++)
                    P[counter].printPantaloni();
            }else{ //kosuli
                for(counter=0;counter<j;counter++)
                    K[counter].print();
            }
        }else if(izbor==2){
            int sum=0, counter;
            for(counter=0;counter<i;counter++){
                P[counter].printPantaloni();
                sum+=P[counter].getCena();
            }
            for(counter=0;counter<j;counter++){
                K[counter].print();
                sum+=K[counter].getCena();
            }
            cout<<"Vkupna cena: "<<sum<<endl;
        }else{
            int sum=0, counter;
            for(counter=0;counter<i;counter++){
                int cena=P[counter].presmetajNabavka();
                if(cena!=0){
                    P[counter].printPantaloni();
                    sum+=cena;
                }
            }
            for(counter=0;counter<j;counter++){
                int izbor2;
                cout<<"Dali ke naracuvate kosuli(da-1, ne-0)?"<<endl;
                cin>>izbor2;
                if(izbor2==1){
                    K[counter].print();
                    sum+=K[counter].presmetajNabavkaArtikl();
                }
            }
            cout<<"Vkupna cena na narackata: "<<sum<<endl;
        }
        cout<<"Napravete izbor:"<<endl;
        cout<<"0 - Dodadi artikl"<<endl;
        cout<<"1 - Prikazi gi artiklite od dadena grupa"<<endl;
        cout<<"2 - Prikazi ja celata lista"<<endl;
        cout<<"3 - Prikazuvanje na artiklite koi treba da se nabavar vo rok od 1 nedela"<<endl;
        cout<<"4 - Kraj"<<endl;
        cin>>izbor;
    }
    return 0;
}
