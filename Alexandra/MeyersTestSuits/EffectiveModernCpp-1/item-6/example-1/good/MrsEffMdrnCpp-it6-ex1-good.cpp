/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/
/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #6.  Exampe 1. auto + hiden proxy class.
//Code type: good

#include <iostream>
#include <vector>

using namespace std;

using VBool = const vector<bool>;

class SomeClass
{
private:
	VBool m_features = {false, false, false, false, true, true, false, false};
friend const VBool& feachers(const SomeClass& sc);
};

const VBool& feachers(const SomeClass& sc)
{
	return sc.m_features;
}


const void process(SomeClass sc, bool b)
{
	cout << b << endl;
}
int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 6. Example 1: auto + hiden proxy class. Bad code." << endl;
	
	SomeClass sc;

	auto someFeature5 = static_cast<bool>(feachers(sc)[5]); // the explicit type initialaizer idiom using
	auto someFeature1 = static_cast<bool>(feachers(sc)[1]); // the explicit type initialaizer idiom using
	process(sc, someFeature1);
	process(sc, someFeature5); 

	return 0;
}
