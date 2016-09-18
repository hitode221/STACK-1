#ifndef stack_cpp
#define stack_cpp
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class stack
{
public:
	stack();
	stack(const stack&);
	~stack();
	size_t count();
	void push(T const &);
	T pop();
	stack& operator=(const stack&);
private:
	T* copy_mas(const T *, size_t, size_t);
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() : array_(nullptr), array_size_(0), count_(0){};

template <typename T>
stack<T>::stack(const stack& x) : array_size_(x.array_size_), count_(x.count_){
	array_ = copy_mas(x.array_, count_, array_size_);
}

template <typename T>
stack<T>::~stack(){
	delete[] array_;
}

template <typename T>
size_t stack<T>::count() { return count_; }

template <typename T>
void stack<T>::push(T const &a){
	if (array_ == nullptr){
		array_ = new T[1]; array_[0] = a;
		count_++; array_size_++;
	}
	else{
		if (count_ == array_size_){
			T *p = array_;
			array_ = copy_mas(p, count_, array_size_*2);
			delete[]p;
			array_size_ *= 2;
		}
		array_[count_] = a;
		count_++;
	}
}

template <typename T>
T stack<T>::pop(){
	if (count_> 0) {
		count_--;
		return array_[count_];
	}
}

template<typename T>
stack<T>& stack<T>::operator=(const stack& b){
	if (this != &b){
		delete[] array_;
		count_ = b.count_;
		array_size_ = b.array_size_;
		array_ = copy_mas(b.array_, count_, array_size_);
	}
	return *this;
}

template<typename T>
T* stack<T>::copy_mas(const T *p1, size_t c, size_t s){
	T *p2 = new T[s];
	copy(p1, p1 + c, p2);
	return p2;
}

#endif
