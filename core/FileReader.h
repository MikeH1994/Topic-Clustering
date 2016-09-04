#ifndef _H_FILEREADER_H_
#define _H_FILEREADER_H_
#include<string>
#include<iostream>
#include<fstream>
#include <sstream>
#include <istream>
class FileReader{
protected:
	int _nDimensions;
	std::string _filepath;
	std::ifstream _file;
	std::istringstream _instream;
	std::string _currentLine;
	std::string _currentWord;
	float* _currentCoords;
	bool _loadedCoords = false;
	
	void loadCoords();
public:
	~FileReader();
	FileReader();
	FileReader(std::string filepath,int nDimensions);
	bool nextLine();
	std::string getWord();
	float* getCoords();
};
	
#endif
