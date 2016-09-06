#include "GloveTopic.h"
#include<iostream>

GloveTopic::GloveTopic(std::string topic, std::vector<GloveWord> wordsInTopic):GloveWord(topic){
	for (unsigned int i = 0; i<wordsInTopic.size();i++){
		_wordsInTopic.push_back(wordsInTopic[i]);
	}
	createWordIndexMap();
}

void GloveTopic::computeTopicCentre(){
	//set the centre of topic cluster
	_coords.clear();
	unsigned int nDimensions = _wordsInTopic[0].getNDimensions();
	float pos;
	int nFound = 0;
	for (unsigned int dimension = 0; dimension<nDimensions; dimension++){
		nFound = 0;
		pos = 0;
		for (unsigned int word = 0; word<_wordsInTopic.size(); word++){
			if (_wordsInTopic[word].getNDimensions()>0){
				pos+=_wordsInTopic[word].getPositionInDimension(dimension);		
				nFound++;	
			}			
		}
		pos/=nFound;
		_coords.push_back(pos);
	}
}

int GloveTopic::getIndex(std::string &word){
	//get index of a word in the topic vector. if the word doesn't exist return -1
	std::unordered_map<std::string,int>::const_iterator index = _wordIndexMap.find (word);
  if ( index == _wordIndexMap.end() ){
  	return -1;
  }
  else return index->second;
}

void GloveTopic::createWordIndexMap(){
	for(unsigned int i = 0; i<_wordsInTopic.size(); i++){
		_wordIndexMap[_wordsInTopic[i].getWord()] = i;
	}
}

GloveWord &GloveTopic::getWord(int index){
	return _wordsInTopic[index];
}

void GloveTopic::printWords(){
	print();
	//for(unsigned int i = 0; i<_wordsInTopic.size(); i++){
		//std::cout<<_wordsInTopic[i].getWord()<<": "<<_wordsInTopic[i].getDistanceFromPoint(_coords)<<std::endl;
		//_wordsInTopic[i].print();
	//}
}

void GloveTopic::print(){
	std::cout<<"--------------\n"<<_word<<std::endl;
	unsigned int nDimensions = getNDimensions();
	for(unsigned int i = 0; i<nDimensions; i++){
		std::cout<<_coords[i]<<"\t";
	}
	std::cout<<std::endl;
}

std::vector<GloveWord> &GloveTopic::getWordVector(){
	return _wordsInTopic;
}
