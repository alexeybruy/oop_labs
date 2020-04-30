#include "Toy.h"
#include <iostream>
#include <fstream>
#include <iostream>

Toy::Toy() {

}


Toy::Toy(string* values) {
	this->Name = values[0];
	this->Count = stoi(values[1]);
	this->Price = stof(values[2]);
	this->MinimalAge = stof(values[3]);
}

void Toy::Print() {
	cout << "Name: " << this->Name << endl;
	cout << "Count: " << this->Count << endl;
	cout << "Price: " << this->Price << endl;
	cout << "MinimalAge: " << this->MinimalAge << endl << endl;
}