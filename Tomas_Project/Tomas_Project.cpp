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
	cout << "Enter the make of your car: " << endl;
	cin >> make;
	cout << "Enter the model of your car: " << endl;
	cin >> model;
	cout << "Enter the year of your car: " << endl;
	cin >> year;
	cout << "You have inputted a " << make << " " << model << " " << year << endl;

	return 0;
}

