#include <iostream>
using namespace std;

class truck; // Предварителна декларация

class car {
    int passengers;
    int speed;
    int distance;

public:
    car(int p, int s, int d) {
        passengers = p;
        speed = s;
        distance = d;
    }

    int sp_greater(truck t);
    friend double time_for_kilometers(car c, truck t);
};

class truck {
    int weight;
    int speed;
    int distance;

public:
    truck(int w, int s, int d) {
        weight = w;
        speed = s;
        distance = d;
    }

    friend int car::sp_greater(truck t);
    friend double time_for_kilometers(car c, truck t);
};

/*
 Връща положителна стойност, ако скоростта на колата е по-голяма от тази на камиона.
 Връща 0, ако скоростите са еднакви.
 Връща отрицателна стойност, ако скоростта на камиона е по-голяма от тази на колата.
*/
int car::sp_greater(truck t)
{
    return speed - t.speed; // Сравнение между скоростите
}

double time_for_kilometers(car c, truck t) {
    double car_time = (c.distance) / (double)c.speed;
    double truck_time = (t.distance) / (double)t.speed;
    cout << "\nTime for car: " << car_time << " hours\n";
    cout << "Time for truck: " << truck_time << " hours\n";
    return 0;
}

int main()
{
    int t;
    car c1(6, 55, 200), c2(2, 120, 150);
    truck t1(10000, 55, 45), t2(20000, 72, 70);

    cout << "Comparing c1 and t1:\n";
    t = c1.sp_greater(t1); // Извиква се като член-функция на car

    if (t < 0)
        cout << "Truck is faster.\n";
    else if (t == 0)
        cout << "Car and truck speed is the same.\n";
    else
        cout << "Car is faster.\n";

    cout << "\nComparing c2 and t2:\n";
    t = c2.sp_greater(t2); // Извиква се като член-функция на car

    if (t < 0)
        cout << "Truck is faster.\n";
    else if (t == 0)
        cout << "Car and truck speed is the same.\n";
    else
        cout << "Car is faster.\n";

    car c3(8, 120, 320);
    truck t3(12, 200, 180);

    time_for_kilometers(c3, t3);

    return 0;
}
