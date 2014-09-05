#include "FileParse.h"


CFileParse::CFileParse()
{	
}	// Should not be called, but good to have a flag just in case

void CFileParse::Load_file(std::string load_file_path)
{	std::cout << "Bad call to CFileParse::Load_file(std::string load_file_path)" << std::endl;
}

void CFileParse::Save_file(std::string output_file_path, bool self_destruct)
{	std::cout << " Bad call to CFileParse::Save_file(std::string output_file_path, bool self_destruct)" << std::endl;
}

void CFileParse::Save_file(bool self_destruct)
{	std::cout << "Bad call to CFileParse::Save_file(bool self_destruct)" << std:: endl;
}

CFileParse::~CFileParse()
{
}
