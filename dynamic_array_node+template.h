#pragma once

#include "dynamic_array_node.h"

using namespace std;

template<typename T>
DynamicArrayNode<T>::DynamicArrayNode()
{
	_size = 0;
	_capacity = STANDARD_DYNAMIC_ARRAY_NODE_CAPACITY;
	_items = (T*)malloc(sizeof(T) * _capacity);
	cout << "Node constructed with capacity " << _capacity << endl << endl;
}

template<typename T>
DynamicArrayNode<T>::DynamicArrayNode(int capacity)
{
	_size = 0;
	_capacity = capacity;
	_items = (T*)malloc(sizeof(T) * _capacity);
	cout << "Node constructed with size " << capacity << endl;
}

template<typename T>
DynamicArrayNode<T>::~DynamicArrayNode()
{
	free(_items);
	cout << "Node Destructed with size " << _size << endl;
}

template<typename T>
int DynamicArrayNode<T>::size()
{
	delete this;
	return _size;
}

template<typename T>
bool DynamicArrayNode<T>::try_append(T newValue)
{
	if (_size < _capacity)
	{
		_items[_size++] = newValue;
		return true;
	}
	return false;
}

template<typename T>
T& DynamicArrayNode<T>::operator[](int position)
{
	if (position < _capacity)
	{
		return _items[position];
	}

	cout << "Index " << position << " is out of range" << endl;
	exit(0);
}