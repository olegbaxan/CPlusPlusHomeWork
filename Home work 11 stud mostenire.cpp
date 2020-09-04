#include<iostream>
#include<conio.h>

using namespace std;

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
	char* getNUME(){return this->nume;}	
	char* getPRENUME(){return this->prenume;}	
	int getANI(){return this->ani;}	
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
	char* getUNIV(){return this->univ;}	
	char* getSPECIALITATE(){return this->specialitate;}	
	char* getGR(){return this->gr;}	
};
class note  : public acad
{	
	public:
	note(){}
	~note(){}
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

int main()
{	
	stud S[2];
	
	for(int i=0;i<2;i++)
	{
		S[i].setNUME();
	//cout<<"Nume="<<S[i].getNUME()<<endl;
	S[i].setPRENUME();
	//cout<<"Prenume="<<S[i].getPRENUME()<<endl;
	S[i].setANI();
	//cout<<"Ani="<<S[i].getANI()<<endl;
	S[i].setUNIV();
	//cout<<"Univ="<<S[i].getUNIV()<<endl;
	S[i].setSPECIALITATE();
	//cout<<"Specialitate="<<S[i].getSPECIALITATE()<<endl;
	S[i].setGR();
	//cout<<"Grupa="<<S[i].getGR()<<endl;
	S[i].enterNote();
	//S[i].listNote();
	}
	
	for(int i=0;i<2;i++)
	{
	//S[i].setNUME();
	cout<<"Nume "<<i<<"="<<S[i].getNUME()<<endl;
	//S[i].setPRENUME();
	cout<<"Prenume "<<i<<"="<<S[i].getPRENUME()<<endl;
	//S[i].setANI();
	cout<<"Ani "<<i<<"="<<S[i].getANI()<<endl;
	//S[i].setUNIV();
	cout<<"Univ "<<i<<"="<<S[i].getUNIV()<<endl;
	//S[i].setSPECIALITATE();
	cout<<"Specialitate "<<i<<"="<<S[i].getSPECIALITATE()<<endl;
	//S[i].setGR();
	cout<<"Grupa "<<i<<"="<<S[i].getGR()<<endl;
	//S[i].enterNote();
	S[i].listNote();
	}
	
	return 0;
}
