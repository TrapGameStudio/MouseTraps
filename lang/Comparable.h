#pragma once
template<typename T>
class Comparable {
public:
	virtual int compareTo(const T* o) const = 0;
	virtual ~Comparable();
};

template<typename T>
inline Comparable<T>::~Comparable() {}