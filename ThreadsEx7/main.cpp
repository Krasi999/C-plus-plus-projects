#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;
int capacity = 600;
int MAX_Capacity = 2000;
bool shouldStart = false;

void threads(const string &name, int liters, int hours, bool isFiller){
    while(true){
        bool shouldSleep = false;
        {
            lock_guard<mutex>lock(m);
            if(isFiller){
                capacity += liters;
                if(capacity >= MAX_Capacity){
                    capacity = MAX_Capacity;
                    shouldStart = true;
                }
                cout << name << " inputs " << liters << " liters -> capacity = " << capacity << endl;
            }else{
                if(shouldStart){
                    capacity -= liters;
                    if(capacity <= 600){
                        capacity = 600;
                        shouldStart = false;
                    }
                    cout << name << " empties " << liters << " liters -> capacity = " << capacity << endl;
                }else{
                    shouldSleep = true;
                }
            }
        }
        if(shouldSleep){
            this_thread::sleep_for(chrono::seconds(1));
        }else{
            this_thread::sleep_for(chrono::milliseconds(hours));
        }
    }
}

int main()
{
    thread t1(threads, "Filler1", 5, 50, true);
    thread t2(threads, "Filler2", 10, 50, true);
    thread t3(threads, "Emptier1", 30, 50, false);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
