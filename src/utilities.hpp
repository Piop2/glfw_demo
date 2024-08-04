#if !defined(OPENGLDEMO_UTILITIES_H)
#define OPENGLDEMO_UTILITIES_H
#pragma once

#include <string>

inline void ReadToString(const char* filepath, std::string& out);

inline std::string ReadToString(const char* filepath);

const char* ExtractProgramName(const char* full);

void WriteLog(const char* msg);

#endif // OPENGLDEMO_UTILITIES_H
