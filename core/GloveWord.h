#ifndef _H_WORDGLOVE_H_
#define _H_WORDGLOVE_H_
#include<string>
#include<vector>
#include <sstream>
#include <fstream>
#include <istream>

class GloveWord{
/*
Contains a word and its associated coordinate vector in GloVe
*/
protected:
	std::string _word;
	std::vector<float> _coords;
public:
	GloveWord(std::string word,std::vector<float> coords);
	GloveWord(std::string word);
	std::vector<float> &getCoords();
	std::string& getWord();
	unsigned int getNDimensions();
	float getPositionInDimension(int index);
	double getDistanceFromPoint(std::vector<float> &point);
	void setCoords(std::vector<float> coords);
	void setCoords(float* array, int nDimensions);
	void print();
	void writeToFile(std::ofstream &file);
};

#endif
