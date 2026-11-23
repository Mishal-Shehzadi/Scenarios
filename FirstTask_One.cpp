#include <iostream>
using namespace std;
int main() {

	int truckId[12] = { 1005, 1023, 1030, 1044, 1056, 1067, 1078, 1001, 1129, 1115, 1180 };
	int size = 11;

	cout << "Size of array before anything: " << size;
	cout << "\n-----------------------------------------";

	//a. Insert a new truck ID 1011 at position 5 

	int new_id = 1011;
	int pos = 5;

	for (int i = size - 1; i >= pos - 1; i--) {
		truckId[i + 1] = truckId[i];
	}
	truckId[pos - 1] = new_id;
	size++;

	//b. Traverse the array.
	cout << "\nArray After inserton: ";
	for (int i = 0; i < size; i++) {
		cout << truckId[i] << " ";

	}
	cout << "\nThe size of array after insertion is: " << size;
	cout << "\n-----------------------------------------";

	//c. Delete a truck ID located at position 9
	int pos_to_delete = 9;
	for (int i = pos_to_delete-1 ; i < size - 1; i++) {
		truckId[i] = truckId[i + 1];
	}
	size--;

	//Traverse the array.
	cout << "\nArray After deletion: ";
	for (int i = 0; i < size; i++) {
		cout << truckId[i] << " ";

	}
	cout << "\nThe size of array after deletion is: " << size;
	cout << "\n-----------------------------------------";
	return 0;
}