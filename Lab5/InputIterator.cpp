#include "InputIterator.h"

InputIterator::InputIterator(Toy* first) :current(first) {
}

Toy& InputIterator::operator ++ (int) { 
	current = this->current->Next;

	return *current;
}


Toy& InputIterator::operator ++ () {
	current = this->current->Next;

	return *current;
}

bool InputIterator::operator != (const InputIterator& it) {
	return current != it.current;
}
bool InputIterator::operator == (const InputIterator& it) {
	return current == it.current;
}
