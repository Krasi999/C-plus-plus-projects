/*

#include <iostream>
#include <string>
using namespace std;

class item{
        string title;
        double price;
        int id;
        string format;
        string dataOfPerchase;
    public:
        item(string t, double p, int n, string f, string d){
            title = t;
            price = p;
            id = n;
            format = f;
            dataOfPerchase = d;
        }

        string getTitle(){return title;}
        double getPrice(){return price;}
        int getId(){return id;}
        string getFormat(){return format;}
        string getDataOfPerchase(){return dataOfPerchase;}

        void print(){
            cout << format << " with title " << title << " was purchased at a price of " << price << " on date " << dataOfPerchase << "." << endl;
        }
};

class movie : public item{
        double rating;
    public:
        movie(string t, double p, int n, string f, string d, double r) : item( t, p, n, f, d)
        {
            rating = r;
        }

        double getRating(){return rating;}

        void printMovie(){
            print();
            cout << "The rating of the movie is " << rating << "." << endl;
        }
};

class game : public item{
        int level;
    public:
        game(string t, double p, int n, string f, string d, int l) : item(t, p, n, f, d)
        {
            level = l;
        }

        double getLevel(){return level;}

        void printGame(){
            print();
            cout << "The level of the game is " << level << "." << endl;
        }
};

class music : public item{
        string singer;
    public:
        music(string t, double p, int n, string f, string d, string s) : item(t, p, n, f, d)
        {
            singer = s;
        }

        string getSinger(){return singer;}

        void printMusic(){
            print();
            cout << "The singer of this song is " << singer << "." << endl;
        }
};

int main()
{
    movie m("The Shawshank redemption", 5.00, 123, "video", "10.12.2023", 9.5);
    cout << "MOVIE:\n";
    m.printMovie();
    cout << endl;

    game g("Minecraft", 36.90, 100, "CD", "12.09.2021", 8);
    cout << "GAME:\n";
    g.printGame();
    cout << endl;

    music s("Beliver", 12.50, 85, "DVD", "23.02.2017", "Imagine Dragons");
    cout << "SONG:\n";
    s.printMusic();
    cout << endl;

    return 0;
}

*/



#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string title;
    double price;
    int id;
    string format;
    string dateOfPurchase;

public:
    Item(string t, double p, int i, string f, string d){
        title = t;
        price = p;
        id = i;
        format = f;
        dateOfPurchase = d;
    }

    string getTitle() const { return title; }
    double getPrice() const { return price; }
    int getId() const { return id; }
    string getFormat() const { return format; }
    string getDateOfPurchase() const { return dateOfPurchase; }

    virtual void print() const = 0;

    virtual ~Item(){
        cout << "\nDestructing object!\n";
    }
};

class Movie : public Item {
    double rating;

public:
    Movie(string t, double p, int i, string f, string d, double r) : Item(t, p, i, f, d)
    {
        rating = r;
    }

    double getRating() const { return rating; }

    void print() const override{
        cout << "Movie \"" << title << "\" (" << format << ") was purchased on "
             << dateOfPurchase << " for $" << price << ".\n";
        cout << "Rating: " << rating << "/10\n";
    }
};

class Game : public Item {
    int level;

public:
    Game(string t, double p, int i, string f, string d, int l) : Item(t, p, i, f, d)
    {
        level = l;
    }

    int getLevel() const { return level; }

    void print() const override{
        cout << "Game \"" << title << "\" (" << format << ") was purchased on "
             << dateOfPurchase << " for $" << price << ".\n";
        cout << "Level: " << level << "\n";
    }
};

class Music : public Item {
    string singer;

public:
    Music(string t, double p, int i, string f, string d, string s) : Item(t, p, i, f, d)
    {
        singer = s;
    }

    string getSinger() const { return singer; }

    void print() const override {
        cout << "Song \"" << title << "\" (" << format << ") was purchased on "
             << dateOfPurchase << " for $" << price << ".\n";
        cout << "Singer: " << singer << "\n";
    }
};

int main() {

    //Item i("f", 5.00, 123, "Video", "10.12.2023"); - Не може да се създава обект от клас Item защото класа е абстрактен

    Movie m("The Shawshank Redemption", 5.00, 123, "Video", "10.12.2023", 9.5);
    Game g("Minecraft", 36.90, 100, "CD", "12.09.2021", 8);
    Music s("Believer", 12.50, 85, "DVD", "23.02.2017", "Imagine Dragons");

    cout << "MOVIE:\n";
    m.print();

    cout << "\nGAME:\n";
    g.print();

    cout << "\nMUSIC:\n";
    s.print();

    return 0;
}
