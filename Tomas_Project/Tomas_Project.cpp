#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Automotive {
	string make;
	string model;
	int year;

};
void displayMenu();
void displayInventory(Automotive* inventory, int size);
void addCar(Automotive*& inventory, int& size, int& capacity);
void removeCar(Automotive inventory, int size);
void searchCar(Automotive* inventory, int size);
void resizeArr(Automotive* inventory, int capacity);


int main() {
	int choice;
	int capacity = 5;
	int size = 0;
	Automotive* inventory = new Automotive[capacity];

	do {
		displayMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nView Inventory Selected" << endl;
			displayInventory(inventory, size);
			break;

		case 2:
			cout << "\nAdd Car Selected" << endl;
			addCar(inventory, size, capacity);
			break;

		case 3:
			cout << "Remove Car Selected" << endl;
			break;

		case 4:
			cout << "\nSearch Car Selected" << endl;
			searchCar(inventory, size);
			break;

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

void displayInventory(Automotive* inventory, int size) {
	if (size == 0) {
		cout << "No cars in inventory" << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": " << (inventory + i)->make << " "
			<< (inventory + i)->model << " "
			<< (inventory + i)->year 
			<< endl;
	}
}

void addCar(Automotive*& inventory, int& size, int& capacity) {
	if (size == capacity) {
		resizeArr(inventory, capacity);
	}

	cout << "Enter make: " ;
	cin >> (inventory + size)->make;

	cout << "Enter model: ";
	cin >> (inventory + size)->model;

	cout << "Enter year: ";
	cin >> (inventory + size)->year;
	cout << endl;
	size++;
}

void removeCar(Automotive inventory, int size) {
	int num;

	cout << "Enter which car you would like to remove: " << endl;
	cin >> num;

	if (num < 0 || num >= size) {
		cout << "Invalid number" << endl;
	}

	for (int i = num; i < size; i++) {
		*(inventory + i) = *(inventory + i + 1);
	}

	size--;
}

void searchCar(Automotive* inventory, int size) {
	string make;
	cout << "Enter the make of the car you would like to search: " << endl;
	cin >> make;

	bool found = false;

	for (int i = 0; i < size; i++) {
		if ((inventory + i)->make == make) {
			cout << (inventory + i)->model << " " << (inventory + i)
				->year << endl << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No cars found." << endl << endl;
	}
}

void resizeArr(Automotive* inventory, int capacity) {
	int newCapacity = capacity * 2;
	Automotive* newArr = new Automotive[newCapacity];

	for (int i = 0; i < capacity; i++) {
		*(newArr + i) = *(inventory + i);
	}

	delete[] inventory;
	inventory = newArr;
	capacity = newCapacity;
}

