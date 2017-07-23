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
//Item: #5.  Exampe 3. auto + hiden proxy class.
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
	cout << "Effective Modern C++. The first edition. Item 5. Example 3: auto + hiden proxy class. Bad code." << endl;
	
	SomeClass sc;

	bool someFeature5 = feachers(sc)[5]; // auto is bad, bool is OK
	bool someFeature1 = feachers(sc)[1]; // auto is bad, bool is OK
	process(sc, someFeature1);
	process(sc, someFeature5); 

	return 0;
}
