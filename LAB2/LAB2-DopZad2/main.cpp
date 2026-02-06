#include <iostream>
using namespace std;

class pr2;

class pr1{
    private:
        int printing;
    public:
        pr1(){
            printing = 0;
        }
        void set_print(int status)
        {
            printing = status;
        }
        friend bool inuse(pr1 p1, pr2 p2);
};

class pr2{
    private:
        int printing;
    public:
        pr2(){
            printing = 0;
        }
        void set_print(int status)
        {
            printing = status;
        }
        friend bool inuse(pr1 p1, pr2 p2);
};

bool inuse(pr1 p1, pr2 p2){
    if(p1.printing == 1 || p2.printing == 1){
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    bool result;

    pr1 p1;
    p1.set_print(0);

    pr2 p2;
    p2.set_print(0);

    result = inuse(p1, p2);
    if(result == true){
        cout << "The printer is in use\n";
    }else {
        cout << "The printer is free\n";
    }

    p1.set_print(0);
    p2.set_print(1);

    result = inuse(p1,p2);
    if(result = true){
        cout << "The printer is in use\n";
    }else{
        cout << "The printer is free\n";
    }

    return 0;
}
