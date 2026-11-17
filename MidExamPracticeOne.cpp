//Question 1: Hospital Patient Management System
//Topics : struct + Queue + Array + Sorting + Searching
//15 Marks
//
//A hospital maintains a waiting queue of patients.Each patient record contains a patient ID, age, and priority level.
// Patients arrive in the following order :
//Patient ID	Age	Priority
//305	45	High
//210	32	Medium
//405	60	High
//210	25	Low
//150	19	Medium
//320	50	Low
//405	38	High
//275	28	Medium
//Write a C++ program to :
//1. Define a struct Patient containing id, age, and priority.
//2. Implement a queue using an array of Patient structures.
//3. Insert all eight patient records into the queue.
//4. Display all patient records in their original arrival order.
//5. Count and display the total number of patients.
//6. Search for patient ID 210 and count its occurrences.
//7. Copy the patient records into a separate array.
//8. Sort the copied records by patient ID in ascending order using Bubble Sort.
//9. Display the sorted patient records.
//10. Sort the records by patient ID in descending order and display them.
//11. Remove the first two patients from the original queue.
//12. Display the updated queue and the remaining patient count.
//Conditions: Use front and rear for the queue.Compare patient IDs during sorting, but preserve the other fields when swapping complete structures.
// Do not use built - in sorting functions.
#include <iostream>
#include <string>
using namespace std;

#define n 8

struct Patient {
    int id;
    int age;
    string priority;
};

Patient queue[n];
Patient copied[n];

int front = 0;
int rear = -1;
int mycount = 0;

void insertPatients() {
    Patient p[n] = {
        {305, 45, "High"},
        {210, 32, "Medium"},
        {405, 60, "High"},
        {210, 25, "Low"},
        {150, 19, "Medium"},
        {320, 50, "Low"},
        {405, 38, "High"},
        {275, 28, "Medium"}
    };

    for (int i = 0; i < n; i++) {
        rear++;
        queue[rear] = p[i];
        mycount++;
    }
}

void displayoriginal() {
    cout << "\nOriginal Patient Records:\n";

    for (int i = front; i <= rear; i++) {
        cout << "ID: " << queue[i].id
            << " Age: " << queue[i].age
            << " Priority: " << queue[i].priority << endl;
    }

    cout << "Total Patients: " << mycount << endl;
}

void searchid() {
    int searchID = 210;
    int count = 0;

    for (int i = front; i <= rear; i++) {
        if (queue[i].id == searchID) {
            count++;
        }
    }

    if (count > 0) {
        cout << "\nPatient ID " << searchID
            << " found " << count << " times.\n";
    }
    else {
        cout << "\nPatient not found.\n";
    }
}

void bubblesortedcopiedarray() {
    for (int i = 0; i < mycount; i++) {
        copied[i] = queue[front + i];
    }

    for (int i = 0; i < mycount - 1; i++) {
        for (int j = 0; j < mycount - i - 1; j++) {
            if (copied[j].id > copied[j + 1].id) {
                Patient temp = copied[j];
                copied[j] = copied[j + 1];
                copied[j + 1] = temp;
            }
        }
    }
}

void displaysorted() {
    cout << "\nAscending Order:\n";

    for (int i = 0; i < mycount; i++) {
        cout << "ID: " << copied[i].id
            << " Age: " << copied[i].age
            << " Priority: " << copied[i].priority << endl;
    }
}

void sortindescendingorder() {
    for (int i = 0; i < mycount - 1; i++) {
        for (int j = 0; j < mycount - i - 1; j++) {
            if (copied[j].id < copied[j + 1].id) {
                Patient temp = copied[j];
                copied[j] = copied[j + 1];
                copied[j + 1] = temp;
            }
        }
    }
}

void displaydescending() {
    cout << "\nDescending Order:\n";

    for (int i = 0; i < mycount; i++) {
        cout << "ID: " << copied[i].id
            << " Age: " << copied[i].age
            << " Priority: " << copied[i].priority << endl;
    }
}

void removePatients() {
    cout << "\nRemoving first two patients...\n";

    for (int i = 0; i < 2; i++) {
        if (mycount > 0) {
            cout << "Removed Patient ID: "
                << queue[front].id << endl;

            front++;
            mycount--;
        }
    }
}

void displayupdated() {
    cout << "\nUpdated Queue:\n";

    for (int i = front; i <= rear; i++) {
        cout << "ID: " << queue[i].id
            << " Age: " << queue[i].age
            << " Priority: " << queue[i].priority << endl;
    }

    cout << "Remaining Patients: " << mycount << endl;
}

int main() {
    insertPatients();

    displayoriginal();

    searchid();

    bubblesortedcopiedarray();
    displaysorted();

    sortindescendingorder();
    displaydescending();

    removePatients();
    displayupdated();

    return 0;
}