#include <iostream>
#include <string>
using namespace std;

struct node {
    int id;
    int age;
    string priority;
    node* next;
};

node* top = NULL;
int mycount = 0;

void push(int id, int age, string priority) {
    node* newnode = new node;

    newnode->id = id;
    newnode->age = age;
    newnode->priority = priority;

    newnode->next = top;
    top = newnode;

    mycount++;
}

void display() {
    if (top == NULL) {
        cout << "Empty stack" << endl;
        return;
    }

    node* temp = top;

    while (temp != NULL) {
        cout << temp->id << " - "
            << temp->age << " - "
            << temp->priority << endl;

        temp = temp->next;
    }
}

void countPatients() {
    cout << "Total patients: " << mycount << endl;
}

void search() {
    int searchID = 210;
    int count = 0;

    node* temp = top;

    while (temp != NULL) {
        if (temp->id == searchID) {
            count++;
        }

        temp = temp->next;
    }

    if (count > 0) {
        cout << "Patient ID " << searchID
            << " found " << count << " times." << endl;
    }
    else {
        cout << "Patient not found." << endl;
    }
}

void bubblesort() {
    if (top == NULL) {
        cout << "Empty stack" << endl;
        return;
    }

    for (node* i = top; i->next != NULL; i = i->next) {
        int flag = 0;

        for (node* j = top; j->next != NULL; j = j->next) {
            if (j->id > j->next->id) {
                int tempID = j->id;
                j->id = j->next->id;
                j->next->id = tempID;

                int tempAge = j->age;
                j->age = j->next->age;
                j->next->age = tempAge;

                string tempPriority = j->priority;
                j->priority = j->next->priority;
                j->next->priority = tempPriority;

                flag = 1;
            }
        }

        if (flag == 0) {
            break;
        }
    }
}

void descending() {
    if (top == NULL) {
        cout << "Empty stack" << endl;
        return;
    }

    for (node* i = top; i->next != NULL; i = i->next) {
        int flag = 0;

        for (node* j = top; j->next != NULL; j = j->next) {
            if (j->id < j->next->id) {
                int tempID = j->id;
                j->id = j->next->id;
                j->next->id = tempID;

                int tempAge = j->age;
                j->age = j->next->age;
                j->next->age = tempAge;

                string tempPriority = j->priority;
                j->priority = j->next->priority;
                j->next->priority = tempPriority;

                flag = 1;
            }
        }

        if (flag == 0) {
            break;
        }
    }
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    node* temp = top;

    cout << "Removed patient: " << temp->id << endl;

    top = top->next;
    delete temp;

    mycount--;
}

int main() {
    push(305, 45, "High");
    push(210, 32, "Medium");
    push(405, 60, "High");
    push(210, 25, "Low");
    push(150, 19, "Medium");
    push(320, 50, "Low");
    push(275, 28, "Medium");

    cout << "Original Stack (Top to Bottom):" << endl;
    display();
    countPatients();

    cout << "\nSearching for patient ID 210:" << endl;
    search();

    bubblesort();
    cout << "\nAscending Order:" << endl;
    display();

    descending();
    cout << "\nDescending Order:" << endl;
    display();

    cout << "\nRemoving top two patients:" << endl;
    pop();
    pop();

    cout << "\nUpdated Stack:" << endl;
    display();
    countPatients();

    return 0;
}