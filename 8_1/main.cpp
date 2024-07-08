#include <iostream>

using namespace std;

class Complex{
private:
    double real; // realen del
    double imaginary; // imaginaren del
public:
    Complex(double r=0.0, double i=0.0){
        real=r;
        imaginary=i;
    }
    Complex operator+(const Complex &operand2) const {
        return Complex(real+operand2.real, imaginary+operand2.imaginary);
    }
    Complex operator-(const Complex &operand2) const {
        return Complex(real-operand2.real, imaginary-operand2.imaginary);
    }
    const Complex& operator=(const Complex &right)
    {
        real=right.real;
        imaginary=right.imaginary;
        return *this;   // ovozmozhuva kaskadiranje
    }
    friend ostream &operator<<(ostream &output, const Complex number){
        output<<"Real part: " <<number.real<<endl;
        output<<"Imaginary part: "<<number.imaginary<<endl;
        return output;
    }
    friend istream &operator>>(istream &input, Complex &number){
        double real, imaginary;
        cout<<"Enter the real and imaginary part:"<<endl;
        input>>real;
        input>>imaginary;
        number.real=real;
        number.imaginary=imaginary;
        return input;
    }
    Complex operator*(const Complex &C){
        double r, i;
        r=real*C.real-imaginary*C.imaginary;
        i=real*C.imaginary+imaginary*C.real;
        real=r;
        imaginary=i;
        return *this;
    }
    friend Complex operator*(const Complex &C, int number){
        Complex temp;
        temp.real=C.real*number;
        temp.imaginary=C.imaginary*number;
        return temp;
    }
    friend Complex operator*(int number, const Complex &C){
        Complex temp;
        temp.real=C.real*number;
        temp.imaginary=C.imaginary*number;
        return temp;
    }
    bool operator==(const Complex &C){
        if(real==C.real && imaginary==C.imaginary) return true;
        else return false;
    }
    bool operator!=(const Complex &C){
        if(real==C.real && imaginary==C.imaginary) return false;
        else return true;
    }
    Complex& operator+=(const Complex &C2){
        *this=*this+C2;
        return *this;
    }
    Complex& operator-=(const Complex &C2){
        *this=*this-C2;
        return *this;
    }
    Complex& operator*=(const Complex&C2){
        *this=*this*C2;
        return *this;
    }
};

int main()
{
    Complex x, y(4.3, 8.2), z(3.3, 1.1), p, q(4.3, 8.2), r;
    x=y+z;
    cout<<x;
    x=y-z;
    cout<<x;
    x=y*z;
    cout<<x;
    cin>>p;
    cout<<p;
    if(p==y) cout<<"The numbers are equal"<<endl;
    p+=z;
    cout<<p;
    r=p*2;
    cout<<r;
    return 0;
}
