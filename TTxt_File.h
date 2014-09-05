#pragma once
#include "fileparse.h"						

// TTxt_File ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TTxt_File :public CFileParse																				
{	public:
	TTxt_File(std::string input_file_path, bool file_autocreate); 													// Constructor loads the file into memory, or optionally creates a new one if the file does not yet exist
	void Load_file(std::string load_file_path);																				// opens up the file and loads the contents into the string vector
	void Process_input(std::string line, unsigned int insert_location);										// Handles a string for input & inserts it at the given numbered line. This should eventually be expanded to cover inserting between existing lines
	void Process_input(std::string line);																						// same deal, just at the standard emplace location instead of the end (beginning I think???)
	std::string Access_data(unsigned int index);																		// Returns the string stored at the given index
	void Output_Data();																												// Outputs everything, including the line numbers by default. I should change that
	void Insert_data(std::vector<std::string>& input_string_vector);											// Inserts a vector of strings at the end of the list
	void Insert_data(std::string input_string);																				// inserts a single string at the end of the list
	void Overwrite_data(std::string input_to_write, unsigned int index);									// overwrite an index with a new string
	void Insert_blank_lines(unsigned int number_of_lines);														// Inserts a given number of blank new lines at the end of the list
	void Remove_line(unsigned int index_to_remove);															// remove an index, shortening the list
	std::string Get_path();																												// return the full path to the file as given when the object is constructed
	unsigned int Get_index_size();																								// return the number of lines in the file, or the 'index'
	bool Read_state();																													// returns the state of the file (ie is it currently read properly)
	bool Check_file_exists();																										// check if the path held by 'file_path' currently leads to a file
	bool Save_file(std::string output_file_path, bool self_destruct);											// overwrite the contents of this object onto the file located by 'file_path'
	bool Save_file(bool self_destruct);																						// same as above, but saving to the default path held by the object
	private:																																	// private access to force interaction through member functions
	std::string File_path;																												// full path of the file on this operating system
	std::vector<std::string> Text_index;																						// The full text of the file, including comments, read cues, etc. 
	unsigned int File_index;																										// The number of elements in the file parse, regardless of whether they should be read or not
	bool File_read;																														// Was the file input succesful, and is the text still loaded into memory?
	public:
	~TTxt_File();
};

bool Create_text_file(std::string directory, std::string file_path);
bool Check_file_exists(std::string file_path);


