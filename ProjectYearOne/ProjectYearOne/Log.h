//Log.h

#pragma once

#include <string>
#include <fstream>

class Log{
public:
	Log(const std::string &filename);
	void Write(const std::string &output);
	~Log();

private:
	std::ofstream m_stream;
};