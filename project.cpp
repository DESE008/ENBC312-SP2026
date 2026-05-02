#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Basic idea:
One main Car class, then Sedan/SUV/Truck inherit from it.
This avoids repeating code for each type.
*/

class Car {
protected:
    string name;
    string type;
    bool isAvailable;
    string rentStart;
    string rentEnd;

public:
    // constructor sets default state
    Car(string n, string t) {
        name = n;
        type = t;
        isAvailable = true;
    }

    // display in a clean format
    void display() {
        cout << "• " << name << " (" << type << ")\n";

        if (isAvailable)
            cout << "   Status: Available\n";
        else
            cout << "   Status: Rented [" << rentStart << " -> " << rentEnd << "]\n";

        cout << "----------------------------------\n";
    }

    // rent logic
    void rentCar(string start, string end) {
        if (isAvailable) {
            isAvailable = false;
            rentStart = start;
            rentEnd = end;
            cout << "\n✔ Rental confirmed for " << name << "\n";
        } else {
            cout << "\n⚠ Already rented\n";
        }
    }

    // return logic
    void returnCar() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "\n✔ " << name << " returned\n";
        } else {
            cout << "\n⚠ Not currently rented\n";
        }
    }

    string getName() { return name; }
    string getType() { return type; }
    bool getAvailability() { return isAvailable; }
};

// child classes just assign type
class Sedan : public Car {
public:
    Sedan(string n) : Car(n, "Sedan") {}
};

class SUV : public Car {
public:
    SUV(string n) : Car(n, "SUV") {}
};

class Truck : public Car {
public:
    Truck(string n) : Car(n, "Truck") {}
};

// storage
vector<Car*> inventory;
vector<string> history;

/*
Simple recommendation:
count which type was rented most
*/
string recommendCar() {
    int suv = 0, sedan = 0, truck = 0;

    for (int i = 0; i < history.size(); i++) {
        if (history[i] == "SUV") suv++;
        else if (history[i] == "Sedan") sedan++;
        else if (history[i] == "Truck") truck++;
    }

    if (suv >= sedan && suv >= truck) return "SUV";
    if (sedan >= suv && sedan >= truck) return "Sedan";
    return "Truck";
}

// add car
void registerCar(Car* c) {
    inventory.push_back(c);
}

// display all cars
void listCars() {
    cout << "\n========== CURRENT CARS ==========\n\n";

    for (int i = 0; i < inventory.size(); i++) {
        inventory[i]->display();
    }
}

// rent process
void rentCar() {
    string name, start, end;

    cout << "\n--- Rent a Car ---\n";
    listCars();

    cout << "\nEnter car name: ";
    cin >> name;

    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i]->getName() == name) {

            cout << "Start date: ";
            cin >> start;

            cout << "End date: ";
            cin >> end;

            bool wasAvailable = inventory[i]->getAvailability();

            inventory[i]->rentCar(start, end);

            if (wasAvailable)
                history.push_back(inventory[i]->getType());

            return;
        }
    }

    cout << "\n⚠ Car not found\n";
}

// return process
void returnCar() {
    string name;

    cout << "\n--- Return a Car ---\n";
    cout << "Enter car name: ";
    cin >> name;

    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i]->getName() == name) {
            inventory[i]->returnCar();
            return;
        }
    }

    cout << "\n⚠ Car not found\n";
}

/*
Compare function (needed for old compiler)
*/
bool compareCars(Car* a, Car* b) {
    return a->getName() < b->getName();
}

// sorting
void sortCars() {
    sort(inventory.begin(), inventory.end(), compareCars);
    cout << "\n✔ Cars sorted\n";
}

// pause so output doesn't disappear instantly
void pause() {
    cout << "\nPress enter to continue...";
    cin.ignore();
    cin.get();
}

int main() {

    // starting data
    registerCar(new Sedan("Camry"));
    registerCar(new SUV("CRV"));
    registerCar(new Truck("F150"));

    int choice;

    while (true) {

        cout << "\n==================================\n";
        cout << "        Car Rental System\n";
        cout << "==================================\n";

        cout << "Suggestion for you: " << recommendCar() << "\n";

        cout << "\n1. View cars\n";
        cout << "2. Rent a car\n";
        cout << "3. Return a car\n";
        cout << "4. Sort cars\n";
        cout << "5. Exit\n";

        cout << "\nChoice: ";
        cin >> choice;

        cin.ignore(); // prevents input bugs

        if (choice == 1) {
            listCars();
            pause();
        }
        else if (choice == 2) {
            rentCar();
            pause();
        }
        else if (choice == 3) {
            returnCar();
            pause();
        }
        else if (choice == 4) {
            sortCars();
            pause();
        }
        else if (choice == 5) {
            cout << "\nGoodbye!\n";
            break;
        }
        else {
            cout << "\nInvalid choice\n";
        }
    }

    return 0;
}
