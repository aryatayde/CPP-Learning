#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if(top == SIZE - 1) {
            cout << "Stack Overflow\n";
        }
        else {
            top++;
            arr[top] = x;
            cout << x << " inserted\n";
        }
    }

    void pop() {
        if(top == -1) {
            cout << "Stack Underflow\n";
        }
        else {
            cout << arr[top] << " removed\n";
            top--;
        }
    }

    void peek() {
        if(top == -1) {
            cout << "Stack is Empty\n";
        }
        else {
            cout << "Top element: " << arr[top] << endl;
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