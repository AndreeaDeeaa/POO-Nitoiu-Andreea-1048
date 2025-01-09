#include <iostream>
#include <cstring>
using namespace std;

class Laptop {
private:
    string brand;
    int ram;
    const int serialNumber;
    static int totalLaptops;
    char* owner;

public:
    Laptop() : brand("Unknown"), ram(4), serialNumber(1000) {
        owner = new char[10];
        strcpy(owner, "Default");
        totalLaptops++;
    }

    Laptop(string b, int r, int s) : brand(b), ram(r), serialNumber(s) {
        owner = new char[10];
        strcpy(owner, "Default");
        totalLaptops++;
    }

    Laptop(const Laptop& other) : brand(other.brand), ram(other.ram), serialNumber(other.serialNumber) {
        owner = new char[strlen(other.owner) + 1];
        strcpy(owner, other.owner);
        totalLaptops++;
    }

    ~Laptop() {
        delete[] owner;
    }

    string getBrand() const { return brand; }
    int getRam() const { return ram; }
    int getSerialNumber() const { return serialNumber; }
    static int getTotalLaptops() { return totalLaptops; }

    void setBrand(string b) { brand = b; }
    void setRam(int r) { ram = r; }

    friend void printLaptopDetails(const Laptop& l);
};

int Laptop::totalLaptops = 0;

void printLaptopDetails(const Laptop& l) {
    cout << "Brand: " << l.brand << ", RAM: " << l.ram << ", Serial Number: " << l.serialNumber << endl;
}

int main() {
    Laptop l1;
    Laptop l2("Dell", 16, 1234);
    Laptop l3 = l2;

    cout << "Total Laptops: " << Laptop::getTotalLaptops() << endl;
    printLaptopDetails(l1);
    printLaptopDetails(l2);
    printLaptopDetails(l3);

    l1.setBrand("Acer");
    l1.setRam(8);
    printLaptopDetails(l1);

    return 0;
}