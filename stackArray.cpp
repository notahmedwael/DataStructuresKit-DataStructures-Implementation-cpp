#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
template <typename T>
class Stack {
private:
    int top;
    T items[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top < 0;
    }

    void push(T element) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack full on push." << endl;
            return;
        } else {
            top++;
            items[top] = element;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        } else {
            top--;
        }
    }

    void pop(T &element) {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        } else {
            element = items[top];
            top--;
        }
    }

    T getTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return T(); // Return default value of type T
        } else {
            return items[top];
        }
    }

    void print() {
        for (int i = top; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s;
    for (int i = 0; i <= 10; i++) {
        s.push(i);
    }
    s.print();
    return 0;
}