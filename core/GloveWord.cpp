#include"GloveWord.h"

GloveWord::GloveWord(std::string word, std::vector<float> coords):_word(word){
	setDimensions(coords);
}

GloveWord::GloveWord(std::string word):_word(word){
	
}

std::vector<float>& GloveWord::getCoords(){
	return _coords;
}

std::string& GloveWord::getWord(){
	return _word;
}

unsigned int GloveWord::getNDimensions(){
	return _coords.size();
}

float GloveWord::x(int index){
	return _coords[index];
}

void GloveWord::setDimensions(std::vector<float> coords){
	_coords.clear();
	for(unsigned int i =0;i<coords.size(); i++){
		_coords.push_back(coords[i]);
	}
}
