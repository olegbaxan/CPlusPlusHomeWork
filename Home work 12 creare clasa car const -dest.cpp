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
	char* tip_combustibil;
	char* cutia;
	public:
		motor(int v, char* tip_c, char* cutia):volum(v),tip_combustibil(tip_c),cutia(cutia){};
		~motor(){};
//		void setTIP(){cout<<"Enter tip combustibil=";cin>>this->tip_combustibil;}
//		void setCUTIA(){cout<<"Enter tip cutia=";cin>>this->cutia;}
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
		~roata(){};
		int getNUMAR(){return numar;	}
		int getDIM(){return dim_roata;	}
};

class caroserie
{	//protected:
	char* model;
	char* culoare;
	char* seria;
	double lungime;
	public:
		caroserie(char*model, char*culoare, char*seria,double lung):model(model),culoare(culoare),seria(seria),lungime(lung){};
//		void setMODEL(){cout<<"Enter model=";cin>>this->model;}	
//		void setCULOARE(){cout<<"Enter culoare=";cin>>this->culoare;}
//		void setSERIA(){cout<<"Enter seria=";cin>>this->seria;}
		~caroserie(){};
		int getLUNGIME(){return lungime;	}
		char* getMODEL(){	return model;}
		char* getCULOARE(){return culoare;}
		char* getSERIA(){return seria;	}
};
class automobil: public roata, public caroserie,public motor
{	char* marca;
	char* tara;
	int an;
	public:
		automobil(int ann,char* marca,char* tara,char* model,char* culoare, char* seria,double lung,int nr,int dim,int v,char* tip_combustibil,char* cutia):an(ann),marca(marca),tara(tara),caroserie(model,culoare,seria,lung),roata(nr,dim),motor(v,tip_combustibil,cutia){}//atribuire a valorii in proprietati
		//void setMARCA(){cout<<"Enter marca=";cin>>this->marca;}	
		//void setTARA(){cout<<"Enter tara=";cin>>this->tara;}
		~automobil(){};
		char* getMARCA(){return marca;}
		char* getTARA(){return tara;	}	
	
		getAN(){return an;}
};

int main(){
	automobil A(2005,"Dacia","RO","Logan","Verde","ABCD1234",4650,4,15,1500,"Diesel","Manuala");
	automobil B(2007,"Mitsubishi","Corea","Lancer","Verde","DSAQ1234",4650,4,15,1600,"Benzina","Manuala");
	//A.setMARCA();
//	A.setTARA();
//	A.setMODEL();
//	A.setCULOARE();
//	A.setSERIA();
//	A.setCUTIA();
//	A.setTIP();
	
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
	cout<<endl;
	cout<<"marca="<<B.getMARCA()<<endl;
	cout<<"tara="<<B.getTARA()<<endl;
	cout<<"an="<<B.getAN()<<endl;
	cout<<"model="<<B.getMODEL()<<endl;
	cout<<"culoare="<<B.getCULOARE()<<endl;
	cout<<"seria="<<B.getSERIA()<<endl;
	cout<<"lungime="<<B.getLUNGIME()<<endl;
	cout<<"numar roti="<<B.getNUMAR()<<endl;
	cout<<"dimensiune roti="<<B.getDIM()<<endl;
	cout<<"volum motor="<<B.getVOLUM()<<endl;
	cout<<"tip combustibil="<<B.getTIP()<<endl;
	cout<<"cutia motor="<<B.getCUTIA()<<endl;
	return 0;
}
