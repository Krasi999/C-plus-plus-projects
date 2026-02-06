#include <iostream>
#include <cstring>
using namespace std;

enum ZooLocs { ZOOANIMAL, BEAR, PANDA, MAMMAL, ELEPHANT, TIGER };

static const char* locTable[] = {
    "Whole zoo area",
    "North B1: brown area",
    "East B1,P area",
    "Mammal sector",
    "Elephant yard",
    "Tiger preserve"
};

class ZooAnimal {
    friend void print(ZooAnimal*);
public:
    ZooAnimal(char* s = "ZooAnimal");
    virtual ~ZooAnimal() { delete name; }

    void link(ZooAnimal*);
    virtual void print();
    virtual void isA() = 0;

protected:
    char* name;
    ZooAnimal* next;
};

class Bear : public ZooAnimal {
public:
    Bear(char* s = "Bear", ZooLocs loc = BEAR, char* sci = "Ursidae");
    ~Bear() { delete sciName; }

    void print();
    void isA();

protected:
    char* sciName;
    ZooLocs ZooArea;
};

class Panda : public Bear {
public:
    Panda(char* nm, int room, char* s = "Panda",
          char* sci = "Ailuropoda Melaoleuca",
          ZooLocs loc = PANDA);

    ~Panda() { delete indName; }

    void print();
    void isA();

protected:
    char* indName;
    int cell;
};

//---------------------------------------------------------------

class Mammal : virtual public ZooAnimal {
public:
    Mammal(char* s = "Mammal", char* sci = "Mammalia",  ZooLocs loc = ZOOANIMAL);
    ~Mammal() { delete sciName; }

    void print();
    void isA();

protected:
    char* sciName;
    ZooLocs area;
};

Mammal::Mammal(char* s, char* sci, ZooLocs loc)
    : ZooAnimal(s), area(loc)
{
    sciName = new char[strlen(sci) + 1];
    strcpy(sciName, sci);
}


void Mammal::isA() {
    ZooAnimal::isA();
    cout << "\tScientific name:\t" << sciName << '\n';
}

void Mammal::print() {
    ZooAnimal::print();
    cout << "\tLocation:\t" << locTable[area] << '\n';
}

class Tiger : public Mammal {
public:
    Tiger( char* nickname, int cageNo,
           char* name = "Tiger",
           char* sci = "Panthera tigris",
          ZooLocs loc = ZOOANIMAL);

    ~Tiger() { delete nick; }

    void print();
    void isA();

protected:
    char* nick;
    int cage;
};

Tiger::Tiger(char* nickname, int cageNo,
              char* name, char* sci, ZooLocs loc)
    : Mammal(name, sci, loc), cage(cageNo)
{
    nick = new char[strlen(nickname) + 1];
    strcpy(nick, nickname);
}

void Tiger::isA() {
    Mammal::isA();
    cout << "\tNickname:\t" << nick << '\n';
}

void Tiger::print() {
    Mammal::print();
    cout << "\tCage No:\t" << cage << '\n';
}

class Elephant : public Mammal {
public:
    Elephant(char* nickname, double weightTons,
             char* name = "Elephant",
             char* sci = "Loxodonta africana",
             ZooLocs loc = ZOOANIMAL);

    ~Elephant() { delete nick; }

    void print();
    void isA();

protected:
    char* nick;
    double weight;
};

Elephant::Elephant(char* nickname, double weightTons,
                   char* name,  char* sci, ZooLocs loc)
    : Mammal(name, sci, loc), weight(weightTons)
{
    nick = new char[strlen(nickname) + 1];
    strcpy(nick, nickname);
}

void Elephant::isA() {
    Mammal::isA();
    cout << "\tNickname:\t" << nick << '\n';
}

void Elephant::print() {
    Mammal::print();
    cout << "\tWeight (tons):\t" << weight << '\n';
}

//------------------------------------------------------------------------------------------

ZooAnimal::ZooAnimal(char* s) : next(0) {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
}

void ZooAnimal::link(ZooAnimal* za) {
    za->next = next;
    next = za;
}

void ZooAnimal::isA() {
    cout << "Animal name: " << name << '\n';
}

void ZooAnimal::print() {
    isA();
}

Bear::Bear(char* s, ZooLocs loc, char* sci)
    : ZooAnimal(s), ZooArea(loc)
{
    sciName = new char[strlen(sci) + 1];
    strcpy(sciName, sci);
}

void Bear::isA() {
    ZooAnimal::isA();
    cout << "\tSname:\t" << sciName << '\n';
}

void Bear::print() {
    ZooAnimal::print();
    cout << "\tAddress:\t" << locTable[ZooArea] << '\n';
}

Panda::Panda(char* nm, int room, char* s,
             char* sci, ZooLocs loc)
    : Bear(s, loc, sci), cell(room)
{
    indName = new char[strlen(nm) + 1];
    strcpy(indName, nm);
}

void Panda::isA() {
    Bear::isA();
    cout << "\tCall our friend:\t" << indName << '\n';
}

void Panda::print() {
    Bear::print();
    cout << "\tCell No:\t" << cell << '\n';
}

void print(ZooAnimal* pz) {
    while (pz) {
        pz->print();
        cout << '\n';
        pz = pz->next;
    }
}

ZooAnimal* headPtr = 0;
// ZooAnimal circus("Circus animal"); - това не може да се изпълни, защото класа ZooAnimal е абстрактен - притежава чисто виртуална функция
Bear yogi("Little bear", BEAR, "ursus cartoonus");
Panda yinYang("Yin Yang", 1001, "Big Panda");
Panda rocky("Rocky", 943, "Red Panda", "Ailurus fulgena");
Tiger shereKhan("Shere Khan", 500, "Bengal Tiger");         // Тигър с примерни имена
Elephant dumbo("Dumbo", 4.2, "African Elephant");           // Слон с примерни имена

ZooAnimal* makelist(ZooAnimal* ptr) {
    ptr = &yinYang;
    // ptr->link(&circus); - това не може да се изпълни, защото класа ZooAnimal е абстрактен - притежава чисто виртуална функция
    ptr->link(&yogi);
    ptr->link(&rocky);
    ptr->link(&shereKhan);
    ptr->link(&dumbo);
    return ptr;
}

int main() {
    cout << "Virtual Function Example\n";
    headPtr = makelist(headPtr);
    print(headPtr);
}
