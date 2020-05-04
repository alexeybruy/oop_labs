#include "Toy.h"
#include <iostream>
#include <fstream>
#include <iostream>

Toy::Toy() {

}

void Toy::Print() {
	cout << "Name: " << this->Name << endl;
	cout << "Count: " << this->Count << endl;
	cout << "Price: " << this->Price << endl;
	cout << "MinimalAge: " << this->MinimalAge << endl << endl;
}