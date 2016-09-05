#include"GloveWord.h"
#include<iostream>
GloveWord::GloveWord(std::string word, std::vector<float> coords):_word(word){
	setCoords(coords);
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

float GloveWord::getPositionInDimension(int index){
	return _coords[index];
}

void GloveWord::setCoords(std::vector<float> coords){
	_coords.clear();
	for(unsigned int i =0;i<coords.size(); i++){
		_coords.push_back(coords[i]);
	}
}

void GloveWord::setCoords(float* array, int nDimensions){
	if (_coords.size()==nDimensions){
		return;
	}
	_coords.clear();
	for(unsigned int i = 0; i<nDimensions; i++){
		_coords.push_back(array[i]);
	}
}

void GloveWord::print(){
	std::cout<<"--------------\n"<<_word<<" ";
	unsigned int nDimensions = getNDimensions();
	for(unsigned int i = 0; i<nDimensions; i++){
		//std::cout<<_coords[i]<<"\t";
	}
	std::cout<<std::endl;
}
