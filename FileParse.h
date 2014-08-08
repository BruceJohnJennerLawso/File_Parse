#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>


class CFileParse
{	public:
	CFileParse();
	virtual void Load_file(std::string load_file_path);
	virtual void Output_Data();		// its kind of useful, I guess
	virtual bool Save_file(std::string output_file_path, bool self_destruct);
	virtual bool Save_file(bool self_destruct);	
	virtual ~CFileParse();
};

