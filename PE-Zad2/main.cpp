#include <iostream>
using namespace std;

class Point{
protected:
    int x;
    int y;
    char name;
public:
    Point()
    {
        cout << "Enter the coordinates of the center:\n";
        cin >> x >> y;
        cout << "Enter the name:\n";
        cin >> name;
    }
    int getX()const{return x;}
    int getY()const{return y;}
    char getName()const{return name;}
};

class Circle{
protected:
    Point p;
    int radius;
public:
    Circle()
    {
        cout << "Enter the radius: ";
        cin >> radius;
    }
    int getRadius()const{return radius;}
    void print() const{
        cout << "The coordinates of the center are: " << p.getX() << ", " << p.getY() << "\n";
        cout << "His name is: " << p.getName() << "\n";
        cout << "The radius is: " << getRadius() << "\n";
    }
};

int main()
{
    Circle c[5];

    cout << "Print every circle witch have radius > 10:\n ";

    for(int i = 0; i < 5; i++){
        if(c[i].getRadius() > 10){
            c[i].print();
        }
    }

    return 0;
}
