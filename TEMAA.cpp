
//domeniu: VAPOR






#include <iostream>
#include <string>
using namespace std;



class Nava {
public:
	string nume;
	static int tonaj;
	const int anLansare;
	char* companie;


	Nava() : anLansare(1962)
	{
		this->nume = "Speranta";
		this->companie = new char[strlen("Costa") + 1];
		strcpy_s(this->companie, strlen("Costa") + 1, "Costa");
	}

	Nava(string nume, const int anLansare, const char* companie) : anLansare(anLansare)
	{
		this->nume = nume;
		this->companie = new char[strlen(companie) + 1];
			strcpy_s(this->companie, strlen(companie) + 1, companie);
	}

	Nava(string nume) :Nava() 
	{
		this->nume = nume;
	}

	static int getLungimeNumeCompanie(char* companie) {
	int lung = strlen(companie);
		return lung;
	}
	
	void afisare()
	{
		cout << "Nume vapor = " << this->nume << "\n Tonaj = " << this->tonaj << "\n An lansare = " << this->anLansare << "\n Companie:" << this->companie << endl;
	}
	

};

int Nava::tonaj = 5000;

class Motor {
public:
	string producator;
	const string motorizare ;
	static string materialCarena;
	int nrRevizii;
	int* anRevizie;


	Motor() :motorizare("Diesel") {
		this->producator = "MAN";
		this->nrRevizii = 3;
		this->anRevizie = new int[this->nrRevizii];
		for (int i = 0;i < this->nrRevizii;i++) {
			this->anRevizie[i] = 2000 + i * 4;
		};
	}

	Motor(string producator) :Motor() {
		this->producator = producator;
	}
	


	Motor(string producator,const string motor, int nrRevizii, int* anRevizie) :motorizare(motor) {
		this->producator = producator;
		this->nrRevizii = nrRevizii;
		this->anRevizie = new int[nrRevizii];
		for (int i = 0;i < nrRevizii; i++) {
			this->anRevizie[i] = anRevizie[i];
		}
	}

	static int aniDeLaUltimaRevizie(int nrRev, int* anRev) 
	{
		int ani =2023 - anRev[nrRev - 1];
		return ani;
	}


	void afisare()
	{
		cout << "Producator = " << this->producator << "\n Motorizare = " << this->motorizare << "\n Material carena = " << this->materialCarena << "\n Nr revizii:" << this->nrRevizii << endl;
		for (int i = 0; i < this->nrRevizii;i++) {
			cout << this->anRevizie[i] << ", "<<endl;
		}
	}
	/*
	static  getLungimeNumeCompanie(Nava* companie) {
		return strlen(companie);
	}
	*/
};


string Motor::materialCarena = "Otel";

class Container {
public:
	string companie;
	const float greutateCutii;
	static int lungime;
	static int latime;
	static int inaltime;
	int nrProduse;
	string* produse;



	Container() :greutateCutii(1500)
	{
		this->companie = "Fedex";
		this->nrProduse = 3;
		this->produse = new string[nrProduse];
		for (int i = 0;i < nrProduse; i++) {
			this->produse[i] = "Container " + to_string(i);
		}
	}

	Container(string companie, const float greutate, int nrProduse, string* produse) :greutateCutii(greutate)
	{
		this->companie = companie;
		this->nrProduse = nrProduse;
		this->produse = new string[nrProduse];
		for (int i = 0;i < nrProduse; i++) {
			this->produse[i] = produse[i];
		}
	}

	Container(string companie): Container() {
		this->companie = companie;
	}

	static int getVolumContainer(int lung, int lat, int inalt)
	{
		int vol = lung * lat * inalt;
		return vol;
	
	}

	void afisare()
	{
		cout << "Companie = " << this->companie << "\n Greutate = " << this->greutateCutii << "\n Lungime = " << this->lungime << "\n Latime = " << this->latime << "\n Inaltime = " << this->inaltime<< "\n Nr revizii:" << this->nrProduse<< endl;
		for (int i = 0; i < this->nrProduse;i++) {
			cout << this->produse[i] << ", " << endl;
		}
	}
};
int Container::lungime = 10;
int Container::latime = 4;
int Container::inaltime = 3;

void main()
{
	
	Motor motor1;
	motor1.afisare();

	int* anReviz = new int[3];
	for (int i = 0;i < 3; i++) 
		anReviz[i] = 1985 + i * 4;
	

	Motor motor2("Ford", "electric", 3, anReviz);
	motor2.afisare();

	

	Motor motor3("Damen");
	motor3.afisare();
	cout<<Motor::aniDeLaUltimaRevizie(motor3.nrRevizii, motor3.anRevizie)<<endl;
	



	
	Container container1;
	container1.afisare();

	string prod[] = { "mere", "cartofi","unelte" };

	Container container2("DHL", 200 , 3 , prod);
	container2.afisare();
	


	Container container3("UPS");
	container3.afisare();
	
	cout << Container::getVolumContainer(container3.lungime, container3.latime, container3.inaltime)<<endl;


	Nava nava1;
	nava1.afisare();


	Nava nava2("Titanic", 2000, "Odyssy");
	nava2.afisare();

	Nava nava3("Bombardierul Cruiser");
	nava3.afisare();
 
    cout<<Nava::getLungimeNumeCompanie(nava3.companie);
	
};