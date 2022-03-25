#pragma once

#include <string>

namespace usu
{
	class Exception
	{
	public:
		Exception(const std::string &process, const std::string &msg);
		void details() const;
	private:
		std::string process;
		std::string msg;
	};
};