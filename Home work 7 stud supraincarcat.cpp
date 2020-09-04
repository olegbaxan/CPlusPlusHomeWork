#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;
class stud;
class note
{
	
	double media;
	int nota1,nota2,nota3;
	public:
	friend istream& operator>>(istream&,stud&);//template
	friend ostream& operator<<(ostream&,stud&);//template

};

class stud
{
	note ns;
	
	char nume;
	char grupa;
	int ani;
	public:

	friend istream& operator>>(istream&,stud&);//template
	friend ostream& operator<<(ostream&,stud&);//template

};

istream& operator>>(istream&X,stud&Obj)
{
	cout<<"Enter nume=";
	X>>Obj.nume;
	cout<<"Enter grupa=";
	X>>Obj.grupa;
	cout<<"Enter ani=";
	X>>Obj.ani;
	cout<<"Enter nota1=";
	X>>Obj.ns.nota1;
	cout<<"Enter nota2=";
	X>>Obj.ns.nota2;
	cout<<"Enter nota3=";
	X>>Obj.ns.nota3;
	
	return X;
}
ostream& operator<<(ostream&X,stud&Obj)
{
	X<<"nume="<<Obj.nume<<", grupa="<<Obj.grupa<<", ani="<<Obj.ani<<",\nnota1="<<Obj.ns.nota1<<", nota2="<<Obj.ns.nota2<<", nota3="<<Obj.ns.nota3<<endl;
	
	return X;
}

int main()

{
	stud A[2];
	
	for (int i=0;i<2;i++)
	{
		cin>>A[i];
	}
	
	for (int i=0;i<2;i++)
	{
		cout<<A[i];
	}

return 0;

}
