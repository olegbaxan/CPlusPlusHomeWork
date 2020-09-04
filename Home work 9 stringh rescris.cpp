#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string.h>

using namespace std;

class stringh
{
    char str[255];

    public:
    friend istream& operator>>(istream&,stringh&);
	friend ostream& operator<<(ostream&,stringh&);//template
	friend int operator!(stringh&);
	friend bool operator+(stringh&,stringh&);
	friend int operator==(stringh&,stringh&);
	friend bool operator/=(stringh&,stringh&);
	friend bool operator~(stringh&);
	friend bool operator^(stringh&,stringh&);

};

//strstr
bool operator^(stringh&Obj1,stringh&Obj2)
{
	//int count=0;
	for (int i=0;i<!Obj1;i++){
		if(Obj1.str[i]==Obj2.str[0]) {
			for(int k=0;k<!Obj2;k++)
				if ((Obj2.str[k]==Obj1.str[i+k])&&!Obj2>1){
					return true;
				}else {
					return false; break;
				}
		}
	}
	return false;
}
//strchr
bool operator~(stringh&Obj1)
{
	char a;
	cout<<"Enter a value to search:";
	cin>>a;
	int count=0;
	while(Obj1.str[count]!='\0')
	{
		if(Obj1.str[count]==a) {
		return true;
		break;
		}count++;
	}
	return false;
}
//strcpy
bool operator/=(stringh&Obj1,stringh&Obj3)
{
	int count=0;
	{ while(Obj1.str[count]!='\0')
		{
			Obj3.str[count]=Obj1.str[count];
			cout<<"Obj1.str[count]="<<Obj1.str[count]<<", Obj3.str[count]="<<Obj3.str[count]<<endl;
			count++;
		}
	}
	if (!Obj1==!Obj3)return true;
	else return false;
}
//strcmp
int operator==(stringh&Obj1,stringh&Obj2)
{
	int count=0;
	if(!Obj1==!Obj2)//verificarea posibilitatii de copiere
	{ while(Obj1.str[count]!='\0')
		{	//cout<<"Obj1.str[count]="<<Obj1.str[count]<<", Obj2.str[count]="<<Obj2.str[count]<<", count="<<count<<endl;
			if(Obj1.str[count]!=Obj2.str[count]){return 2;break;}
			count++;
		}
	}
	else if (!Obj1>!Obj2) 	return -1;
	else return 1;
}
//strcat
bool operator+(stringh&Obj1,stringh&Obj2)
{
	int count=0;
	int count1=!Obj1;
	if((!Obj1+!Obj2)<=255)//verificarea posibilitatii de copiere
	{ while(Obj2.str[count]!=0)
		{	//cout<<"OBJ2="<<Obj2.str[count]<<", OBJ1in="<<!Obj1<<", count="<<count<<endl;
			Obj1.str[count1]=Obj2.str[count];
			
			//cout<<"Obj1.str[!Obj1]="<<Obj1.str[count1]<<", OBJ1="<<!Obj1<<endl;
			count++;
			count1++;
			
		}Obj1.str[count1]=0;
	return true;
	}
	else 	return false;
}
//strlen
int operator!(stringh&Obj)
{	int count=0;while(Obj.str[count]!=0){count++;}
	return count;
}

istream& operator>>(istream&X,stringh&Obj)
{
	cout<<"Enter sir=";
	X>>Obj.str;


	return X;
}
ostream& operator<<(ostream&X,stringh&Obj)
{
	X<<"\nsir="<<Obj.str<<endl;
}

int main()
{
	stringh STR1;
    stringh STR2;
    stringh STR3;
    stringh STR4;
    cin>>STR1;
    cin>>STR2;
	//strlen
    cout<<STR1<<STR2<<endl;

	int c=!STR1;

	cout<<"c="<<c<<endl;
	//strcpy
	if(STR1/=STR3){cout<<"strcpy OK = "<<endl;}
	else {cout<<"strcpy NOK = "<<endl;}
	//strstr
	cout<<"To find a string ";
	cin>>STR4;
	if(STR1^STR4){cout<<"strstr OK "<<endl;}
	else {cout<<"strstr NOK "<<endl;}	
	
	//strchr
	if(~STR1){cout<<"strchr OK "<<endl;}
	else {cout<<"strchr NOK "<<endl;}
	//strcmp
	int cmp=STR1==STR2;
	if (cmp==2){cout<<"strcmp. Sirurile sunt egale ca lungime, dar difera literele"<<endl;} 
	else cout<<"strcmp ="<<cmp<<". Sirul STR1 este "<<(cmp==0 ? " egal cu " : cmp==1 ? " mai mic decat " : " mai mare decat ")<<" STR2."<<endl;
	//strcat
	if(STR1+STR2){cout<<"strcat OK"<<endl;cout<<STR1<<STR2<<endl;	}
	else {cout<<"strcat Error"<<endl;	}
	
return 0;
}
