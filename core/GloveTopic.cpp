#include "GloveTopic.h"

GloveTopic::GloveTopic(std::string topic, std::vector<GloveWord> wordsInTopic):GloveWord(topic){;
	for (unsigned int i = 0; i<wordsInTopic.size();i++){
		_wordsInTopic.push_back(wordsInTopic[i]);
	}
	computeTopicCentre();
}

void GloveTopic::computeTopicCentre(){
	_coords.clear();
	unsigned int nDimensions = _wordsInTopic[0].getNDimensions();
	float pos;
	for (unsigned int dimension = 0; dimension<nDimensions; dimension++){
		pos = 0;
		for (unsigned int word = 0; word<_wordsInTopic.size(); word++){
			pos+=_wordsInTopic[word].x(dimension);
		}
		pos/=nDimensions;
		_coords.push_back(pos);
	}
}
