#include "utilities.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <memory>

std::string ReadToString(const char* filepath)
{
	std::ifstream input_file_stream(filepath);
	if (!input_file_stream.is_open())
	{
		throw("invalid file path");
	}
	std::stringstream data_stream;
	data_stream << input_file_stream.rdbuf();
	return data_stream.str();
}

void ReadToString(const char* filepath, std::string& out)
{
	// std::ifstream input_file_stream(filepath);
	// if (!input_file_stream.is_open())
	// {
	// 	throw("invalid file path");
	// }
	// std::stringstream data_stream;
	// data_stream << input_file_stream.rdbuf();
	// out = data_stream.str();
	out = ReadToString(filepath);
}

const char* ExtractProgramName(const char* full)
{
	std::string p1 = full;
	static std::string p2;
	p2.clear();
	p2 = p1.substr(
		p1.find_last_of("/\\") + 1,  // from after last slash
		(p1.length() - p1.find_last_of("/\\")) - (p1.length() - (p1.find_last_of(".")) + 1)  // up to last dot
	);
	return p2.c_str();
}

#if defined(_DEBUG)
void WriteLog(const char* msg)
{
	std::ofstream logs;
	logs.open("our_log.txt", std::ofstream::app | std::ofstream::out);
	logs << msg;
	logs.close();
}
#else
void WriteLog(const char* msg)
{
}
#endif // _DEBUG
