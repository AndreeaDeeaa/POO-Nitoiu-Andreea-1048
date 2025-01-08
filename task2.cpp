#include <iostream>
#include <cstring>
using namespace std;

class Laptop {
public:
    string brand;
    int ram;
    const int serialNumber;
    static int totalLaptops;
    char* owner;

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

    Laptop(string b, int r, int s, const char* o) : brand(b), ram(r), serialNumber(s) {
        owner = new char[strlen(o) + 1];
        strcpy(owner, o);
        totalLaptops++;
    }

    static int getTotalLaptops() {
        return totalLaptops;
    }

    ~Laptop() {
        delete[] owner;
    }
};
int Laptop::totalLaptops = 0;

class Smartphone {
public:
    string model;
    double screenSize;
    const int imei;
    static int totalSmartphones;
    char* os;

    Smartphone() : model("Generic"), screenSize(5.0), imei(2000) {
        os = new char[10];
        strcpy(os, "Android");
        totalSmartphones++;
    }

    Smartphone(string m, double s, int i) : model(m), screenSize(s), imei(i) {
        os = new char[10];
        strcpy(os, "Android");
        totalSmartphones++;
    }

    Smartphone(string m, double s, int i, const char* o) : model(m), screenSize(s), imei(i) {
        os = new char[strlen(o) + 1];
        strcpy(os, o);
        totalSmartphones++;
    }

    static int getTotalSmartphones() {
        return totalSmartphones;
    }

    ~Smartphone() {
        delete[] os;
    }
};
int Smartphone::totalSmartphones = 0;

class Tablet {
public:
    string brand;
    float batteryLife;
    const int serialNumber;
    static int totalTablets;
    char* os;

    Tablet() : brand("Unknown"), batteryLife(10.0), serialNumber(3000) {
        os = new char[10];
        strcpy(os, "iOS");
        totalTablets++;
    }

    Tablet(string b, float bl, int s) : brand(b), batteryLife(bl), serialNumber(s) {
        os = new char[10];
        strcpy(os, "iOS");
        totalTablets++;
    }

    Tablet(string b, float bl, int s, const char* o) : brand(b), batteryLife(bl), serialNumber(s) {
        os = new char[strlen(o) + 1];
        strcpy(os, o);
        totalTablets++;
    }

    static int getTotalTablets() {
        return totalTablets;
    }

    ~Tablet() {
        delete[] os;
    }
};
int Tablet::totalTablets = 0;

int main() {
    Laptop l1;
    Laptop l2("Dell", 16, 1234);
    Laptop l3("HP", 8, 5678, "John");

    cout << "Total Laptops: " << Laptop::getTotalLaptops() << endl;

    Smartphone s1;
    Smartphone s2("Samsung", 6.5, 7890);
    Smartphone s3("Apple", 5.8, 3456, "iOS");

    cout << "Total Smartphones: " << Smartphone::getTotalSmartphones() << endl;

    Tablet t1;
    Tablet t2("Lenovo", 12.0, 4567);
    Tablet t3("Microsoft", 9.5, 8912, "Windows");

    cout << "Total Tablets: " << Tablet::getTotalTablets() << endl;

    return 0;
}