// TestCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Data {
public:
	int info;

	int subInfo;

	Data(int val) {
		info = val;
	}

	Data() {
		this->info = 17;
		this->subInfo = 23;
	}
};

void Process(Data** data) {
	(*data) = new Data(15 + (**data).info);
}


int main()
{
	Data * a = new Data(10);

	Data * b = a;
	
	Process(&a);

	cout << (*b).info << " " << (*a).info << endl;

	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
