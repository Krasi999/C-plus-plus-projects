#include <iostream>
using namespace std;

class MPC{
protected:
    int year;
    char brand;
public:
    MPC(int y, char b){
        year = y;
        brand = b;
    }
    int getYear() const{return year;}
    char getBrand() const{return brand;}

    virtual void print() const {
        cout << "The year is: " << getYear() << endl;
        cout << "The brand is: " << getBrand() << endl;
    }
};

class Automobil : public MPC{
protected:
    int number;
public:
    Automobil(int n, int y, char b) : MPC(y, b){
        number = n;
    }
    int getNumber()const {return number;}

    virtual void print() const override{
        MPC::print();
        cout << "The number of the car is: " << getNumber() << endl;
    }
};

class RentACar : public Automobil{
protected:
    double price;
public:
    RentACar(double p, int n, int y, char b) : Automobil(n, y, b){
        price = p;
    }
    double getPrice() const {return price;}
    virtual void print() const override{
        Automobil::print();
        cout << "The price of the rent is: " << getPrice() << endl;
    }
};

int main()
{
    MPC m(1987, 'G');
    m.print();
    cout << endl;

    Automobil a(1234, 1987, 'K');
    a.print();
    cout << endl;

    RentACar rent(78.40, 3425, 2019, 'L');
    rent.print();
    cout << endl;

    return 0;
}
