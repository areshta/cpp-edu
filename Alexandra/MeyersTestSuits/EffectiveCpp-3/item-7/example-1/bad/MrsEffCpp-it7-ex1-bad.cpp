/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate usein correpondent item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective C++. Third edition
//Item: #7.  Declare destructors virtual in polymorphic base classes.
//Code type: bad

#include <iostream>
#include <vector>
#include "some-header.h"

using std::vector;

int main()
{
	cout << "Effective C++. Third edition. Item 7. Bad code" << endl;

	vector<SomeBase*> someVect;
	someVect.push_back( new Child1() );
	someVect.push_back( new Child2() );

	for ( int i = 0; i < someVect.size(); i++)
	{
		delete someVect[i];
	}
	
}
