#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Stack class containing push, pop, and display functions
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
        }

    // Push operation: Adds a new element to the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop operation: Removes the top element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Display operation: Prints all elements of the stack
    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // Hardcoding push operations
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the stack
    cout << "Stack after pushing elements:\n";
    stack.display();

    // Hardcoding pop operation
    stack.pop();

    // Display the stack after pop
    cout << "Stack after popping one element:\n";
    stack.display();

    return 0;
}
