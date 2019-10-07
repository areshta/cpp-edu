//============================================================================
// Name        : linux_service.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
	int a=0;
	int b=0;

	while(true){

		ifstream infile("/var/tmp/input_data.txt");
		infile >> a >> b;

		ofstream outfile("/var/tmp/output_data.txt");
		outfile << a+b ;
		outfile.flush();
		cout << outfile.fail() << endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		cout << a <<" " << b << endl; // prints !!!Hello World!!!

	}
	return 0;
}
