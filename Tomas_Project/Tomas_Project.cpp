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


int main() {
	string make;
	string model;
	int year;
	int choice;
	displayMenu();
	cin >> choice;
	cout << "Enter the make of your car: " << endl;
	cin >> make;
	cout << "Enter the model of your car: " << endl;
	cin >> model;
	cout << "Enter the year of your car: " << endl;
	cin >> year;
	cout << "You have inputted a " << make << " " << model << " " << year << endl;

	return 0;
}
void displayMenu() {
	cout << "Please select what you like to do: " << endl;
	cout << "1. View Inventory" << endl;
	cout << "2. Add Car" << endl;
	cout << "3. Remove Car" << endl;
	cout << "3. Search Car" << endl;

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

