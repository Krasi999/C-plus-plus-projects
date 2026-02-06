#include <iostream>
#include<cstring>
using namespace std;

class Bank{
protected:
    string name;
    double balance;
    double percent;
public:
    Bank(string n, double b, double p){
        name = n;
        balance = b;
        percent = p;
    }

    string getName()const{return name;}
    double getBalance()const{return balance;}
    double getPercent()const{return percent;}

    virtual void deposit(){
        cout << "You can't deposit money in this account!\n";
    }

    virtual void withdraw() const{
        cout << "You can't withdraw money from this account!\n";
    }

    virtual double sizeOfCredit(int months)const{
        return percent * months;
    }

    virtual ~Bank(){
        cout << "Destructing object successfully!\n";
    }
};

class Deposit : public Bank{
public:
    Deposit(string n, double b, double p) : Bank(n, b, p){}
};

class Credit : public Bank{
public:
    Credit(string n, double b, double p) : Bank(n, b, p){}

    void deposit() override{
        double depositMoney;
        cout << "Enter the money you want to deposit: ";
        cin >> depositMoney;
        balance += depositMoney;
        cout << "The new balance is: " << balance << endl;
    }
};

int main()
{
    Bank* banks[4];

    banks[0] = new Deposit("Ivan", 1500, 2.5);
    banks[1] = new Credit("Peter", 500, 3.2);
    banks[2] = new Credit("Maria", 2000, 4.1);
    banks[3] = new Deposit("Georgi", 1200, 1.8);

    banks[0]->deposit();
    banks[0]->withdraw();

    banks[1]->deposit();
    banks[1]->withdraw();

    double sizeofcredit = banks[0]->sizeOfCredit(6);
    cout << "The size of credit of " << banks[0]->getName() << " is: "<< sizeofcredit << endl;

    double maxAcc = banks[0]->getPercent();
    int indexMax = 0;
    for (int i = 1; i < 4; i++) {
        if (banks[i]->getPercent() > maxAcc) {
            maxAcc = banks[i]->getPercent();
            indexMax = i;
        }
    }

    cout << "The bank account with name " << banks[indexMax]->getName() << " has the biggest interest percent: " << maxAcc << endl;


    for (int i = 0; i < 4; i++)
    {
        delete banks[i];
    }

    return 0;
}
