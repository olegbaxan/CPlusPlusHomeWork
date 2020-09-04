#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

class stud
{
	char nume[255];
	char grupa[255];
	int ani,nr_stud,nr_obiecte=4;
	double media=0;
	int note[777];
	double sumNOTE()
	{	int i=0;
		do
		{
			cout <<"Enter nota"<<i<<"=";
			cin>>note[i];
			media+=note[i];
			i++;
			cout<<"ESC - Iesire, Any - Continue"<<endl;
			
		}while(_getch()!=27);
		return media/=i;
	}
	
	public:
		//stud(){setNrSTUD();}
		stud(){setNume();setGrupa();setAni();setMedia();}
		//stud(){setNume();setGrupa();}
		
		int setNrSTUD();
		void setNume();
		void setGrupa();
		void setAni();
		void setMedia();
		//inline int setNrSTUD(){cout<<"Enter number of students=";cin>>nr_stud;}

		const int getNrSTUD()const;
		const char* getNume()const;
		const char* getGrupa()const;
		const int getAni()const;
		const double getMedia()const;
		

};
void stud::setNume()
{
	cout<<"Enter nume=";
	cin>>nume;
}
void stud::setGrupa()
{
	cout<<"Enter grupa=";
	cin>>grupa;
}
void stud::setAni()
{	
	cout<<"Enter ani=";
	cin>>ani;
}
void stud::setMedia()
{
	media=sumNOTE();
}
const char* stud::getNume()const
{	
	return nume;
}
const int stud::getNrSTUD()const
{
	return nr_stud;
}
const char* stud::getGrupa()const
{
	return grupa;
}
const int stud::getAni()const
{
	return ani;
}
const double stud::getMedia()const
{
	return media;
}
int main()
{
	
	stud a[2];

	for (int i;i<2;i++){
		cout<<"Name="<<a[i].getNume()<<", Grupa= "<<a[i].getGrupa()<<", Ani= "<<a[i].getAni()<<", Media= "<<a[i].getMedia()<<endl;
	}
		
	return 0;
}
