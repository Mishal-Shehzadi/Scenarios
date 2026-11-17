//C++ Midterm Practice : Queue Using a Linked List
//Scenario : Hospital Patient Management System
//15 Marks
//
//A hospital maintains a waiting queue of patients.Since the number of patients changes throughout the day,
// the hospital uses a dynamic, node - based FIFO structure instead of a fixed - size array.
//Each node stores the patient's ID, age, priority, and a pointer to the next node.
//The patients arrive in this order :
//    Patient ID	Age	Priority
//    305	45	High
//    210	32	Medium
//    405	60	High
//    210	25	Low
//    150	19	Medium
//    320	50	Low
//    275	28	Medium
//
//    Tasks
//    Write a complete C++ program to :
//1. Define a struct Node containing id, age, priority, and next.
//2. Implement a queue using a linked list with front and rear pointers.
//3. Insert all seven patient records into the queue.
//4. Display all patient records in their original arrival order.
//5. Count and display the total number of patients.
//6. Search for patient ID 210 and count its occurrences.
//7. Sort the patient records by ID in ascending order using Bubble Sort.
//8. Display all records after ascending sorting.
//9. Sort the patient records by ID in descending order.
//10. Display all records after descending sorting.
//11. Remove the first two patients using the queue's dequeue operation.
//12. Display the updated queue and count the remaining patients.
//Conditions
//- Use struct and dynamic memory allocation with new.
//- Do not use an array to store the queue records.
//- Use front and rear to manage the queue.
//- Do not use built - in sorting functions.
//- During sorting, swap the complete patient data so that age and priority remain associated with the correct ID.
//- Maintain FIFO behavior when inserting and removing patients.
//- Handle the queue becoming empty correctly.


#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    int age;
    string priority;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int id, int age, string priority) {
    Node* newNode = new Node;

    newNode->id = id;
    newNode->age = age;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void display() {
    Node* temp = front;

    while (temp != NULL) {
        cout << "ID: " << temp->id
            << " Age: " << temp->age
            << " Priority: " << temp->priority << endl;

        temp = temp->next;
    }
}

void countPatients() {
    int count = 0;
    Node* temp = front;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total patients: " << count << endl;
}

void searchPatient(int searchID) {
    int count = 0;
    Node* temp = front;

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

void sortAscending() {
    if (front == NULL) {
        return;
    }

    for (Node* i = front; i->next != NULL; i = i->next) {
        for (Node* j = front; j->next != NULL; j = j->next) {
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
            }
        }
    }
}

void sortDescending() {
    if (front == NULL) {
        return;
    }

    for (Node* i = front; i->next != NULL; i = i->next) {
        for (Node* j = front; j->next != NULL; j = j->next) {
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
            }
        }
    }
}

void sortInsertion() {
    if (front == NULL) {
        return;
    }

    for (Node* i = front->next; i != NULL; i = i->next) {
        int keyID = i->id;
        int keyAge = i->age;
        string keyPriority = i->priority;

        Node* j = front;

        while (j != i) {
            if (j->id > keyID) {
                int tempID = j->id;
                j->id = keyID;
                keyID = tempID;

                int tempAge = j->age;
                j->age = keyAge;
                keyAge = tempAge;

                string tempPriority = j->priority;
                j->priority = keyPriority;
                keyPriority = tempPriority;
            }

            j = j->next;
        }

        i->id = keyID;
        i->age = keyAge;
        i->priority = keyPriority;
    }
}

void sortSelection() {
    if (front == NULL) {
        return;
    }

    for (Node* i = front; i->next != NULL; i = i->next) {
        Node* minNode = i;

        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->id < minNode->id) {
                minNode = j;
            }
        }

        if (minNode != i) {
            int tempID = i->id;
            i->id = minNode->id;
            minNode->id = tempID;

            int tempAge = i->age;
            i->age = minNode->age;
            minNode->age = tempAge;

            string tempPriority = i->priority;
            i->priority = minNode->priority;
            minNode->priority = tempPriority;
        }
    }
}



void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;
    cout << "Removed patient ID: " << temp->id << endl;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

int main() {
    enqueue(305, 45, "High");
    enqueue(210, 32, "Medium");
    enqueue(405, 60, "High");
    enqueue(210, 25, "Low");
    enqueue(150, 19, "Medium");
    enqueue(320, 50, "Low");
    enqueue(275, 28, "Medium");

    cout << "Original Queue:\n";
    display();
    countPatients();

    cout << "\nSearching for patient ID 210:\n";
    searchPatient(210);

    sortAscending();
    cout << "\nAscending Order:\n";
    display();

    sortDescending();
    cout << "\nDescending Order:\n";
    display();

    cout << "\nRemoving first two patients:\n";
    dequeue();
    dequeue();

    cout << "\nUpdated Queue:\n";
    display();
    countPatients();

    return 0;
}