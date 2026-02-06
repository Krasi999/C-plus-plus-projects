#include <iostream>
#include <cstring>
using namespace std;

class Student{
protected:
    string name;
    string fNumber;
    int gNumber;
    int course;
public:
    Student(){
        cout << "\nEnter the name of the student: ";
        getline(cin, name);
        cout << "\nEnter the faculty number of the student: ";
        getline(cin, fNumber);
        cout << "\nEnter the group number of the student: ";
        cin >> gNumber;
        cout << "\nEnter the course of the student: ";
        cin >> course;
        cin.ignore();
    }

    virtual void printGrades() const {}

    virtual double avg() const { return 0.0; }


    virtual void print()const{
        cout << "The whole student info is:\n";
        cout << "Name: " << name << endl;
        cout << "Fnumber: " << fNumber << endl;
        cout << "Gnumber: " << gNumber << endl;
        cout << "Course: " << course << endl;
    }
};

class Grades : public Student{
private:
    double semester1[5];
    double semester2[5];
public:
    Grades() : Student() {
        cout << "Enter 5 grades for Semester 1:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Grade " << i + 1 << ": ";
            cin >> semester1[i];
        }
        cout << "Enter 5 grades for Semester 2:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Grade " << i + 1 << ": ";
            cin >> semester2[i];
        }
        cin.ignore();
    }

    void printGrades() const override {
        cout << "Semester 1 grades: ";
        for (int i = 0; i < 5; i++) cout << semester1[i] << " ";
        cout << "\nSemester 2 grades: ";
        for (int i = 0; i < 5; i++) cout << semester2[i] << " ";
        cout << endl;
    }

    double avg() const override {
        double sum = 0.0;
        for (int i = 0; i < 5; i++) sum += semester1[i] + semester2[i];
        return sum / 10.0;
    }

    void print()const override{
        cout << "The whole student info is:\n";
        cout << "Name: " << name << endl;
        cout << "Fnumber: " << fNumber << endl;
        cout << "Gnumber: " << gNumber << endl;
        cout << "Course: " << course << endl;
    }

    void fNumberFunction(){
        string searchFnum;
        cout << "Enter the Fnumber you want to search: ";
        getline(cin, searchFnum);
        if(searchFnum == fNumber){
            print();
        }
        cin.ignore();
    }

};

int main()
{
    int n;
    cout << "Number of students: ";
    cin >> n;
    cin.ignore();

    Grades *students = new Grades[n];

    double avg;
    for (int i = 0; i < n; i++){
        students[i].print();
        avg = students[i].avg();
        cout << "The avg of the student is: " << avg << endl;
    }


    double maxAvg = 0;
    for (int i = 0; i < n; i++)
        if (students[i].avg() > maxAvg)
            maxAvg = students[i].avg();

    cout << "\nMax average in the group: " << maxAvg << endl;

    for(int i = 0; i < n; i++){
        students[i].fNumberFunction();
    }

    delete[] students;

    return 0;
}
