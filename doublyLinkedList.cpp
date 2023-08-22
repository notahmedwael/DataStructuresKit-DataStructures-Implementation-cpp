#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node *next, *prev;
    };
    Node *head, *tail;
    int length;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
        length = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtBegin(T element) {
        Node *newNode = new Node;
        newNode->value = element;
        if (length == 0) {
            head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        } else {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void insertAtEnd(T element) {
        Node *newNode = new Node;
        newNode->value = element;
        if (length == 0) {
            head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        } else {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void insertAtPos(int pos, T element) {
        if (pos < 0 || pos > length) {
            cout << "Out of range." << endl;
            return;
        } else if (pos == 0) {
            insertAtBegin(element);
        } else if (pos == length) {
            insertAtEnd(element);
        } else {
            Node *newNode = new Node;
            newNode->value = element;
            Node *current = head;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
            current->next->prev = newNode;
            length++;
        }
    }

    void removeFirst() {
        if (length == 0) {
            cout << "Empty list" << endl;
            return;
        } else if (length == 1) {
            delete head;
            head = tail = nullptr;
            length--;
        } else {
            Node *current = head;
            head = head->next;
            head->prev = nullptr;
            delete current;
            length--;
        }
    }

    void removeLast() {
        if (length == 0) {
            cout << "Empty list" << endl;
            return;
        } else if (length == 1) {
            delete head;
            head = tail = nullptr;
            length--;
        } else {
            Node *current = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
            length--;
        }
    }

    void removeElement(T element) {
        if (isEmpty()) {
            cout << "List empty." << endl;
            return;
        }
        if (head->value == element) {
            removeFirst();
            return;
        } else {
            Node *current = head;
            while (current != nullptr && current->value != element) {
                current = current->next;
            }
            if (current == nullptr) {
                cout << "Element not found." << endl;
                return;
            } else if (current == tail) {
                removeLast();
                return;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                length--;
            }
        }
    }

    void removePos(int pos) {
        if (pos < 0 || pos >= length) {
            cout << "Invalid position." << endl;
            return;
        }
        if (pos == 0) {
            removeFirst();
            return;
        } else if (pos == length - 1) {
            removeLast();
            return;
        } else {
            Node *current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;
            length--;
        }
    }

    void print() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printReverse() {
        Node *current = tail;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        Node *temp = head;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        length = 0;
    }
};

int main() {
    DoublyLinkedList<int> d;
    d.insertAtPos(0, 1);
    d.insertAtPos(1, 2);
    d.insertAtPos(2, 3);
    d.insertAtBegin(0);
    d.insertAtEnd(4);
    d.removeElement(4);
    d.removePos(3);
    d.print();
    d.printReverse();
    return 0;
}