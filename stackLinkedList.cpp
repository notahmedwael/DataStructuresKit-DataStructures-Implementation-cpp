#include <iostream>
using namespace std;
template <class T>
class Stack{
    private:
    struct Node{
        T item;
        Node *next;
    };
    Node *top;
    public:
    Stack(){
        top = nullptr;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    void push(T element){
        Node *newItem = new Node;
        if (newItem == nullptr)
        {
            cout << "Stack push cannot allocate memory." << endl;
            return;
        }else{        
        newItem->item = element;
        newItem->next = top;
        top = newItem;
    }
    }
    void pop(){
        if (isEmpty())
        {
            cout << "Stack empty." << endl;
            return;
        }else{
            Node *temp = top;
            top = top->next;
            temp = temp->next = nullptr;
            delete temp;
        }
    }
    // pop method that can save the top element in a variable before popping it, so it can be readded later on.
    void pop(T &stackTop){
        if (isEmpty())
        {
            cout << "Stack empty." << endl;
            return;
        }else{
            stackTop = top->item;
            Node *temp = top;
            top = top->next;
            temp = temp->next = nullptr;
            delete temp;
        }
    }
    T getTop(){
        if (isEmpty())
        {
            cout << "Stack empty." << endl;
            return;
        }else{
            return top->item;
        }
    }
    void print(){
        Node *temp = top;
        while(temp != nullptr){
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
  Stack<int> s;
    for (int i = 0; i <= 10; i++) {
        s.push(i);
    }
    s.print();
    for (int i = 0; i <= 5; i++)
    {
        s.pop();
    }
    s.print();
    int top = 0;
    s.pop(top);
    cout << "Top element: " << top << " is popped." << endl;
    s.print();
  return 0;  
}