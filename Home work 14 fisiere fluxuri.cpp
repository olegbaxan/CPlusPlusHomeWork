#include<iostream>
#include<exception>
#include<fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	srand(time(0));
	int a,b,c,R;
	ofstream f;
	int n=rand()%9+1;
	f.open("Suma.txt");
	f<<n<<endl;
	for(int i=0;i<n;i++)
	{
		a=rand()%10;
		b=rand()%10;
		c=rand()%10;
		R=a+b-c;
		if(i<n-1){f<<a<<" "<<b<<" "<<c<<" "<<R<<endl;}
		else {f<<a<<" "<<b<<" "<<c<<" "<<R;}	
	}
	f.close();
	
	ifstream f1;
	f1.open("Suma.txt");
	int V[100];
	int j=1;
	f1>>V[0];
	for (int i=1;i<4*V[0];i=i+4)
	{
		f1>>V[i]>>V[i+1]>>V[i+2]>>V[i+3];
	}
	f1.close();	
	
	char s[255];
	ifstream f2;
	f2.open("Suma.txt");
	f2>>n;
	cout<<"From file\n"<<"n="<<n<<endl;
	while(!f2.eof())
	{
		f2>>a>>b>>c>>R; cout<<"a="<<a<<", b="<<b<<", c="<<c<<", R="<<R<<endl;
	}
	f2.close();	
	
	cout<<"From vector\n"<<"n="<<V[0]<<endl;
	for (int i=1;i<4*V[0];i=i+4)
	{
		cout<<"a="<<V[i]<<", b="<<V[i+1]<<" ,c="<<V[i+2]<<", R="<<V[i+3]<<endl;
	}

	return 0;
}
