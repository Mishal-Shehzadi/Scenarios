#include <iostream>
using namespace std;
int main()
{
    string name[100];
    int age[100];
    int passenger = 0;
    float childfare = 0;
    float adultfare = 0;
    int childcount = 0;
    int adultcount = 0;

    bool choice = 0;

    float beforefare[100];

    do
    {
        cout << "Enter your name: ";
        cin >> name[passenger];

        cout << "Enter age: ";
        cin >> age[passenger];

        if (age[passenger] < 18)
        {
            childfare += 2500;
            childcount++;
            beforefare[passenger] += 2500;
        }
        else
        {
            adultfare += 700;
            adultcount++;
            beforefare[passenger] += 7000;
        }
        passenger++;
        cout << "Do u want to enter any other person? 1 or 0?";
        cin >> choice;

    } while (choice == 1);

    float child_d = 0;
    float adult_d = 0;

    if (childcount >= 2)
    {
        child_d = 0.4;
    }
    if (adultcount >= 3)
    {
        adult_d = 0.5;
    }
    int afterfare[100];
    int totalafterdiscount = 0;
    float totalbefor  ediscount = childfare + adultfare;
    for (int i = 0; i < passenger; i++)
    {
        if (age[i] < 18)
        {
            afterfare[i] = beforefare[i] - (beforefare[i] * child_d);
        }
        else
        {
            afterfare[i] = beforefare[i] - (beforefare[i] * adult_d);
        }
        totalafterdiscount += afterfare[i];
    }
    cout << "\n--- BOOKING REPORT ---\n";
    cout << "Name\tAge\tFare Before Discount\tFare After Discount\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < passenger; i++)
    {
        cout << name[i] << "\t" << age[i] << "\t" << beforefare[i]
             << "\t\t\t" << afterfare[i] << endl;
    }
    cout << "-------------------------------------------------------------\n";
    cout << "Total Amount Before Discount: Rs. " << totalbeforediscount << endl;
    cout << "-------------------------------------------------------------\n";
    cout << "After Discount Total Amount to be Paid: Rs. " << totalafterdiscount << endl;
    cout << "-------------------------------------------------------------\n";
    cout << "Thank you for booking with Promises Delivered!" << endl;

    return 0;
}