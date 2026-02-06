#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;
int capacity = 15000;
const int MIN_Capacity = 5000;

bool creditPaused1 = false;
bool creditPaused2 = false;
int monthsPaused1 = 0;
int monthsPaused2 = 0;

void threads(const string &name, int money, int month, bool isCreditor){
    while(true){

        bool shouldSleep = false;

        {
            lock_guard<mutex> lock(m);

            if(name == "Creditor2" && creditPaused1){
                monthsPaused1 --;
                cout << name << "is paused -> monthsPaused left = " << monthsPaused1 << endl;

                if(monthsPaused1 <= 0){
                    creditPaused1 = false;
                }
                shouldSleep = true;
            }
            else if(name == "Creditor3" && creditPaused2){
                monthsPaused2--;
                cout << name << "is paused -> monthsPaused left = " << monthsPaused2 << endl;

                if (monthsPaused2 <= 0){
                    creditPaused2 = false;
                }
                shouldSleep = true;
            }

            else if(isCreditor){

                capacity -= money;
                cout << name << " withdraw " << money << " -> capacity = " << capacity << endl;

                if(capacity <= MIN_Capacity && (!creditPaused1 && !creditPaused2)){
                    creditPaused1 = true;
                    creditPaused2 = true;
                    monthsPaused1 = 12;
                    monthsPaused2 = 12;
                    cout << "The limit is reached!" << endl;

                    capacity = MIN_Capacity;
                }
            }else{
                capacity += money;
                cout << name << " entered " << money << " -> capacity = " << capacity << endl;
            }
        }
        if(shouldSleep){
            this_thread::sleep_for(chrono::seconds(1));
        }else{
            this_thread::sleep_for(chrono::seconds(month));
        }
    }
}


int main()
{
    thread t1(threads, "Creditor1", 500, 1, true);
    thread t2(threads, "Creditor2", 500, 1, true);
    thread t3(threads, "Creditor3", 500, 1, true);
    thread t4(threads, "Depositor1", 250, 1, false);
    thread t5(threads, "Depositor2", 250, 1, false);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
