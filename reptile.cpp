#include <iostream>
#include <cstring>
using namespace std;

class Reptile {
private:
    string species;
    int age;
    const int idNumber;
    static int totalReptiles;
    char* habitat;

public:
    Reptile() : species("Unknown"), age(0), idNumber(100) {
        habitat = new char[10];
        strcpy(habitat, "Default");
        totalReptiles++;
    }

    Reptile(string s, int a, int id) : species(s), age(a), idNumber(id) {
        habitat = new char[10];
        strcpy(habitat, "Default");
        totalReptiles++;
    }

    Reptile(const Reptile& other) : species(other.species), age(other.age), idNumber(other.idNumber) {
        habitat = new char[strlen(other.habitat) + 1];
        strcpy(habitat, other.habitat);
        totalReptiles++;
    }

    ~Reptile() {
        delete[] habitat;
    }

    string getSpecies() const { return species; }
    int getAge() const { return age; }
    int getIdNumber() const { return idNumber; }
    static int getTotalReptiles() { return totalReptiles; }

    void setSpecies(string s) { species = s; }
    void setAge(int a) { age = a; }

    bool operator==(const Reptile& other) const {
        return (species == other.species) && (age == other.age);
    }

    friend void printReptileDetails(const Reptile& r);
};

int Reptile::totalReptiles = 0;

void printReptileDetails(const Reptile& r) {
    cout << "Species: " << r.species << ", Age: " << r.age << ", ID Number: " << r.idNumber << endl;
}

int main() {
    Reptile r1;
    Reptile r2("Iguana", 5, 101);
    Reptile r3 = r2;

    cout << "Total Reptiles: " << Reptile::getTotalReptiles() << endl;
    printReptileDetails(r1);
    printReptileDetails(r2);
    printReptileDetails(r3);

    r1.setSpecies("Chameleon");
    r1.setAge(2);
    printReptileDetails(r1);

    if (r2 == r3) {
        cout << "Reptile r2 and r3 are identical." << endl;
    } else {
        cout << "Reptile r2 and r3 are different." << endl;
    }

    return 0;
}