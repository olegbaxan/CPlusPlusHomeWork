#include<iostream>
#include<exception>
#include<string.h>
#include <stdlib.h> 

using namespace std;



int main(){

bool counter;
do
{	counter=0;
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
