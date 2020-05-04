#include "ProcessingCenter.h"

template<class T>
void ProcessingCenter<T>::Order(RingContainer* container, function<bool(T, T)> predicate) {
	return;
}

template<class T>
int ProcessingCenter<T>::Pos(RingContainer* container, vector<T>* sequence, function<bool(T, T)> predicate) {
	auto iterator = container->inputBegin();
	auto startIterator = container->inputBegin();

	int positionCount = 0;

	do {
		auto local = iterator;

		bool flag = true;

		for (int i = 0; i < sequence->size(); i++) {
			if (!predicate((*sequence)[i], (*local))) {
				flag = false;
			}

			local++;
		}

		if (flag == true) {
			return positionCount;
		}

		positionCount++;
		iterator++;
	} while (startIterator != iterator);

	return -1;
}

template<class T>
void ProcessingCenter<T>::Distinct(RingContainer* container, function<bool(T, T)> predicate) {
	auto iterator = container->inputBegin();
	auto startIterator = container->inputBegin();

	do {
		auto local = iterator;

		bool flag = true;

		do{
			if (iterator != local && predicate(*iterator, *local)) {
				container->Remove(&*local);
			}

			local++;
		} while (local != startIterator);

		iterator++;
	} while (startIterator != iterator);
}
