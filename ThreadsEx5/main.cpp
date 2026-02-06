#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;

int text = 0;
bool isWriting = false;
int currentWriter = 0;
int nextWriter = 1;


void threads(const string &name, int WriterID, bool isWriter){
    while(true){
        bool shouldSleep = false;
        {
            lock_guard<mutex>lock(m);

            if(isWriter){
                if(!isWriting && currentWriter == WriterID){
                    isWriting = true;
                    text++;
                    cout << "The " << currentWriter << " is writing now -> the current text is: " << text << endl;
                    isWriting = false;

                    nextWriter = (WriterID == 1 ? 2 : 1);
                    currentWriter = 0;

                    shouldSleep = true;

                }
            }else{
                if(!isWriting && currentWriter == 0){
                    cout << "The reader reads -> the current text is: " << text << endl;
                    currentWriter = nextWriter;
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
    thread t1(threads, "Writer1", 1, true);
    thread t2(threads, "Writer2", 2, true);
    thread t3(threads, "Reader1", 0, false);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
