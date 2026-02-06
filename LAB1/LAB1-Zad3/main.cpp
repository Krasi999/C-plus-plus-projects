#include <iostream>
#include <string>
using namespace std;

class line {
private:
    int len;

public:
    line(int l);
    ~line();
};


line::line(int l) {
    len = l;

    for (int i = 0; i < len; i++) {
        cout << "*";
    }
    cout << endl;
}


line::~line() {

    for (int i = 0; i < len; i++) {
        cout << "\b \b";
    }
    cout << "\nLine object destroyed!\n";
}


int main() {
    line ob1(25);

    return 0;
}



/*

#include <iostream>
#include <cstdlib>
using namespace std;

class line {
private:
    int len;

public:
    line(int l);
    ~line();
};


line::line(int l) {
    len = l;
    cout << "Drawing line of length " << len << ":\n";
    for (int i = 0; i < len; i++) {
        cout << "*";
    }
    cout << endl;
}

line::~line() {
    cout << "\nClearing the screen (destroying the line)...\n";
    system("cls");
    cout << "Line object destroyed!\n";
}


int main() {
    line ob1(25);

    cout << "\nPress Enter to continue...";
    cin.get();

    return 0;
}

*/
