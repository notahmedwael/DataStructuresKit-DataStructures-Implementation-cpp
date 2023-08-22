#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* arr;
    int maxSize;
    int length;

public:
    ArrayList(int size = 10) {
        if (size < 0) {
            maxSize = 10;
        } else {
            maxSize = size;
            length = 0;
            arr = new T[maxSize];
        }
    }

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == maxSize;
    }

    int getSize() {
        return length;
    }

    void print() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertAt(int pos, T element) {
        if (isFull()) {
            cout << "Array is full." << endl;
        } else if (pos < 0 || pos > length) {
            cout << "Out of array range." << endl;
        } else {
            for (int i = length; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
            length++;
        }
    }

    int search(T element) {
        for (int i = 0; i < length; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void uniqueInsert(T element) {
        if (search(element) == -1) {
            insertAtEnd(element);
        } else {
            cout << "Element is already in the list, no duplicates are allowed." << endl;
        }
    }

    void updateAt(int pos, T element) {
        if (pos < 0 || pos >= length) {
            cout << "Out of array range." << endl;
        } else {
            arr[pos] = element;
        }
    }

    void insertAtEnd(T element) {
        if (isFull()) {
            cout << "Array is full." << endl;
        } else {
            arr[length] = element;
            length++;
        }
    }

    void removeAt(int pos) {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
        } else if (pos < 0 || pos >= length) {
            cout << "Out of array range." << endl;
        } else {
            for (int i = pos; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }

    T getElement(int pos) {
        if (pos < 0 || pos >= length) {
            cout << "Out of array range." << endl;
        } else {
            return arr[pos];
        }
        return T(); // Return a default value if out of range.
    }

    ~ArrayList() {
        delete[] arr;
    }
};

int main() {
    ArrayList<int> arr;
    arr.uniqueInsert(24);
    arr.insertAt(0, 20);
    arr.print();
    return 0;
}
