/*

НЕ НАПЪЛНО РАБОТЕЩА ВЕРСИЯ, НО ПАК СТАВА

void thread_pool(const string &name, int liters, int milliseconds, bool isFiller) {
    while (true) {
        {
            lock_guard<mutex> lock(m);

            if (isFiller) {
                // Ако басейнът е пълен
                if (capacity >= MAX_CAPACITY) {
                    cout << name << " paused (pool full: " << capacity << "L)" << endl;
                    this_thread::sleep_for(chrono::seconds(10));
                    continue;
                }

                capacity += liters;
                if (capacity > MAX_CAPACITY)
                    capacity = MAX_CAPACITY;

                cout << name << " filled " << liters << "L -> capacity = " << capacity << endl;
            }
            else {
                // Ако басейнът е празен
                if (capacity <= MIN_CAPACITY) {
                    cout << name << " paused (pool empty: " << capacity << "L)" << endl;
                    this_thread::sleep_for(chrono::seconds(10));
                    continue;
                }

                capacity -= liters;
                if (capacity < MIN_CAPACITY)
                    capacity = MIN_CAPACITY;

                cout << name << " emptied " << liters << "L -> capacity = " << capacity << endl;
            }
        }

        // Изчакване между операциите
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }
}

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;
int capacity = 2500;
const int MAX_CAPACITY = 5000;
const int MIN_CAPACITY = 0;

void thread_pool(const string &name, int liters, int milliseconds, bool isFiller) {
    while (true) {

        bool shouldSleep = false;

        {
            lock_guard<mutex> lock(m);

            if (isFiller) {
                if (capacity >= MAX_CAPACITY) {
                    cout << name << " paused (pool full: " << capacity << "L)" << endl;
                    shouldSleep = true;  // отбелязваме, че трябва да спим
                } else {
                    capacity += liters;
                    if (capacity > MAX_CAPACITY) capacity = MAX_CAPACITY;
                    cout << name << " filled " << liters << "L -> capacity = " << capacity << endl;
                }
            } else {
                if (capacity <= MIN_CAPACITY) {
                    cout << name << " paused (pool empty: " << capacity << "L)" << endl;
                    shouldSleep = true;
                } else {
                    capacity -= liters;
                    if (capacity < MIN_CAPACITY) capacity = MIN_CAPACITY;
                    cout << name << " emptied " << liters << "L -> capacity = " << capacity << endl;
                }
            }
        } // 🔒 mutex-ът се освобождава тук

        if (shouldSleep)
            this_thread::sleep_for(chrono::seconds(10));
        else
            this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }
}


int main() {
    thread t1(thread_pool, "Filler 1", 10, 30, true);
    thread t2(thread_pool, "Emptier 1", 50, 70, false);
    thread t3(thread_pool, "Emptier 2", 300, 1000, false);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
