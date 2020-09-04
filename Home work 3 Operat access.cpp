#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

class stud
{
	char nume[255];
	char grupa[255];
	int ani,nr_stud,mate,romana,istoria,chimia,nr_obiecte=4;
	double media=0;
	int note[777];
	double sumNOTE()
	{	int i=0;
		do
		{
			cout <<"Enter nota ["<<i<<"]=";
			cin>>note[i];
			media+=note[i];
			i++;
			cout<<"ESC - Iesire, Any - Continue"<<endl;
			
		}while(_getch()!=27);
		return media/=i;
	}
	
	public:
		int setNrSTUD();
		void setNume();
		void setGrupa();
		void setAni();
		void setMedia();

		const int getNrSTUD()const;
		const char* getNume()const;
		const char* getGrupa()const;
		const int getAni()const;
		const double getMedia()const;
};
int stud::setNrSTUD()
{
	cout<<"Enter number of students=";
	cin>>nr_stud;
}
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
	stud s[100];
	s[0].setNrSTUD();
	int n=s[0].getNrSTUD();
	for (int i=0;i<n;i++){
		s[i].setNume();
		s[i].setGrupa();
		s[i].setAni();
		s[i].setMedia();
		
	}
	system("cls");
	cout<<"Lista studentilor:"<<endl;
	for (int i=0;i<n;i++){
		cout<<"Nume["<<i+1<<"]="<<setw(5)<<s[i].getNume()<<" | Grupa["<<i+1<<"]="<<setw(5)<<s[i].getGrupa()<<" | Ani["<<i+1<<"]="<<setw(5)<<s[i].getAni()<<" | Media["<<i+1<<"]="<<setw(5)<<s[i].getMedia()<<endl;
	}
	return 0;
}
