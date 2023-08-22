#include<iostream>
using namespace std;
template<class T>
class LinkedQueue{
private:
struct Node
{
    T item;
    Node* next;
};
    Node *front;
    Node *rear;
    int length;
public:
    LinkedQueue():front(nullptr), rear(nullptr), length(0){}
    bool isEmpty()const{
        return length == 0;
    }
    void enqueue(const T& item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    length++;
}
    void dequeue(){
        if (isEmpty())
        {
            cout << "Queue is empty cannot dequeue." << endl;
            return;
        }else{
            Node *temp = front;
            if (front == rear)
            {
                front = rear = nullptr;
            }else{
                front = front->next;
                temp->next = nullptr;
                delete temp;
            }
            length--;
        }
    }
    T getFront() const {
    if (!isEmpty()) {
        return front->item;
    } else {
        cout << "Queue is empty." << endl;
        return T();  // Return a default-constructed value for 'T'
    }
}
    void clear(){
        Node *current;
        while(front != nullptr){
            current = front;
            front = front->next;
            delete current;
        }
        rear = nullptr;
        length = 0;
    }
    int getSize()const{
        return length;
    }
    void print(){
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->item << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedQueue<int> lq;
    lq.enqueue(1);
    lq.enqueue(2);
    lq.enqueue(3);
    lq.print();
    lq.dequeue();
    lq.print();
    cout << "Size is: " << lq.getSize() << endl;
    cout << "Front: " <<lq.getFront() << endl;
    lq.clear();
    lq.print();
    return 0;
}