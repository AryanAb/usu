#include "Exception.h"

#include <iostream>

namespace usu
{
	Exception::Exception(const std::string &process, const std::string &msg) : process{process}, msg{msg}
	{
	}

	void Exception::details() const
	{
		std::cerr << "Compilation failed while " << process << "." << std::endl;
		std::cerr << msg << std::endl;
	}
};
