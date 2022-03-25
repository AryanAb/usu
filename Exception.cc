#include "Exception.h"

#include <iostream>

namespace usu
{
	Exception::Exception(const std::string &process, const std::string &msg) : process{process}, msg{msg}
	{
	}

	void Exception::details() const
	{
		std::cout << "Compilation failed while " << process << "." << std::endl;
		std::cout << msg << std::endl;
	}
};
