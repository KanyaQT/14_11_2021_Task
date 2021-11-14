#pragma once

#include <iostream>

#define STANDARD_DYNAMIC_ARRAY_NODE_CAPACITY 2

template<typename T>
class DynamicArrayNode
{
private:
	T* _items;
	int _capacity;
	int _size;
public:
	DynamicArrayNode();
	DynamicArrayNode(int size);
	~DynamicArrayNode();

	int size();
	bool try_append(T newValue);

	T& operator[](int index);
};