#include <iostream>
#include <cstring>
using namespace std;

class Data{
protected:
    int day;
    int month;
    int year;
public:
    Data(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }

    Data(const Data& other){
        day = other.day;
        month = other.day;
        year = other.year;
    }

    friend ostream& operator<<(ostream& out, const Data& d){
        out << "Data: "<< d.day << "." << d.month << "." << d.year << endl;
        return out;
    }
};

class Patient{
protected:
    string EGN;
    string name;
    string complain;
    Data data;
    string medicaments[5];
    int numMed;
public:
    Patient(string e, string n, string c, Data d, string med[], int num) : data(d){
        EGN = e;
        name = n;
        complain = c;
        data = d;
        numMed = (num > 5) ? 5 : num;
        for(int i = 0; i < num; i++){
            medicaments[i] = med[i];
        }
    }

    string getComplain()const{return complain;}

    friend ostream& operator<<(ostream& out, const Patient& p){
        out << "Patient name: " << p.name << endl;
        out << "Patient EGN: " << p.EGN << endl;
        out << "Patient complain: " << p.complain << endl;
        out << "Patient data: " << p.data << endl;
        out << "Medicaments: ";
        for(int i = 0; i < p.numMed; i++){
            out << p.medicaments[i];
            if(i != p.numMed - 1){
                out << ", ";
            }
        }
        out << endl;
        out << "-------------------------------------";
        return out;
    }
};


int main()
{
    string medicaments1[] = {"Ljdfjkf", "Gkldlfs"};
    string medicaments2[] = {"Kkhjdhksf", "Ljfkdshf", "Hkgkdfjsfj"};
    string medicaments3[] = {"Dkdjslkkf", "Uyuedhfks", "Nhiihdsfj", "Ahkjdfhsdlj"};

    Patient patients[3] = {
        Patient("0453456789", "Krasuska", "headache", Data(4, 12, 1978), medicaments1, 2),
        Patient("0561234587", "Maggie", "stomachache", Data(3,1, 2009), medicaments2, 3),
        Patient("0712345122", "HugoBoss", "virus", Data(1, 8, 2001), medicaments3, 4)
    };

    string searchComplain;
    cout << "Enter the complain you want to search: ";
    getline(cin, searchComplain);

    for(int i = 0; i < 3; i++){
        if(patients[i].getComplain() == searchComplain){
            cout << patients[i];
        }
    }

    return 0;
}
