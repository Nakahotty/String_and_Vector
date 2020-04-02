#include <iostream>
#include "Vector.h"

using namespace std;

template <typename T>
void Vector<T>::init()
{
	this->data = nullptr;
	this->size = 0;
}

template <typename T>
Vector<T>::Vector()
{
	init();
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->data = new T[other.size];
	for (size_t i = 0; i < other.size; i++)
	{
		this->data[i] = other[i];
	}

	this->size = other.size;	
}

template <class T>
void Vector<T>::push_back(const T& x)
{
	T* biggerBuffer = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		biggerBuffer[i] = this->data[i];
	}

	biggerBuffer[size] = x; // set the last item to X
	++size;

	delete[] data;
	this->data = biggerBuffer;
}

template <typename T>
void Vector<T>::push(const T& x)
{
	T* biggerBuffer = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		biggerBuffer[i + 1] = data[i];
	}

	biggerBuffer[0] = x; // set the first item to X
	++size;

	delete[] data;
	this->data = biggerBuffer;
}

template <class T>
Vector<T> Vector<T>::operator+ (const Vector<T>& other) const
{
	Vector result;

	result.data = new T[this->size + other.size];
	for (size_t i = 0; i < this->size; i++)
	{
		result.data[i] = this->data[i];
	}

	for (size_t i = 0; i < this->size; i++)
	{
		result.data[this->size + i] = other.data[i];
	}

	result.size = this->size + other.size;
	return result;
}

template <typename T>
Vector<T> Vector<T>::operator+ (const T& x) const
{
	Vector<T> result(*this);
	result += x;
	return result;
}

template <typename T>
Vector<T>& Vector<T>::operator+= (const T& x)
{
	this->push_back(x);
	return *this;
}


template <typename T>
T& Vector<T>::operator[] (size_t i)
{
	return data[i];
}

template <class T>
T Vector<T>::operator[] (size_t i) const
{
	return data[i];
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
	if (this != &other)
	{
		delete[] this->data;

		this->data = new T[other.size];
		for (size_t i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}

		this->size = other.size;
	}

	return *this;
}

template <class T>
size_t Vector<T>::length() const
{
	return size;
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& other) const
{
	if (this->size != other.size)
		return false;

	for (size_t i = 0; i < this->size; i++)
	{
		if (this->data[i] != other.data[i])
			return false;
	}

	return true;
}

template <class T>
bool Vector<T>::operator!=(const Vector<T>& other) const
{
	return !(this == &other);
}

template <class T>
ostream& operator <<(ostream& stream, Vector<T> v)
{
	for (size_t i = 0; i < v.size; i++)
	{
		cout << v.data[i] << " ";
	}

	return stream;
}