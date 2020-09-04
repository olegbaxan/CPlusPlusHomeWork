#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

class stud
{
	char *nume;
	char *grupa;
	int *ani;
	double *media;
	int *note;

	
	public:
		//stud(char *grupe='\0'){this->nume=new char[25];setNume();this->grupa=new char[25];grupa=grupe;this->ani=new int;setAni();this->media=new double;setMedia();}
		stud(char *grupe='\0'){this->nume=new char[25];this->grupa=new char[25];grupa=grupe;this->ani=new int;this->media=new double;}
		~stud();
		int setNrSTUD();
		void setNume();
		void setGrupa();
		void setAni();
		void setMedia();
		
		friend void sumNOTE(stud);
		
		const int getNrSTUD()const;
		const char* getNume()const;
		const char* getGrupa()const;
		const int getAni()const;  // folosim * cand returnam siruri
		const double getMedia()const;
		
void sumNOTE(stud)
	{	int i=0;
		int *note=new int;
		do
		{
			cout <<"Enter nota"<<i<<"=";
			cin>>*note;
			*media+=*note;
			
			i++;
			cout<<"ESC - Iesire, Any - Continue"<<endl;
			
		}while(_getch()!=27);
		*(this)->media=*media/i;
		//return *media/=i;
}

};
void stud::setNume()
{
	cout<<"Enter nume=";
	cin>>nume; //fara * pentru ca este sir
}
void stud::setGrupa()
{
	cout<<"Enter grupa=";
	cin>>grupa;
}
void stud::setAni()
{	
	cout<<"Enter ani=";
	cin>>*(this)->ani;
}
//void stud::setMedia()
//{
//	//*media=sumNOTE();
//	sumNOTE(stud a);
//}
const char* stud::getNume()const
{	
	return this->nume;
}
/*
const int stud::getNrSTUD()const
{
	return *nr_stud;
}
*/
const char* stud::getGrupa()const
{
	return this->grupa;
}
const int stud::getAni()const
{
	return *(this)->ani;
}
const double stud::getMedia()const
{
	return *(this)->media;
}
int main()
{
	
	stud *a[2]; //un tablou de pointer
	for (int i=0;i<2;i++){
		a[i]= new stud("LPS1911");
		
		a[i]->setNume();
		a[i]->setAni();
		//a[i]->setMedia();
		sumNOTE(a[i]);
		//a[i]= new stud('\0','\0',1);
	}
	//delete z[0]; se foloseste for pentru a sterge toate obiectele create
	
	for (int i=0;i<2;i++){
		cout<<"Name="<<a[i]->getNume()<<", Grupa= "<<a[i]->getGrupa()<<", Ani= "<<a[i]->getAni()<<", Media= "<<a[i]->getMedia()<<endl;
	}
		
	return 0;
}
