//poly_processing.cpp
//Processing the employee derived-class objects individually
//    and polymorphically using dynamic binding

#include <iostream>
#include <iomanip>
#include <vector>
#include "Empolyee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namepspace std;

void virtualViaPointer( const Employee * const ); //prototype
void virtualViaReference( const Employee & ); //prototype

int main()
{
// set floating-point output formatting
cout<< fixed << setprecision(2);

//create derived-class objects
SlariedEmployee salariedEmployee(
"John", "Smith", "111-11-1111", 800);

CommissionEmployee commissionEmployee(
"Sue","Jones", "333-33-3333", 10000, .06
);

BasePlusCommissionEmployee basePlusCommissionEmployee(
"Bob", "Lewis","444-44-4444", 5000, .04,300
);

cout<<"Employees processed indivisually using static binding: \n\n ";

//output each Employee's information and earnings using static binding

salariedEmployee.print();
cout<< "\n earned $ " << salariedEmployee.earnings() << "\n\n";
commissionEmployee.print();
cout<< "\n earned $ " << commissionEmployee.earnings() << "\n\n";
basePlusCommissionEmployee.print();
cout<< "\n earned $ " << basePlusCommissionEmployee.earnings() << "\n\n";

//create vector of three base-class pointers
vector< Employee * > employees(3);

//initialize vector with pointers to Employees
employees[ 0 ] = &salariedEmployee;
employees[ 1 ] = &commissionEmployee;
employees[ 2 ] = &basePlusCommissionEmployee;

cout<< "Employees processed polymorphically via dynamic binding : \n\n";

for( const Employee * employeePtr : employees)
   virtualViaPointer(employeePtr);
   
   //call virtualViaReference to print each Employee's information
   //and earnings using dynamic binding
   
   cout<< "Virtual function calls made off base class references: \n\n ";
   
   for( const Employee * employeePtr : employees )
   virtualViaReference (*employeePtr); //note dereferencing
   }  //main function end here
   
   //call Employee virtual function print and earnings off a 
   //base-class pointer using dynamic binding
   
   void virtualViaPointer (const Employee * const baseClassPtr)
   {
   baseClassPtr->print();
   cout<< "\nearned $ "<< baseClassPtr->earnings() <<"\n\n";
   }// end function virtualViaPointer
   
   //call Employee virtual function print and earnings off a 
   //base-class reference using dynamic binding
   
   void virtualViaReference( const Employee &baseClassRef )
   {
   baseClassRef.print();
   cout<< "\n earned $ " << baseClassRef.earnings() << "\n\n";
   } //end function virtuallyViaReference
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

