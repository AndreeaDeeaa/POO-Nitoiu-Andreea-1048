#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Energie {
private:
    const int id_client;
    char* numeClient;
    int consumLunar;
    int consumEstimat;
    int nrContract;
    string durataContract;
    float* pret;

public:
    Energie() : id_client(0) {
        this->numeClient = new char[strlen("Catalin") + 1];
        strcpy(this->numeClient, "Catalin");
        this->consumLunar = 58;
        this->consumEstimat = 60;
        this->nrContract = 35;
        this->durataContract = "trei ani";
        this->pret = new float(500);
    }

    Energie(const int id_client, const char* numeClient, int consumLunar, int consumEstimat, int nrContract, string durataContract, float pret) 
    : id_client(id_client) {
        this->numeClient = new char[strlen(numeClient) + 1];
        strcpy(this->numeClient, numeClient);
        this->consumLunar = consumLunar;
        this->consumEstimat = consumEstimat;
        this->nrContract = nrContract;
        this->durataContract = durataContract;
        this->pret = new float(pret);
    }

    Energie(const Energie& c) : id_client(c.id_client) {
        this->numeClient = new char[strlen(c.numeClient) + 1];
        strcpy(this->numeClient, c.numeClient);
        this->consumLunar = c.consumLunar;
        this->consumEstimat = c.consumEstimat;
        this->nrContract = c.nrContract;
        this->durataContract = c.durataContract;
        this->pret = new float(*(c.pret));
    }

    ~Energie() {
        delete[] numeClient;
        delete pret;
    }

    int getId_client() const {
        return this->id_client;
    }

    const char* getNumeClient() const {
        return this->numeClient;
    }

    int getConsumLunar() const {
        return this->consumLunar;
    }

    int getConsumEstimat() const {
        return this->consumEstimat;
    }

    int getNrContract() const {
        return this->nrContract;
    }

    string getDurataContract() const {
        return this->durataContract;
    }

    float getPret() const {
        return *this->pret;
    }

    void setNumeClient(const char* numeClient) {
        delete[] this->numeClient;
        this->numeClient = new char[strlen(numeClient) + 1];
        strcpy(this->numeClient, numeClient);
    }

    void setConsumLunar(int consumLunar) {
        this->consumLunar = consumLunar;
    }

    void setConsumEstimat(int consumEstimat) {
        this->consumEstimat = consumEstimat;
    }

    void setNrContract(int nrContract) {
        this->nrContract = nrContract;
    }

    void setDurataContract(string durataContract) {
        this->durataContract = durataContract;
    }

    void setPret(float pret) {
        *(this->pret) = pret;
    }

    friend ostream& operator<<(ostream& out, const Energie& p) {
        out << "id_client: " << p.id_client << endl;
        out << "nume client: " << p.numeClient << endl;
        out << "consum lunar: " << p.consumLunar << endl;
        out << "consum estimat: " << p.consumEstimat << endl;
        out << "nr contract: " << p.nrContract << endl;
        out << "durata contract: " << p.durataContract << endl;
        out << "pret: " << *(p.pret) << endl;
        return out;
    }
};

int main() {
    Energie e1(1, "Catalin", 58, 60, 35, "trei ani", 500);
    cout << "id_client: " << e1.getId_client() << endl;
    cout << "nume client: " << e1.getNumeClient() << endl;
    cout << "consum lunar: " << e1.getConsumLunar() << endl;
    cout << "consum estimat: " << e1.getConsumEstimat() << endl;
    cout << "nr contract: " << e1.getNrContract() << endl;
    cout << "durata contract: " << e1.getDurataContract() << endl;
    cout << "pret: " << e1.getPret() << endl;

    e1.setNumeClient("Radu");
    e1.setConsumLunar(60);
    e1.setConsumEstimat(65);
    e1.setNrContract(40);
    e1.setDurataContract("zece ani");
    e1.setPret(550);

    cout << "\nInformatii actualizate:" << endl;
    cout << e1 << endl;

    return 0;
}
