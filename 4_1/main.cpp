#include <iostream>

using namespace std;

class Dropki{
private:
    int broitel, imenitel;
public:
    Dropki(int b=0, int i=1){
        broitel=b;
        if(i==0)
            imenitel=1;
        else
            imenitel=i;
    }
    int getBroitel(){
        return broitel;
    }
    int getImenitel(){
        return imenitel;
    }
    void Sobiranje(int b, int i){
        if(imenitel==i)
            broitel=broitel+b;
        else{
            broitel=broitel*i+b*imenitel;
            imenitel=imenitel*i;
        }
        int flag=min(broitel,imenitel); // najgolem zaednicki delitel
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
    }
    void Odzemanje(int b, int i){
        if(imenitel==i)
            broitel=broitel-b;
        else{
            broitel=broitel*i-b*imenitel;
            imenitel=imenitel*i;
        }
        int flag=min(broitel,imenitel); // najgolem zaednicki delitel
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
    }
    void Mnozenje(int b, int i){
        broitel=broitel*b;
        imenitel=imenitel*i;
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
    }
    void Delenje(int b, int i){
        broitel=broitel*i;
        imenitel=imenitel*b;
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
    }
    void print(){
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        cout<<"Dropkata e: "<<broitel<<"/"<<imenitel<<endl;
    }
    double dropka(){
        return (double)broitel/imenitel;
    }
};


int main()
{
    Dropki dropka1(2,3), dropka2(2,4);
    dropka1.Sobiranje(dropka2.getBroitel(),dropka2.getImenitel());
    dropka1.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka1.dropka()<<endl;

    Dropki dropka3(3,4), dropka4(2,5);
    dropka3.Odzemanje(dropka4.getBroitel(),dropka4.getImenitel());
    dropka3.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka3.dropka()<<endl;

    Dropki dropka5(4,5), dropka6(1,2);
    dropka5.Mnozenje(dropka6.getBroitel(),dropka6.getImenitel());
    dropka5.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka5.dropka()<<endl;

    Dropki dropka7(5,6), dropka8(1,2);
    dropka7.Delenje(dropka8.getBroitel(),dropka8.getImenitel());
    dropka7.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka7.dropka()<<endl;
    return 0;
}
