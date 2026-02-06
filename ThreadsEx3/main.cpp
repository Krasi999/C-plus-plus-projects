#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;
int capacity = 20000;
const int MAX_Cpacity = 40000;
const int MIN_Capacity = 20000;
bool isCreditingActive = false;

void threads(const string &name, int money, int months, bool isCreditor){
    while(true){
            bool shouldSleep = false;
        {
            lock_guard<mutex> lock(m);

            if(isCreditor){
                if(isCreditingActive){
                    capacity -= money;
                    cout << name << " withdraw " << money << " -> capacity = " << capacity << endl;
                    if(capacity <= MIN_Capacity){
                        isCreditingActive = false;
                    }
                }else{
                    cout << "The creditors are limitted!" << endl;
                    shouldSleep = true;
                }
            }else{
                capacity += money;
                cout << name << " entered " << money << " -> capacity = " << capacity << endl;
                if(capacity >= MAX_Cpacity){
                    isCreditingActive = true;
                }
            }
        }
        if(shouldSleep){
            this_thread::sleep_for(chrono::seconds(1));
        }else
            this_thread::sleep_for(chrono::seconds(months));
    }
}

int main()
{
    thread t1(threads, "Creditor1", 1500, 1, true);
    thread t2(threads, "Creditor2", 1500, 1, true);
    thread t3(threads, "Creditor3", 1500, 1, true);
    thread t4(threads, "Creditor4", 1500, 1, true);

    thread t5(threads, "Depositor1", 1000, 1, false);
    thread t6(threads, "Depositor2", 1000, 1, false);
    thread t7(threads, "Depositor3", 1000, 1, false);
    thread t8(threads, "Depositor4", 1000, 1, false);

    t1.join();t2.join();t3.join();t4.join();t5.join();t6.join();t7.join();t8.join();

    return 0;
}
