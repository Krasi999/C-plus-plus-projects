#include <iostream>
#include <queue>
using namespace std;

class Queue {
public:
    using QueueInt = queue<int>;
    QueueInt qi;
    int maxSize;

public:
    Queue(int size);
    QueueInt &enqueue(int value);
    int dequeue();
    int front();
    void isEmpty();
    void isFull();
    static QueueInt mergeQueues(const Queue &q1, const Queue &q2);
    ~Queue()
    {
        cout << "Destructing object Queue!\n";
    }
};

Queue::Queue(int size)
{
    maxSize = size;
    cout << "Enter " << size << " elements of the queue:\n";
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        qi.push(num);
    }
}

Queue::QueueInt &Queue::enqueue(int value)
{
    if ((int)qi.size() >= maxSize) {
        cout << "Queue is full! Cannot enqueue.\n";
    } else {
        qi.push(value);
    }
    return qi;
}

int Queue::dequeue()
{
    if (qi.empty()) {
        cout << "Queue is empty! Nothing to dequeue.\n";
        return -1;
    }

    int num = qi.front();
    qi.pop();
    return num;
}

int Queue::front()
{
    if (qi.empty()) {
        cout << "Queue is empty!\n";
        return -1;
    }

    return qi.front();
}


void Queue::isEmpty()
{
    if (qi.empty()) {
        cout << "The queue is empty!\n";
    } else {
        cout << "The queue is not empty!\n";
    }
}

void Queue::isFull()
{
    if ((int)qi.size() == maxSize) {
        cout << "The queue is full!\n";
    } else {
        cout << "The queue is not full!\n";
    }
}

Queue::QueueInt Queue::mergeQueues(const Queue &q1, const Queue &q2)
{
    Queue::QueueInt result;
    Queue::QueueInt temp1 = q1.qi;
    Queue::QueueInt temp2 = q2.qi;

    while (!temp1.empty() || !temp2.empty()) {
        if (!temp1.empty()) {
            result.push(temp1.front());
            temp1.pop();
        }
        if (!temp2.empty()) {
            result.push(temp2.front());
            temp2.pop();
        }
    }

    return result;
}

int main()
{
    Queue qi1(3);
    Queue qi2(3);

    cout << endl;
    qi1.enqueue(10);
    qi2.enqueue(5);

    cout << endl;
    cout << "Merging qi1 and qi2 into result...\n";
    queue<int> result = Queue::mergeQueues(qi1, qi2);

    cout << "Result queue (front to back): ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    cout << "\nFront element of qi1: " << qi1.front() << endl;
    cout << "Dequeued element from qi2: " << qi2.dequeue() << endl;
    qi2.enqueue(15);
    cout << "Enqueued element in qi2: " << 15 << endl;

    cout << endl;
    qi1.isEmpty();
    qi2.isFull();

    cout << endl;

    return 0;
}
