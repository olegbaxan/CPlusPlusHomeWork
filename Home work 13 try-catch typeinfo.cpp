#include<iostream>
#include<exception>
#include<string.h>
#include <stdlib.h> 

using namespace std;



int main(){

bool counter;
do
{//de utilizat typeinfo pentru a afla ce tip de date avem. Apoi in catch facem un switch care are identitifica tipul de date apoi alocam spatiu	
counter=0;
	try {
		//int n=3000000000;
		int n;
		char nchar[256];
		cout<<"Enter a value for n=";
		cin>>nchar;
		n=atoi (nchar);
		int *p=new int [n];
		cout<<"S-a alocat "<<n<<" elemente"<<endl;
	}
		catch(exception& e)
	{
		if (strstr(e.what(),"std::bad_alloc"))	counter=1;
		cout<<" Error ::"<<e.what()<<" counter="<<counter<<endl;
	}
	
}while(counter==1);

	return 0;
}
