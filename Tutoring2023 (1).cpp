//https://drive.google.com/drive/folders/1SnprQVKQ8zCSQ3NYtqXxEuldvxOXvpvX?usp=sharing
//https://drive.google.com/drive/folders/1BULha8CdRY0VDjzyKp4ORxXbw6TEOBMi?usp=sharing
//https://drive.google.com/drive/folders/1uTi9SyxZu5w5m1fRQ3zV78xrUa_KR0xU?usp=sharing
//https://drive.google.com/drive/folders/1SnprQVKQ8zCSQ3NYtqXxEuldvxOXvpvX
//https://drive.google.com/drive/folders/1TfFp-MmJbbadMTKgL-bp5oM4pcf7xAIC
//https://drive.google.com/drive/folders/19YaKKVku4iQcuDHqJGPFQU0OxQalLsrr?usp=sharing

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>//biblioteca necesara pentru scriere/citire din fisiere text
#include<vector>
using namespace std;

class CarteDeVizita {
	//atribut constant, autogenerat/initializat pe baza unui atribut static
	const int idCarte;
	static int numarator;
	//

	//atribut constant singur
	const string codCAENTitular;
	//

	//atribut static singur
	static string material;
	//
	char* numarTelefon;
	string numeTitular;
	float latime;
	float lungime;
public:
	//constructor fara parametri/implicit/default
	CarteDeVizita():idCarte(numarator++),codCAENTitular("00000") {
		//in constructorul fara parametrii, la atributele alocate dinamic(pointeri/vectori) dam NULL
		//eu nu dau null la char* ca mi da eroare
		this->numarTelefon = new char[strlen("00000")+1];
		strcpy(this->numarTelefon, "00000");
		this->numeTitular = "";
		this->latime = 10;
		this->lungime = 10;
	}

	//getter
	/*
	tipDeDataAtribut getNumeAtribut() {
		return this->numeAtribut;
	}
	*/
	float getLatime() {
		return this->latime;
	}

	////pt domnul Iancu
	//char* getNumarTelefon() {
	//	char* aux = new char[strlen(this->numarTelefon) + 1];
	//	strcpy(aux, this->numarTelefon);
	//	return aux;
	//}

	//pt restul
	char* getNumarTelefon() {
		return this->numarTelefon;
	}

	float getLungime() {
		return this->lungime;
	}


	//setter
	/*
		void setAtribut(tipDeDataAtribut numeAtribut){
			this->numeAtribut = numeAtribut;
		}
	*/
	void setLatime(float latime) {
		if (this->latime > 10) {
			this->latime = latime;
		}

	}

	void setNumarTelefon(const char* numarTelefon) {
		if (strlen(numarTelefon) == 10) {
			if (this->numarTelefon != NULL) {
				delete[]this->numarTelefon;
			}
			this->numarTelefon = new char[strlen(numarTelefon) + 1];
			strcpy(this->numarTelefon, numarTelefon);
		}
		else {
			//cout << "Numarul introdus nu poate fi salvat!" << endl;
			throw exception("Am aruncat o exceptie de tip obiect!");
		}
	}
	//constructor cu doi parametri
	CarteDeVizita(const char* numarTelefon, string numeTitular) :idCarte(numarator++), codCAENTitular("00000") {
		//in constructorul fara parametrii, la atributele alocate dinamic(pointeri/vectori) dam NULL
		//eu nu dau null la char* ca mi da eroare
		this->numarTelefon = new char[strlen(numarTelefon) + 1];
		strcpy(this->numarTelefon, numarTelefon);
		this->numeTitular = numeTitular;
		this->latime = 0;
		this->lungime = 0;
	}

	//constructor cu toti parametri
	CarteDeVizita(string codCAENTitular, const char* numarTelefon, string numeTitular, float latime, float lungime) :idCarte(numarator++), codCAENTitular(codCAENTitular) {
		//in constructorul fara parametrii, la atributele alocate dinamic(pointeri/vectori) dam NULL
		//eu nu dau null la char* ca mi da eroare
		this->numarTelefon = new char[strlen(numarTelefon) + 1];
		strcpy(this->numarTelefon, numarTelefon);
		this->numeTitular = numeTitular;
		this->latime = latime;
		this->lungime = lungime;
	}

	//constructor de copiere -- se apeleaza atunci cand vream sa cream un obiect nou pe baza altuia deja existent
	//constructorul de copiere este de fapt constructorul cu toti parametri, la care punem obiectul in fara atributului 
	CarteDeVizita(const CarteDeVizita& c) :idCarte(c.idCarte), codCAENTitular(c.codCAENTitular) {
		this->numarTelefon = new char[strlen(c.numarTelefon) + 1];
		strcpy(this->numarTelefon, c.numarTelefon);
		this->numeTitular = c.numeTitular;
		this->latime = c.latime;
		this->lungime = c.lungime;
	}

	//destructor
	~CarteDeVizita() {
		if (this->numarTelefon != NULL) {
			delete[]this->numarTelefon;
		}

		//cout << "S-a apelat destructorul!" << endl;
	}
	
	//operator = -- se apeleaza intre doua obiecte deja existente
	//operator se compune din destructor + constructor de copiere + return *this;
	CarteDeVizita& operator=(const CarteDeVizita& c) {
		if (this != &c) {//evitarea auto-asignarii(impiedicam egalarea unui obiect cu el insusi)
			if (this->numarTelefon != NULL) {
				delete[]this->numarTelefon;
			}
			this->numarTelefon = new char[strlen(c.numarTelefon) + 1];
			strcpy(this->numarTelefon, c.numarTelefon);
			this->numeTitular = c.numeTitular;
			this->latime = c.latime;
			this->lungime = c.lungime;
			return *this;
		}
		/*
		if (this == &c) {
			return;
		}
		if (this->numarTelefon != NULL) {
			delete[]this->numarTelefon;
		}
		this->numarTelefon = new char[strlen(c.numarTelefon) + 1];
		strcpy(this->numarTelefon, c.numarTelefon);
		this->numeTitular = c.numeTitular;
		this->latime = c.latime;
		this->lungime = c.lungime;
		return *this;*/

	}

	friend ostream& operator<<(ostream& out, const CarteDeVizita& c) {
		out << c.idCarte << endl;
		out << c.codCAENTitular << endl;
		out << c.material << endl;//atribut static
		out << c.numarTelefon << endl;
		out << c.numeTitular << endl;
		out << c.latime << endl;
		out << c.lungime << endl;
		return out;
	}

	//NICIODATA, DAR NICIODATA NU PRIMIM POINTERUL THIS IN FUNCTII FRIEND SAU FUNCTII STATICE!!!
	friend istream& operator>>(istream& in, CarteDeVizita& c) {
		//asa citim un char* cu nume compus;
		cout << "Introduceti numarul de telefon al titularului: ";
		if (c.numarTelefon != NULL) {
			delete[]c.numarTelefon;
		}
		char buffer[100];
		//in >> buffer;//asa citim pana la spatiu
		in >> ws;
		in.getline(buffer, 99);
		c.numarTelefon = new char[strlen(buffer) + 1];
		strcpy(c.numarTelefon, buffer);
		//asa citim un string cu nume compus
		cout << "Introduceti numele titularului: ";
		//in >> c.numeTitular;//asa citim pana la spatiu
		in >> ws;
		getline(in, c.numeTitular);

		//asa citim un numeric
		cout << "Introduceti latime: ";
		in >> c.latime;
		cout << "Introduceti lungime: ";
		in >> c.lungime;
		return in;
	}

	//OFSTREAM SI IFSTREAM SUNT DE FAPT OSTREAM SI ISTREAM FARA TEXTE ADITIONALE 
	//SI FARA ATRIBUTE STATICE SAU CONSTANTE!!!!!
	friend ofstream& operator<<(ofstream& out, const CarteDeVizita& c) {
		out << c.numarTelefon << endl;
		out << c.numeTitular << endl;
		out << c.latime << endl;
		out << c.lungime << endl;
		return out;
	}

	//NICIODATA, DAR NICIODATA NU PRIMIM POINTERUL THIS IN FUNCTII FRIEND SAU FUNCTII STATICE!!!
	friend ifstream& operator>>(ifstream& in, CarteDeVizita& c) {
		//asa citim un char* cu nume compus;
		if (c.numarTelefon != NULL) {
			delete[]c.numarTelefon;
		}
		char buffer[100];
		//in >> buffer;//asa citim pana la spatiu
		in >> ws;
		in.getline(buffer, 99);
		c.numarTelefon = new char[strlen(buffer) + 1];
		strcpy(c.numarTelefon, buffer);
		//asa citim un string cu nume compus
		//in >> c.numeTitular;//asa citim pana la spatiu
		in >> ws;
		getline(in, c.numeTitular);

		//asa citim un numeric
		in >> c.latime;
		in >> c.lungime;
		return in;
	}

	//obj==obj1
	bool operator ==(CarteDeVizita c) {
		//return (this->latime == c.latime && this->lungime == c.lungime&& this->latime == c.lungime && this->lungime == c.latime);
		//return (this->latime * this->lungime == c.lungime * c.latime);

		if (this->latime * this->lungime == c.lungime * c.latime) {
			return true;
		}
		else {
			return false;
		}
	}

	//
	explicit operator float() {
		return this->latime * this->lungime;
	}
};
//numar telefon -> 0721444555
int CarteDeVizita::numarator = 1;
string CarteDeVizita::material = "Plastic";

class Agentie {
	string nume;
	string adresa;
	int nrCartiVizita;
	CarteDeVizita* carti;//vector de obiecte de tip CarteDeVizita
public:
	Agentie() {
		this->nume = "X";
		this->adresa = "Y";
		this->nrCartiVizita = 0;
		this->carti = NULL;
	}

	Agentie(string nume, int nrCartiDeVizita) {
		this->nume = nume;
		this->adresa = "Y";
		this->nrCartiVizita = 2;
		this->carti =  new CarteDeVizita[this->nrCartiVizita];
	}

	Agentie(string nume, CarteDeVizita carte) {
		this->nume = nume;
		this->adresa = "Y";
		this->nrCartiVizita = 1;
		this->carti = new CarteDeVizita[this->nrCartiVizita];
		for (int i = 0; i < this->nrCartiVizita; i++) {
			this->carti[i] = carte;
		}
		//this->carti[0] = carte;
	}
	Agentie(string nume, string adresa, int nrCartiVizita, CarteDeVizita* carti) {
		this->nume = nume;
		this->adresa = adresa;
		this->nrCartiVizita = nrCartiVizita;
		this->carti = new CarteDeVizita[this->nrCartiVizita];
		for (int i = 0; i < this->nrCartiVizita; i++) {
			this->carti[i] = carti[i];
		}
	}
	
	Agentie(const Agentie& a) {
		this->nume = a.nume;
		this->adresa = a.adresa;
		this->nrCartiVizita = a.nrCartiVizita;
		this->carti = new CarteDeVizita[this->nrCartiVizita];
		for (int i = 0; i < this->nrCartiVizita; i++) {
			this->carti[i] = a.carti[i];
		}
	}

	~Agentie() {
		if (this->carti != NULL) {
			delete[]this->carti;
		}
	}

	Agentie& operator=(const Agentie& a) {
		if (this != &a) {
			if (this->carti != NULL) {
				delete[]this->carti;
			}
			this->nume = a.nume;
			this->adresa = a.adresa;
			this->nrCartiVizita = a.nrCartiVizita;
			this->carti = new CarteDeVizita[this->nrCartiVizita];
			for (int i = 0; i < this->nrCartiVizita; i++) {
				this->carti[i] = a.carti[i];
			}
			return *this;
		}
	}

	friend ostream& operator<<(ostream& out, const Agentie& a) {
		out << "=====================================" << endl;
		out << a.nume << endl;
		out << a.adresa << endl;
		out << a.nrCartiVizita << endl;
		out << "----------------------------------------" << endl;
		for (int i = 0; i < a.nrCartiVizita; i++) {
			out << a.carti[i] << endl;
		}
		out << "----------------------------------------" << endl;
		out << "=====================================" << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Agentie& a) {
		cout << "Nume:";
		getline(in, a.nume);
		cout << "Adresa:";
		getline(in, a.adresa);
		cout << "Nr Carti Vizita:";
		in >> a.nrCartiVizita;
		cout << "Carti Vizita:";
		if (a.carti != NULL) {
			delete[]a.carti;
		}
		a.carti = new CarteDeVizita[a.nrCartiVizita];
		for (int i = 0; i < a.nrCartiVizita; i++) {
			in >> a.carti[i];
		}

		return in;

	}

	void determinaMinSiMaxLungime() {
		float min = this->carti[0].getLungime();
		float maxim = this->carti[0].getLungime();
		for (int i = 0; i < this->nrCartiVizita; i++)
		{
			if (min > this->carti[i].getLungime()) {
				min = this->carti[i].getLungime();
			}

			if (maxim < this->carti[i].getLungime()) {
				maxim = this->carti[i].getLungime();
			}
		}

		cout << "Valoarea minima a lungimii este de : " << min << ", iar lungimea maxima este de : " << maxim << endl;
	}
};
int main() {
	
	CarteDeVizita c;//obiect creat pe baza constructorului fara parametri
	cout << c.getLatime() << endl;//10
	c.setLatime(50);
	cout << c.getLatime() << endl;//50
	c.setLatime(8);
	cout << c.getLatime() << endl;//50

	cout << c.getNumarTelefon() << endl;
	c.setNumarTelefon("0734511231");

	try {
		c.setNumarTelefon("072312311");
		cout << c.getNumarTelefon() << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	catch (exception* ex) {
		cout << "Vezi ca ai aruncat o exceptie pointer!";
	}
	catch (...) {
		cout << "Ai o eroare tu pe undeva!" << endl;
	}

	cout << endl << endl;
	CarteDeVizita c1("TDX","0723412345","Tudorel",25,25);//obiect creat pe baza constructorului cu toti parametri
	//CarteDeVizita c1("0723412345","Tudorel");//obiect creat pe baza constructorului cu doi parametri
	cout << c1.getNumarTelefon() << endl;
	cout << c1.getLatime() << endl;

	cout << endl << endl;
	CarteDeVizita c2 = c;//apelam constructorul de copiere
	//CarteDeVizita c3(c);//tot constructor de copiere
	cout << c2.getNumarTelefon() << endl;
	cout << c2.getLatime() << endl;
	cout << endl << endl;
	//operator =
	c2 = c1;
	cout << c2.getNumarTelefon() << endl;
	cout << c2.getLatime() << endl;
	cout << endl << endl;
	c2 = c1;

	c2 = c2;
	cout << c2.getNumarTelefon() << endl;//0723412345
	cout << c2.getLatime() << endl;//25

	cout << endl << endl;
	cout << c2 << endl;

	cout << endl << endl;
	cout << (c1 == c1) << endl;
	if (c1 == c1) {
		cout << "Obiectele au aceeasi suprafata!" << endl;
	}
	else {
		cout << "Obiectele nu au aceeasi suprafata!" << endl;
	}
	cout << (c1 == c) << endl;
	if (c1 == c) {
		cout << "Obiectele au aceeasi suprafata!" << endl;
	}
	else {
		cout << "Obiectele nu au aceeasi suprafata!" << endl;
	}
	cout << endl << endl;
	cout << (float)c2 << endl;
	cout << c2 << endl;

	cout << endl << endl;
	/*cin >> c2;
	
	cout << endl;
	cout << c2 << endl;*/

	cout << endl << endl;
	ofstream f("carteDeVizita.txt", ios::out);
	f << c2 << endl;
	cout << "Obiectul a fost exportat in fisier!" << endl;
	f.close();
	cout << endl << endl;
	//citirea din fisier
	CarteDeVizita c4;
	cout << c4 << endl;
	ifstream g("carteDeVizita.txt", ios::in);
	if (g.is_open()) {
		g >> c4;
		g.close();
	}
	else {
		cout << "Fisierul cautat nu exista!" << endl;
	}

	cout << c4 << endl;

	cout << endl<<endl<<endl<<endl;
	CarteDeVizita cv("TX","0723412345", "Alexandra F", 13, 13);//obiect creat pe baza constructorului cu toti parametri
	CarteDeVizita cv1("FAX", "0753412345", "Alex Mi", 12, 15);//obiect creat pe baza constructorului cu toti parametri
	CarteDeVizita cv2("AF", "0763442345", "Ionut A", 55, 16);//obiect creat pe baza constructorului cu toti parametri
	CarteDeVizita cv3("HF", "0753412345", "Maria L", 11, 17);//obiect creat pe baza constructorului cu toti parametri
	CarteDeVizita cv4("RE", "0725412345", "Bogdan P", 14, 12);//obiect creat pe baza constructorului cu toti parametri


	Agentie a;
	cout << a << endl<<endl;

	CarteDeVizita* cartiVec = new CarteDeVizita[5];
	cartiVec[0] = cv;
	cartiVec[1] = cv1;
	cartiVec[2] = cv2;
	cartiVec[3] = cv3;
	cartiVec[4] = cv4;

	Agentie a1("XL Media", "Strada Luminii, nr.14", 5, cartiVec);
	cout << a1 << endl << endl;

	cout << a1 << endl << endl;

	a1.determinaMinSiMaxLungime();
	return 0;
	Agentie a2 = a;//constructor de copiere

	cout << a2 << endl << endl;

	a2 = a1;//op =

	cout << a2 << endl << endl;

	cout << endl << endl << endl;
	Agentie a3("Agentie Test", 2);
	cout << a3 << endl << endl;
	cout << endl << endl << endl;
	Agentie a4("Agentie Cu o Carte", cv1);
	cout << cv1 << endl << endl;
	cout << a4 << endl << endl;
	cout << endl << endl << endl << endl;

	cout << a << endl;
	cin >> a;
	cout << endl << endl;
	cout << a << endl << endl;
	//STL
	return 0;
	vector<CarteDeVizita> vectCartiSTL;
	//ca sa adaugam in vector STL
	vectCartiSTL.push_back(cv);
	vectCartiSTL.push_back(cv1);
	vectCartiSTL.push_back(cv2);
	vectCartiSTL.push_back(cv3);
	vectCartiSTL.push_back(cv4);
	//cum le parcurgem

	float lungimeTotala = 0;
	float maxim = vectCartiSTL[0].getLungime();
	for (int i = 0; i < vectCartiSTL.size(); i++) {
		lungimeTotala += vectCartiSTL[i].getLungime();
		if (maxim < vectCartiSTL[i].getLungime()) {
			maxim = vectCartiSTL[i].getLungime();
		}
	}

	cout << "Lungimea totala a cartilor de vizita este: " << lungimeTotala << endl;
	cout << "Lungimea maxima a unei carti de vizita este: " << maxim << endl;

}
