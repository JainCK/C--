#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Queue class containing enqueue, dequeue, and display functions
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front= nullptr;
        rear=nullptr; 
    } 

    // Enqueue operation: Adds a new element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {  // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue operation: Removes the front element from the queue
    void dequeue() {
        if (front == nullptr) {  // If the queue is empty
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {  // If the queue becomes empty after dequeue
            rear = nullptr;
        }

        delete temp;
    }

    // Display operation: Prints all elements of the queue
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    // Hardcoding enqueue operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the queue
    cout << "Queue after enqueuing elements:\n";
    queue.display();

    // Hardcoding dequeue operation
    queue.dequeue();

    // Display the queue after dequeue
    cout << "Queue after dequeuing one element:\n";
    queue.display();

    return 0;
}
