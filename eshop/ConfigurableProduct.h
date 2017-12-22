#pragma once
#include "Product.h"

class ConfigurableProduct :public Product {
public:
	bool solid;
	int width;
	int height;
	int depth;
	int mass;
};
