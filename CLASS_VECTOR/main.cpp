#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include "Vector.cpp"

using namespace std;

TEST_CASE("Push test")
{
	Vector<int> v;
	v.push(13);
	v.push(553);
	v.push(1);
	Vector<int> c;
	c.push(13);
	c.push(553);
	c.push(1);

	CHECK(v[0] == 1);
	CHECK(v[1] == 553);
	CHECK(c[2] == 13);
}

TEST_CASE("Modify value test")
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v[0] = 6;

	CHECK(v[0] == 6);
	CHECK(v[1] == 2);
	CHECK(v[2] == 3);
}

TEST_CASE("Equal vectors test")
{
	Vector<double> a,b;
	a.push(4.5);
	b.push(4.5);
	
	CHECK(a == b);
}

TEST_CASE("Addition test")
{
	Vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	Vector<int> b(a);
	b += 4;

	CHECK(a + 4 == b);
}

TEST_CASE("Equality test")
{
	Vector<int> a;
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);

	Vector<int> b(a);
	b += 44;

	CHECK(a != b);
}

TEST_CASE("Length test")
{
	Vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);

	Vector<int> b;
	b.push_back(3);
	b.push_back(3);
	b.push_back(3);

	CHECK(a.length() == b.length());
}

int main()
{
	// Run doctest
	doctest::Context().run();
}