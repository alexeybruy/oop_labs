#include "RingContainer.h"
#include "InputIterator.h"
#include "ReverseIterator.h"
#include "Toy.h"

RingContainer::RingContainer(Toy* first, Toy* second) {
	toy = first;
	toy->Next = second;
	toy->Next->Next = toy;
}

InputIterator RingContainer::inputBegin() { return toy; }

ReverseIterator RingContainer::reverseBegin() { return toy; }

void RingContainer::Add(Toy* item) {
	Toy* currentPoiner = toy;

	for (; currentPoiner->Next != toy; currentPoiner = currentPoiner->Next) {
	}

	currentPoiner->Next = item;
	item->Next = this->toy;

	return;
}
