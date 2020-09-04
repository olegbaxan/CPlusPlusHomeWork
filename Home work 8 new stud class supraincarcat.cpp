#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;
class str;
class in;
class npp;
class stud;

class note
{
	int note[777];
	
	public:
		friend istream& operator>>(istream&,stud&);//template
		friend ostream& operator<<(ostream&,stud&);//template
		friend void f(stud&);
};

class media
{
	double media=0;
	
	public:
		friend istream& operator>>(istream&,stud&);//template
		friend ostream& operator<<(ostream&,stud&);//template
		friend void f(stud&);
};
class str
{
	char val[255];
	public:
		friend istream& operator>>(istream&,stud&);//template
		friend ostream& operator<<(ostream&,stud&);//template
		friend void f(stud&);
};
class in
{
	int val;
	public:
		friend istream& operator>>(istream&,stud&);//template
		friend ostream& operator<<(ostream&,stud&);//template
		friend void f(stud&);
};
class npp
{
	str NUME;
	str PRENUME;
	 in ANI;
	 in NOTE;
	public:
		friend istream& operator>>(istream&,stud&);//template
		friend ostream& operator<<(ostream&,stud&);//template
		friend void f(stud&);
};
class acad
{
	str UNIVERSITATE;
	in SPECIALITATE;
	in GRUPA;
	public:
		friend istream& operator>>(istream&,stud&);//template
		friend ostream& operator<<(ostream&,stud&);//template
		friend void f(stud&);
};

class stud
{
	npp NPP;
	acad ACAD;
	note NOTE;
	media MEDIA;
	
	public:

		friend istream& operator>>(istream&,stud&);
		friend ostream& operator<<(ostream&,stud&);//template
		friend void f(stud&);
};

istream& operator>>(istream&X,stud&Obj)
{
	cout<<"Enter nume=";
	X>>Obj.NPP.NUME.val;
	cout<<"Enter prenume=";
	X>>Obj.NPP.PRENUME.val;
	cout<<"Enter ani=";
	X>>Obj.NPP.ANI.val;
	cout<<"Enter Univer=";
	X>>Obj.ACAD.UNIVERSITATE.val;
	cout<<"Enter specialitate=";
	X>>Obj.ACAD.SPECIALITATE.val;
	cout<<"Enter grupa=";
	X>>Obj.ACAD.GRUPA.val;
	Obj.NOTE.note[0]=1;
	do
	{	cout <<"Enter nota"<<Obj.NOTE.note[0]<<"=";
		X>>Obj.NOTE.note[Obj.NOTE.note[0]];
		Obj.MEDIA.media+=Obj.NOTE.note[Obj.NOTE.note[0]];
		Obj.NOTE.note[0]++;
		cout<<"ESC - Iesire, Any - Continue"<<endl;		
	}while(_getch()!=27);
	Obj.MEDIA.media=Obj.MEDIA.media/(Obj.NOTE.note[0]-1);

	return X;
}
ostream& operator<<(ostream&X,stud&Obj)
{
	X<<"\nnume="<<Obj.NPP.NUME.val<<", prenume="<<Obj.NPP.PRENUME.val<<", ani="<<Obj.NPP.ANI.val
	<<"\nUniversitate = "<<Obj.ACAD.UNIVERSITATE.val<<", specialitate="<<Obj.ACAD.SPECIALITATE.val<<", grupa="<<Obj.ACAD.GRUPA.val
	<<", media="<<Obj.MEDIA.media<<endl;
	for (int i=1;i<Obj.NOTE.note[0];i++)
	{
		X<<"\nnota["<<i<<"]="<<Obj.NOTE.note[i];
	}
	return X;
}
void f(stud&X)//alternativa pentru supraincarcare
{
	cout<<"f() nume=";
	cin>>X.NPP.NUME.val;
	cout<<"f() prenume=";
	cin>>X.NPP.PRENUME.val;
	cout<<"f() ani=";
	cin>>X.NPP.ANI.val;
}

int main()
{
	stud S[2];
	cout<<"sizeof()="<<sizeof(S)<<endl;
	for (int i=0;i<2;i++)
{
		cin>>S[i];
}
	//f(S); //folosit daca avem functie
	for (int i=0;i<2;i++)
	{
		cout<<S[i];
	}
return 0;
}
