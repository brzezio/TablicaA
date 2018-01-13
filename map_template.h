#include <iostream>

using namespace std;

template <class TypeA,class TypeB> class map_template{
	
	TypeA *ID;
	TypeB *Value;
	unsigned int n=0;
	
	public:
		map_template<TypeA,TypeB>(const map_template<TypeA,TypeB>&A){
			this->n=A.n;
			ID=new TypeA[n];
			try{
				Value=new TypeB[n];
			}catch(...){
				delete[] ID;
			}
			this->ID=A.ID;
			this->Value=A.Value;
		}
		~map_template(){
			delete[] ID;
			delete[] Value;
		}

		void Add(TypeA pierwszyArg, TypeB drugiArg){
			n++;
			//TODO:zabezpieczyć
			TypeA *A=new TypeA[n];
			TypeB *B=new TypeB[n];
			/*try{
				TypeB *B=new TypeB[n];
			}catch(...){
				delete[] A;
			}*/
			for(int i=0;i<n-2;i++){
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
		
		TypeB Find(TypeA id){
			for(int i;i<n;i++)
				if(ID[i]==id)
					return Value[i];
			cout<<"Nie znaleziono obiektu o takim ID"<<endl;
			TypeB a;
			return a;
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
			//this->ID=A.ID;
			//this->Value=A.Value;
			for(int i=0;i<n;i++){
				this->ID[i]=A.ID[i];
				this->Value[i]=A.Value[i];
			}
		}
		
		ostream operator<<(const map_template<TypeA,TypeB> A){
			ostream o;
			for(int i=0;i<A.n;i++)
				o<<A.ID[i]<<"/t"<<A.Value[i]<<endl;
			return o;
		}

};
