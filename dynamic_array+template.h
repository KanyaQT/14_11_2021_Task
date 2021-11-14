#pragma once

#include "dynamic_array.h"

using namespace std;

template<typename T>
DynamicArray<T>::DynamicArray()
{
	_nodeCount = 1;
	_nodes = (DynamicArrayNode<T>*)malloc(sizeof(DynamicArrayNode<T>) * _nodeCount);

	DynamicArrayNode<T> n;
	_nodes[0] = n;

	cout << "Dynamic array constructed" << endl;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	free(_nodes);
	cout << endl << "Dynamic array freed" << endl;
}

template<typename T>
T& DynamicArray<T>::operator[](int index)
{
	cout << _nodes[0];
}

template<typename T>
void DynamicArray<T>::append(T item)
{
	if (_nodes[_nodeCount - 1].try_append(item))
	{
		cout << "Successfully added item " << item << "!" << endl;
	}
	else
	{
		_nodes = (DynamicArrayNode<T>*)realloc((void*)_nodes, sizeof(DynamicArrayNode<T>) * ++_nodeCount);

		DynamicArrayNode<T> n;
		_nodes[_nodeCount - 1] = n;

		_nodes[_nodeCount - 1].try_append(item);
		cout << "New node created with item " << _nodes[_nodeCount - 1][0] << endl;
	}

	_size++;
}

template<typename T>
int DynamicArray<T>::size()
{
	return _size;
}