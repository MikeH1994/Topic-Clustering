#ifndef _H_GLOVETOPIC_H_
#define _H_GLOVETOPIC_H_
#include "GloveWord.h"
#include <unordered_map>

class GloveTopic:public GloveWord{
protected:
	std::vector<GloveWord> _wordsInTopic;
	std::unordered_map<std::string,int> _wordIndexMap;
	void createWordIndexMap();
public:
	GloveTopic(std::string topic, std::vector<GloveWord> wordsInTopic);
	int getIndex(std::string &word);
	GloveWord &getWord(int index);
	std::vector<GloveWord> &getWordVector();
	void printWords();
	void print();
	void computeTopicCentre();
};

#endif
