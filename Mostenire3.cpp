#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

// Clasa abstractă pentru vehicule
class Vehicle {
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle(const string& brand, const string& model, int year)
        : brand(brand), model(model), year(year) {}

    virtual void showDetails() const = 0; // Funcție virtuală pură
    virtual void startEngine() const = 0;

    virtual ~Vehicle() = default;
};

// Clasă de bază pentru mașini
class Car : public Vehicle {
protected:
    int horsepower;
    double fuelConsumption; // Litri/100 km

public:
    Car(const string& brand, const string& model, int year, int horsepower, double fuelConsumption)
        : Vehicle(brand, model, year), horsepower(horsepower), fuelConsumption(fuelConsumption) {}

    void showDetails() const override {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year
             << ", Horsepower: " << horsepower
             << ", Fuel Consumption: " << fuelConsumption << " L/100 km\n";
    }
};

// Interfață pentru vehicule electrice
class Electric {
protected:
    double batteryCapacity; // kWh
    double range; // km

public:
    Electric(double batteryCapacity, double range)
        : batteryCapacity(batteryCapacity), range(range) {}

    virtual void chargeBattery() const {
        cout << "Charging battery to " << batteryCapacity << " kWh...\n";
    }
};

// Interfață pentru vehicule sport
class Sport {
protected:
    double topSpeed;

public:
    Sport(double topSpeed) : topSpeed(topSpeed) {}

    virtual void boost() const {
        cout << "Activating sport mode! Top speed: " << topSpeed << " km/h\n";
    }
};

// Clasă pentru mașini sport electrice
class ElectricSportsCar : public Car, public Electric, public Sport {
public:
    ElectricSportsCar(const string& brand, const string& model, int year, double batteryCapacity, double range, double topSpeed)
        : Car(brand, model, year, 0, 0.0), Electric(batteryCapacity, range), Sport(topSpeed) {}

    void startEngine() const override {
        cout << "Starting electric sports engine silently...\n";
    }

    void showDetails() const override {
        Car::showDetails();
        cout << "Battery Capacity: " << batteryCapacity << " kWh, Range: " << range
             << " km, Top Speed: " << topSpeed << " km/h\n";
    }
};

// Clasă pentru mașini clasice
class ClassicCar : public Car {
private:
    bool isRestored;

public:
    ClassicCar(const string& brand, const string& model, int year, int horsepower, double fuelConsumption, bool isRestored)
        : Car(brand, model, year, horsepower, fuelConsumption), isRestored(isRestored) {}

    void startEngine() const override {
        cout << "Starting the roaring classic engine...\n";
    }

    void showDetails() const override {
        Car::showDetails();
        cout << "Restored: " << (isRestored ? "Yes" : "No") << "\n";
    }
};

// Clasă pentru mașini autonome
class AutonomousCar : public Car {
private:
    string softwareVersion;

public:
    AutonomousCar(const string& brand, const string& model, int year, int horsepower, double fuelConsumption, const string& softwareVersion)
        : Car(brand, model, year, horsepower, fuelConsumption), softwareVersion(softwareVersion) {}

    void startEngine() const override {
        cout << "Starting autonomous driving system...\n";
    }

    void engageAutopilot() const {
        cout << "Autopilot engaged with software version: " << softwareVersion << "\n";
    }

    void showDetails() const override {
        Car::showDetails();
        cout << "Autonomous Software Version: " << softwareVersion << "\n";
    }
};

// Showroom pentru gestionarea mașinilor
class Showroom {
private:
    vector<shared_ptr<Vehicle>> vehicles;

public:
    void addVehicle(shared_ptr<Vehicle> vehicle) {
        vehicles.push_back(vehicle);
    }

    void showAllVehicles() const {
        cout << "Showroom Inventory:\n";
        for (const auto& vehicle : vehicles) {
            vehicle->showDetails();
            cout << "----------------------\n";
        }
    }

    void startAllEngines() const {
        for (const auto& vehicle : vehicles) {
            vehicle->startEngine();
        }
    }
};

int main() {
    Showroom showroom;

    // Adăugăm diferite tipuri de mașini în showroom
    showroom.addVehicle(make_shared<ElectricSportsCar>("Tesla", "Roadster", 2022, 100.0, 1000, 400));
    showroom.addVehicle(make_shared<ClassicCar>("Ford", "Mustang", 1969, 300, 15.0, true));
    showroom.addVehicle(make_shared<AutonomousCar>("Tesla", "Model S", 2023, 670, 0.0, "v12.5.7"));

    // Afișăm toate mașinile din showroom
    showroom.showAllVehicles();

    // Pornim motoarele tuturor mașinilor
    cout << "\nStarting all engines...\n";
    showroom.startAllEngines();

    return 0;
}
