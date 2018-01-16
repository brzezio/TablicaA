#include <iostream>
using namespace std;

#include "employee.h"			//defines class Employee
#include "biblioteka.h"
#include "map_template.h"		//defines template map_template<Key,Value>

int main(void)
{
	typedef unsigned int ID; 							//Identification number of Employee
	map_template<ID,Employee> Database;					//Database of employees

	Database.Add(761028073,Employee("Jan Kowalski","salesman",28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	Database.Add(510212881,Employee("Adam Nowak","storekeeper",54)); 	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	Database.Add(730505129,Employee("Anna Zaradna","secretary",32)); 	//Add third employee: name: Anna Zaradna, position: secretary, age: 32
	/*cout<<"1.Done: "<<Database.ID[0]<<"\t"<<Database.Value[0]<<endl;	
	cout<<"2.Done: "<<Database.ID[1]<<"\t"<<Database.Value[1]<<endl;	
	cout<<"3.Done: "<<Database.ID[2]<<"\t"<<Database.Value[2]<<endl;*/
	
	cout << Database << endl;							//Print databese

	map_template<ID,Employee> NewDatabase = Database;	//Make a copy of database
	/*cout<<"1.Done: "<<NewDatabase.ID[0]<<"\t"<<NewDatabase.Value[0]<<endl;	
	cout<<"2.Done: "<<NewDatabase.ID[1]<<"\t"<<NewDatabase.Value[1]<<endl;	
	cout<<"3.Done: "<<NewDatabase.ID[2]<<"\t"<<NewDatabase.Value[2]<<endl;*/
	Employee* pE;
	pE = NewDatabase.Find(510212881);					//Find employee using its ID
	pE->Position = "salesman";							//Modify the position of employee
	pE = NewDatabase.Find(761028073);					//Find employee using its ID
	pE->Age = 29;										//Modify the age of employee

	Database = NewDatabase;								//Update original database
	
	cout << Database << endl;							//Print original databese

	cout<<"----------------------------------------------"<<endl;

	map_template<string,biblioteka> NewBiblioteka;

	NewBiblioteka.Add("Wiedzmin",biblioteka("Andrzej Sapkowski","fantazy",250,"na polce")); 
	NewBiblioteka.Add("Wiedzmin2",biblioteka("Sapkowski","fantazy",250,"na polce")); 
	
	cout<<NewBiblioteka<<endl;


	biblioteka* A;
	A = NewBiblioteka.Find("Wiedzmin");					
	A->Stan = "wypozyczone";							
	A = NewBiblioteka.Find("Wiedzmin2");					
	A->Autor = "Andrzej Sapkowski";
	
	cout<<NewBiblioteka<<endl;
	
}
