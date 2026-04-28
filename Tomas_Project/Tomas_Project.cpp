#include <iostream>
#include <string>

using namespace std;

struct Automotive {
	string make;
	string model;
	int year;

};
void displayMenu();
void displayInventory(Automotive inventory, int size);
void addCar(Automotive inventory, int size);
void removeCar(Automotive inventory, int size);
void searchCar(Automotive inventory, int size);
void resizeArr(Automotive* inventory, int capacity);


int main() {
	int choice;
	
	do {
		displayMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "View Inventory Selected" << endl;
			break;

		case 2:
			cout << "Add Car Selected" << endl;
			break;

		case 3:
			cout << "Remove Car Selected" << endl;
			break;

		case 4:
			cout << "Search Car Selected" << endl;

		case 5:
			cout << "Exit" << endl;
			break;

		default:
			cout << "Invalid Choice" << endl;
		}
	}
	while (choice != 5);


	return 0;
}
void displayMenu() {
	cout << "Please select what you like to do: " << endl;
	cout << "1. View Inventory" << endl;
	cout << "2. Add Car" << endl;
	cout << "3. Remove Car" << endl;
	cout << "4. Search Car" << endl;
	cout << "5. Exit" << endl;

}

void searchCar(Automotive inventory, int size) {
	string make;
	cout << "Enter the make of the car you would like to search: " << endl;
	cin >> make;

	bool found = false;

	for (int i = 0; i < size; i++) {
		if ((inventory + i)->make == make) {
			cout << (inventory + i)->model << " " << (inventory + i)
				->year << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No cars found." << endl;
	}
}

