#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Bloc {
public:
    string strada;
    int numarScari;
    int numarApartamente;
    int anConstructie;
    string culoareExterior;

    void citireDate() {
        cout << "Introduceti strada: ";
        cin >> ws; // eliminare spatii
        getline(cin, strada);
        cout << "Introduceti numarul de scari: ";
        cin >> numarScari;
        cout << "Introduceti numarul de apartamente: ";
        cin >> numarApartamente;
        cout << "Introduceti anul constructiei: ";
        cin >> anConstructie;
        cout << "Introduceti culoarea exteriorului: ";
        cin >> ws; 
        getline(cin, culoareExterior);
    }

    void afisareDate() const {
        cout << "Blocul de pe strada " << strada 
             << ", are " << numarScari << " scari si un numar total de "
             << numarApartamente << " apartamente. A fost construit in "
             << anConstructie << " si are culoarea " << culoareExterior << ".\n";
    }
};

int main() {
    const int numarBlocuri = 10;
    vector<Bloc*> blocuri;

    for (int i = 0; i < numarBlocuri; ++i) {
        Bloc* blocNou = new Bloc();
        cout << "\nCitire date pentru blocul " << (i + 1) << ":\n";
        blocNou->citireDate();
        blocuri.push_back(blocNou);
    }

    cout << "\nAfisare informatii despre blocuri:\n";
    for (const auto& bloc : blocuri) {
        bloc->afisareDate();
    }

    // Eliberare memorie alocata dinamic
    for (const auto& bloc : blocuri) {
        delete bloc;
    }

    return 0;
}