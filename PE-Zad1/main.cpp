#include <iostream>
using namespace std;

class Temperature{
protected:
    double fTemperature;
public:
    Temperature(double t){
        fTemperature = t;
    }

    double getFTemperature() const{return fTemperature;}

    void setFTemperature(double fT){fTemperature = fT;}

    virtual double predifine() const = 0;

    virtual ~Temperature(){
        cout << "\nDestructing object!\n";
    }

};

class Celsius : public Temperature{
public:
    Celsius(double t) : Temperature(t){}

    double predifine()const override
    {
        return 5.0 / 9.0 * (getFTemperature() - 32.0);
    }

    double getFTemperature() const{return fTemperature;}

    void setFTemperature(double fT){fTemperature = fT;}
};

int main()
{
    Temperature* t = new Celsius(0);

    double f;
    cout << "Enter temperature in  Farenhait: ";
    cin >> f;

    t->setFTemperature(f);

    cout << "The temperature in Celsius: " << t->predifine() << " C" << endl;

    delete t;

    return 0;
}
