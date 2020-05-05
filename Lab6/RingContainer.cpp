#include "RingContainer.h"
#include "Toy.h"
#include "InputIterator.h"

RingContainer::RingContainer(Toy* first, Toy* second) {
	toy = first;
	toy->Next = second;
	toy->Next->Next = toy;
}

InputIterator RingContainer::inputBegin() { return toy; }

void RingContainer::Add(Toy* item) {
	Toy* currentPoiner = toy;

	for (; currentPoiner->Next != toy; currentPoiner = currentPoiner->Next)
	{
	}

	currentPoiner->Next = item;
	item->Next = this->toy;

	return;
}

void RingContainer::Remove(Toy* item) {
	Toy* currentPoiner = item;

	for (; currentPoiner->Next != item; currentPoiner = currentPoiner->Next)
	{
	}

	currentPoiner->Next = item->Next;
}

void RingContainer::MoveUp(Toy* item) {
	Toy* itemPointer = item;

	for (; itemPointer->Next != item; itemPointer = itemPointer->Next)
	{
	}

	auto next = item->Next;

	item->Next = item->Next->Next;

	next->Next = item;

	itemPointer->Next = next;
}