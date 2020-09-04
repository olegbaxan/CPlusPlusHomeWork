#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <iomanip>

using namespace std;
class stud;
class note;
class acad;
int size;
class npp
{
	char nume[255];
	char prenume[255];
	int ani;
	public:
	npp(){}
	~npp(){}
	
	void setNUME(){cout<<"Enter nume=";cin>>this->nume;}	
	void setPRENUME(){cout<<"Enter prenume=";cin>>this->prenume;}	
	void setANI(){cout<<"Enter ani=";cin>>this->ani;}
	inline const char* getNUME(){return this->nume;}	
	inline const char* getPRENUME(){return this->prenume;}	
	inline const int getANI(){return this->ani;}	
};
class acad  : public npp
{
	char univ[255];
	char specialitate[255];
	char gr[255];
	public:
	acad(){}
	~acad(){}
	
	void setUNIV(){cout<<"Enter universitatea=";cin>>this->univ;}
	void setSPECIALITATE(){cout<<"Enter specialitatea=";cin>>this->specialitate;}
	void setGR(){cout<<"Enter grupa=";cin>>this->gr;}
	inline const char* getUNIV(){return this->univ;}	
	inline const char* getSPECIALITATE(){return this->specialitate;}	
	inline const char* getGR(){return this->gr;}	
};
class note  : public acad
{	
	public:
	note(){}
	~note(){}
	//	friend void show(stud ,note,acad,npp  )	;	
//	void setNOTA(){cout<<"Enter note=";cin>>this->nota;}
//	int getNOTA(){return this->nota;}
	protected:
		int nota[777];
		double media;	
};
class stud  : public note
{
	public:
	stud(){}
	~stud(){}
	//friend void show(stud ,note,acad,npp  )	;	
	void enterNote(){
		this->nota[0]=1;
	do
	{	cout <<"Enter nota"<<this->nota[0]<<"=";
		cin>>this->nota[this->nota[0]];
		this->media+=this->nota[this->nota[0]];
		this->nota[0]++;
		cout<<"ESC - Iesire, Any - Continue"<<endl;		
	}while(_getch()!=27);
		
	this->media=this->media/(this->nota[0]-1);	
	}
	void listNote(){
	cout<<"Media="<<this->media<<endl;	
	for (int i=1;i<this->nota[0];i++)
		{
			cout<<"Nota "<<i<<"="<<this->nota[i]<<endl;
		}
	}	
};

int insert(stud S[], int n)
{
	int i=n;
	do 
	{
		system("cls");
		S[i].setNUME();
		S[i].setPRENUME();
		S[i].setANI();
		S[i].setUNIV();
		S[i].setSPECIALITATE();
		S[i].setGR();
		S[i].enterNote();
	
		size += sizeof(S[i]);
		i++;
		cout<<"size="<<size<<", i="<<i<<endl;
		cout<<"\nstudent ESC - exit, anykey continue ..."<<endl;
	}while(_getch()!=27);

	return i;	
}
void show(stud S[], int n)
{
for(int i=0;i<n;i++)
	{

	cout<<"Nume "<<i<<"="<<S[i].getNUME()<<endl;
	cout<<"Prenume "<<i<<"="<<S[i].getPRENUME()<<endl;
	cout<<"Ani "<<i<<"="<<S[i].getANI()<<endl;
	cout<<"Univ "<<i<<"="<<S[i].getUNIV()<<endl;
	cout<<"Specialitate "<<i<<"="<<S[i].getSPECIALITATE()<<endl;
	cout<<"Grupa "<<i<<"="<<S[i].getGR()<<endl;
	S[i].listNote();
	system("pause");
}
}

template<typename T>
int	write(T st[],char FN[])
{
	//ofstream ofs("red_text_.txt", ios::binary); // myfile.open("", ios::out|ios::binary);
	ofstream ofs(FN, ios::binary);
	cout<<"1size="<<size<<", fn="<<FN<<endl;
	ofs.write(reinterpret_cast<char*>(st), size);//transforma obiectul in char
	ofs.close();
}

int	read(stud S[],char FN[])
{
	ifstream ifs(FN, ios::binary);
	if (!ifs) { cout << "File not found"; return 1; }
	
	ifs.seekg(0, ifs.end); // setam informatia (marcam informatia)
	int len = ifs.tellg(); // obtinem lungimea informatiei
	ifs.seekg(0, ifs.beg); // setam fisierul la inceput, ne intoarcem la inceputul fisierului
	
	int max = (len / sizeof(stud)); //numarul de blocuri exitente (obiecte my)
	ifs.read(reinterpret_cast<char*>(S), 100); //
	ifs.close();
	for (int i = 0; i<max; i++){
	cout << " - getNUME()		(" << i + 1 << ")=" <<S[i].getNUME() 		<< endl;
	cout << " - getPRENUME() 	(" << i + 1 << ")="	<<S[i].getPRENUME()		<<endl;
	cout << " - Ani 			(" << i + 1 << ")="	<<S[i].getANI()			<<endl;
	cout << " - Univ 			(" << i + 1 << ")="	<<S[i].getUNIV()		<<endl;
	cout << " - Specialitate 	(" << i + 1 << ")="	<<S[i].getSPECIALITATE()<<endl;
	cout << " - Grupa 			(" << i + 1 << ")="	<<S[i].getGR()			<<endl;
	S[i].listNote();
	
	}
	system("pause");
	return max;
}


int main()
{
	srand(time(0));
	stud *S=new stud[10];
	int size=0;
	
	char name[255]="studenti.step";
	int n=read(S,name);

	while (1)
	{
		system("cls");
		cout<<"\t\t*****MENU*****"<<endl;
		cout<<"\t\t 1. Inserare"<<endl;
		cout<<"\t\t 2. Afisare"<<endl;
		cout<<"\t\t 3. Salvare"<<endl;
		cout<<"\t\t 4. Incarcare date"<<endl;
		cout<<"\t\t ESC. Iesire"<<endl;
		switch(_getch())
		{
			case 49: {system("cls"); n=insert (S,n);} break;
			case 50: {system("cls"); show(S,n);} break; 
			case 51: {system("cls"); write(S,name);break;}
			case 52: {system("cls"); n=read(S,name);break;}

			case 27: {write(S,name);exit(0);} break;	
		}	
	}
return 0;
}
