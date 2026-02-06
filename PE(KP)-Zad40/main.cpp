#include <iostream>
#include <cstring>
using namespace std;

class Electronics{
protected:
    int eNumber;
    string name;
    int value;
    string measure;
public:
    Electronics(int e, string n, int v, string m){
        eNumber = e;
        name = n;
        value = v;
        measure = m;
    }

    virtual void print()const{
        cout << "Enumber: " << eNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Value: " << value << endl;
        cout << "Measure: " << measure << endl;
    }

    ~Electronics(){cout << "The object is deleted!\n";}
};

class Device : public Electronics{
protected:
    string country;
    double price;
public:
    Device(string c, double p, int e, string n, int v, string m) : Electronics(e, n, v, m){
        country = c;
        price = p;
    }

    void print() const override{
        Electronics::print();
        cout << "Country: " << country << endl;
        cout << "Price: " << price << endl;

    }

    ~Device(){cout << "The object is deleted!\n";};
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
