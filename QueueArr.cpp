#include <iostream>
using namespace std;

#define MAX 100

class QueueArray {
private:
    int arr[MAX];
    int front, rear, size;

public:
    QueueArray() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int data) {
        if (size == MAX) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = data;
        size++;
        cout << data << " enqueued to queue\n";
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " dequeued from queue\n";
        front = (front + 1) % MAX;
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    QueueArray queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.dequeue();
    queue.display();
    return 0;
}
