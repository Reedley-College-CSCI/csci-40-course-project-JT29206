#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Automotive {
	string make;
	string model;
	int year;
	double price;
	bool available;

};
void displayMenu();
void displayInventory(Automotive* inventory, int size);
void addCar(Automotive*& inventory, int& size, int& capacity);
void removeCar(Automotive* inventory, int& size);
void searchCar(Automotive* inventory, int size);
void resizeArr(Automotive*& inventory, int& capacity);
void sortByPrice(Automotive* inventory, int size);
void saveToFile(Automotive* inventory, int size);
void loadFromFile(Automotive*& inventory, int& size, int& capacity);

int main() {
	int choice;
	int capacity = 5;
	int size = 0;
	Automotive* inventory = new Automotive[capacity];
	loadFromFile(inventory, size, capacity);

	do {
		displayMenu();
		
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input! Please enter a number" << endl;
			continue;
		}

		switch (choice) {
		case 1:
			cout << "\n------View Inventory Selected------" << endl;
			displayInventory(inventory, size);
			break;

		case 2:
			cout << "\n------Add Car Selected------" << endl;
			addCar(inventory, size, capacity);
			break;

		case 3:
			cout << "------Remove Car Selected------" << endl;
			removeCar(inventory, size);
			break;

		case 4:
			cout << "\n------Search Car Selected------" << endl;
			searchCar(inventory, size);
			break;
		
		case 5: 
			cout << "\n------Sort by Price Selected------" << endl;
			sortByPrice(inventory, size);
			displayInventory(inventory, size);
			break;

		case 6:
			saveToFile(inventory, size);
			cout << "Saving to file and exiting" << endl;
			break;

		default:
			cout << "Invalid Choice" << endl;
		}
	}
	while (choice != 6);

	delete[] inventory;
	return 0;
}
void displayMenu() {
	cout << "------Car Dealership Management System------" << endl;
	cout << "1. View Inventory" << endl;
	cout << "2. Add Car" << endl;
	cout << "3. Remove Car" << endl;
	cout << "4. Search Car" << endl;
	cout << "5. Sort by Price" << endl;
	cout << "6. Exit" << endl;
	cout << "Please select what you like to do (1-6):" << endl;

}

void displayInventory(Automotive* inventory, int size) {
	if (size == 0) {
		cout << "No cars in inventory" << endl;
		return;
	}
	cout << fixed << setprecision(2);

	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": " 
			<< inventory[i].make << " "
			<< inventory[i].model << " | Year: "
			<< inventory[i].year << " | Price: $"
			<< inventory[i].price << " | "
			<< (inventory[i].available ? "Available" : "Sold")
			<< endl;
	}
	cout << endl;
}

void addCar(Automotive*& inventory, int& size, int& capacity) {
	if (size == capacity) {
		resizeArr(inventory, capacity);
	}

	cout << "Enter make: " ;
	cin >> inventory[size].make;

	cout << "Enter model: ";
	cin >> inventory[size].model;

	cout << "Enter year: ";
	cin >> inventory[size].year;

	cout << "Enter price: ";
	cin >> inventory[size].price;

	cout << "Is it available? (1 = Yes, 0 = No): ";
	cin >> inventory[size].available;
	
	size++;

	cout << "Car added successfully" << endl << endl;
}

void removeCar(Automotive* inventory, int& size) {
	int num;

	if (size == 0) {
		cout << "No cars in inventory" << endl;
		return;
	}

	cout << "Enter which car you would like to remove (1-" 
		<< size << " ): " << endl;
	cin >> num;
	num--;

	if (num < 0 || num >= size) {
		cout << "Invalid number" << endl;
		return;
	}

	for (int i = num; i < size -1; i++) {
		inventory[i] = inventory[i + 1];
	}

	size--;

	cout << "Car removed successfully" << endl << endl;
}

void searchCar(Automotive* inventory, int size) {
	string make;
	cout << "Enter the make of the car you would like to search: " << endl;
	cin >> make;

	bool found = false;

	for (int i = 0; i < size; i++) {
		if (inventory[i].make == make) {
			cout << inventory[i].make << " "
				<< inventory[i].model << " | Year: "
				<< inventory[i].year << " | Price: $ "
				<< inventory[i].price << " | "
				<< (inventory[i].available ? "Available" : "Sold")
				<< endl << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No cars found." << endl << endl;
	}
}

void sortByPrice(Automotive* inventory, int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (inventory[j].price < inventory[minIndex].price) {
				minIndex = j;
			}
		}
		Automotive temp = inventory[i];
		inventory[i] = inventory[minIndex];
		inventory[minIndex] = temp;
	}
	cout << "Inventory sorted by price" << endl;
}

void resizeArr(Automotive*& inventory, int& capacity) {
	int newCapacity = capacity * 2;
	Automotive* newArr = new Automotive[newCapacity];

	for (int i = 0; i < capacity; i++) {
		newArr[i] = inventory[i];
	}

	delete[] inventory;
	inventory = newArr;
	capacity = newCapacity;
}

void saveToFile(Automotive* inventory, int size) {
	ofstream file("inventory.txt");

	for (int i = 0; i < size; i++) {
		file << inventory[i].make << " "
		<< inventory[i].model << " "
		<< inventory[i].year << " "
		<< inventory[i].price << " "
		<< inventory[i].available << endl;
	}
	file.close();
}

void loadFromFile(Automotive*& inventory, int& size, int& capacity) {
	ifstream file("inventory.txt");

	if (!file) {
		cout << "No saved inventory found" << endl;
		return;
	}

	while (file >> inventory[size].make 
		>> inventory[size].model
		>> inventory[size].year 
		>> inventory[size].price 
		>> inventory[size].available) {
		
		size++;

		if (size >= capacity) { // If array is too full, then resizes array
			resizeArr(inventory, capacity);
		}
	}
	file.close();

	cout << "Inventory loaded successfully" << endl;
}

