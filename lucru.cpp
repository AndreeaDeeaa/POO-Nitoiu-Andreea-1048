#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<string>
using namespace std;
class Petitie{
    private:
    const int id_petitie;
    string dataDepunere;
    char* numePrenume;
    string categorie;
    string descriere;
    float* costOrganizare;
    public:
    Petitie():id_petitie(0){
        this->dataDepunere="X";
        this->numePrenume=new char[20];
        strcpy(this->numePrenume, "Barbulescu Stefan");
        this->categorie="social";
        this->descriere="";
        this->costOrganizare=new float(9.90);
    }
    Petitie(const int id_petitie, string dataDepunere, const char*numePrenume, string categorie, string descriere, float costOrganizare):id_petitie(id_petitie){
        this->dataDepunere=dataDepunere;
        this->numePrenume=new char[strlen(numePrenume)+1];
        strcpy(this->numePrenume, numePrenume);
        this->categorie=categorie;
        this->descriere=descriere;
        this->costOrganizare=new float(costOrganizare);
    }
    Petitie(const Petitie& c):id_petitie(c.id_petitie){
        this->dataDepunere=c.dataDepunere;
        this->numePrenume=new char[strlen(c.numePrenume)+1];
        strcpy(this->numePrenume, c.numePrenume);
        this->categorie=c.categorie;
        this->descriere=c.descriere;
        this->costOrganizare=new float(*(c.costOrganizare));
    }
    ~Petitie(){
        delete[]numePrenume;
        delete costOrganizare;
    }
    int getId_petitie()const{
        return id_petitie;
    }
    string getDataDepunere()const{
        return dataDepunere;
    }
    const char* getNumePrenume()const{
        return numePrenume;
    }
    string getCategorie()const{
        return categorie;
    }
    string getDescriere()const{
        return descriere;
    }
    float getCostOrganizare()const{
        return* costOrganizare;
    }
    void setDataDepunere(string dataDepunere){
        this->dataDepunere=dataDepunere;
    }
    void setNumePrenume(const char* numePrenume){
        delete[]this->numePrenume;
        this->numePrenume=new char[strlen(numePrenume)+1];
        strcpy(this->numePrenume, numePrenume);
    }
    void setCategorie(string categorie){
        this->categorie=categorie;
    }
    void setDescriere(string descriere){
        this->descriere=descriere;
    }
    void setCostOrganizare(float costOrganizare){
        *(this->costOrganizare)=costOrganizare;
    }
    friend ostream&operator<<(ostream& out, const Petitie&p){
    out<<"id petitie:"<<p.id_petitie<<endl;
    out<<"data depunerii:"<<p.dataDepunere<<endl;
    out<<"nume si prenume solicitant:"<<p.numePrenume<<endl;
    out<<"categorie:"<<p.categorie<<endl;
    out<<"descriere:"<<p.descriere<<endl;
    out<<"cost organizare:"<<*(p.costOrganizare)<<endl;
    return out;
    }
};
int main(){
    Petitie p1(1, "01/01/2025", "Barbulescu Stefan", "social", "Aceasta este descrierea", 9.90f);
    cout<<"id petitie:"<<p1.getId_petitie()<<endl;
    cout<<"data depunerii:"<<p1.getDataDepunere()<<endl;
    cout<<"nume si prenume solicitant:"<<p1.getNumePrenume()<<endl;
    cout<<"categorie:"<<p1.getCategorie()<<endl;
    cout<<"descriere:"<<p1.getDescriere()<<endl;
    cout<<"cost organizare:"<<p1.getCostOrganizare()<<endl;
    p1.setDataDepunere("02/01/2025");
    p1.setNumePrenume("CroitoruClaudiu");
    p1.setCategorie("economic");
    p1.setDescriere("Nu exista descriere");
    p1.setCostOrganizare(10.13f);
    cout<<"\nInformatii actualizate:"<<endl;
    cout<<"id petitie:"<<p1.getId_petitie()<<endl;
    cout<<"data depunerii:"<<p1.getDataDepunere()<<endl;
    cout<<"nume si prenume solicitant:"<<p1.getNumePrenume()<<endl;
    cout<<"categorie:"<<p1.getCategorie()<<endl;
    cout<<"descriere:"<<p1.getDescriere()<<endl;
    cout<<"cost organizare:"<<p1.getCostOrganizare()<<endl;
    cout<<"\nInformatii actualizate:"<<endl;
    cout<<p1<<endl;
    return 0;
}