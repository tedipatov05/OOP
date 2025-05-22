#pragma once
#include <iostream>

template <typename T>
class Optional
{
public:
	Optional();
	Optional(const T& value);
	Optional(const Optional<T>& other);
	Optional& operator=(const Optional<T>& other);
	~Optional();
	
	const T& operator*();
	bool has_value() const;
	T value() const;
	T value_or(T val) const;
	void reset();


private:
	T* data;
};

template <typename T>
Optional<T>::Optional() : data(nullptr) {
}

template <typename T>
Optional<T>::Optional(const T& value) : data(new T(value)) {
}

template <typename T>
Optional<T>::Optional(const Optional<T>& other) : data(other.data ? new T(*other.data) : nullptr) {
}

template <typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other) {
	if (this != &other) {
		delete data;
		data = other.data ? new T(*other.data) : nullptr;
	}
	return *this;
}

template <typename T>
Optional<T>::~Optional() {
	delete data;
}

template <typename T>
const T& Optional<T>::operator*() {
	return *data;
}

template <typename T>
bool Optional<T>::has_value() const{
	return data != nullptr;
}

template <typename T>
T Optional<T>::value() const {
	if (data) {
		return *data;
	}
	throw std::runtime_error("No value present");
}

template <typename T>
T Optional<T>::value_or(T val) const {
	if (data) {
		return *data;
	}
	return val;
}

template <typename T>
void Optional<T>::reset() {
	delete data;
	data = nullptr;
}