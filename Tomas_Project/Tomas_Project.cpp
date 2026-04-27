#include <iostream>
#include <string>

using namespace std;

struct Automotive {
	string make;
	string model;
	int year;

};
void displayMenu();
void addCar(Automotive inventory, int size);
void removeCar(Automotive inventory, int size);
void searchCar(Automotive inventory, int size);


int main() {
	string make;
	string model;
	int year;
	displayMenu();
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
	cout << "1. Add Car" << endl;
	cout << "2. Remove Car" << endl;
	cout << "3. Search Car" << endl;

}

void searchCar(Automotive inventory, int size) {
	string make;
	cout << "Enter car make you would like to search: " << endl;
	cin >> make;

	bool found = false;

	for (int i = 0; i < size; i++) {

	}
}

