#include<iostream>
#include<string>
#include<limits>
using namespace std;

class Node {
public:
    string name;
    string location;
    int employees;
    Node* next;

    Node(string n, string l, int e) {
        name = n;
        location = l;
        employees = e;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

    // Function to input company details
    Node* createNode() {
        string name, location;
        int employees;

        cout << "Enter Company Name: ";
        getline(cin, name);

        cout << "Enter Company Location: ";
        getline(cin, location);

        cout << "Enter Number of Employees: ";
        cin >> employees;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return new Node(name, location, employees);
    }

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    // Clear the existing list
    void clearList() {
        Node* temp = head;

        while(temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        head = tail = NULL;
    }

    // A) Create a list of N companies
    void createList(int n) {
        clearList();

        for(int i = 0; i < n; i++) {
            cout << "\nEnter details of Company " << i + 1 << ":\n";
            Node* newNode = createNode();

            if(head == NULL) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        cout << "\nCompany list created successfully!\n";
    }

    // B) Append a company at the end
    void appendCompany() {
        Node* newNode = createNode();

        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "\nCompany added at the end!\n";
    }

    // C) Add a company at the beginning
    void addBeginning() {
        Node* newNode = createNode();

        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }

        cout << "\nCompany added at the beginning!\n";
    }

    // D) Find number of employees
    void findEmployees(string companyName) {
        Node* temp = head;

        while(temp != NULL) {
            if(temp->name == companyName) {
                cout << "Number of Employees: "
                     << temp->employees << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Company not found!\n";
    }

    // E) Find company location
    void findLocation(string companyName) {
        Node* temp = head;

        while(temp != NULL) {
            if(temp->name == companyName) {
                cout << "Company Location: "
                     << temp->location << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Company not found!\n";
    }

    // Display all companies
    void display() {
        Node* temp = head;

        if(head == NULL) {
            cout << "\nList is empty!\n";
            return;
        }

        cout << "\n--- Company Details ---\n";

        while(temp != NULL) {
            cout << "\nCompany Name: " << temp->name;
            cout << "\nLocation: " << temp->location;
            cout << "\nEmployees: " << temp->employees;
            cout << "\n----------------------\n";

            temp = temp->next;
        }
    }

    ~List() {
        clearList();
    }
};

int main() {
    List ll;
    int choice, n;
    string companyName;

    do {
        cout << "\n===== COMPANY MANAGEMENT SYSTEM =====\n";
        cout << "1. Create List of N Companies\n";
        cout << "2. Append a Company\n";
        cout << "3. Add Company at Beginning\n";
        cout << "4. Find Number of Employees\n";
        cout << "5. Find Company Location\n";
        cout << "6. Display All Companies\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {

            case 1:
                cout << "Enter number of companies: ";
                cin >> n;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ll.createList(n);
                break;

            case 2:
                ll.appendCompany();
                break;

            case 3:
                ll.addBeginning();
                break;

            case 4:
                cout << "Enter company name: ";
                getline(cin, companyName);
                ll.findEmployees(companyName);
                break;

            case 5:
                cout << "Enter company name: ";
                getline(cin, companyName);
                ll.findLocation(companyName);
                break;

            case 6:
                ll.display();
                break;

            case 0:
                cout << "Program terminated!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 0);

    return 0;
}
