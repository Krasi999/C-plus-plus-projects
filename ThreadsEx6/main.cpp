#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;
int capacity = 2000;
const int MIN_Capacity = 800;
bool shouldStart = false;

void threads(const string &name, int liters, int hours, bool isEmptier){
    while(true){
        bool shouldSleep = false;
        {
            lock_guard<mutex> lock(m);
            if(isEmptier){
                capacity -= liters;
                cout << name << " empties " << liters << " liters -> capacity = " << capacity << endl;
                if(capacity <= MIN_Capacity){
                    capacity = MIN_Capacity;
                    shouldStart = true;
                }
            }else{
                if(shouldStart){
                    capacity += liters;
                    cout << name << " inputs " << liters << " liters -> capacity = " << capacity << endl;
                    if(capacity >= 2000){
                        capacity = 2000;
                        shouldStart = false;
                    }
                }else{
                    shouldSleep = true;
                    cout << "The inputer is not active!" << endl;
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
    thread t1(threads, "Emptier1", 10, 200, true);
    thread t2(threads, "Emptier2", 5, 200, true);
    thread t3(threads, "Filler1", 20, 200, false);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
