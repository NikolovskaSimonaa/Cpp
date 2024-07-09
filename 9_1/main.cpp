#include <iostream>

using namespace std;

#define max 100

class Matrica{
private:
    int m, n;
    int matrica[max][max];
public:
    Matrica(int r=1, int k=1){
        m=r; // broj na redici
        n=k; // broj na koloni
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrica[i][j]=0;
    }
    Matrica(Matrica &M){
        m=M.m;
        n=M.n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrica[i][j]=M.matrica[i][j];
    }
    friend istream &operator>>(istream &input, Matrica &M){
        for(int i=0;i<M.m;i++){
            for(int j=0;j<M.n;j++){
                cout<<"Vnesi sleden element na matricata:"<<endl;
                input>>M.matrica[i][j];
            }
        }
        return input;
    }
    friend ostream &operator<<(ostream &output, Matrica &M){
        for(int i=0;i<M.m;i++){
            for(int j=0;j<M.n;j++)
                output<<M.matrica[i][j]<<" ";
            output<<endl;
        }
        return output;
    }
    int operator[](int i){ // i - broj na redica
        int j;
        cout<<"Vnesi broj na kolona za elementot:"<<endl;
        cin>>j;
        return matrica[i][j];
    }
    Matrica operator+(Matrica &M){
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrica[i][j]+=M.matrica[i][j];
        return *this;
    }
    Matrica operator-(Matrica &M){
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrica[i][j]-=M.matrica[i][j];
        return *this;
    }
    friend Matrica operator*(Matrica &M1, Matrica &M2){
        Matrica rez(M1.m,M2.n);
        int r1=0, k1=0, r2=0, k2=0;
        for(int i=0;i<rez.m;i++){
            for(int j=0;j<rez.n;j++){
                while(k1<M1.n && r2<M2.m){
                    rez.matrica[i][j]+=M1.matrica[r1][k1]*M2.matrica[r2][k2];
                    k1++;
                    r2++;
                }
                k1=0;
                r2=0;
                k2++;
            }
            k2=0;
            r1++;
        }
        return rez;
    }
    friend void operator*(Matrica &M, int number){
        for(int i=0;i<M.m;i++)
            for(int j=0;j<M.n;j++)
                M.matrica[i][j]*=number;
    }
    friend void operator*(int number, Matrica &M){
        for(int i=0;i<M.m;i++)
            for(int j=0;j<M.n;j++)
                M.matrica[i][j]*=number;
    }
    bool operator==(Matrica &M){
        bool flag=true;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrica[i][j]!=M.matrica[i][j]){
                    flag=false;
                    break;
                }
        return flag;
    }
};

int main()
{
    Matrica M1(3,3), M2(3,3);
    cout<<"Vnesete matrica:"<<endl;
    cin>>M1;
    cout<<"Vnesete matrica:"<<endl;
    cin>>M2;
    Matrica M3=M1*M2;
    cout<<M3;
    M3*3;
    cout<<M3;
    cout<<M3[1]<<endl;
    M1+M2;
    cout<<M1;
    if(M1==M2) cout<<"Matricite se ednakvi"<<endl;
    return 0;
}

