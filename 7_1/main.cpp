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
    Dropki operator+(Dropki &D){
        if(imenitel==D.imenitel)
            broitel=broitel+D.broitel;
        else{
            broitel=broitel*D.imenitel+D.broitel*imenitel;
            imenitel=imenitel*D.imenitel;
        }
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
    Dropki operator+(int number){
        broitel=broitel+number*imenitel;
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
    Dropki operator-(Dropki &D){
        if(imenitel==D.imenitel)
            broitel=broitel-D.broitel;
        else{
            broitel=broitel*D.imenitel-D.broitel*imenitel;
            imenitel=imenitel*D.imenitel;
        }
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
    Dropki operator-(int number){
        broitel=broitel-number*imenitel;
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
    Dropki operator*(Dropki &D){
        broitel=broitel*D.broitel;
        imenitel=imenitel*D.imenitel;
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
    Dropki operator*(int number){
        broitel=broitel*number;
        int flag=min(broitel, imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
    Dropki operator/(Dropki &D){
        broitel=broitel*D.imenitel;
        imenitel=imenitel*D.broitel;
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
    Dropki operator/(int number){
        imenitel=imenitel*number;
        int flag=min(broitel,imenitel);
        while(flag>0){
            if(broitel%flag==0 && imenitel%flag==0)
                break;
            flag--;
        }
        broitel=broitel/flag;
        imenitel=imenitel/flag;
        return *this;
    }
};

int main()
{
    Dropki dropka1(2,3), dropka2(2,4);
    dropka1+dropka2;
    dropka1.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka1.dropka()<<endl;

    Dropki dropka3(3,4), dropka4(2,5);
    dropka3-dropka4;
    dropka3.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka3.dropka()<<endl;

    Dropki dropka5(4,5), dropka6(1,2);
    dropka5*dropka6;
    dropka5.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka5.dropka()<<endl;

    Dropki dropka7(5,6), dropka8(1,2);
    dropka7/dropka8;
    dropka7.print();
    cout<<"Novata dropka kako realen broj e: "<<dropka7.dropka()<<endl;

    dropka1+3;
    dropka1.print();
    dropka3-1;
    dropka3.print();
    dropka5*5;
    dropka5.print();
    dropka7/2;
    dropka7.print();
    return 0;
}

