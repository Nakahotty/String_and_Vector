#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Vector
{
public:
	T* data;
	size_t size;

	void init();
	Vector();
	Vector(const Vector<T>& other);
	void push_back(const T& x);
	void push(const T& x);
	Vector<T> operator+ (const Vector<T>& other) const;
	Vector<T> operator+ (const T& x) const;
	Vector<T>& operator+= (const T& x);
	T& operator[] (size_t i);
	Vector<T>& operator= (const Vector<T>& other);
	T operator[] (size_t i) const;
	size_t length() const;

	// NEW OPERATORS
	bool operator==(const Vector& other) const; 
	bool operator!=(const Vector& other) const;
};

template <typename T>
ostream& operator <<(ostream& stream, Vector<T> v);