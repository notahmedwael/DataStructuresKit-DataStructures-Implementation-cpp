#include <iostream>
using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T value;
        Node* next;
    };
    Node* head;
    Node* tail;
    int length;

public:
    SinglyLinkedList() {
        head = tail = nullptr;
        length = 0;
    }

    bool isEmpty() {
        return length == 0 || head == nullptr;
    }

    void insertAtBegin(T element) {
        Node* newNode = new Node;
        newNode->value = element;
        if (length == 0 || head == nullptr) {
            head = tail = newNode;
            newNode->next = nullptr;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void insertAtEnd(T element) {
        Node* newNode = new Node;
        newNode->value = element;
        if (length == 0 || head == nullptr) {
            head = tail = newNode;
            newNode->next = nullptr;
        } else {
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
        length++;
    }

    void insertAtPos(int pos, T element) {
        if (pos < 0 || pos > length) {
            cout << "Out of range" << endl;
        } else {
            Node* newNode = new Node;
            newNode->value = element;
            if (pos == 0) {
                insertAtBegin(element);
            } else if (pos == length) {
                insertAtEnd(element);
            } else {
                Node* current = head;
                for (int i = 1; i < pos; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                length++;
            }
        }
    }
    void removeFirst(){
        if(length == 0){
            return;
        }else if(length == 1){
            delete head;
            head = tail = nullptr;
            length--;
        }else{
            Node *current = head;
            head = head->next;
            delete current;
            length--;
        }
    }
    void removeLast(){
        if(length == 0){
            return;
        }else if(length == 1){
            delete head;
            head = tail = nullptr;
            length--;
        }else{
            Node *current = head->next;
            Node *previous = head;
            while(current != tail){
                previous = current;
                current = current->next;
            }
            delete current;
            previous->next = nullptr;
            tail = previous;
            length--;
        }
    }
    void removeElement(int element){
        if(isEmpty()){
            return;
        }
        if(head->value == element){
           removeFirst();
           return;
        }else{
            Node *current, *previous;
            current = head->next; 
            previous = head;
            while(current != nullptr && current->value != element){
                previous = current;
                current = current->next;
            }
            if (current == nullptr)
            {
                cout << "Element does not exist in the linked list." << endl;
            }else{
                previous->next = current->next;
                if(tail == current){
                    tail = previous;
                }
                delete current;
                length--;
            }
        }
    }
    void removePos(int pos){
        if(pos < 0 || pos > length){
            cout << "Invalid position." << endl;
            return;
        }
        if(pos == 0){
            removeFirst();
            return;
        }else{
            Node *current, *previous;
            current = head->next;
            previous = head;
            for (int i = 0; i < pos-1; i++)
            {
                previous = current;
                current = current ->next;
            }
            if (current->next == nullptr)
            {
                removeLast();
                return;
            }
            previous ->next = current ->next;
            if(current == tail){
                tail = previous;
            }
            delete current;
            length--;
        }
    }
    void reverse(){
        Node *current, *next, *previous;
        previous = nullptr;
        current = head;
        next = current->next;
        while(current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    int search(int element){
        Node *current;
        current = head;
        int pos = 0;
        while(current != nullptr){
            if (current->value == element)
            {
                return pos;
            }else{
                current = current->next;
                pos++;
            }
        }
        return -1;
    }
    void print(){
        Node *current = head;
        while(current != nullptr){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~SinglyLinkedList() {
    Node *temp = head;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        length = 0;
}
};
int main(){
    SinglyLinkedList<int> s;
    s.insertAtBegin(30);
    s.insertAtPos(0,20);
    s.insertAtPos(1,23);
    s.insertAtPos(2, 24);
    s.insertAtPos(3,19);
    s.insertAtEnd(25);
    s.print();
    s.reverse();
    s.print();
    cout << s.search(45);
    return 0;
}