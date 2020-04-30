#include "ReverseIterator.h"
#include "Toy.h"

ReverseIterator::ReverseIterator(Toy* first) :current(first) {
}

Toy& ReverseIterator::operator ++ (int) { 
	Toy* currentPoiner = current;

	for (; currentPoiner->Next != this->current; currentPoiner = currentPoiner->Next) {
	}

	current = currentPoiner;

	return *current;
}

Toy& ReverseIterator::operator ++ () {
	Toy* currentPoiner = current;

	for (; currentPoiner->Next != this->current; currentPoiner = currentPoiner->Next) {
	}

	current = currentPoiner;

	return *current;
}

bool ReverseIterator::operator != (const ReverseIterator& it) {
	return current != it.current;
}
bool ReverseIterator::operator == (const ReverseIterator& it) {
	return current == it.current;
}

Toy& ReverseIterator::operator* () {
	return *current;
}