//Sa se creeze clasele pentru obiectul automobile
/*
motor(volum,tip_combustibil,cutia)
caroserie(model,culoare,seria,lungime)
roata(numar,dimensiunea)
automobil(marca,tara,anul_producerii)

*/

#include<iostream>

using namespace std;

class motor
{	int volum;
	char tip_combustibil[255];
	char cutia[255];
	public:
		motor(int v):volum(v){};
		void setTIP(){cout<<"Enter tip combustibil=";cin>>this->tip_combustibil;}
		void setCUTIA(){cout<<"Enter tip cutia=";cin>>this->cutia;}
		int getVOLUM(){return volum;	}
		char *getTIP(){return tip_combustibil;}
		char* getCUTIA(){return cutia;}
};
class roata
{	//protected:
	int numar;
	int dim_roata;
	public:
		roata(int nr, int dim):numar(nr),dim_roata(dim){};
		int getNUMAR(){return numar;	}
		int getDIM(){return dim_roata;	}
};

class caroserie
{	//protected:
	char model[255];
	char culoare[255];
	char seria[255];
	double lungime;
	public:
		caroserie(double lung):lungime(lung){};
		void setMODEL(){cout<<"Enter model=";cin>>this->model;}	
		void setCULOARE(){cout<<"Enter culoare=";cin>>this->culoare;}
		void setSERIA(){cout<<"Enter seria=";cin>>this->seria;}
		int getLUNGIME(){return lungime;	}
		char* getMODEL(){	return model;}
		char* getCULOARE(){return culoare;}
		char* getSERIA(){return seria;	}
};
class automobil: public roata, public caroserie,public motor
{	char marca[255];
	char tara[255];
	int an;
	public:
		automobil(int ann,int nr,int dim,double lung,int v):an(ann),roata(nr,dim),caroserie(lung),motor(v){}//atribuire a valorii in proprietati
		void setMARCA(){cout<<"Enter marca=";cin>>this->marca;}	
		void setTARA(){cout<<"Enter tara=";cin>>this->tara;}
		char* getMARCA(){return marca;}
		char* getTARA(){return tara;	}	
	
		getAN(){return an;}
};

int main(){
	automobil A(2005,4,16,4650,1500);
	A.setMARCA();
	A.setTARA();
	A.setMODEL();
	A.setCULOARE();
	A.setSERIA();
	A.setCUTIA();
	A.setTIP();
	
	cout<<"marca="<<A.getMARCA()<<endl;
	cout<<"tara="<<A.getTARA()<<endl;
	cout<<"an="<<A.getAN()<<endl;
	cout<<"model="<<A.getMODEL()<<endl;
	cout<<"culoare="<<A.getCULOARE()<<endl;
	cout<<"seria="<<A.getSERIA()<<endl;
	cout<<"lungime="<<A.getLUNGIME()<<endl;
	cout<<"numar roti="<<A.getNUMAR()<<endl;
	cout<<"dimensiune roti="<<A.getDIM()<<endl;
	cout<<"volum motor="<<A.getVOLUM()<<endl;
	cout<<"tip combustibil="<<A.getTIP()<<endl;
	cout<<"cutia motor="<<A.getCUTIA()<<endl;
	return 0;
}
