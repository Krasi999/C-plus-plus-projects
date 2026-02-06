#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;

int text = 0;
bool isWriting = false;
int nextReader = 1;
int currentReader = 0;


void threads(const string &name, int ReaderID, bool isReader){
    while(true){
        bool shouldSleep = false;
        {
            lock_guard<mutex>lock(m);

            if(!isReader){
                if(!isWriting && currentReader == 0){
                    isWriting = true;
                    text++;
                    cout << "The writer is writing now -> the current text is: " << text << endl;
                    isWriting = false;

                    currentReader = nextReader;
                    shouldSleep = true;
                }
            }else{
                if(!isWriting && currentReader == ReaderID){
                    cout << "The reader" << currentReader << " reads -> the current text is: " << text << endl;
                    nextReader = (ReaderID == 1 ? 2 : 1);
                    currentReader = 0;
                    shouldSleep = true;
                }
            }

        }
        if(shouldSleep){
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}

int main()
{
    thread t1(threads, "Writer1", 0, false);
    thread t2(threads, "Reader1", 1, true);
    thread t3(threads, "Reader2", 2, true);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
