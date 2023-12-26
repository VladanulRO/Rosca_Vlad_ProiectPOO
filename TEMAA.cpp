
//domeniu: VAPOR






#include <iostream>
#include <string>
using namespace std;



class Nava {
private:
	string nume;
	static int tonaj;
	int anLansare;
	char* companie;
public:

	Nava()
	{
		this->nume = "Speranta";
		this->anLansare = 1990;
		this->companie = new char[strlen("Costa") + 1];
		strcpy_s(this->companie, strlen("Costa") + 1, "Costa");
	}

	Nava(string nume, int anLansare, const char* companie)
	{
		this->nume = nume;
		this->anLansare = anLansare;
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

	Nava(const Nava& nava)// :anLansare(nava.anLansare) 
	{
		this->nume = nava.nume;
		this->anLansare = nava.anLansare;
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


	//Supraincarcare operatori~~~~~~~~~~~~~~~~~~


	Nava& operator&=(const Nava& nava)
	{
		if (this != &nava)
		{
			if(this->companie != NULL)
			   delete[]this->companie;

			this->nume = nava.nume;
			this->anLansare = nava.anLansare;
			if (nava.companie != NULL)
			{
				this->companie = new char[strlen(nava.companie) + 1];
				strcpy_s(this->companie, strlen(nava.companie) + 1, nava.companie);
			}
			else
			{
				this->companie = nullptr;
			}

		}
		return *this;
	}

	string operator()(string adaugare)
	{
		return nume + adaugare;
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
	
	friend ostream& operator<<(ostream& afis, const Nava& nava)
	{
		afis << "Nume vapor = " << nava.nume << "\n Tonaj = " << nava.tonaj << "\n An lansare = " << nava.anLansare << "\n Companie:" << nava.companie << endl;

		return afis;
	}

	friend istream& operator>>(istream& in, Nava& nava) {
		cout << "Nume vapor = ";
		in >> nava.nume;
		cout << "\n An lansare = ";
		in >> nava.anLansare;
		char* companie = new char[100];
		cout << "\n Companie:";
		in >> companie;
		cout<< endl;
		
		if (nava.companie) {
			delete[]nava.companie;
		}
		nava.companie = new char[strlen(companie) + 1];
		strcpy_s(nava.companie, strlen(companie) + 1, companie);
		delete[]companie;
		return in;
	}


	friend void varstaNava(const Nava& nava);

	friend bool operator!(Nava);

};

bool operator!(Nava nava)
{
	return nava.companie != "Costa";
}



int Nava::tonaj = 5000;

class Motor {
private:
	string producator;
	string motorizare ;
	static string culoareMotor;
	int nrRevizii;
	int* anRevizie;

public:

	Motor() {
		this->producator = "MAN";
		this->nrRevizii = 3;
		this->motorizare = "Diesel";
		this->anRevizie = new int[this->nrRevizii];
		for (int i = 0;i < this->nrRevizii;i++) {
			this->anRevizie[i] = 2000 + i * 4;
		};
	}

	Motor(string producator) :Motor() {
		this->producator = producator;
	}
	


	Motor(string producator,string motor, int nrRevizii, int* anRevizie) {
		this->producator = producator;
		this->nrRevizii = nrRevizii;
		this->motorizare = motor;
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

	Motor(const Motor& motor)
	{
		this->producator = motor.producator;
		this->nrRevizii = motor.nrRevizii;
		this->motorizare = motor.motorizare;
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

	//Supraincarcare operatori~~~~~~~~~~~~~~~~~~


	Motor& operator=(const Motor& motor)
	{
		if (this != &motor)
		{
			if (this->anRevizie != nullptr)
			{
				delete[]this->anRevizie;
				this->anRevizie = nullptr;
			}

			this->producator = motor.producator;
			
			if (motor.anRevizie != nullptr && motor.nrRevizii > 0)
			{
				this->anRevizie = new int[motor.nrRevizii];
				for (int i = 0; i < motor.nrRevizii; i++)
				{
					this->anRevizie[i] = motor.anRevizie[i];
				}
				this->nrRevizii = motor.nrRevizii;
			}
			else
			{
				this->anRevizie = nullptr;
				this->nrRevizii = 0;
			}


		}
		return *this;

	}



	int& operator[](int index)
	{
		if (index >= 0 && index < nrRevizii)
		{
			return anRevizie[index];
		}
	}


	explicit operator int()
	{
		return nrRevizii;
	}

	friend int operator+(const Motor& motor1, const Motor& motor2);


	friend ostream& operator<<(ostream& afis, const Motor& motor)
	{
		afis << "Producator = " << motor.producator<< "\n Motorizare =  " << motor.motorizare << "\n Culoare motor " << motor.culoareMotor << "\n Numar de revizii =" << motor.nrRevizii << endl;
		for (int i = 0;i < motor.nrRevizii;i++)
		{
			afis << "Anul reviziei nr " << i << ": " << motor.anRevizie[i] << endl;
		}
		return afis;
	}


	friend istream& operator>>(istream& in, Motor& motor) {
		cout << "Producator = ";
		in >> motor.producator;
		cout << "\n Motorizare = ";
		in >> motor.motorizare;
		cout << "\n Numar de revizii =";
		in >> motor.nrRevizii;
	
		if (motor.anRevizie) {
			delete[]motor.anRevizie;
		}
		motor.anRevizie = new int[motor.nrRevizii];
		for (int i = 0;i < motor.nrRevizii;i++)
		{   
			cout << "Anul Reviziei nr " << i<<": ";
			in >> motor.anRevizie[i];
		}
		return in;
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

int operator+(const Motor& motor1, const Motor& motor2)
{
	return motor1.nrRevizii + motor2.nrRevizii;
}


string Motor::culoareMotor = "Gri";





class Container {
private:
	string companie;
	float greutateCutii;
	static int lungime;
	static int latime;
	static int inaltime;
	int nrProduse;
	string* produse;
public:


	Container()
	{
		this->companie = "Fedex";
		this->greutateCutii = 4500, 20;
		this->nrProduse = 3;
		this->produse = new string[nrProduse];
		for (int i = 0;i < nrProduse; i++) {
			this->produse[i] = "Container " + to_string(i);
		}
	}

	Container(string companie, float greutate, int nrProduse, string* produse) 
	{
		this->companie = companie;
		this->greutateCutii = greutate;
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

	Container(const Container& container)
	{
		this->companie = container.companie;
		this->greutateCutii = container.greutateCutii;
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

		//Supraincarcare operatori~~~~~~~~~~~~~~~~~~


	Container& operator=(const Container& container)
	{
		if (this != &container)
		{
			if (this->produse != nullptr)
			{
				delete[]this->produse;
				this->produse = nullptr;
			}

			this->companie = container.companie;

			if (container.produse != nullptr && container.nrProduse > 0)
			{
				this->produse = new string[container.nrProduse];
				for (int i = 0; i < container.nrProduse; i++)
				{
					this->produse[i] = container.produse[i];
				}
				this->nrProduse = container.nrProduse;
			}
			else
			{
				this->produse = nullptr;
				this->nrProduse = 0;
			}


		}
		return *this;

	}

	Container operator++(int)
	{
		this->companie += " Mai buna ";
		Container copie = *this;
		return copie;
	}

	float operator/(const Container& container)
	{
		return greutateCutii / nrProduse;
	}


	Container operator-(int ProdInMinus) {
		if (ProdInMinus > 0 && ProdInMinus <= nrProduse) {
			nrProduse -= ProdInMinus;
			string* newProduse = new string[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				newProduse[i] = produse[i];
			}
			delete[] produse;
			produse = newProduse;
		}

		return *this;
	}


	friend ostream& operator<<(ostream& afis, const Container& container)
	{
		afis << "Companie = " << container.companie << "\n Greutate Cutii =  " << container.greutateCutii << "\n NumarProduse " << container.nrProduse << "\n Lungime =" << container.lungime << "\n Latime =" << container.latime << "\n Inaltime =" << container.inaltime << endl;
		for (int i = 0;i < container.nrProduse;i++)
		{
			afis << "Produsul nr " << i << ": " << container.produse[i] << endl;
		}
		afis << endl;
		return afis;
	}


	friend istream& operator>>(istream& in, Container& container) {
		cout << "Companie = ";
		in >> container.companie;
		cout << "\n Greutate cutii = ";
		in >> container.greutateCutii;
		cout << "\n Numar de produse =";
		in >> container.nrProduse;

		if (container.produse) {
			delete[]container.produse;
		}
		container.produse = new string[container.nrProduse];
		for (int i = 0;i < container.nrProduse;i++)
		{
			cout << "Produsul nr " << i << ": ";
			in >> container.produse[i];
		}
		return in;
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
	//motor1.afisare();

	int* anReviz = new int[3];
	for (int i = 0;i < 3; i++) 
		anReviz[i] = 1985 + i * 4;
	

	Motor motor2("Ford", "electric", 3, anReviz);
	//motor2.afisare();

	int* anRev = new int[3]{ 1990, 1994, 1998 };

	motor2.setAnRevizie(3, anRev);
	//motor2.afisare();
	

	Motor motor3("Damen");
	/*int* anRevi = motor3.getAnRevizie();
	for (int i = 0; i < motor3.getNrRevizii(); i++)
	{
		cout << anRevi[i] << endl;
	}*/
	
	//cout<<Motor::aniDeLaUltimaRevizie(motor3.nrRevizii, motor3.anRevizie)<<endl;
	



	
	Container container1;
	//container1.afisare();

	string prod[] = { "mere", "cartofi","unelte" };

	Container container2("DHL", 200 , 3 , prod);
	//container2.afisare();
	
	string* prod2 = new string[3]{"mere", "morcovi", "inghetata"};

	/*container2.setProduse(3, prod2);
	container2.afisare();*/

	Container container3("UPS");
	
	/*string* myProducts = container3.getProduse();
	if (myProducts != nullptr) {
		for (int i = 0; i < container3.getNrProduse(); i++) {
			cout << myProducts[i] << endl;
		}
		delete[] myProducts;  
	}*/
	
	//cout << Container::getVolumContainer(container3.lungime, container3.latime, container3.inaltime)<<endl;


	 Nava nava1;
	 //cin >> nava1;
	 //cout << nava1;
	 //nava1.afisare();


	Nava nava2("Titanic", 2000, "Odyssy");
	//nava2.afisare();


	Nava nava3("Bombardierul Cruiser");
	//nava3.afisare();

	//constructor de copiere in actiune
	Nava nava4(nava3);
    //cout<<Nava::getLungimeNumeCompanie(nava3.companie);

///~~~~~~~~~FAZA 3



	/*cout <<endl<< "Chestii noi~~~~~~~~~~~"<<endl;

	string numeNou = nava2("Albatros");
	cout << numeNou << endl;

	cout << nava1<<endl;

	bool esteCosta = !nava1;
	cout << esteCosta << endl;

	int an = motor2[2];
	cout << an << endl;

	int TotalRevizii = motor1 + motor2;
	cout << TotalRevizii << endl;

	int rezCast = (int)motor2;
	cout << rezCast << endl;

	Container container4 = container2++;
	container4.afisare();

	float greutateMedie = container1 / container1;
	cout << greutateMedie << endl;


	Container container5;
	container5.afisare();

	container5 = container5 - 2;

	container5.afisare();*/




//////~~~~~~~FAZA 4~~~~



	Nava nva[3];
	for (int i = 0; i < 3;i++)
	{
		cout << "Introdu datele pentru nava " << i << " :";
		cin >> nva[i];
	};
	for (int i = 0; i < 3;i++)
	{
		cout << nva[i];
	}


	Motor mtr[3];
	for (int i = 0; i < 3;i++)
	{
		cout << "Introdu datele pentru motorul " << i << " : ";
		cin >> mtr[i];
	};
	for (int i = 0; i < 3;i++)
	{
		cout << mtr[i];
	}



	Container ctr[2]; 


	for (int i = 0; i < 2;i++)
	{
		cout << "Introdu datele pentru Containerul " << i << " : ";
		cin >> ctr[i];
	};
	for (int i = 0; i < 3;i++)
	{
		cout << ctr[i];
	}




	Nava nva2[2][2];
	for (int i = 0; i < 2;i++)
		for (int j = 0; j < 2;j++)
	      {
		        cout << "Introdu datele pentru nava de pe randul " << i << " si coloana "<<j<<" : ";
		        cin >> nva2[i][j];
	     };
	for (int i = 0; i < 2;i++)
		for (int j = 0; j < 2;j++)
		{
			cout << nva2[i][j];
		};













};