#include "WriteAll.h"


#include <iostream>
#include <fstream>
#include <iostream>

#include "Toy.h"

using namespace std;

Toy* GetAll(int& itemsCount) {

    ifstream file;

    file.open("data.txt");    

    string values((std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));

    file.close();

    string cellDelimiter = "&";
    string rowDelimiter = "||";

    size_t rowPos = 0;

    Toy* outputValues = new Toy[100];

    for (int rowCount = 0; (rowPos = values.find(rowDelimiter)) != string::npos; rowCount ++) {
        string rowToken;

        rowToken = values.substr(0, rowPos);

        string * rowArray =new string [4];        

        size_t cellPos = 0;


        for (int i = 0; (cellPos = rowToken.find(cellDelimiter)) != string::npos; i++) {
            string token;

            token = rowToken.substr(0, cellPos);

            rowArray[i] = token;

            rowToken.erase(0, cellPos + cellDelimiter.length());
        }


        outputValues[rowCount] = Toy(rowArray);
        (itemsCount)++;

        values.erase(0, rowPos + rowDelimiter.length());

        if (itemsCount == 100) {
            break;
        }
    }

    return outputValues;
}