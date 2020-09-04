#include<iostream>


using namespace std;

class calcul
{
	int a,b,c;

public:
	void calc(){
		cout<<"Enter value for a: ";
		cin>>a;
		cout<<"Enter value for b: ";
		cin>>b;
		cout<<"Enter value for c: ";
		cin>>c;	
		int R = a+b-c;
		cout<<"a+b-c="<<R<<endl;
	};
};
	

int main()
{
	calcul A;
	A.calc();
	
	
	return 0;
}
