#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	cout << "Size: " << v.getSize() << endl;
	v.pop_front();
	v.print();

	Vector<int> v2;
	cout << v2.isEmpty() << endl;
	v2.push_back(4);
	v2.push_back(5);

	Vector<int> mix;
	mix += v2;
	cout << mix << endl;

	Vector<int> PUSHAT;
	PUSHAT.push_back(1);
	PUSHAT.push_back(2);
	PUSHAT.push_back(3);

	PUSHAT.push_at(456, 2);
	cout << PUSHAT << endl;

	Vector<int> v3;
	v3.push_back(100);
	v3.push_back(200);
	v3.push_back(300);
	v3.push_back(400);
	v3.pop_at(2);

	v3.pop_by_data(300);
	cout << v3;
}