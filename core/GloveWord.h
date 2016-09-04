#ifndef _H_WORDGLOVE_H_
#define _H_WORDGLOVE_H_
#include<string>
#include<vector>

class GloveWord{
protected:
	std::string _word;
	std::vector<float> _coords;
public:
	GloveWord(std::string word,std::vector<float> coords);
	GloveWord(std::string word);
	std::vector<float> &getCoords();
	std::string& getWord();
	unsigned int getNDimensions();
	float x(int index);
	void setDimensions(std::vector<float> coords);
};

#endif
