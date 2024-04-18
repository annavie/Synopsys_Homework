#include"vector.h"

int main() {
	Vector<int> myVector;
	for (int i = 0; i < 10; ++i) {
		myVector.push_back(i);
	}

	myVector.print();
	myVector.pop_back();
	myVector.print();
	myVector.push_front(99);
	myVector.print();
	myVector.pop_front();
	myVector.insert(5,15);
	myVector.print();
	myVector.remove(5);
	myVector.print();
	myVector.clear();
	myVector.print();
	//Vector<int> newVector = foo<int>();
	//newVector.print();

	//Vector<int> other;
	//other = foo<int>();
	//other.print();
	
	return 0;
}
