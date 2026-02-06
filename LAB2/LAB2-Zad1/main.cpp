#include <iostream>
#include <cmath>
using namespace std;

class ractangle {
private:
    double a, b;

public:
    ractangle();
    double face();              // Член-функция face() без аргумент
    double face(double *);      // Член-функция face() с един аргумент
    void show(const char *);
    ~ractangle()
    {
        cout << "\nDestructing object triangle!\n";
    }
};

ractangle::ractangle()
{
    do {
        cout << "\nEnter the two sides of the rectangle:\n";
        cin >> a >> b;
    } while (!((a > 0) && (b > 0)));
}

double ractangle::face() // Дефиниция на член-функция face() без аргументи
{
    double p = 2 * (a + b);
    double s = a * b;
    return s;
}

double ractangle::face(double *p) // Предефинирана член-функция face()
{
    double pp = 2 * (a + b);
    *p = pp; // Връщане на втория резултат чрез аргумент-указател
    double s = a * b;
    return s;
}

void ractangle::show(const char *name)
{
    cout << "Sides of the ractangle " << name << ":\n";
    cout << "a=" << a << ", b=" << b << endl;
}

int main()
{
    ractangle rt1; // Обект rt1; извиква се конструкторът на класа
    double p, s;

    rt1.show("rt1");
    cout << "\nThe face of ractangle 1 is s = " << rt1.face();

    ractangle rt2; // Обект rt2; извиква се конструкторът на класа
    rt2.show("rt2");

    s = rt2.face(&p); // Зарежда се член-функция face() с аргумент
    cout << "\nThe face of ractangle 2 is s = " << s << ", and the perimeter is p = " << p << endl;

    return 0;
}
