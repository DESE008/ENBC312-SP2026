#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Simple car rental system
Uses basic C++98 compatible syntax
*/

class Car {
protected:
    string name;
    string type;
    bool available;
    string startDate;
    string endDate;

public:
    Car(string n, string t) {
        name = n;
        type = t;
        available = true;
    }

    void display() {
        cout << "• " << name << " (" << type << ")\n";

        if (available)
            cout << "   Status: Available\n";
        else
            cout << "   Status: Rented [" << startDate << " -> " << endDate << "]\n";

        cout << "----------------------------------\n";
    }

    void rent(string start, string end) {
        if (!available) {
            cout << "\n⚠ Already rented\n";
            return;
        }

        available = false;
        startDate = start;
        endDate = end;

        cout << "\n✔ Rental confirmed for " << name << "\n";
    }

    void giveBack() {
        if (available) {
            cout << "\n⚠ Not currently rented\n";
            return;
        }

        available = true;
        cout << "\n✔ " << name << " returned\n";
    }

    string getName() { return name; }
    string getType() { return type; }
    bool isAvailable() { return available; }
};

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

vector<Car*> cars;
vector<string> history;

/*
recommendation logic
*/
string recommend() {
    int suv = 0, sedan = 0, truck = 0;

    for (int i = 0; i < history.size(); i++) {
        if (history[i] == "SUV") suv++;
        else if (history[i] == "Sedan") sedan++;
        else if (history[i] == "Truck") truck++;
    }

    if (history.size() == 0) return "No data yet";

    if (suv >= sedan && suv >= truck) return "SUV";
    if (sedan >= suv && sedan >= truck) return "Sedan";
    return "Truck";
}

/*
display all cars
*/
void listCars() {
    cout << "\n========== CARS ==========\n\n";

    for (int i = 0; i < cars.size(); i++) {
        cars[i]->display();
    }
}

/*
rent process
*/
void rentCar() {
    string name, s, e;

    cout << "\n--- Rent ---\n";
    listCars();

    cout << "Enter car name: ";
    cin >> name;

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i]->getName() == name) {

            cout << "Start date: ";
            cin >> s;
            cout << "End date: ";
            cin >> e;

            bool wasFree = cars[i]->isAvailable();
            cars[i]->rent(s, e);

            if (wasFree)
                history.push_back(cars[i]->getType());

            return;
        }
    }

    cout << "Car not found\n";
}

/*
return process
*/
void returnCar() {
    string name;

    cout << "\n--- Return ---\n";
    cout << "Enter car name: ";
    cin >> name;

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i]->getName() == name) {
            cars[i]->giveBack();
            return;
        }
    }

    cout << "Car not found\n";
}

/*
compare function (needed for old compiler)
*/
bool compareCars(Car* a, Car* b) {
    return a->getName() < b->getName();
}

/*
sort cars
*/
void sortCars() {
    sort(cars.begin(), cars.end(), compareCars);
    cout << "\n✔ Sorted\n";
}

/*
recommendation display
*/
void showRec() {
    cout << "\n--- Recommendation ---\n";
    cout << "Based on " << history.size() << " rentals\n";
    cout << "Suggested: " << recommend() << "\n";
}

/*
pause
*/
void pause() {
    cin.ignore();
    cout << "\nPress Enter...";
    cin.get();
}

int main() {

    // add cars manually (no {} syntax)
    cars.push_back(new Sedan("Camry"));
    cars.push_back(new Sedan("Accord"));
    cars.push_back(new Sedan("Civic"));

    cars.push_back(new SUV("CRV"));
    cars.push_back(new SUV("Rav4"));
    cars.push_back(new SUV("Highlander"));

    cars.push_back(new Truck("F150"));
    cars.push_back(new Truck("Silverado"));
    cars.push_back(new Truck("Ram1500"));

    // fake history
    history.push_back("SUV");
    history.push_back("SUV");
    history.push_back("SUV");
    history.push_back("Sedan");
    history.push_back("Sedan");
    history.push_back("Truck");

    int choice;

    while (true) {

        cout << "\n==================================\n";
        cout << "       Car Rental System\n";
        cout << "==================================\n";

        cout << "\n1. View cars\n";
        cout << "2. Rent a car\n";
        cout << "3. Return a car\n";
        cout << "4. Sort cars\n";
        cout << "5. Get recommendation\n";
        cout << "6. Exit\n";

        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 1) { listCars(); pause(); }
        else if (choice == 2) { rentCar(); pause(); }
        else if (choice == 3) { returnCar(); pause(); }
        else if (choice == 4) { sortCars(); pause(); }
        else if (choice == 5) { showRec(); pause(); }
        else if (choice == 6) break;
        else cout << "Invalid\n";
    }

    return 0;
}
