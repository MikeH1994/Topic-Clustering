#ifndef _H_GLOVETOPIC_H_
#define _H_GLOVETOPIC_H_
#include "GloveWord.h"

class GloveTopic:public GloveWord{
protected:
	std::vector<GloveWord> _wordsInTopic;
	void computeTopicCentre();
public:
	GloveTopic(std::string topic, std::vector<GloveWord> wordsInTopic);
};

#endif
