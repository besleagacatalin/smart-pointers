#include<utility>
#include "UniquePtr.hpp"

template<typename T>
UniquePtr<T>::UniquePtr() : ptr(nullptr) {}

template<typename T>
UniquePtr<T>::UniquePtr(T* obj) : ptr(obj) {}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& obj) : ptr(std::exchange(obj.ptr, nullptr)) {}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& obj)
{
	UniquePtr<T> tmp = std::move(obj);
	std::swap(ptr, tmp.ptr);
	return *this;
}

template<typename T>
T* UniquePtr<T>::get() const
{
	return ptr;
}

template<typename T>
T& UniquePtr<T>::operator*() const
{
	return *ptr;
}

template<typename T>
T* UniquePtr<T>::operator->() const
{
	return ptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
	delete ptr;
}