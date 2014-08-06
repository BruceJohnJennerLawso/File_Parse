#include "TTxt_File.h"
using namespace std;


TTxt_File::TTxt_File(std::string input_file_path, bool file_autocreate)
{	file_index = 0;
	file_read = false;
	file_path = "NULL";
	switch(this->Check_file_exists())
	{	case false:
		{	if(file_autocreate == true)
			{	Create_text_file(exe_path, file_offset);
				goto load;	// Bahahahaha
			}
			else
			{	file_read = false;
			}
			break;
		}
		case true:
		{	load:
			Load_file(exe_path.append(file_offset));
			break;
		}
	}
}


void TTxt_File::Load_file(std::string load_file_path)
{	ifstream file (file_offset);
	if (file.is_open())
	{	file_read = true;	// Indicate that the file is now copied to memory
		file_path = file_offset;
		std::string line; 
		while (std::getline(file,line))
		{	Process_input(line);	// Nom, nom, nom, tasty bytes of data	
		}	line.clear();
	}	
	file.close();
}

void TTxt_File::Process_input(std::string line, unsigned int insert_location)
{	text_index.emplace((text_index.begin() + insert_location), line);
	file_index++;
}

void TTxt_File::Process_input(std::string line)
{	text_index.emplace_back(line);
	file_index++;
}	

void TTxt_File::Insert_data(std::vector<std::string>& input_string_vector)	// reference pass seems reasonable in this case
{	for(std::vector<std::string>::iterator it = i.begin(); it != i.end(); ++it)
	{	Process_input(*it);
	}
}

void TTxt_File::Insert_data(std::string input_string)
{	Process_input(i);
}

void TTxt_File::Overwrite_data(std::string input_to_write, unsigned int index)
{	unsigned int cy = 0;
	for(std::vector<std::string>::iterator it = text_index.begin(); it != text_index.end(); ++it)
	{	if (cy == index)
		{	(it)->assign(i);
		}
		else
		{	++cy;
		}
	}
}

void TTxt_File::Insert_blank_lines(unsigned int number_of_lines)
{	for (unsigned int cy = 0; cy != n; ++cy)
	{	Process_input("");
	}
}

void TTxt_File::Remove_line(unsigned int index_to_remove)
{	std::vector<std::string>::iterator it = text_index.begin()+index;
	if(index <= file_index)
	{	text_index.erase(it);
		file_index--;
	}	
	else
	{	// ??? I dunno, maybe tell the user not to do that?
	}
}

std::string TTxt_File::Access_data(unsigned int index)
{	unsigned int cy = 0;
	for(std::vector<std::string>::iterator it = text_index.begin(); it != text_index.end(); ++it)
	{	if (cy == index)
		{	return *it;
		}
		else
		{	++cy;
		}
	}
	return "BAD_INDEX";	
}

void TTxt_File::Output_Data()
{	for(unsigned int cy = 0; cy != text_index.size(); ++cy)
	{	cout << cy << "	" << text_index.at(cy) << endl;
	}
}

std::string TTxt_File::Get_path()
{	return file_path;
}

unsigned int TTxt_File::Get_index_size()
{	return file_index;
}	// Pretty much what it says on the llama

bool TTxt_File::Read_state()
{	return file_read;
}	// A check on whether the read was successful

bool TTxt_File::Check_file_exists()
{	bool check = false;
	ifstream file (file_path);
	if(file.is_open())
	{	check = true;
	}	file.close();
	return check;
}

bool TTxt_File::Save_file(std::string output_file_path, bool self_destruct)
{	if(Check_file_exists(output_file_path))
	{	std::remove(output_file_path.c_str());
	}
	ofstream file (output_file_path);
	if (file.is_open())
	{	for (std::vector<std::string>::iterator it = Text_index.begin(); it != Text_index.end(); ++it)
		{	file << ((*it).append("\n"));		// maybe this could be << std::endl;
		}
	}
	else
	{	return false
	}
	file.close();
	// It read funny without a comment in here.
	if (selfdestruct == true)
	{	this->~TTxt_File();
	}
	else
	{	return true;
	}	
}

bool TTxt_File::Save_file(bool self_destruct)
{	if(this->Check_file_exists())
	{	std::remove(file_path.c_str());
	}
	ofstream file (File_path);
	if (file.is_open())
	{	for (std::vector<std::string>::iterator it = Text_index.begin(); it != Text_index.end(); ++it)
		{	file << ((*it).append("\n"));		// maybe this could be << std::endl;
		}
	}
	else
	{	return true;
	}
	file.close();
	// It read funny without a comment in here.
	if (selfdestruct == true)
	{	this->~TTxt_File();
	}
	else
	{	return true;
	}	
}

TTxt_File::~TTxt_File()
{	text_index.clear();
	file_read = false;	// I have no idea why
}


// Non-member function to remove the Cmd_dashdash dependency ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Create_text_file(std::string directory, std::string file_path)
{	switch(Check_file_exists(directory.append(file_path)))	// Please note, input has to be complete, including the .txt file extension
	{	case true:
		{	return false;
		}
		case false:
		{	ofstream file (directory);
			if (file.is_open())
			{	file << "//File_Parse generated file created on " << Cmd_dashdash::GetDTI(); 
			}
			file.close();
			return true;
		}
	}
	return false;
}

bool Check_file_exists(std::string file_path)
{	bool check = false;
	ifstream file (file_path);
	if(file.is_open())
	{	check = true;
	}	file.close();
	return check;
}
