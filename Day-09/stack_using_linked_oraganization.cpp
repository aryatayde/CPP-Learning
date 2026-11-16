#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);

        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow\n";
        }
        else {
            Node* temp = top;
            cout << temp->data << " removed\n";

            top = top->next;
            delete temp;
        }
    }

    void peek() {
        if(top == NULL) {
            cout << "Stack is Empty\n";
        }
        else {
            cout << "Top: " << top->data << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();
    s.pop();
    s.peek();

    return 0;
}