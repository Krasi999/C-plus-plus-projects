#include <iostream>
using namespace std;

class time {
    public:
        int hour, minutes, seconds;
    public:
        time();
        void printHour();
        ~time()
        {
            cout << "\nDestructing object time!\n";
        }
};

time::time()
{
    do{
        cout << "Enter the hour: ";
        cin >> hour;
        cout << "Enter the minutes: ";
        cin >> minutes;
        cout << "Enter the seconds: ";
        cin >> seconds;
    }while(!(hour >= 0 && hour < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60));
}

void time::printHour()
{
    int choise;
    cout << "Enter the time format you want to see -> 1 for(00:00:00) or 2 for(00:00:00 AM/PM):";
    cin >> choise;

    switch(choise){
        case 1:
            {
                cout << "The hour is: " << hour <<":" << minutes <<":" << seconds;
                break;
            }
        case 2:
            {
                 if(hour < 12){
                    cout << "The hour is: " << hour <<":" << minutes <<":" << seconds <<" AM";
                }else{
                    cout << "The hour is: " << hour <<":" << minutes <<":" << seconds <<" PM";
                }
                break;
            }
        default:
            {
                 cout << "You enter a wrong number!";
                 break;
            }
    }
}

int main(){

    time ob1;
    ob1.printHour();

    return 0;

}
