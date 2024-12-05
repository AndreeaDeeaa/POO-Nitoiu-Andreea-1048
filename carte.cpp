#include<iostream>
using namespace std;

class Carte {
private:
    string titlu;
    string autor;
    int nrPagini;
    float pret;
    static float discount;
    const int anPublicatie;

public:
    Carte() : anPublicatie(2024), nrPagini(200) {
        this->titlu = "Titlu Default";
        this->autor = "Autor Necunoscut";
        this->pret = 50;
    }

    Carte(string titlu, string autor, int nrPagini, float pret, int an)
        : anPublicatie(an), nrPagini(nrPagini) {
        this->titlu = titlu;
        this->autor = autor;
        this->pret = pret;
    }

    Carte(const Carte& c) : anPublicatie(c.anPublicatie) {
        this->titlu = c.titlu;
        this->autor = c.autor;
        this->nrPagini = c.nrPagini;
        this->pret = c.pret;
    }

    Carte operator=(const Carte& c) {
        if (this != &c) {
            this->titlu = c.titlu;
            this->autor = c.autor;
            this->nrPagini = c.nrPagini;
            this->pret = c.pret;
        }
        return *this;
    }

    ~Carte() {}

    Carte operator+(const Carte& c) const {
        Carte temp = *this;
        temp.pret = this->pret + c.pret;
        return temp;
    }

    Carte operator+=(float reducere) {
        this->pret -= reducere;
        return *this;
    }

    Carte operator+(float adaos) const {
        Carte temp = *this;
        temp.pret += adaos;
        return temp;
    }

    friend Carte operator+(float adaos, Carte c) {
        Carte temp = c;
        temp.pret += adaos;
        return temp;
    }

    explicit operator float() {
        return calculeazaPretFinal();
    }

    explicit operator int() {
        return this->nrPagini;
    }

    string getTitlu() const {
        return this->titlu;
    }

    void setTitlu(string titlu) {
        if (!titlu.empty()) {
            this->titlu = titlu;
        }
    }

    void afisare() const {
        cout << "Titlu: " << this->titlu << endl;
        cout << "Autor: " << this->autor << endl;
        cout << "Nr Pagini: " << this->nrPagini << endl;
        cout << "Pret: " << this->pret << endl;
        cout << "An Publicatie: " << this->anPublicatie << endl;
        cout << "Discount: " << Carte::discount << "%" << endl;
    }

    float calculeazaPretFinal() const {
        return this->pret - (this->pret * (Carte::discount / 100));
    }

    static void setDiscount(float d) {
        if (d >= 0 && d <= 100) {
            Carte::discount = d;
        }
    }

    bool operator<(const Carte& c) const {
        return this->pret < c.pret;
    }

    friend istream& operator>>(istream& input, Carte& c) {
        cout << "Introduceti titlul: ";
        input >> ws; // pentru a consuma newline
        getline(input, c.titlu);
        cout << "Introduceti autorul: ";
        getline(input, c.autor);
        cout << "Introduceti nr pagini: ";
        input >> c.nrPagini;
        cout << "Introduceti pretul: ";
        input >> c.pret;
        return input;
    }

    friend ostream& operator<<(ostream& output, const Carte& c);
};

float Carte::discount = 10;

ostream& operator<<(ostream& output, const Carte& c) {
    output << "Titlu: " << c.titlu << endl;
    output << "Autor: " << c.autor << endl;
    output << "Nr Pagini: " << c.nrPagini << endl;
    output << "Pret: " << c.pret << endl;
    output << "An Publicatie: " << c.anPublicatie << endl;
    return output;
}

int main() {
    Carte c1;
    Carte c2("Clean Code", "Robert C. Martin", 464, 75, 2008);

    float pretFinal = (float)c2;
    cout << "Pret final: " << pretFinal << endl;

    int nrPagini = (int)c2;
    cout << "Nr Pagini: " << nrPagini << endl;

    cout << c2 << endl;

    try {
        Carte c3;
        cin >> c3;
        cout << endl << c3 << endl;
    }
    catch (const char* e) {
        cout << e << endl;
    }

    if (c2 < c1) {
        cout << "c2 este mai ieftina decat c1" << endl;
    }

    Carte c4 = c2 + 10.0f; // Adaugare adaos pret
    cout << c4 << endl;

    return 0;
}
