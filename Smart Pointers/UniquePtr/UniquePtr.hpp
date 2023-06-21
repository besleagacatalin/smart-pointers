#pragma once

template<typename T>
class UniquePtr
{
public:
	UniquePtr();
	~UniquePtr();

	// use explicit to prevent implicit conversions from raw pointer to UniquePtr<T>
	explicit UniquePtr(T* obj); 

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	UniquePtr(UniquePtr&&);
	UniquePtr& operator=(UniquePtr&&);

	T* get() const;
	T& operator*() const;
	T* operator->() const;


private:
	T* ptr = nullptr;
};

template<typename T, typename... Args>
UniquePtr<T> make_unique(Args&&... args)
{
	return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

#include "UniquePtr.cpp"