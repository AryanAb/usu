#include "Messages.h"

namespace usu
{
	std::string Messages::error(const std::string &msg)
	{
		return "\033[1;31mERROR\033[0m: " + msg;
	}

	std::string Messages::warning(const std::string &msg)
	{
		return "\033[1;33mWARNING\033[0m: " +  msg;
	}
}
