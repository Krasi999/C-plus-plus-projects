#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;
int capacity = 10000;
const int MIN_Capacity = 5000;

bool isPaused = false;
int monthsPaused = 0;

void threads(const string &name, int money, int month, bool isCreditor){
    while(true){
        bool shouldSleep = false;

        {
            lock_guard<mutex> lock(m);

            if(name == "Creditor2" && isPaused){
                monthsPaused--;

                    if(monthsPaused <= 0){
                        monthsPaused = 0;
                        isPaused = false;
                    }
                    cout << name << "is paused -> monthsPaused left = " << monthsPaused << endl;
                    shouldSleep = true;
            }
            else if(isCreditor){
                if(capacity <= MIN_Capacity && !isPaused){
                    capacity = MIN_Capacity;
                    isPaused = true;
                    monthsPaused = 6;
                }
                else{
                    capacity -= money;
                    if(capacity <= MIN_Capacity) capacity = MIN_Capacity;
                    cout << name << " withdraw " << money << " -> capacity = " << capacity << endl;
                }
            }

            else{
                capacity += money;
                cout << name << " inputs " << money << " -> capacity = " << capacity << endl;
            }
        }//mutex-ът се отлючва тук
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
    thread t3(threads, "Depositor1", 250, 1, false);
    thread t4(threads, "Depositor2", 250, 1, false);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
