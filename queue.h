#include <iostream>
using namespace std;

// Structure of Node for the queue
struct Node {
    string cname;
    Node* link;
};

Node* front = NULL;
Node* rear = NULL;

// Function to check if the queue is empty
bool isempty() {
    return (front == NULL && rear == NULL);
}

// Function to add a customer to the queue
void enqueue(string name) {
    Node* ptr = new Node();
    ptr->cname = name;
    ptr->link = NULL;

    if (front == NULL) {
        front = ptr;
        rear = ptr;
    } else {
        rear->link = ptr;
        rear = ptr;
    }
}

// Function to remove a customer from the queue
void dequeue() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else if (front == rear) {
        delete front;
        front = rear = NULL;
    } else {
        Node* ptr = front;
        front = front->link;
        delete ptr;
    }
}

// Function to show the front customer in the queue
void showfront() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Element at front is: " << front->cname << "\n";
    }
}

// Function to display all customers in the queue
void displayQueue() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        Node* ptr = front;
        cout << "\nCustomer Queue:\n";
        while (ptr != NULL) {
            cout << "\t" << ptr->cname << endl;
            ptr = ptr->link;
        }
    }
}
