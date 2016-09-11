#include"GloveWord.h"
#include<iostream>
#include<cmath>
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
	std::cout<<_word;
	unsigned int nDimensions = getNDimensions();
	for(unsigned int i = 0; i<nDimensions; i++){
		std::cout<<"\t"<<_coords[i];
	}
	std::cout<<std::endl;
}

double GloveWord::getDistanceFromPoint(std::vector<float> &point){
	double dist = 0;
	for(unsigned int i = 0; i<point.size(); i++){
		dist+=(point[i]-_coords[i])*(point[i]-_coords[i]);
	}
	dist = sqrt(dist);
}

void GloveWord::writeToFile(std::ofstream &file){
	file<<_word;
	for(unsigned int i =0 ; i<_coords.size(); i++){
		file<<"\t"<<_coords[i];
	}
	file<<"\n";
}
