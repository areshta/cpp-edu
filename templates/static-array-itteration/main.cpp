#include <iostream>
#include <utility>

#include <array>

using namespace std;

const size_t arraySize = 3;

const std::array<string,arraySize> names = {"one","two","three"};

template<size_t index>
void prepareJiraExec(string& result, std::array<string,arraySize> names)
{
    result += names[index] + " "; 
}

template <size_t ... ArraySize>
void prepareJiraItr (string& result, std::array<string,3> names, std::integer_sequence<size_t, ArraySize...> const &)
{ 
    ((prepareJiraExec<ArraySize>(result, names)), ...); 
}

template <size_t ArraySize>
void prepareJira (string& result, std::array<string,ArraySize> names)
{ 
     prepareJiraItr(result, names, std::make_integer_sequence<size_t, ArraySize>{}); 
}
 

int main()
{
    cout << "__cplusplus = " << __cplusplus << endl;
    std::cout << "Start!\n";
    string result;
    prepareJira<arraySize>(result, names);
    cout << result << "\n";
}