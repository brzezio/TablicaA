#include <iostream>
//#include "employee.h"

using namespace std;

template <class TypeA,class TypeB> class map_template{
		TypeA *ID;
		TypeB *Value;
		unsigned int n=0;
	
	public:
		class error{};
		map_template(){}
		map_template(const map_template<TypeA,TypeB>&A){
			this->n=A.n;
			ID=new TypeA[n];
			try{
				Value=new TypeB[n];
			}catch(...){
				delete[] ID;
				throw error();
			}
			for(unsigned int i=0;i<this->n;i++){
				this->ID[i]=A.ID[i];
				this->Value[i]=A.Value[i];
			}
		}
		~map_template(){
			delete[] ID;
			delete[] Value;
		}

		void Add(TypeA pierwszyArg, TypeB drugiArg){
			if(this->n==0){
				n++;
				ID=new TypeA[1];
				try{
					Value=new TypeB[1];
				}catch(...){
					delete[] ID;
					throw error();
				}
				ID[0]=pierwszyArg;
				Value[0]=drugiArg;
			}else{
				n++;
				//TODO:zabezpieczyć
				TypeA *A=new TypeA[n];
				TypeB *B=new TypeB[n];
				/*try{
					TypeB *B=new TypeB[n];
				}catch(...){
					delete[] A;
					throw error();
				}*/
				for(unsigned int i=0;i<=n-2;i++){
					A[i]=ID[i];
					B[i]=Value[i];
				}
				A[n-1]=pierwszyArg;
				B[n-1]=drugiArg;
				delete[] ID;
				delete[] Value;
				ID=A;
				Value=B;
			}
		}
		
		TypeB* Find(TypeA id){
			for(unsigned int i=0;i<n;i++){
				//cout<<"Find i="<<i<<endl;
				if(this->ID[i]==id)
					return &Value[i];
			}
			cout<<"Nie znaleziono obiektu o takim ID"<<endl;
			throw error();
		}

		void operator =(const map_template<TypeA,TypeB> A){
			this->n=A.n;
			delete[] this->ID;
			delete[] this->Value;
			ID=new TypeA[n];
			try{
				Value=new TypeB[n];
			}catch(...){
				delete[] ID;
			}
			for(unsigned int i=0;i<n;i++){
				this->ID[i]=A.ID[i];
				this->Value[i]=A.Value[i];
			}
		}
		friend ostream& operator<<(ostream& o,map_template<TypeA,TypeB> A){
			for(unsigned int i=0;i<A.n;i++){
				//cout<<"ostream i="<<i<<endl;
				o<<A.ID[i]<<"\t"<<A.Value[i]<<endl;
			}
			return o;
		}

};
