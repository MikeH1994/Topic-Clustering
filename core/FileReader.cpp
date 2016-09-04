#include"FileReader.h"

FileReader::FileReader(std::string filepath,int nDimensions):
																	_nDimensions(nDimensions),_filepath(filepath){
	_file = std::ifstream(_filepath.c_str(),std::ifstream::in);
	_currentCoords = new float[_nDimensions];
	nextLine();
}

FileReader::FileReader(){}

FileReader::~FileReader(){
	_file.close();
	delete _currentCoords;
}



bool FileReader::nextLine(){
	_loadedCoords = false;
	if(!getline(_file,_currentLine)){
		return false;
	}
	_currentWord = "";
	_instream.clear();
	_instream.str(_currentLine);
	_instream>>_currentWord;
}

void FileReader::loadCoords(){
	if (_loadedCoords){
		return;
	}
	std::string stemp;
	for(int i = 0; i<_nDimensions; i++){
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
