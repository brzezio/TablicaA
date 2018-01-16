#include <iostream>

using namespace std;

class biblioteka{
	
	public:
		string Autor;
		string Gatunek;
		unsigned int Strony;
		string Stan;
		biblioteka(){}
		biblioteka(string autor,string gatunek,int strony, string stan):Autor(autor),Gatunek(gatunek),Strony(strony),Stan(stan){}
		
		~biblioteka(){}

		friend ostream& operator<<(ostream& o,const biblioteka& A){
			return o<<A.Autor<<"\t"<<A.Gatunek<<"\t"<<A.Strony<<"\t"<<A.Stan<<endl;
		}

};
