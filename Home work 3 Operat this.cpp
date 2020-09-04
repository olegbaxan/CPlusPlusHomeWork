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
		int setNrSTUD(){cout<<"Enter number of students=";cin>>this->nr_stud;}
		void setNume(){cout<<"Enter nume=";cin>>this->nume;}
		void setGrupa(){cout<<"Enter grupa=";cin>>this->grupa;}
		void setAni(){cout<<"Enter ani=";cin>>this->ani;}
		void setMedia(){media=sumNOTE();}

		const int getNrSTUD()const{return this->nr_stud;}
		const char* getNume()const{return this->nume;}
		const char* getGrupa()const{return this->grupa;}
		const int getAni()const{return this->ani;}
		const double getMedia()const{return this->media;}
		

};

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
