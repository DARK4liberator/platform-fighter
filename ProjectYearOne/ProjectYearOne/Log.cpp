//Log.cpp

#include "Log.h"

Log::Log(const std::string &filename){
	m_stream.open(filename);
}

void Log::Write(const std::string &output){
	m_stream << output << std::endl;
	m_stream.flush();
};

Log::~Log(){
	m_stream.flush();
	m_stream.close();
}