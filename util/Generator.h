#pragma once
#include <functional>
template <typename T>
class Generator {
	unsigned int counter = 0;
	std::function<T(void)> generatorSupplier;
public:
	Generator();
	~Generator();
};

