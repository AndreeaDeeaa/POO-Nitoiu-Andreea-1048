#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Clasa de bază abstractă pentru toate animalele
class Animal {
protected:
    string name;
    int age;

public:
    Animal(const string& name, int age) : name(name), age(age) {}

    virtual void makeSound() const = 0; // Funcție virtuală pură
    virtual void showInfo() const {
        cout << "Animal: " << name << ", Age: " << age << " years." << endl;
    }

    virtual ~Animal() = default; // Destructor virtual
};

// Clasă derivată pentru mamifere
class Mammal : public Animal {
protected:
    bool isDomesticated;

public:
    Mammal(const string& name, int age, bool isDomesticated)
        : Animal(name, age), isDomesticated(isDomesticated) {}

    void showInfo() const override {
        Animal::showInfo();
        cout << "Type: Mammal, Domesticated: " << (isDomesticated ? "Yes" : "No") << endl;
    }
};

// Clasă derivată pentru păsări
class Bird : public Animal {
protected:
    double wingSpan;

public:
    Bird(const string& name, int age, double wingSpan)
        : Animal(name, age), wingSpan(wingSpan) {}

    void showInfo() const override {
        Animal::showInfo();
        cout << "Type: Bird, Wing Span: " << wingSpan << " meters." << endl;
    }
};

// Clasă derivată specifică pentru leu
class Lion : public Mammal {
public:
    Lion(const string& name, int age)
        : Mammal(name, age, false) {}

    void makeSound() const override {
        cout << name << " roars: ROAAAR!" << endl;
    }
};

// Clasă derivată specifică pentru papagal
class Parrot : public Bird {
private:
    string vocabulary;

public:
    Parrot(const string& name, int age, double wingSpan, const string& vocabulary)
        : Bird(name, age, wingSpan), vocabulary(vocabulary) {}

    void makeSound() const override {
        cout << name << " says: " << vocabulary << endl;
    }
};

// Clasă derivată pentru animale acvatice
class Aquatic : public Animal {
protected:
    bool isSaltWater;

public:
    Aquatic(const string& name, int age, bool isSaltWater)
        : Animal(name, age), isSaltWater(isSaltWater) {}

    void showInfo() const override {
        Animal::showInfo();
        cout << "Type: Aquatic, Salt Water: " << (isSaltWater ? "Yes" : "No") << endl;
    }
};

// Clasă derivată specifică pentru rechin
class Shark : public Aquatic {
public:
    Shark(const string& name, int age)
        : Aquatic(name, age, true) {}

    void makeSound() const override {
        cout << name << " silently swims by..." << endl;
    }
};

// Grădina Zoologică - clasa de gestionare
class Zoo {
private:
    vector<shared_ptr<Animal>> animals;

public:
    void addAnimal(shared_ptr<Animal> animal) {
        animals.push_back(animal);
    }

    void showAllAnimals() const {
        cout << "Zoo Inventory:\n";
        for (const auto& animal : animals) {
            animal->showInfo();
            animal->makeSound();
            cout << "----------------------\n";
        }
    }
};

int main() {
    Zoo myZoo;

    // Creăm câteva animale și le adăugăm în grădina zoologică
    myZoo.addAnimal(make_shared<Lion>("Simba", 5));
    myZoo.addAnimal(make_shared<Parrot>("Polly", 2, 0.3, "Hello!"));
    myZoo.addAnimal(make_shared<Shark>("Bruce", 7));

    // Afișăm toate animalele din grădina zoologică
    myZoo.showAllAnimals();

    return 0;
}
