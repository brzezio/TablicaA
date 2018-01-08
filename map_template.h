#include <iostream>

using namespace std;

template <class TypeA,class TypeB> class map_template{
	
	TypeA *ID;
	TypeB *Value;
	unsigned int n=0;

	~map_template{
		delete[] ID;
		delete[] Value;
	}

	public void Add(TypeA pierwszyArg, TypeB drugiArg){
		if(n==0){
			n++;
			ID=new TypeA[n];
			ID[n-1]=pierwszyArg;
			try(){
				Value=new TybeB[n];
				Value[n-1]=drugiArg;
			}catch(...){
				delete[] ID;
			}
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
			TypeA *ID=A;
			TypeB *Value=B;
		}
	}

};
