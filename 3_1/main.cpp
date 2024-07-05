#include <iostream>

using namespace std;

class Kvadar{
private:
    float dolzina, sirina, visina;
public:
    void set(float d=0, float s=0, float v=0){
        dolzina=d;
        sirina=s;
        visina=v;
    }
    void print(){
        cout<<"dolzina: "<<dolzina<<", sirina: "<<sirina<<", visina: "<<visina<<endl;
    }
    bool eKocka(){
        if(dolzina==sirina && dolzina==visina)
            return true;
        else
            return false;
    }
    float Plostina(){
        return 2*(dolzina*sirina+dolzina*visina+sirina*visina);
    }
    float Volumen(){
        return dolzina*sirina*visina;
    }
};

int main()
{
    int izbor, i=0;
    Kvadar objekti[10];
    cout<<"Napravi izbor:"<<endl;
    cout<<"0 - Kreiraj nov objekt"<<endl;
    cout<<"1 - Postavi dimenzii na objekt"<<endl;
    cout<<"2 - Pecati gi dimenziite za site objekti"<<endl;
    cout<<"3 - Pecati dimenzii za specificen objekt"<<endl;
    cout<<"4 - Pecati dimenzii za onie koi go ispolnuvaat uslovot"<<endl;
    cin>>izbor;
    while(izbor>=0 && izbor<=4){
        if(izbor==0){
            cout<<"Vnesi dimenzii za noviot objekt:"<<endl;
            float d, s, v;
            cin>>d>>s>>v;
            objekti[i++].set(d,s,v);
        }else if(izbor==1){
            cout<<"Vnesi indeks na objektot koj ke go menuvas:"<<endl;
            int j;
            cin>>j;
            cout<<"Vnesi dimenzii:"<<endl;
            float d, s, v;
            cin>>d>>s>>v;
            objekti[j].set(d,s,v);
        }else if(izbor==2){
            for(int j=0;j<i;j++)
                objekti[j].print();
        }else if(izbor==3){
            cout<<"Vnesi indeks na objektot koj sakas da se ispecati:"<< endl;
            int j;
            cin>>j;
            objekti[j].print();
        }else if(izbor==4){
            int position=0;
            float min=objekti[0].Plostina();
            for(int j=1;j<i;j++){
                if(min>objekti[j].Plostina()){
                    if(objekti[j].eKocka()==false){
                        min=objekti[j].Plostina();
                        position=j;
                    }
                }
            }
            cout<<"Dimenzii na kvadarot so najmala plostina:"<<endl;
            objekti[position].print();
        }
        cout<<"Napravi izbor:"<<endl;
        cout<<"0 - Kreiraj nov objekt"<<endl;
        cout<<"1 - Postavi dimenzii na objekt"<<endl;
        cout<<"2 - Pecati gi dimenziite za site objekti"<<endl;
        cout<<"3 - Pecati dimenzii za specificen objekt"<<endl;
        cout<<"4 - Pecati dimenzii za onie koi go ispolnuvaat uslovot"<<endl;
        cin>>izbor;
    }
    return 0;
}
