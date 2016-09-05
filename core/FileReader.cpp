#include"FileReader.h"

FileReader::FileReader(std::string filepath,int nDimensions):
																	_nDimensions(nDimensions),_filepath(filepath){
	//create the FileReader instance and read in the first line
	_file = std::ifstream(_filepath.c_str(),std::ifstream::in);
	_currentCoords = new float[_nDimensions];
	nextLine();
}

FileReader::FileReader(){}

FileReader::~FileReader(){
	//when the destructor is called, close the file and delete the coordinate
	//array allocated on the heap
	_file.close();
	delete _currentCoords;
}



bool FileReader::nextLine(){
	//read the next line of the GloVe file in. If the last line has been reached,
	//return false.
	
	//load the next line into _currentLine. return if false
	if(!getline(_file,_currentLine)){
		return false;
	}
	_loadedCoords = false;
	_currentWord = "";
	//clear the string stream and use the current line, then get the current
	//word in the stream
	_instream.clear();
	_instream.str(_currentLine);
	_instream>>_currentWord;
	return true;
}

void FileReader::loadCoords(){
	//load the coordinates from _currentLine into the array. This is done so
	//the array is only written to when necessary (most of the lines in GloVe will
	//not be the ones we are looking for
	if (_loadedCoords){
		//if the coordinates have already been loaded from the string stream
		return;
	}
	std::string stemp;
	for(int i = 0; i<_nDimensions; i++){
		//else copy them into array
		_instream>>stemp;
		_currentCoords[i] = std::stof(stemp);
		stemp = "";
	}
	_loadedCoords = true;
}

float* FileReader::getCoords(){
	loadCoords();
	return _currentCoords;
}

std::string FileReader::getWord(){
	return _currentWord;
}
