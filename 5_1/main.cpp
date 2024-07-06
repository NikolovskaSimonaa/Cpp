#include <iostream>
#include <string.h>

using namespace std;

class Date{
private:
    int day, month, year;
public:
    Date(int d=1, int m=1, int y=2007){
        day=d;
        month=m;
        year=y;
    }
    void setDate(int d, int m, int y){
        day=d;
        month=m;
        year=y;
    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    void print(){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Zivotno{
private:
    Date datum_na_ragjanje;
    Date datum_na_donesuvanje_vo_zoo;
    Date datum_na_vakcinacija;
    char tip; // c - cicaci, v - vlekaci, p - ptici
    char pol; // m - maski, z - zenski
    char name[20];
public:
    Zivotno(char t='m', char p='m', char *n=(char*)"Ime"):datum_na_ragjanje(),datum_na_donesuvanje_vo_zoo(),datum_na_vakcinacija(){
        tip=t;
        pol=p;
        strcpy(name,n);
    }
    void setZivotno(char t, char p, char *n, int ragjanje_day, int ragjanje_month, int ragjanje_year, int donesuvanje_day, int donesuvanje_month, int donesuvanje_year, int v_day, int v_month, int v_year){
        tip=t;
        pol=p;
        strcpy(name,n);
        datum_na_ragjanje=Date(ragjanje_day,ragjanje_month,ragjanje_year);
        datum_na_donesuvanje_vo_zoo=Date(donesuvanje_day,donesuvanje_month,donesuvanje_year);
        datum_na_vakcinacija=Date(v_day,v_month,v_year);
    }
    char getTip(){
        return tip;
    }
    void prikaziPodatoci(){
        if(tip=='c')
            cout<<"Tip: Cicac"<<endl;
        else if(tip=='v')
            cout<<"Tip: Vlekac"<<endl;
        else if(tip=='p')
            cout<<"Tip: Ptica"<<endl;
        else
            cout<<"Tip: Nepoznato"<<endl;

        if(pol=='m')
            cout<<"Pol: Maski"<<endl;
        else if(pol=='z')
            cout<<"Pol: Zenski"<<endl;
        else
            cout<<"Pol: Nepoznato"<<endl;

        cout<<"Ime na zivotnoto: "<<name<<endl;
        cout<<"Datum na ragjanje: ";
        datum_na_ragjanje.print();
        cout<<"Datum na donesuvanje vo zoo: ";
        datum_na_donesuvanje_vo_zoo.print();
        cout<<"Datum na posledna vakcinacija: ";
        datum_na_vakcinacija.print();
    }
    int presmetajVakcinacija(int day, int month, int year){ // vrakja dali treba(1) ili nei(0) da se napravi vakcinacija
        if(tip=='c'){
            int d=datum_na_vakcinacija.getDay();
            int m=datum_na_vakcinacija.getMonth();
            int y=datum_na_vakcinacija.getYear();
            if(year-y>1){
                datum_na_vakcinacija.setDate(day,month,year);
                return 1;
            }else if(year-y==1){
                if(month>m){
                    datum_na_vakcinacija.setDate(day,month,year);
                    return 1;
                }else if(month==m){
                    if(day>=d){
                        datum_na_vakcinacija.setDate(day,month,year);
                        return 1;
                    }else
                        return 0;
                }else
                    return 0;
            }else
                return 0;
        }else if(tip=='v'){
            int d=datum_na_vakcinacija.getDay();
            int m=datum_na_vakcinacija.getMonth();
            int y=datum_na_vakcinacija.getYear();
            if(year-y>1){
                datum_na_vakcinacija.setDate(day,month,year);
                return 1;
            }else if(year-y==1){
                if(month>(m-4)){
                    datum_na_vakcinacija.setDate(day,month,year);
                    return 1;
                }else if(month==(m-4)){
                    if(day>=d){
                        datum_na_vakcinacija.setDate(day,month,year);
                        return 1;
                    }else
                        return 0;
                }else
                    return 0;
            }else{
                if(month-m>8){
                    datum_na_vakcinacija.setDate(day,month,year);
                    return 1;
                }else if(month-m==8){
                    if(day>=d){
                        datum_na_vakcinacija.setDate(day,month,year);
                        return 1;
                    }else
                        return 0;
                }else
                    return 0;
            }
        }else{ //ptica
            int d=datum_na_vakcinacija.getDay();
            int m=datum_na_vakcinacija.getMonth();
            int y=datum_na_vakcinacija.getYear();
            if(year-y>1){
                datum_na_vakcinacija.setDate(day,month,year);
                return 1;
            }else if(year-y==1){
                if(month>(m-6)){
                    datum_na_vakcinacija.setDate(day,month,year);
                    return 1;
                }else if(month==(m-6)){
                    if(day>=d){
                        datum_na_vakcinacija.setDate(day,month,year);
                        return 1;
                    }else
                        return 0;
                }else
                    return 0;
            }else{
                if(month-m>6){
                    datum_na_vakcinacija.setDate(day,month,year);
                    return 1;
                }else if(month-m==6){
                    if(day>=d){
                        datum_na_vakcinacija.setDate(day,month,year);
                        return 1;
                    }else
                        return 0;
                }else
                    return 0;
            }
        }
    }
};


int main()
{
    Zivotno zivotni[10];
    int izbor, i=0;
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

            cout<<"Vnesi tip na zivotnoto:"<<endl;
            cin>>t;
            cout<<"Vnesi pol na zivotnoto:"<<endl;
            cin>>p;
            cout<<"Vnesi ime na zivotnoto:"<<endl;
            cin>>ime;
            cout<<"Vnesi datum na ragjanje na zivotnoto:"<<endl;
            cin>>ragjanje_den>>ragjanje_mesec>>ragjanje_godina;
            cout<<"Vnesi datum an donesuvanje vo zooloska:"<<endl;
            cin>>donesuvanje_den>>donesuvanje_mesec>>donesuvanje_godina;
            cout<<"Vnesi datum na posledna vakcinacija"<<endl;
            cin>>v_den>>v_mesec>>v_godina;
            zivotni[i].setZivotno(t,p,ime,ragjanje_den,ragjanje_mesec,ragjanje_godina,donesuvanje_den,donesuvanje_mesec,donesuvanje_godina,v_den,v_mesec,v_godina);
            i++;
        }else if(izbor==1){
            cout<<"Vkupniot broj na zivotni vo zooloskata e: "<<i<<endl;
        }else if(izbor==2){
            char t;
            cout<<"Koj tip na zivotni sakate da go pregledate:"<<endl;
            cin>>t;
            for(int j=0;j<i;j++){
                if(zivotni[j].getTip()==t)
                    zivotni[j].prikaziPodatoci();
            }
        }else if(izbor==3){
            for(int j=0;j<i;j++)
                zivotni[j].prikaziPodatoci();
        }else if(izbor==4){
            for(int j=0;j<i;j++){
                if(zivotni[j].presmetajVakcinacija(6,7,2024)==1)
                    zivotni[j].prikaziPodatoci();
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
    cout<<"Kraj"<<endl;
    return 0;
}
