#include <iostream>
#include <cstring>
using namespace std;

class People{
protected:
    string name;
    string EGN;
public:
    People(string n, string e){
        name = n;
        EGN = e;
    }
    string getName()const{return name;}
    string getEGN()const{return EGN;}

};

class Student : public People{
protected:
    string fNumber;
    double averageGrade;
public:
    Student(string fN, double aG, string n, string e) : People(n, e){
        fNumber = fN;
        averageGrade = aG;
    }
    string getFNumber()const{return fNumber;}
    double getAverageGrade()const{return averageGrade;}

};

class PStudent : public Student{
public:
    PStudent(string fN, double aG, string n, string e) : Student(fN, aG, n, e){}

    void isReciveingAward(){
        bool award = false;
        if(getAverageGrade() > 4.5){
            award = true;
            cout << "The student is receiving award!\n";
        }
        else {
            cout << "The student is not receiving award!\n";
        }
    }
};

int main()
{
    PStudent s1("121223008", 3.6, "Krasimir" , "0541093427");
    s1.isReciveingAward();


    return 0;
}
