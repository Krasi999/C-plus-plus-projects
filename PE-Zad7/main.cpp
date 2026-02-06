#include <iostream>
#include <cstring>
using namespace std;

class Reader{
protected:
    string name;
    int rNumber;
public:
    Reader(string n, int r){
        name = n;
        rNumber = r;
    }
    string getName()const{return name;}
    int getRNumber()const{return rNumber;}
};

enum status{freee, taken};

class Library : public Reader{
protected:
    string bookName;
    enum status sts;
public:
    Library(string b, enum status s, string n, int r) : Reader(n, r){
        bookName = b;
        sts = s;
    }
    string getBookName()const{return bookName;}
    enum status getSts()const{return sts;}

    void takeBook(){
        if(sts == freee){
            cout << "You can take the book " << bookName << "!\n";
            sts = taken;
        }else{
            cout << "The book is already taken!\n";
        }
    }

    void checkBook(){
        if(sts == freee){
            cout << "The status of this book is free!\n";
        }
        else{
            cout << "The status of this book is taken!\n";
        }
    }

    void print(){
        cout << "The name of the book is: " << bookName << endl;
        cout << "The status of the book is: " << sts << endl;
        cout << "The name of the reader is: " << getName() << endl;
        cout << "The number of the reader is: " << getRNumber() << endl;
        cout << "\n----------------------------------------\n";
    }
};

int main()
{
    Library l[3] = {
            Library("HP", freee, "Krasi", 1),
            Library("KP", taken, "Magi", 2),
            Library("LH", freee, "Luke", 3)
    };

    for(int i = 0; i < 3; i++){
        if(l[i].getSts() == freee){
            l[i].print();
        }
    }

    l[0].takeBook();

    l[0].checkBook();

    return 0;
}
