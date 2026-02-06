#include <iostream>
#include <cstring>
using namespace std;

class Date{
protected:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
    Date(const Date& other){
        day = other.day;
        month = other.month;
        year = other.year;
    }

    void print()const{
        cout << day << "." << month << "." << year << endl;
    }
};

class Patient{
protected:
    string name;
    string EGN;
    string complain;
    Date date;
public:
    Patient(string n, string e, string c, Date d) : date(d){
        name = n;
        EGN = e;
        complain = c;
        date = d;
    }

    string getComplain()const{return complain;}

    void print()const{
        cout << "Name: " << name << endl;
        cout << "EGN: " << EGN << endl;
        cout << "Complain: " << complain << endl;
        cout << "Date: ";
        date.print();
        cout << endl;
        cout << "--------------------------------------\n";
    }

};

int main()
{
    Patient p[3] = {
        Patient("Krasimir", "0541093427", "headache", Date(1, 1, 2009)),
        Patient("Magi", "0483943032", "stomachache", Date(4, 3, 2011)),
        Patient("Georgi", "9423839931", "toothache", Date(1, 5, 1999))

    };

    string enterComplain;
    cout << "Enter a complain you want to search: ";
    getline(cin, enterComplain);

    cout << "Patient with complain: " << enterComplain << endl;

    bool foundComplain = false;
    for(int i = 0; i < 3; i++){
        if(p[i].getComplain() == enterComplain){
            p[i].print();
            foundComplain = true;
        }
    }

    if(!foundComplain){
        cout << "There are no patients with this complain!\n";
    }


    return 0;
}
