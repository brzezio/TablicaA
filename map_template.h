#include <iostream>

using namespace std;

template <class TypeA,class TypeB> class map_template{
	
	TypeA *ID=new TypeA[1];
	TypeB *Value=new TypeB[1];
	unsigned int n=0;

	~map_template{
		delete[] ID;
		delete[] Value;
	}

	public void Add(TypeA pierwszyArg, TypeB drugiArg){
		if(n==0){
			n++;
			ID[n-1]=pierwszyArg;
			Value[n-1]=drugiArg;
		}else{
			n++;
			TypeA *A=new TypeA[n];
			try{
				TypeB *B=new TypeB[n];
			}catch{
				delete[] A;
			}

			for(int i=0;i<n-2;i++){
				A[i]=ID[i];
				B[i]=Value[i];
			}
			A[n-1]=pierszyArg;
			B[n-1}=drugiArg;
			delete[] ID;
			delete[] Value;
			ID=A;
			Value=B;
		}
	}
	
	public TypeB Find(TypeA id){
		for(int i;i<n;i++)
			if(ID[i]==id)
				return Value[i];
		cout<<"Nie znaleziono obiektu o takim ID"<<endl;
		TypeB a;
		return a;
	}

	public void operator =(map_template A){
		this->n=A.n;
		delete[] this->ID;
		delete[] this->Value;
		ID=new TypeA[n];
		try{
			Value=new TypeB[n];
		}catch(...){
			delete[] ID;
		}
		for(int i=0;i<n;i++){
			this->ID[i]=A.ID[i];
			this->Value[i]=A.Value[i];
		}
	}

};
