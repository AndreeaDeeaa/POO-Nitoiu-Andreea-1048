#include <iostream>
using namespace std;

// Clasa de bază
class Base {
public:
    virtual void show() const { // Funcție virtuală
        cout << "Base class function" << endl;
    }
    virtual ~Base() {} // Destructor virtual
};

// Clasa derivată A
class DerivedA : public Base {
public:
    void show() const override {
        cout << "DerivedA class function" << endl;
    }
};

// Clasa derivată B
class DerivedB : public Base {
public:
    void show() const override {
        cout << "DerivedB class function" << endl;
    }
};

int main() {
    Base* ptr; // Pointer de tip bază

    DerivedA objA;
    DerivedB objB;

    ptr = &objA;
    ptr->show(); // Apel funcție DerivedA (late binding)

    ptr = &objB;
    ptr->show(); // Apel funcție DerivedB (late binding)

    return 0;
}
