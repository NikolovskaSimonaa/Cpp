#include <iostream>
#include <cstring>

using namespace std;

class Vraboten{
private:
    char ime[20], prezime[20];
    int godina_vrabotuvanje;
public:
    Vraboten(char i[]=(char *)"", char p[]=(char *)"", int g=2024){
        strcpy(ime,i);
        strcpy(prezime,p);
        godina_vrabotuvanje=g;
    }
    void setVraboten(char *i, char *p, int g){
        strcpy(ime,i);
        strcpy(prezime,p);
        godina_vrabotuvanje=g;
    }
    void printVraboten(){
        cout<<"Ime i prezime: "<<ime<<" "<<prezime<<endl;
        cout<<"Godina na vrabotuvanje: "<<godina_vrabotuvanje<<endl;
    }
    ~Vraboten(){}
};

class Profesor:public Vraboten{
private:
    char zvanje[30];
    char oblast[30];
    int br_predmeti;
public:
    Profesor(char i[]=(char *)"", char p[]=(char *)"", int g=2024, char z[]=(char *)"", char o[]=(char *)"", int br=0):Vraboten(i,p,g){
        strcpy(zvanje,z);
        strcpy(oblast,o);
        br_predmeti=br;
    }
    void setProfesor(char i[], char p[], int g, char z[], char o[], int br){
        setVraboten(i,p,g);
        strcpy(zvanje,z);
        strcpy(oblast,o);
        br_predmeti=br;
    }
    void printProfesor(){
        printVraboten();
        cout<<"Zvanje: "<<oblast<<endl;
        cout<<"Oblast: "<<oblast<<endl;
        cout<<"Broj na predmeti: "<<br_predmeti<<endl;
    }
    ~Profesor(){}
};

class Asistent:public Vraboten{
private:
    char zvanje[30];
    char mentor[20];
    int br_predmeti;
public:
    Asistent(char i[]=(char *)"", char p[]=(char *)"", int g=2024, char z[]=(char *)"", char m[]=(char *)"", int br=0):Vraboten(i,p,g){
        strcpy(zvanje,z);
        strcpy(mentor,m);
        br_predmeti=br;
    }
    void setAsistent(char i[], char p[], int g, char z[], char m[], int br){
        setVraboten(i,p,g);
        strcpy(zvanje,z);
        strcpy(mentor,m);
        br_predmeti=br;
    }
    void printAsistent(){
        printVraboten();
        cout<<"Zvanje: "<<zvanje<<endl;
        cout<<"Mentor: "<<mentor<<endl;
        cout<<"Broj na predmeti: "<<br_predmeti<<endl;
    }
    ~Asistent(){}
};

class Demonstrator:public Vraboten{
private:
    char rabotno_vreme[10];
public:
    Demonstrator(char i[]=(char *)"", char p[]=(char *)"", int g=2024, char r[]=(char *)""):Vraboten(i,p,g){
        strcpy(rabotno_vreme,r);
    }
    void setDemonstrator(char i[], char p[], int g, char r[]){
        setVraboten(i,p,g);
        strcpy(rabotno_vreme,r);
    }
    void printDemonstrator(){
        printVraboten();
        cout<<"Rabotno vreme: "<<rabotno_vreme<<endl;
    }
    ~Demonstrator(){}
};

int main()
{
    Profesor P[3];
    Asistent A[3];
    Demonstrator D[3];
    int p=0, a=0, d=0;
    int izbor;

    cout<<"Napravete izbor:"<<endl;
    cout<<"0 - Dodadi nov vraboten"<<endl;
    cout<<"1 - Prikazi gi podatocite"<<endl;
    cout<<"2 - Kraj"<<endl;
    cin>>izbor;

    while(izbor==0 || izbor==1){
        if(izbor==0){
            int izbor2;
            cout<<"Za dodavanje profesor vnesi 1, za asistent 2, za demonstrator 3:"<<endl;
            cin>>izbor2;
            if(izbor2==1){ //profesor
                char i[20], pr[20], z[30], o[30];
                int g, brp;
                cout<<"Ime i prezime:"<<endl;
                cin>>i>>pr;
                cout<<"Godina na vrabotuvanje:"<<endl;
                cin>>g;
                cout<<"Zvanje:"<<endl;
                cin>>z;
                cout<<"Oblast:"<<endl;
                cin>>o;
                cout<<"Broj na predmeti:"<<endl;
                cin>>brp;
                P[p].setProfesor(i,pr,g,z,o,brp);
                p++;
            }else if(izbor2==2){ //asistent
                char i[20], p[20], z[30], m[20];
                int g, brp;
                cout<<"Ime i prezime:"<<endl;
                cin>>i>>p;
                cout<<"Godina na vrabotuvanje:"<<endl;
                cin>>g;
                cout<<"Zvanje:"<<endl;
                cin>>z;
                cout<<"Mentor:"<<endl;
                cin>>m;
                cout<<"Broj na predmeti:"<<endl;
                cin>>brp;
                A[a].setAsistent(i,p,g,z,m,brp);
                a++;
            }else if(izbor2==3){ //demonstrator
                char i[20], p[20], r[10];
                int g;
                cout<<"Ime i prezime:"<<endl;
                cin>>i>>p;
                cout<<"Godina na vrabotuvanje:"<<endl;
                cin>>g;
                cout<<"Rabotno vreme:"<<endl;
                cin>>r;
                D[d].setDemonstrator(i,p,g,r);
                d++;
            }
        }else{ //izbor==1
            cout<<"Profesori:"<<endl;
            for(int i=0;i<p;i++)
                P[i].printProfesor();
            cout<<"Asistenti:"<<endl;
            for(int i=0;i<a;i++)
                A[i].printAsistent();
            cout<<"Demonstratori:"<<endl;
            for(int i=0;i<d;i++)
                D[i].printDemonstrator();
        }
        cout<<"Napravete izbor:"<<endl;
        cout<<"0 - Dodadi nov vraboten"<<endl;
        cout<<"1 - Prikazi gi podatocite"<<endl;
        cout<<"2 - Kraj"<<endl;
        cin>>izbor;
    }
    return 0;
}

