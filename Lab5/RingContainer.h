#pragma once
#include "Toy.h"
#include "InputIterator.h"
#include "ReverseIterator.h"

class RingContainer
{
	Toy* toy;
public:
	RingContainer(Toy* first, Toy *second);
	InputIterator inputBegin();
	ReverseIterator reverseBegin();

	void Add(Toy* item);
};

