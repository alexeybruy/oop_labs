#include "FileManager.h"
#include<iostream>
#include<fstream>



std::ifstream::pos_type filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

void FileManager::Add(Toy* toy) {
	int length = filesize("data.txt");

	fstream file("data.txt", ios::binary | ios::in | ios::out);

	file.seekp(length);

	file.write((char*)toy, sizeof(Toy));

	file.close();
}

void FileManager::OrderDown(function<bool(Toy, Toy)> predicate) {
	this->Order(false, predicate);
}

void FileManager::OrderUp(function<bool(Toy, Toy)> predicate) {
	this->Order(true, predicate);
}

void FileManager::Order(bool up, function<bool(Toy, Toy)> predicate) {
	int fileLength = filesize("data.txt");
	int n = fileLength / sizeof(Toy);

	fstream file("data.txt", ios::binary | ios::in | ios::out);

	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			Toy left;
			file.seekg((j - 1) * sizeof(Toy));
			file.read((char*)&left, sizeof(Toy));

			Toy right;
			file.seekg((j) * sizeof(Toy));
			file.read((char*)&right, sizeof(Toy));

			if (up == false && !predicate(left,right)) {
				break;
			}

			if (up == true && predicate(left, right)) {
				break;
			}

			file.seekp((j) * sizeof(Toy));
			file.write((char*)&left, sizeof(Toy));

			file.seekp((j - 1) * sizeof(Toy));
			file.write((char*)&right, sizeof(Toy));
		}
	}
}

void FileManager::Print() {
	int fileLength = filesize("data.txt");
	int length = fileLength / sizeof(Toy);

	fstream file("data.txt", ios::binary | ios::in);

	file.seekp(0);

	for (int i = 0; i < length; i++) {
		Toy toy;

		file.read((char*) &toy, sizeof(Toy));

		toy.Print();
	}
}