
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Mesaj {
	const int numarMesaj;
	string adresa;
	char* mesaj;
	float* dimensiuneFisierAtasat;
	float dimensiuneMesaj;
	unsigned int nrFisiere;
	bool citit;
	static int numar;
public:
	Mesaj();
	Mesaj(char adresa[50]);
	Mesaj(string adresa, char* mesaj, float* dimensiuneFisier, int nrFisiere, float dimensiuneMesaj, bool citit);
	Mesaj(int numarMesaj, string adresa, char* mesaj);

	void setNumarMesaj(int numarMesaj);
	int getNumarMesaj();
	void setAdresa(string adresa);
	string getAdresa();
	void setMesaj(char* mesaj);
	char* getMesaj();
	void setDimensiune(float* dimensiune);
	float* getDimensiune();
	void setNrFisiere(int nrFisiere);
	int getNrFisiere();
	void setCitit(bool citit);
	bool getCitit();
	void setDimensiuneMesaj(float dimensiuneMesaj);
	float getDimensiuneMesaj();

	Mesaj(const Mesaj& m);
	void afisare();


	Mesaj& operator=(const Mesaj& m);
	friend ostream& operator<<(ostream& out, Mesaj& m);
	friend istream& operator>>(istream& in, Mesaj m);

	// supraincarcarea operatorilor: [], ++ (pre si post), --(pre si post), +=, <,>, ==, >=, <=, !, (), cast, +, - 
	float& operator[](int index);
	bool operator<(Mesaj& m);
	bool operator>(Mesaj& m);
	bool operator==(Mesaj& m);
	bool operator<=(Mesaj& m);
	bool operator>=(Mesaj& m);
	bool operator!();
	float operator()();
	operator int();
	Mesaj operator++(int);
	Mesaj& operator++();
	Mesaj operator +=(float x);
	Mesaj operator-(int y);
	Mesaj operator+(float x);
};
int Mesaj::numar = 0;
Mesaj::Mesaj() :numarMesaj(numar) {
	this->mesaj = new char[strlen("null") + 1];
	strcpy(this->mesaj, "NULL");
	this->adresa = "NULL";
	this->nrFisiere = 0;
	this->dimensiuneFisierAtasat = 0;
	this->dimensiuneMesaj = 0;
	this->citit = false;
	numar++;
}
Mesaj::Mesaj(string adresa, char* mesaj, float* dimensiuneFisier, int nrFisiere, float dimensiuneMesaj, bool citit) :numarMesaj(numar) {

	if (this->dimensiuneFisierAtasat != NULL) {
		delete[] this->dimensiuneFisierAtasat;
	}
	if (this->mesaj != NULL) {
		delete[] this->mesaj;
	}
	if (adresa.length() > 0) {
		this->adresa = adresa;
	}
	if (mesaj) {
		this->mesaj = new char[strlen(mesaj) + 1];
		strcpy(this->mesaj, mesaj);
	}
	if (nrFisiere > 0) {
		this->nrFisiere = nrFisiere;
	}
	if (dimensiuneFisier) {
		this->dimensiuneFisierAtasat = new float[this->nrFisiere];
		for (int i = 0; i < this->nrFisiere; i++) {
			this->dimensiuneFisierAtasat[i] = dimensiuneFisier[i];
		}
	}
	this->dimensiuneMesaj = dimensiuneMesaj;
	this->citit = citit;
	numar++;
}

//Mesaj::Mesaj(int numarMesaj, string adresa, char* mesaj) :numarMesaj(numar) {
//	if (this->mesaj != NULL) {
//		delete[] this->mesaj;
//	}
//	this->mesaj = new char[strlen(mesaj)+1];
//	strcpy(this->mesaj, mesaj);
//	this->adresa = adresa;
//}
Mesaj::Mesaj(const Mesaj& m) :numarMesaj(m.numar++) {
	if (m.mesaj) {
		this->mesaj = new char[strlen(m.mesaj) + 1];
		strcpy(this->mesaj, m.mesaj);
	}
	if (m.dimensiuneMesaj) {
		this->dimensiuneMesaj = m.dimensiuneMesaj;
	}
	if (m.adresa.length() > 0) {
		this->adresa = m.adresa;
	}
	if (m.nrFisiere) {
		this->nrFisiere = m.nrFisiere;
	}
	if (m.dimensiuneFisierAtasat) {
		this->dimensiuneFisierAtasat = new float[this->nrFisiere];
		for (int i = 0; i < this->nrFisiere; i++) {
			this->dimensiuneFisierAtasat[i] = m.dimensiuneFisierAtasat[i];
		}
	}
	this->citit = m.citit;
	numar++;

}
void Mesaj::afisare() {
	cout << "Mesajul numarul: " << this->numarMesaj << endl;
	if (this->citit == true) {
		cout << "Mesajul a fost citit" << endl;
	}
	else {
		cout << "Mesajul nu a fost citit" << endl;
	}
	cout << "Adresa: " << this->adresa << endl;
	cout << "Mesajul este: " << this->mesaj << endl;
	cout << "Dimensiunea mesajului este: " << this->dimensiuneMesaj << endl;
	cout << "Numarul fisierelor este: " << this->nrFisiere << endl;
	cout << "Dimensiunea fisierelor este atasate: " << endl;
	for (int j = 0; j < this->nrFisiere; j++) {
		cout << this->dimensiuneFisierAtasat[j] << endl;
	}
}

Mesaj& Mesaj::operator=(const Mesaj& m) {
		delete[] this->mesaj;
		delete[] this->dimensiuneFisierAtasat;
	if (m.mesaj) {
		this->mesaj = new char[strlen(m.mesaj) + 1];
		strcpy(this->mesaj, m.mesaj);
	}
	if (m.dimensiuneMesaj) {
		this->dimensiuneMesaj = m.dimensiuneMesaj;
	}
	if (m.adresa.length() > 0) {
		this->adresa = m.adresa;
	}
	if (m.nrFisiere) {
		this->nrFisiere = m.nrFisiere;
	}
	if (m.dimensiuneFisierAtasat) {
		this->dimensiuneFisierAtasat = new float[this->nrFisiere];
		for (int i = 0; i < this->nrFisiere; i++) {
			this->dimensiuneFisierAtasat[i] = m.dimensiuneFisierAtasat[i];
		}
	}
	this->citit = m.citit;
	return *this;

}
void Mesaj::setNumarMesaj(int numarMesaj) {
	this->numar = numarMesaj;
}
int Mesaj::getNumarMesaj() {
	return this->numarMesaj;
}
void Mesaj::setAdresa(string adresa) {
	this->adresa = adresa;
}
string Mesaj::getAdresa() {
	return this->adresa;
}
void Mesaj::setMesaj(char* mesaj) {
	if (this->mesaj != NULL) {
		delete[] this->mesaj;
	}
	this->mesaj = new char[strlen(mesaj) + 1];
	strcpy(this->mesaj, mesaj);
}
char* Mesaj::getMesaj() {
	return this->mesaj;
}
void Mesaj::setNrFisiere(int nrFisiere) {
	this->nrFisiere = nrFisiere;
}
int Mesaj::getNrFisiere() {
	return this->nrFisiere;
}
void Mesaj::setDimensiune(float* dimensiune) {
	this->dimensiuneFisierAtasat = dimensiune;
}
float* Mesaj::getDimensiune() {
	return this->dimensiuneFisierAtasat;
}

void Mesaj::setCitit(bool citit) {
	this->citit = citit;
}
bool Mesaj::getCitit() {
	return this->citit;
}
void Mesaj::setDimensiuneMesaj(float dimensiuneMesaj) {
	this->dimensiuneMesaj = dimensiuneMesaj;
}
float Mesaj::getDimensiuneMesaj() {
	return this->dimensiuneMesaj;
}
ostream& operator<<(ostream& out, Mesaj& m) {
	out << "Afisare: " << endl;
	out << "Numarul mesajului este: " << m.numarMesaj << endl;
	out << "Statusul mesajului este: ";
	if (m.citit == true) {
		out << "citit" << endl;
	}
	else {
		out << "necitit" << endl;
	}
	out << "Adresa de e-mail a destinatarului este: " << m.adresa << endl;
	out << "Mesajul primit este: " << m.mesaj << endl;
	out << "Dimensiunea mesajului este: " << m.dimensiuneMesaj << endl;
	out << "Numarul fisierelor primite este: " << m.nrFisiere << endl;
	out << "Dimensiunea fisierelor atasate este: " << endl;
	for (int i = 0; i < m.nrFisiere; i++) {
		out << m.dimensiuneFisierAtasat[i] << endl;
	}
	return out;
}
// istream& operator>>(istream& in, Mesaj m) {
//	 if (m.mesaj != NULL) {
//		 delete[] m.mesaj;
//	 }
//	 if (m.dimensiuneFisierAtasat != NULL) {
//		 delete[] m.dimensiuneFisierAtasat;
//	 }
//	 cout << "Introducere valori: " << endl;
//	 cout << "Numarul mesajului: ";
//	 in >> m.numar;
//	 cout << "Statusul mesajului: ";
//	 in >> m.citit;
//	 cout << "Adresa de e-mail a destinatarului: ";
//	 in >> m.adresa;
//	 cout << "Numarul fisierelor primite: ";
//	 in >> m.nrFisiere;
//	 cout << "Dimensiunea fisierelor atasate: ";
//	 m.dimensiuneFisierAtasat = new float[m.nrFisiere];
//	 for (int i = 0; i < m.nrFisiere; i++) {
//		 in >> m.dimensiuneFisierAtasat[i];
//	 }
//	 return in;
//}
float& Mesaj::operator[](int index) {
	if (index != NULL && this->dimensiuneFisierAtasat != NULL)
		return this->dimensiuneFisierAtasat[index];
}
Mesaj& Mesaj::operator++() {
	this->dimensiuneMesaj++;
	return *this;
}
Mesaj Mesaj::operator++(int) {
	Mesaj m = *this;
	m.dimensiuneMesaj++;
	return m;
}
float Mesaj::operator()() {
	float dimensiuneTotalaFisiere = 0;
	if (this->nrFisiere > 0 && this->dimensiuneFisierAtasat != NULL) {
		for (int i = 0; i < this->nrFisiere; i++) {
			dimensiuneTotalaFisiere = dimensiuneTotalaFisiere + this->dimensiuneFisierAtasat[i];
		}
	}
	return dimensiuneTotalaFisiere;
}
bool Mesaj::operator<(Mesaj& m) {
	if (this->dimensiuneMesaj < m.dimensiuneMesaj) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Mesaj::operator>(Mesaj& m) {
	if (strlen(this->mesaj) > strlen(m.mesaj)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Mesaj::operator==(Mesaj& m) {
	if (this->adresa == m.adresa) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Mesaj::operator<=(Mesaj& m) {
	if (this->nrFisiere <= m.nrFisiere) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Mesaj::operator>=(Mesaj& m) {
	float dimensiune1 = 0;
	float dimensiune2 = 0;
	for (int i = 0; i < this->nrFisiere; i++) {
		dimensiune1 = dimensiune1 + this->dimensiuneFisierAtasat[i];
	}
	for (int j = 0; j < m.nrFisiere; j++) {
		dimensiune2 = dimensiune2 + this->dimensiuneFisierAtasat[j];
	}
	if (dimensiune1 >= dimensiune2) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Mesaj::operator!() {
	if (this->citit != NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
Mesaj::operator int() {
	return this->dimensiuneMesaj;
}
Mesaj Mesaj::operator +=(float x) {
	Mesaj m = *this;
	if (this->dimensiuneFisierAtasat != NULL) {
		delete[] this->dimensiuneFisierAtasat;
	}
	this->nrFisiere = m.nrFisiere + 1;
	this->dimensiuneFisierAtasat = new float[this->nrFisiere];
	for (int i = 0; i < m.nrFisiere; i++) {
		this->dimensiuneFisierAtasat[i] = m.dimensiuneFisierAtasat[i];
	}
	this->dimensiuneFisierAtasat[m.nrFisiere] = x;
	this->dimensiuneMesaj = this->dimensiuneMesaj + x;
	return *this;
}

Mesaj Mesaj::operator-(int y) {
	Mesaj m = *this;
	float s = 0;
	float* array = new float[m.nrFisiere - y];
	for (int i = 0; i < m.nrFisiere - y; i++) {
		array[i] = m.dimensiuneFisierAtasat[i];
	}
	m.nrFisiere = m.nrFisiere - y;
	delete[] m.dimensiuneFisierAtasat;
	m.dimensiuneFisierAtasat = new float[m.nrFisiere];
	for (int j = 0; j < m.nrFisiere; j++) {
		m.dimensiuneFisierAtasat[j] = array[j];
	}
	return m;
}

	/*this->dimensiuneFisierAtasat = new float[m.nrFisiere];
	for (int i = 0; i < this->nrFisiere; i++) {

		this->dimensiuneFisierAtasat[i] = m.dimensiuneFisierAtasat[i];
	}
	for (int j = this->nrFisiere; j < m.nrFisiere; j++) {
		this->dimensiuneFisierAtasat[j] = m.dimensiuneFisierAtasat[j];
		s = s + this->dimensiuneFisierAtasat[j];
	}
	this->dimensiuneMesaj = this->dimensiuneMesaj - s;
	return *this;*/



Mesaj Mesaj::operator+(float x) {
	Mesaj m = *this;
	float* array = new float[m.nrFisiere + 1];
	for (int i = 0; i < m.nrFisiere; i++) {
		array[i] = m.dimensiuneFisierAtasat[i];
	}
	array[m.nrFisiere] = x;
	m.nrFisiere++;
	delete[] m.dimensiuneFisierAtasat;
	m.dimensiuneFisierAtasat = new float[m.nrFisiere];
	for (int j = 0; j < m.nrFisiere; j++) {
		m.dimensiuneFisierAtasat[j] = array[j];
	}
	return m;

}

int main() {
	Mesaj m;
	m.afisare();
	cout << endl;
	char aux[50] = "Buna! Ce faci?";
	strcpy(aux, "Buna! Ce faci?");
	char buff[50] = "Buna ziua! Numele meu este Ionescu Vasile.";
	strcpy(buff, "Buna ziua! Numele meu este Ionescu Vasile.");
	char buff1[50] = "Salut! Eu sunt Oana.";
	float fisiere[2]{ 1.5 ,3.2 };
	float fisiere1[4]{ 0.2, 0.6, 0.8, 1.3 };
	float fisiere2[6]{ 0.4, 1.8, 1.4, 1.4, 0.3, 0.9 };
	Mesaj m1("dan.coman@yahoo.com", aux, fisiere, 2, 2.4, true);
	Mesaj m2("ana.popescu@gmai.com", aux, fisiere, 2, 4.3, false);
	Mesaj m3("vasile.ionescu@yahoo.com", buff, fisiere1, 4, 6.3, true);
	Mesaj m4("oana.banana@gmail.com", buff1, fisiere2, 6, 8.4, false);
	m1.afisare();

	cout << "Getter adresa: " << m1.getAdresa() << endl;
	cout << "Getter citit: " << m1.getCitit() << endl;
	cout << "Getter dimensiune fisier/fisiere atasat/atasate: " << m1.getDimensiune() << endl;
	cout << "Getter mesaje: " << m1.getMesaj() << endl;
	cout << "Getter dimensiune mesaj: " << m1.getDimensiuneMesaj() << endl;
	cout << "Getter numar fisiere: " << m1.getNrFisiere() << endl;
	cout << "Getter numar mesaje: " << m1.getNumarMesaj() << endl;

	float var[5] = { 0.5, 0.6, 1.3, 0.9, 1.7 };
	m1.setNrFisiere(5);
	m1.setDimensiune(var);
	m1.setAdresa("popa.ion@gmail.com");
	m1.setNumarMesaj(4);
	m1.setCitit(true);
	m1.setDimensiuneMesaj(2.);
	char auxiliar[50];
	strcpy(auxiliar, "Salut ca buna esti deja!");
	m1.setMesaj(auxiliar);
	cout << endl;

	m1.setNumarMesaj(10);
	cout << m1.getNumarMesaj();



	m1[2] = 6;
	cout << m1;
	cout << m3 << endl;
	m3 = ++m2;
	m4 = ++m3;


	float dimensiuneFisiereTotala = m2();
	cout << m2 << endl;
	cout << dimensiuneFisiereTotala << endl;

	if (m2 < m1) {
		cout << "M1 are un mesaj mai lung decat m2." << endl;
	}
	else {
		cout << "M2 are un mesaj mai lung decat m1." << endl;
	}
	if (m3 > m1) {
		cout << "Mesajul m3 are o lungime mai mare decat m1." << endl;
	}
	else {
		cout << "Mesajul m1 are o lungime mai mare decat m3." << endl;
	}
	if (m1 == m2) {
		cout << "Adresele m1 si m2 coincid." << endl;
	}
	else {
		cout << "Adresele m1 si m2 nu coincid." << endl;
	}
	if (m3 <= m2) {
		cout << "Numarul de fisiere din m2 este mai mic sau egal cu numarul de fisiere din m3." << endl;
	}
	else {
		cout << "Numarul de fisiere din m3 este mai mic sau egal cu numarul de fisiere din m2." << endl;
	}
	if (m4 >= m3) {
		cout << "Dimesiunea fisierelor din m4 este mai mare sau egala decat dimensiunea fisierelor din m3." << endl;
	}
	else {
		cout << "Dimensiunea fisierelor din m3 este mai mare sau egala decat dimensiunea fisierelor din m4." << endl;
	}
	if (!m) {
		cout << "Mesajul este citit." << endl;
	}
	else {
		cout << "Mesajul nu este citit." << endl;
	}
	int dimMesajm4 = (m4);
	cout << dimMesajm4 << endl;
	m2 += 2.5;
	cout << m2 << endl;
	cout << m4 << endl <<m2<< endl;
	m2 = m4 - 2;
	cout << m4 << endl<<m2;

}