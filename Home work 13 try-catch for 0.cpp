#include<iostream>
#include<exception>

using namespace std;



int main(){

	int a,b;
	cout<<"Enter a value for a=";
	cin>>a;
	cout<<"Enter a value for b=";
	cin>>b;
	while(b==0)
	{	
		cout<<"Value for is "<<b<<", Can you enter a new value=";
		cin>>b;
		try {
			if(b==0)throw 1;
			else throw 0;
		}
		catch(int z)
		{
			if (z==0)
			{
				break;
			}
		}
	}
system("cls");
cout<<"rezultatul a/b="<<double(a/b)<<endl;
	return 0;
}
