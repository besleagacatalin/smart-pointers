#include <iostream>
#include <memory>
#include "UniquePtr/UniquePtr.hpp"


int main()
{
	UniquePtr ptr = make_unique<int>();
	std::unique_ptr ptr2 = std::make_unique<int>();

	return 0;
}
