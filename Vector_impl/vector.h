#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<stdexcept>

template<typename T>
class Vector {
public:
	Vector(); 
	Vector(const Vector& other);
	Vector(Vector&& other);
	Vector& operator=(Vector&& other); 
	~Vector();
	Vector& operator=(const Vector& other);
	T& operator[](int index);
	void push_back(T elem);
	void push_front(T elem);
	void pop_back();
	void pop_front();
	void insert(int position,T value);
	void remove(int position);
	void clear();
	void print();
	int get_size() const;
private:
	int m_capacity;
	int m_size;
	T* m_arr;
};

#include "vector.cpp"

#endif // VECTOR_H
