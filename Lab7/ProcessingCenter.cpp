#include "Toy.h"
#include <iostream>
#include <deque>
#include "Toy.h"
#include <functional>
#include <vector>

using namespace std;

template<class T> class ProcessingCenter
{
public:
	void Order(deque<T>* container, function<bool(T, T)> predicate);
	int Pos(deque<T>* container, deque<T>* sequence, function<bool(T, T)> predicate);
	void Distinct(deque<T>* container, function<bool(T, T)> predicate);
};

template<class T>
void ProcessingCenter<T>::Order(deque<T>* container, function<bool(T, T)> predicate) {
	auto first = container->begin();
	auto last = container->end();

	for (auto d = (last - first) / 2; d != 0; d /= 2) {
		for (auto i = first + d; i != last; ++i) {
			for (auto j = i; j - first >= d && predicate(*j, *(j - d)); j -= d) {
				std::swap(*j, *(j - d));
			}
		}
	}
}

template<class T>
int ProcessingCenter<T>::Pos(deque<T>* container, deque<T>* sequence, function<bool(T, T)> predicate) {
	int position = 0;

	for (auto i = container->begin(); i != container->end(); i++) {
		if (container->end() - i < sequence->size()) {
			break;
		}

		bool flag = true;

		auto local = i;
		auto j = sequence->begin();

		while (j != sequence->end() && local != container->end()){
			if (!predicate(*j, *local)) {
				flag = false;
				break;
			}

			j++;
			local++;
		}

		if (flag == true) {
			return position;
		}

		position++;
	}

	return -1;
}

template<class T>
void ProcessingCenter<T>::Distinct(deque<T>* container, function<bool(T, T)> predicate) {
	for (auto i = 0; i < container->size(); i++) {
		for (auto j = container->begin() + i + 1; j != container->end(); ) {
			if (predicate(*j, container->at(i))) {
				j = container->erase(j);
			}
			else {
				j++;
			}
		}
	}
}
