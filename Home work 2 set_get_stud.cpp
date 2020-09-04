#include<iostream>
#include<iomanip>

using namespace std;

class stud
{
	char nume[255];
	char grupa[255];
	int ani,nr_stud,mate,romana,istoria,chimia,nr_obiecte=4;
	double media;
	
	public:
		int setNrSTUD(){cout<<"Enter number of students=";cin>>nr_stud;}
		void setNume(){cout<<"Enter nume=";cin>>nume;}
		void setGrupa(){cout<<"Enter grupa=";cin>>grupa;}
		void setAni(){cout<<"Enter ani=";cin>>ani;}
		void setMedia(double m){media=m;}
		void setMATE(){cout<<"Enter nota mate=";cin>>mate;}
		void setROMANA(){cout<<"Enter nota romana=";cin>>romana;}
		void setISTORIA(){cout<<"Enter nota istoria=";cin>>istoria;}
		void setCHIMIA(){cout<<"Enter nota chimia=";cin>>chimia;}

		const int getNrSTUD()const{return nr_stud;}
		const char* getNume()const{return nume;}
		const char* getGrupa()const{return grupa;}
		const int getAni()const{return ani;}
		const double getMedia()const{return media;}
		const int getMATE()const{return mate;}
		const int getROMANA()const{return romana;}
		const int getISTORIA()const{return istoria;}
		const int getCHIMIA()const{return chimia;}
		const int getNR_OBIECTE()const{return nr_obiecte;}
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
		s[i].setMATE();
		s[i].setROMANA();
		s[i].setISTORIA();
		s[i].setCHIMIA();
		s[i].setMedia(double(s[i].getMATE()+s[i].getROMANA()+s[i].getISTORIA()+s[i].getCHIMIA())/s[0].getNR_OBIECTE());
		
	}
	system("cls");
	cout<<"Lista studentilor:"<<endl;
	for (int i=0;i<n;i++){
		cout<<"Nume["<<i+1<<"]="<<setw(5)<<s[i].getNume()<<" | Grupa["<<i+1<<"]="<<setw(5)<<s[i].getGrupa()<<" | Ani["<<i+1<<"]="<<setw(5)<<s[i].getAni()<<" | Media["<<i+1<<"]="<<setw(5)<<s[i].getMedia()<<endl;
	}
	return 0;
}
