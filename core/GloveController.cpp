#include "GloveController.h"
#include<unordered_map>
GloveController::GloveController(std::string gloveFilepath,std::vector<std::string> topicFilepaths,int nDimensions){
	_gloveFilepath = gloveFilepath;
	_topicFilepaths = topicFilepaths;
	_nDimensions = nDimensions;
	_fileReader = new FileReader(_gloveFilepath,_nDimensions);
}

GloveController::GloveController(std::string gloveFilepath,int nDimensions){
	_gloveFilepath = gloveFilepath;
	_nDimensions = nDimensions;
	_fileReader = new FileReader(_gloveFilepath,_nDimensions);
}

void GloveController::run(){
	loadTopicWords();
	std::string word;
	float* arr;
	int num = 0;
	int index;
	do{
		word = _fileReader->getWord();
		for(unsigned int i = 0; i<_topics.size(); i++){
			
			index = _topics[i].getIndex(word);
			if (index!=-1){
				arr = _fileReader->getCoords();
				_topics[i].getWord(index).setCoords(arr,_nDimensions);	
			}
			_topics[i].computeTopicCentre();
		}
		//num++;
	}while(_fileReader->nextLine());
	
}

void GloveController::loadTopicWords(){
	//TODO
	//Test
	std::vector<std::string> list = {"atom","neutron","proton","electron",
					"muon","tau"};
	std::vector<GloveWord> physicsWords;
	for (unsigned int i = 0; i<list.size(); i++){
		physicsWords.push_back(GloveWord(list[i]));
	}
	GloveTopic gt("physics",physicsWords);
	_topics.push_back(gt);
}

void GloveController::print(){
	for(unsigned int i = 0; i<_topics.size(); i++){
		_topics[i].printWords();
	}
}
