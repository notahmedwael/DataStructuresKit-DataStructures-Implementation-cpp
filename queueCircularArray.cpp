#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class CircularQueue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int cap) {
        if (cap <= 0) {
            capacity = 10;
        } else {
            capacity = cap;
        }
        front = 0;
        rear = capacity - 1;
        size = 0;
        arr = new T[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void enqueue(const T& item) {
        if (isFull()) {
            front = (front + 1) % capacity;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        if (!isFull()) {
            size++;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    T frontElement() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[front];
    }

    void print() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i != rear; i = (i + 1) % capacity) {
            std::cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }

    int getSize() const {
        return size;
    }
};


int main() {
    CircularQueue<int> cq(5);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.print();
    cq.dequeue();
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);  // Overwrites oldest element (1)
    cq.print();
    return 0;
}