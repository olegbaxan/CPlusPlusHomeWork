#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class my1
{
	int b;
  
public:

	void create1() {
		cout << "b = ";
		cin >> b;
		cout << this->b << " created\n";
	}
	void show1() { cout << " b= " << this->b << endl; }
	inline const int returnB()const { return this->b; }
};	
class my : public my1
{
	int a;
  
public:

	void create() {
		cout << "a = ";
		cin >> a;
		cout << this->a << " created\n";
	}
	void show() { cout << " a= " << this->a << endl; }
	inline const int returnA()const { return this->a; }
};
my *o = new my[100];

void write(int size)
{
    ofstream ofs("red_text_.txt", ios::binary); // myfile.open("", ios::out|ios::binary);
	ofs.write(reinterpret_cast<char*>(o), size);
	ofs.close();
	
}

int read()
{
    ifstream ifs("red_text_.txt", ios::binary); // myfile.open("", ios::in|ios::binary);
	if (!ifs) { cout << "File not found"; }

	ifs.seekg(0, ifs.end); // setam informatia
	int len = ifs.tellg(); // obtinem lungimea informatiei
	ifs.seekg(0, ifs.beg); // setam fisierul la inceput

	int max = (len / sizeof(my));

	ifs.read(reinterpret_cast<char*>(o), 100); //
	ifs.close();
	
	return max;	
}
int main()
{
	

	int n, i = 0, size = 0;

    int Key;
    do
    {
    	    o[i].create();
    	    o[i].create1();
			size += sizeof(o[i]);
			i++;
    	cout<<" Any key to continue OR ESC to Exit"<<endl;
	}while(_getch()!=27);
	
    n = i;
	
	for (int i = 0; i<n; i++) cout << " - obj(" << i + 1 << "??" << o[i].returnA() <<" - "<<o[i].returnB() << endl;

	cout << "size=" << size << endl;
	
	/// WRITE file RED 2020   
	write(size);

	/// READ file RED 2020

	
    int max = read();
    
	for (int i = 0; i<max; i++) 
	cout << " - obj(" << i + 1 << "??" << o[i].returnA() <<" - "<<o[i].returnB() << endl;

	system("pause");
}
