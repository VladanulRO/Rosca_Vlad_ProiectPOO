
//domeniu: VAPOR






#include <iostream>
#include <string>
using namespace std;



class Nava {
private:
	string nume;
	static int tonaj;
	const int anLansare;
	char* companie;
public:

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

	//Getteri ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	string getNume()
	{
		return nume;
	}

	int getAnLansare()
	{
		return anLansare;
	}

	char* getCompanie()
	{
		if (companie != nullptr)
		{
			char* comp = new char[strlen(companie) + 1];
			strcpy_s(comp, strlen(companie) + 1, companie);
			return comp;
		}
		else
		{
			return nullptr;
		}
	}

	static int getTonaj()
	{
		return tonaj;
	}

	//Setteri~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void setNume(string nume)
	{
		if (nume.length() > 3)
			this->nume = nume;;
	}

	void setCompanie(char* companie)
	{
		if (companie != nullptr)
		{
			delete[]this->companie;
			this->companie = new char[strlen(companie) + 1];
			strcpy_s(this->companie, strlen(companie) + 1, companie);
		}
	}

	static void setTonaj(int tonaj)
	{
		if (tonaj > 0)
			Nava::tonaj = tonaj;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	

	//copiere si destructor~~~~~~~~~~~~~~~~~~

	Nava(const Nava& nava) :anLansare(nava.anLansare) 
	{
		this->nume = nava.nume;
		this->companie = new char[strlen(nava.companie) + 1];
		strcpy_s(this->companie, strlen(nava.companie) + 1, nava.companie);

	}

	~Nava()
	{
		if (this->companie != NULL)
		{
			delete[]this->companie;
		}
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	static int getLungimeNumeCompanie(char* companie) {
	int lung = strlen(companie);
		return lung;
	}
	
	void afisare()
	{
		cout << "Nume vapor = " << this->nume << "\n Tonaj = " << this->tonaj << "\n An lansare = " << this->anLansare << "\n Companie:" << this->companie << endl;
	}
	
	friend void varstaNava(const Nava& nava);
};

int Nava::tonaj = 5000;

class Motor {
private:
	string producator;
	const string motorizare ;
	static string culoareMotor;
	int nrRevizii;
	int* anRevizie;

public:

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

	//Getteri ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	string getProducator()
	{
		return producator;
	}

	string getMotorizare()
	{
		return motorizare;
	}

	int getNrRevizii()
	{
		return nrRevizii;
	}

	int* getAnRevizie()
	{
		if (anRevizie != nullptr && nrRevizii > 0)
		{
			int* anRev = new int[nrRevizii];
			for (int i = 0; i < nrRevizii; i++)
			{
				anRev[i] = anRevizie[i];
			}
			return anRev;
		}
		else
		{
			return nullptr;
		}
	}

	static string getCuloareMotor()
	{
		return culoareMotor;
	}

	//Setteri~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	void setProducator(string producator)
	{
		if (producator.length() > 3)
		{
			this->producator = producator;
		}
	}

	void setNrRevizii(int nrRevizii)
	{
		if (nrRevizii != 0)
		{
			this->nrRevizii = nrRevizii;
		}
	}

	void setAnRevizie(int  nrRevizii ,int* anRevizie)
	{
		if (anRevizie != nullptr && nrRevizii > 0)
		{
			if (this->anRevizie != nullptr)
			{
				delete[]this->anRevizie;
			}
			this->anRevizie = new int[nrRevizii];
			for (int i = 0; i < nrRevizii; i++)
				this->anRevizie[i] = anRevizie[i];
			this->nrRevizii = nrRevizii;
		}
	}

	static void setCuloareMotor(string culoareMotor)
	{
		if (culoareMotor.length() > 3)
		{
			Motor::culoareMotor = culoareMotor;
		}
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//copiere si destructor~~~~~~~~~~~~~~~~~~

	Motor(const Motor& motor) :motorizare(motor.motorizare)
	{
		this->producator = motor.producator;
		this->nrRevizii = motor.nrRevizii;
		this->anRevizie = new int[motor.nrRevizii];
		for (int i = 0; i < motor.nrRevizii; i++)
		{
			this->anRevizie[i] = motor.anRevizie[i];
		}
	}

	~Motor()
	{
		if (this->anRevizie != NULL)
		{
			delete[]this->anRevizie;
			this->anRevizie = NULL;
		}
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	static int aniDeLaUltimaRevizie(int nrRev, int* anRev) 
	{
		int ani =2023 - anRev[nrRev - 1];
		return ani;
	}


	void afisare()
	{
		cout << "Producator = " << this->producator << "\n Motorizare = " << this->motorizare << "\n Material carena = " << this->culoareMotor << "\n Nr revizii:" << this->nrRevizii << endl;
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


string Motor::culoareMotor = "Gri";

class Container {
private:
	string companie;
	const float greutateCutii;
	static int lungime;
	static int latime;
	static int inaltime;
	int nrProduse;
	string* produse;
public:


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

	//Getteri si setteri~~~~~~~~~~~~~~~~~~~~~

	string getCompanie()
	{
		return companie;
	}

	float getGreutateCutii()
	{
		return greutateCutii;
	}

	int getNrProduse()
	{
		return nrProduse;
	}

	string* getProduse()
	{
		if (produse != nullptr && nrProduse > 0)
		{
			string* prod = new string[nrProduse];
			for (int i = 0; i < nrProduse; i++)
			{
				prod[i] = produse[i];
			}
			return prod;
		}
		else
		{
			return nullptr;
		}
	}

	static int getLungime()
	{
		return lungime;
	}

	static int getLatime()
	{
		return latime;
	}

	static int getInaltime()
	{
		return inaltime;
	}

	//Setteri~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	void setCompanie(string companie)
	{
		if (companie.length() > 3)
		{
			this->companie = companie;
		}
	}

	void setProduse(int nrProduse, string* produse)
	{
		if (nrProduse > 0 && produse != nullptr)
		{
			if (this->produse != nullptr)
			{
				delete[]this->produse;
			}
			this->produse = new string[nrProduse];
			for (int i = 0; i < nrProduse; i++)
			{
				this->produse[i] = produse[i];
			}
			this->nrProduse = nrProduse;
		}
	}

	static void setLungime(int lungime)
	{
		if (lungime > 0)
			Container::lungime = lungime;
	}

	static void setLatime(int latime)
	{
		if (latime > 0)
			Container::latime = latime;
	}

	static void setInaltime(int inaltime)
	{
		if (inaltime > 0)
			Container::inaltime = inaltime;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//copiere si destructor~~~~~~~~~~~~~~~~~~

	Container(const Container& container) :greutateCutii(container.greutateCutii)
	{
		this->companie = container.companie;
		this->nrProduse = container.nrProduse;
		this->produse = new string[container.nrProduse];
		for (int i = 0; i < container.nrProduse; i++)
		{
			this->produse[i] = container.produse[i];
		}
	}

	~Container()
	{
		if (this->produse != NULL)
		{
			delete[]this->produse;
			this->produse = NULL;
		}
	}
	

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


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

	friend void calcGreutate(Container container);
};
int Container::lungime = 10;
int Container::latime = 4;
int Container::inaltime = 3;



void calcGreutate(Container container)
{
	cout << container.nrProduse * container.greutateCutii<<endl;
}


void varstaNava(const Nava& nava)
{
	cout << 2023 - nava.anLansare<<endl;
}




void main()
{
	
	Motor motor1;
	motor1.afisare();

	int* anReviz = new int[3];
	for (int i = 0;i < 3; i++) 
		anReviz[i] = 1985 + i * 4;
	

	Motor motor2("Ford", "electric", 3, anReviz);
	motor2.afisare();

	int* anRev = new int[3]{ 1990, 1994, 1998 };

	motor2.setAnRevizie(3, anRev);
	motor2.afisare();
	

	Motor motor3("Damen");
	int* anRevi = motor3.getAnRevizie();
	for (int i = 0; i < motor3.getNrRevizii(); i++)
	{
		cout << anRevi[i] << endl;
	}
	
	//cout<<Motor::aniDeLaUltimaRevizie(motor3.nrRevizii, motor3.anRevizie)<<endl;
	



	
	Container container1;
	container1.afisare();

	string prod[] = { "mere", "cartofi","unelte" };

	Container container2("DHL", 200 , 3 , prod);
	container2.afisare();
	
	string* prod2 = new string[3]{"mere", "morcovi", "inghetata"};

	container2.setProduse(3, prod2);
	container2.afisare();

	Container container3("UPS");
	
	string* myProducts = container3.getProduse();
	if (myProducts != nullptr) {
		for (int i = 0; i < container3.getNrProduse(); i++) {
			cout << myProducts[i] << endl;
		}
		delete[] myProducts;  
	}
	
	//cout << Container::getVolumContainer(container3.lungime, container3.latime, container3.inaltime)<<endl;


	Nava nava1;
	nava1.afisare();


	Nava nava2("Titanic", 2000, "Odyssy");
	nava2.afisare();


	Nava nava3("Bombardierul Cruiser");
	nava3.afisare();

	//constructor de copiere in actiune
	Nava nava4(nava3);
	cout<<nava4.getCompanie()<<endl;
    //cout<<Nava::getLungimeNumeCompanie(nava3.companie);



	calcGreutate(container2);
	varstaNava(nava3);


};