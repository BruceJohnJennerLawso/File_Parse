#include "FileParse.h"


CFileParse::CFileParse()
{	
}	// Should not be called, but good to have a flag just in case

void CFileParse::Load_file(std::string load_file_path)
{	std::cout << "Bad call to CFileParse::Load_file(std::string load_file_path)" << std::endl;
}

void CFileParse::Output_Data()
{	std::cout << "Bad call to CFileParse::Output_Data()" << std::endl;
}

bool CFileParse::Save_file(std::string output_file_path, bool self_destruct)
{	std::cout << " Bad call to CFileParse::Save_file(std::string output_file_path, bool self_destruct)" << std::endl;
	return false;
}

bool CFileParse::Save_file(bool self_destruct)
{	std::cout << "Bad call to CFileParse::Save_file(bool self_destruct)" << std:: endl;
	return false;
}

CFileParse::~CFileParse()
{	std::cout << "Bad call to CFileParse::~CFileParse()" << std::endl;
}



