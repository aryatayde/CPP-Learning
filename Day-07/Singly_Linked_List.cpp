
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 1. Create a linked list
void create(Node* &head, int n) {

    for(int i = 0; i < n; i++) {

        Node* newNode = new Node;

        cout << "Enter data: ";
        cin >> newNode->data;

        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

// 2. Display the linked list
void display(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// 3. Search an element
void search(Node* head, int key) {

    Node* temp = head;
    int position = 1;

    while(temp != NULL) {

        if(temp->data == key) {
            cout << "Element found at position " << position;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Element not found";
}

// 4. Insert an element at a given position
void insert(Node* &head, int value, int pos) {

    Node* newNode = new Node;
    newNode->data = value;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "Invalid position";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// 5. Delete an element by value
void deleteNode(Node* &head, int key) {

    if(head == NULL) {
        cout << "List is empty";
        return;
    }

    if(head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted";
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        cout << "Element not found";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted";
}

int main() {

    Node* head = NULL;
    int choice, n, value, pos;

    do {

        cout << "\n\n1. Create";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Insert";
        cout << "\n5. Delete";
        cout << "\n6. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "How many nodes? ";
                cin >> n;
                create(head, n);
                break;

            case 2:
                display(head);
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> value;
                search(head, value);
                break;

            case 4:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insert(head, value, pos);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 6);

    return 0;
}
