#pragma once
#include "Toy.h"
#include "InputIterator.h"

class RingContainer
{
	Toy* toy;
public:
	RingContainer(Toy* first, Toy* second);
	InputIterator inputBegin();

	void Add(Toy* item);
	void Remove(Toy* item);
	void MoveUp(Toy* item);
};

