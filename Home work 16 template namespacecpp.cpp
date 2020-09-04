#include <iostream>

#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
//class carte;
namespace detalii_despre_carti_editate
{
//	class carte;
//}


template <class Titlu, class Autor, class Pagini, class Ebook>
class carte
{
	Titlu *ttl=new Titlu[255];
	Autor aut;
	Pagini pag;
	Ebook ebk;
	public :
//		carte(Titlu t,Autor A, Pagini P,Ebook E){
//		ttl=t;
//		aut=A;
//		pag=P;
//		ebk=E;
//		}
		
		
		void setTTL(){cin>>*ttl;	}
		Titlu* getTTL(){return ttl;		}
		void setAUT(){cin>>aut;	}
		Autor getAUT(){return aut;		}
		void setPAG(){cin>>pag;	}
		Pagini getPAG(){return pag;		}
		void setEBK(){cin>>ebk;	}
		Ebook getEBK(){return ebk;		}
		

};
}
namespace det_cart=detalii_despre_carti_editate;

using det_cart::carte;
int main()

{
	
	carte <char,char,int,bool> Obj;
	Obj.setTTL();
	Obj.setAUT();
	Obj.setPAG();
	Obj.setEBK();
	cout<<Obj.getTTL()<<endl;
	cout<<Obj.getAUT()<<endl;
	cout<<Obj.getPAG()<<endl;
	cout<<Obj.getEBK()<<endl;
	
//	carte <int,double,char,int> Obj (23,3.4,'q',32);
//	cout<<Obj.getTTL()<<endl;
//	cout<<Obj.getAUT()<<endl;
//	cout<<Obj.getPAG()<<endl;
//	cout<<Obj.getEBK()<<endl;
	
return 0;
}
