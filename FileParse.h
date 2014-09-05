#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <time.h>
#include <algorithm>


class CFileParse
{	public:
	CFileParse();
	virtual void Load_file(std::string load_file_path);
	virtual void Save_file(std::string output_file_path, bool self_destruct);
	virtual void Save_file(bool self_destruct);	
	virtual ~CFileParse();
};

namespace Parse_functions
{	void Log_exception(std::string e);
	unsigned int GetDTI ();
	std::string Get_directory();
};

#ifdef _WIN64
    #include <direct.h>
    #define GetCurrentDir _getcwd
#elif _WIN32
    #include <direct.h>
    #define GetCurrentDir _getcwd
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
		#include <unistd.h>
		#define GetCurrentDir getcwd
    #elif TARGET_OS_IPHONE
        #include <unistd.h>
		#define GetCurrentDir getcwd
    #elif TARGET_OS_MAC
        #include <unistd.h>
		#define GetCurrentDir getcwd
    #else
        #include <unistd.h>
		#define GetCurrentDir getcwd
    #endif
#elif __linux
    #include <unistd.h>
    #define GetCurrentDir getcwd
#elif __unix // all unices not caught above
    #include <unistd.h>
    #define GetCurrentDir getcwd
#elif __posix // if not posix, what the hell are you running?
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

