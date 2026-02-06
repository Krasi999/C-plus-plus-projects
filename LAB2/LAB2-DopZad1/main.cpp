#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<char> st;

public:
    Stack();
    stack<char> loadstack();
    stack<char> loadstack(int upper);
    void show(stack<char> s);
    ~Stack()
    {
        cout << "\nDestructing object Stack!\n";
    }
};

Stack::Stack()
{
    cout << "Stack object created.\n";
}


stack<char> Stack::loadstack()
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


stack<char> Stack::loadstack(int upper)
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


void Stack::show(stack<char> s)
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
