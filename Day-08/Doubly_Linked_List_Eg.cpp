
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class DoctorList {

    struct Node {
        string name;
        string specialization;
        string phone;
        Node* prev;
        Node* next;

        Node(string n, string s, string p) {
            name = n;
            specialization = s;
            phone = p;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

public:

    // Constructor
    DoctorList() {
        head = NULL;
        tail = NULL;
    }

    // A) Append a doctor
    void appendDoctor() {

        string name, specialization, phone;

        cout << "\nEnter doctor name: ";
        getline(cin, name);

        cout << "Enter specialization: ";
        getline(cin, specialization);

        cout << "Enter phone number: ";
        getline(cin, phone);

        Node* newNode = new Node(name, specialization, phone);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Doctor added successfully!\n";
    }

    // B) Display doctors of given specialization
    void displaySpecialization() {

        string searchSpecialization;
        bool found = false;

        cout << "\nEnter specialization: ";
        getline(cin, searchSpecialization);

        Node* temp = head;

        while(temp != NULL) {

            if(temp->specialization == searchSpecialization) {

                cout << "\nDoctor Name: " << temp->name;
                cout << "\nPhone Number: " << temp->phone;
                cout << "\n----------------------";

                found = true;
            }

            temp = temp->next;
        }

        if(found == false) {
            cout << "\nNo doctors found for this specialization.";
        }
    }

    // C) Reverse the doubly linked list
    void reverseList() {

        if(head == NULL) {
            cout << "\nList is empty!";
            return;
        }

        Node* temp = head;

        while(temp != NULL) {

            Node* nextNode = temp->next;

            temp->next = temp->prev;
            temp->prev = nextNode;

            temp = nextNode;
        }

        Node* swapNode = head;
        head = tail;
        tail = swapNode;

        cout << "\nList reversed successfully!";
    }

    // Display all doctors
    void displayAll() {

        Node* temp = head;

        if(head == NULL) {
            cout << "\nList is empty!";
            return;
        }

        while(temp != NULL) {

            cout << "\nDoctor Name: " << temp->name;
            cout << "\nSpecialization: " << temp->specialization;
            cout << "\nPhone Number: " << temp->phone;
            cout << "\n----------------------";

            temp = temp->next;
        }
    }
};

int main() {

    DoctorList ll;
    int choice;

    do {

        cout << "\n\n===== DOCTOR MANAGEMENT SYSTEM =====";
        cout << "\n1. Append a doctor";
        cout << "\n2. List doctors by specialization";
        cout << "\n3. Reverse the list";
        cout << "\n4. Display all doctors";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {

            case 1:
                ll.appendDoctor();
                break;

            case 2:
                ll.displaySpecialization();
                break;

            case 3:
                ll.reverseList();
                break;

            case 4:
                ll.displayAll();
                break;

            case 5:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while(choice != 5);

    return 0;
}
