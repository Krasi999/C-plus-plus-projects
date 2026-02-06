#include <iostream>
#include <string>
using namespace std;

class employee {
private:
    int socialNumber;
    string name;
    int yearsAtWork;
    string position;
    double salaries[12];

public:
    employee();
    employee(bool askPosition);
    void setParameters();
    double averageSalary();
    double minSalary();
};

employee::employee() {
    socialNumber = 0;
    yearsAtWork = 0;
}


employee::employee(bool askPosition) {
    if (askPosition) {
        cout << "Enter the current position: ";
        getline(cin, position);
    }
}

void employee::setParameters() {
    cout << "Enter social number: ";
    cin >> socialNumber;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter years at work: ";
    cin >> yearsAtWork;
    cin.ignore();

    cout << "Enter position: ";
    getline(cin, position);

    cout << "Enter the last 12 salaries (for each month):" << endl;
    for (int i = 0; i < 12; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> salaries[i];
    }
}


double employee::averageSalary() {
    double sum, count = 0;
    for (int i = 0; i < 12; i++) {
        sum += salaries[i];
        count ++;
    }
    return sum / count;
}

double employee::minSalary() {
    double min = salaries[0];
    for (int i = 1; i < 12; i++) {
        if (salaries[i] < min) {
            min = salaries[i];
        }
    }
    return min;
}

int main() {
    employee ob1;
    ob1.setParameters();

    cout << "\nThe average salary is: " << ob1.averageSalary() << endl;
    cout << "The minimum salary is: " << ob1.minSalary() << endl;

    return 0;
}
