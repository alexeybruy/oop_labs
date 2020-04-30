#pragma once
#include "Toy.h"
#include <string>
#include <iostream>

using namespace std;

void Toy::SetName(string name) {
	for (int i = 0; i < name.length(); i++) {
		this->Name[i] = name[i];
	}
}

Toy::Toy() {

}

void Toy::Print() {
	cout << "Name: " << this->Name << endl;
	cout << "Count: " << this->Count << endl;
	cout << "Price: " << this->Price << endl;
	cout << "MinimalAge: " << this->MinimalAge << endl << endl;
}

void Toy::FillWithConsole() {
    Toy& toy = *this;

    cout << "Pls, insert Toy info" << endl;
    cout << "Name" << endl;

    cin >> toy.Name;

    cout << "Count" << endl;

    while (true)
    {
        try {
            string val;
            cin >> val;
            int intVal = stoi(val);

            toy.Count = intVal;

            break;
        }
        catch (...) {
            cout << "Invalid input, try again" << endl;
        }
    }

    cout << "Price" << endl;

    while (true)
    {
        try {
            string val;
            cin >> val;
            float floatVal = stof(val);

            toy.Price = floatVal;

            break;
        }
        catch (...) {
            cout << "Invalid input, try again" << endl;
        }
    }

    cout << "Minimal Age" << endl;

    while (true)
    {
        try {
            string val;
            cin >> val;
            float floatVal = stof(val);

            toy.MinimalAge = floatVal;

            break;
        }
        catch (...) {
            cout << "Invalid input, try again" << endl;
        }
    }
}
