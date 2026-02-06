#include <iostream>
using namespace std;

class Square{
protected:
    double radius;
public:
    Square(double r){
        radius = r;
    }

    void setRadius(double r ){radius = r;}
    double getRadius()const {return radius;}

    virtual double Calc() const = 0;

    virtual ~Square(){}

};

class Circle : public Square{
public:
    Circle(double r) : Square(r) {}
    double Calc()const override {
        return 3.14159 * getRadius() * getRadius();
    }
};

int main()
{
    Circle c1(0), c2(0);

    double r1, r2;
    cout << "Enter the radius of the first circle: ";
    cin >> r1;
    cout << "Enter the radius of the second circle: ";
    cin >> r2;

    c1.setRadius(r1);
    c2.setRadius(r2);

    double area1 = c1.Calc();
    double area2 = c2.Calc();

    cout << "Area of circle 1: " << area1 << endl;
    cout << "Area of circle 2: " << area2 << endl;

    cout << "\nCircle with larger radius has radius: " << (c1.getRadius() > c2.getRadius() ? c1.getRadius() : c2.getRadius()) << endl;

    return 0;
}
