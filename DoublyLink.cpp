#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a new node at the beginning
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = nullptr;
    
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert a new node after a given node
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be nullptr\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {  // If the list is empty
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


// Function to delete the node at the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Function to delete the node after a given node
void deleteAfter(Node* prevNode) {
    if (prevNode == nullptr || prevNode->next == nullptr) {
        cout << "No node exists after the given node\n";
        return;
    }
    Node* temp = prevNode->next;
    prevNode->next = temp->next;

    if (temp->next != nullptr) {
        temp->next->prev = prevNode;
    }
    delete temp;
}

// Function to delete a node at the end of the doubly linked list
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {  // If the list is empty
        cout << "List is empty. No elements to delete." << endl;
        return;
    }

    if (head->next == nullptr) {  // If the list has only one node
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

// Function to print the doubly linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Custom input for inserting at the beginning
    cout << "Enter 5 elements to insert at the beginning:\n";
    int values[5];
    for(int i = 0; i < 5; ++i) {
        cin >> values[i];
    }

    for(int i = 0; i < 5; ++i) {
        insertAtBeginning(head, values[i]);
    }

    cout << "Doubly linked list after inserting at the beginning:\n";
    printList(head);

    // Insertion after a given node
    cout << "Enter the value to insert after the first node: ";
    int afterValue;
    cin >> afterValue;
    insertAfter(head, afterValue);

    cout << "Doubly linked list after inserting after the first node:\n";
    printList(head);

    // Deletion at the beginning
    deleteAtBeginning(head);
    cout << "Doubly linked list after deleting the first node:\n";
    printList(head);

    // Deletion after a given node
    deleteAfter(head);
    cout << "Doubly linked list after deleting the node after the first node:\n";
    printList(head);

    return 0;
}
