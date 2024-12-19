#include <iostream>
#include <cstring>

class Scoala {
private:
    char* nume;
    int nrElevi;

public:
    // Constructor implicit
    Scoala() : nume(nullptr), nrElevi(0) {
        std::cout << "Constructor implicit apelat.\n";
    }

    // Constructor cu parametri
    Scoala(const char* nume, int nrElevi) : nrElevi(nrElevi) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        std::cout << "Constructor cu parametri apelat.\n";
    }

    // Constructor de copiere
    Scoala(const Scoala& other) {
        nrElevi = other.nrElevi;
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
        std::cout << "Constructor de copiere apelat.\n";
    }

    // Destructor
    ~Scoala() {
        delete[] nume;
        std::cout << "Destructor apelat.\n";
    }

    // Supraincarcarea operatorului de asignare
    Scoala& operator=(const Scoala& other) {
        if (this != &other) {
            delete[] nume;
            nrElevi = other.nrElevi;
            nume = new char[strlen(other.nume) + 1];
            strcpy(nume, other.nume);
        }
        return *this;
    }

    // Operatorul friend pentru a afisa detalii
    friend std::ostream& operator<<(std::ostream& os, const Scoala& scoala) {
        os << "Nume: " << (scoala.nume ? scoala.nume : "N/A") << ", Nr. elevi: " << scoala.nrElevi;
        return os;
    }

    // Metoda virtuala pentru binding tarziu
    virtual void afisare() const {
        std::cout << "Scoala: " << (nume ? nume : "N/A") << ", Nr. elevi: " << nrElevi << "\n";
    }

    // Getter pentru binding timpuriu
    const char* getNume() const {
        return nume;
    }

    int getNrElevi() const {
        return nrElevi;
    }
};

class Liceu : public Scoala {
private:
    int nrProfesori;

public:
    // Constructor cu parametri
    Liceu(const char* nume, int nrElevi, int nrProfesori) : Scoala(nume, nrElevi), nrProfesori(nrProfesori) {
        std::cout << "Constructor Liceu apelat.\n";
    }

    // Metoda virtuala suprascrisa pentru binding tarziu
    void afisare() const override {
        std::cout << "Liceu: " << getNume() << ", Nr. elevi: " << getNrElevi() << ", Nr. profesori: " << nrProfesori << "\n";
    }
};

int main() {
    Scoala* scoala = new Scoala("Scoala Generala nr. 1", 500);
    Liceu* liceu = new Liceu("Liceul Teoretic", 1000, 50);

    // Demonstratie early binding
    std::cout << "Detalii Scoala (early binding):\n";
    std::cout << *scoala << "\n";

    // Demonstratie late binding
    std::cout << "Detalii Liceu (late binding):\n";
    Scoala* baza = liceu; // Pointer de tip baza
    baza->afisare();

    // Dealocare dinamica
    delete scoala;
    delete liceu;

    return 0;
}
