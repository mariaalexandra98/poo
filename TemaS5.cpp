#include "pch.h"
#include <iostream>
using namespace std;
class Produs {
private:
	const int id;
	char* nume;
	float pret;
	char unitateMasura[10];
	static int nr_produse;
public:
	Produs();
	Produs(int id, char* nume, float pret, char unitateMasura[10]);
	Produs(const Produs& copie);
	~Produs();
	int getId();
	void setNume(char* v_nume);
	char* getNume();
	void setPret(float v_pret);
	float getPret();
	void setUnitateMasura(char v_unitateMasura[10]);
	char* getUnitateMasura();
	Produs& operator=(const Produs& produs);
	friend ostream& operator<<(ostream& out, Produs& produs);
	friend istream& operator>>(istream& in, Produs& produs);
};
int Produs::nr_produse = 0;

Produs::Produs():id(1) {
	this->nume = new char[strlen("Anonim") + 1];
	strcpy(this->nume, "Anonim");
	float pret = 10;
	strcpy(this->unitateMasura, "grame");
	Produs::nr_produse++;
}
Produs::Produs(int id, char* nume, float pret, char unitateMasura[10]):id(id) {
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
	this->pret = pret;
	strcpy(this->unitateMasura, unitateMasura);
	Produs::nr_produse++;
}
Produs::Produs(const Produs& copie):id(copie.id) {
	if(copie.nume!=NULL){
		this->nume = new char[strlen(copie.nume) + 1];
		strcpy(this->nume, copie.nume);
	}
	this->pret = copie.pret;
	strcpy(this->unitateMasura, copie.unitateMasura);
	Produs::nr_produse++;
}

Produs::~Produs() {
	if (this->nume != NULL) {
		delete[] this->nume;
	}
}

int Produs::getId() {
	return this->id;
}
void Produs::setNume(char* v_nume) {
	if (v_nume != NULL) {
		if (this->nume != NULL) {
			delete[] this->nume;
		}
		this->nume = new char[strlen(v_nume) + 1];
		strcpy(this->nume, v_nume);
	}
}

char* Produs::getNume() {
	return this->nume;
}

void Produs::setPret(float v_pret) {
	if (v_pret != NULL) {
		this->pret = v_pret;
	}
}

float Produs::getPret() {
	return this->pret;
}
void Produs::setUnitateMasura(char v_unitateMasura[10]) {
	if (v_unitateMasura != NULL) {
		strcpy(this->unitateMasura, v_unitateMasura);
	}
}
char* Produs::getUnitateMasura() {
	return this->unitateMasura;
}
 Produs& Produs::operator=(const Produs& produs) {
	 if (this->nume != NULL)
	 {
		 delete[] this->nume;
	 }
	 if (produs.nume != NULL) {
		 this->nume = new char[strlen(produs.nume) + 1];
		 strcpy(this->nume, produs.nume);
	 }
	 this->pret = produs.pret;
	 strcpy(this->unitateMasura, produs.unitateMasura);
	 return *this;
}
 ostream& operator<<(ostream& out, Produs& produs) {
	 out << "Id: " << produs.id << endl;
	 out << "Afisare nume: " << produs.nume << endl;
	 out << "Pret: " << produs.pret << endl;
	 out << "Unitate masura" << produs.unitateMasura << endl;
	out << "Numar produs: " << produs.nr_produse << endl;
	 return out;

 }

 istream& operator>>(istream& in, Produs& produs) {

	 char buff[50];
	 in.getline(buff, 50);
	 cout << "Nume: ";
	 in >> produs.nume;
	 if (produs.nume != NULL) {
		 delete[] produs.nume;
	 }
	 produs.nume = new char[strlen(buff) + 1];
	 strcpy(produs.nume, buff);
	 cout << endl;
	 cout << "Pret: ";
	 in >> produs.pret;
	 cout << endl;
	 cout << "Unitate masura: ";
	 in >> produs.unitateMasura;
	 cout << endl;
	 cout << "Numar produs: ";
	 in >> Produs::nr_produse;
	 return in;
 }

 void main(){
 }
 