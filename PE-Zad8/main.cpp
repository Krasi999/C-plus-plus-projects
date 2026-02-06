#include <iostream>
#include <cstring>
using namespace std;

class Book{
protected:
    string title;
    string author;
    string dateOfRent;
public:
    Book() = default;

    Book(string t, string a, string d){
        title = t;
        author = a;
        dateOfRent = d;
    }

    string getTitle()const{return title;}
    string getAuthor()const{return author;}
    string getDateOfRent()const{return dateOfRent;}

    friend ostream& operator<< (ostream& out, const Book& b){
        out<< "Book name: " << b.title
        << ", Author: " << b.author
        << ", Get date: " << b.dateOfRent << ".";
        return out;
    }
};

class Library{
protected:
    int titleNum;
    Book* books;
public:
    Library(int t){
        titleNum = t;
        books = new Book[titleNum];
    }

    int getTitleNum()const{return titleNum;}

    ~Library(){
        delete[] books;
    }

    Book& operator[](int index){
        return books[index];
    }

    friend ostream& operator<<(ostream& out, const Library& lib){
        for(int i = 0; i < lib.titleNum; i++){
            out << lib.books[i] << endl;
        }
        return out;
    }

};

int main()
{

    Library library(3);

    library[0] = Book("HP", "JKR", "12.12.2028");
    library[1] = Book("KP", "GHD", "09.01.2001");
    library[2] = Book("DH", "DTT", "06.11.1987");

    string searchDate;
    cout << "Enter the date you want to search: ";
    getline(cin, searchDate);

    bool flag = false;

    for(int i = 0; i < 3; i++){
        if(library[i].getDateOfRent() == searchDate){
            cout << "The title of the book is: " << library[i].getTitle() << endl;
            flag = true;
        }
    }

    if(!flag){
        cout << "The book with this data of rent is not existing!\n";
    }

    return 0;
}
