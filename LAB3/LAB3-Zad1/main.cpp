#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    using StackChar = stack<char>;
    StackChar st;

public:
    Stack();
    StackChar loadstack();
    StackChar loadstack(int upper);
    void show(StackChar s);
    ~Stack()
    {
        cout << "\nDestructing object Stack!\n";
    }
};

Stack::Stack()
{
    cout << "Stack object created.\n";
}


Stack::StackChar Stack::loadstack()
{
    while (!st.empty())
    {
        st.pop();
    }

    for (char c = 'a'; c <= 'z'; c++) {
        st.push(c);
    }
    return st;
}


Stack::StackChar Stack::loadstack(int upper)
{
    while (!st.empty())
    {
        st.pop();
    }

    if (upper == 1) {
        for (char c = 'A'; c <= 'Z'; c++) {
            st.push(c);
        }
    } else {
        for (char c = 'a'; c <= 'z'; c++) {
            st.push(c);
        }
    }
    return st;
}


void Stack::show(StackChar s)
{
    cout << "Stack content (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    Stack st1;
    stack<char> s;

    cout << "\nLoading lowercase stack...\n";
    s = st1.loadstack();
    st1.show(s);

    cout << "\nLoading uppercase stack...\n";
    s = st1.loadstack(1);
    st1.show(s);

    cout << "\nLoading lowercase stack again...\n";
    s = st1.loadstack(0);
    st1.show(s);

    return 0;
}
