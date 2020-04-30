#include <iostream>
#include <fstream>
#include <iostream>

#include "Toy.h"

Toy* GetNewFromConsole() {
    Toy* toyObject = new Toy();

    Toy& toy = *toyObject;

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

    return &toy;
}
