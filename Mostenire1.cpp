//La finalul acestui program am marcat prin comentarii cateva aspecte teoretice importante legate de acest cod
#include <iostream>
#include <string>

using namespace std;

// Clasa de bază
class Device {
protected:
    string brand;

public:
    Device(const string& brandName) : brand(brandName) {
        cout << "Constructor Device: " << brand << endl;
    }

    virtual ~Device() {
        cout << "Destructor Device: " << brand << endl;
    }

    virtual void displayInfo() const {
        cout << "Device Brand: " << brand << endl;
    }
};

// Clasa derivată 1
class Laptop : public Device {
protected:
    int ram;

public:
    Laptop(const string& brandName, int ramSize)
        : Device(brandName), ram(ramSize) {
        cout << "Constructor Laptop: " << brand << ", RAM: " << ram << "GB" << endl;
    }

    ~Laptop() override {
        cout << "Destructor Laptop" << endl;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Laptop RAM: " << ram << "GB" << endl;
    }
};

// Clasa derivată 2
class TouchscreenLaptop : public Laptop {
    bool hasStylus;

public:
    TouchscreenLaptop(const string& brandName, int ramSize, bool stylus)
        : Laptop(brandName, ramSize), hasStylus(stylus) {
        cout << "Constructor TouchscreenLaptop: " << (hasStylus ? "with Stylus" : "without Stylus") << endl;
    }

    ~TouchscreenLaptop() override {
        cout << "Destructor TouchscreenLaptop" << endl;
    }

    void displayInfo() const override {
        Laptop::displayInfo();
        cout << "Touchscreen Laptop: " << (hasStylus ? "Has Stylus" : "No Stylus") << endl;
    }
};

// Demonstrarea Upcasting și Downcasting
void showDeviceInfo(const Device* device) {
    device->displayInfo();
}

int main() {
    // Upcasting
    TouchscreenLaptop myLaptop("Dell", 16, true);
    Device* devicePtr = &myLaptop;

    cout << "\nUpcasting Example:" << endl;
    showDeviceInfo(devicePtr); // Funcția acceptă pointer la clasa de bază

    cout << "\nDowncasting Example:" << endl;
    TouchscreenLaptop* touchscreenPtr = dynamic_cast<TouchscreenLaptop*>(devicePtr);
    if (touchscreenPtr) {
        touchscreenPtr->displayInfo();
    } else {
        cout << "Downcasting failed." << endl;
    }

    return 0;
}

//    Metodele virtuale din acest cod sunt gestionate printr-o structură numită "V-Table" (Virtual Table).
//    Aceasta este creată de compilator pentru fiecare clasă care conține metode virtuale.
//    La runtime, pointerii la funcțiile corespunzătoare din V-Table sunt folosiți pentru a determina ce implementare a metodei este apelată, în funcție de tipul obiectului real (polimorfism dinamic).
//    C++ permite covarianța tipului de retur pentru metodele virtuale suprascrise. Aceasta înseamnă că metoda suprascrisă poate returna un pointer sau o referință la un tip derivat din cel returnat  de metoda din clasa de bază. În acest cod, dacă `displayInfo` ar returna un tip pointer, acest mecanism  ar putea fi folosit pentru a îmbunătăți polimorfismul.