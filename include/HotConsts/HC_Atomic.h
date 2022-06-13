#pragma once
#include <mutex>

namespace HotConsts
{

// TODO: Implement template specializations to allow for true atomics on valid types.

// A type which simulates an atomic variable but works for all types.
// Internally uses locking to prevent data races.
template <typename T>
struct HC_Atomic
{
public:
	typedef T type;

	// Casting overloads (allows direct use of the value name)
	operator T() const noexcept
	{
		std::lock_guard<std::mutex> lck(_mtx);
		T returnval = _val;
		return returnval;
	}
	operator T() const volatile noexcept
	{
		std::lock_guard<std::mutex> lck(_mtx);
		T returnval = _val;
		return returnval;
	}

	// Assignment operators
	// Note: these return a reference to the LHS for the purpose of facilitating 
	// the HC() macro.
	HC_Atomic<T>& operator = (const T& other) noexcept
	{
		std::lock_guard<std::mutex> lck(_mtx);
		_val = other;
		return *this;
	}
	HC_Atomic<T>& operator = (const T& other) volatile noexcept
	{
		std::lock_guard<std::mutex> lck(_mtx);
		_val = other;
		return *this;
	}
	HC_Atomic& operator = (const HC_Atomic&) = delete;

	// Constructors & Destructor
	HC_Atomic() { _val = T{}; };
	HC_Atomic(T val) { _val = val; }
	HC_Atomic(const HC_Atomic&) = delete;
	
private:
	T _val;
	mutable std::mutex _mtx;
};

}
