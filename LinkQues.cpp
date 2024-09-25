#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node*& head, int newData) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;
    // Make next of new node as head
    newNode->next = head;
    // Move the head to point to the new node
    head = newNode;
}

// Function to print all elements of the list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Initialize head pointer
    Node* head = nullptr;

    // Insert nodes at the beginning
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 9);
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);

    // Print all elements of the list
    cout << "Linked list elements: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
