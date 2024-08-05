#if !defined(OPENGLDEMO_UTILITIES_H)
#define OPENGLDEMO_UTILITIES_H
#pragma once

#include <string>

void ReadToString(const char* filepath, std::string& out);
std::string ReadToString(const char* filepath);

const char* ExtractProgramName(const char* full);

void WriteLog(const char* msg);

#endif // OPENGLDEMO_UTILITIES_H
