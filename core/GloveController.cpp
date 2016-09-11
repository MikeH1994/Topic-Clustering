#include "GloveController.h"
#include<unordered_map>
#include <sstream>
#include <fstream>
#include <istream>

GloveController::GloveController(std::string gloveFilepath,int nDimensions){
	if(_saveOutput){
		_outputFile.open("output.txt");
	}
	_gloveFilepath = gloveFilepath;
	_nDimensions = nDimensions;
	_fileReader = new FileReader(_gloveFilepath,_nDimensions);
}

GloveController::~GloveController(){
	if(_saveOutput){
		_outputFile.close();
	}
}

void GloveController::runListOfTopics(std::vector<std::string> topicFilepaths){
	_topicFilepaths = topicFilepaths;
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
	writeOutputToFile();
}

void GloveController::loadTopicWords(){
	std::vector<std::string> wordVector;
	for(unsigned int i = 0; i<_topicFilepaths.size(); i++){
		wordVector = loadWordsFromFilepath(_topicFilepaths[i],wordVector);
		_topics.push_back(getGloveTopicFromVector(wordVector,_topicFilepaths[i]));		
	}
}

std::vector<std::string> GloveController::loadWordsFromFilepath(std::string filepath,std::vector<std::string> returnedVector){
	returnedVector.clear();
	std::ifstream file(filepath.c_str(),std::ifstream::in);
	if (file.fail()) {
			std::cout << "Was unable to open file " << filepath <<std::endl;
			throw (std::string) "IOException in parseFile()";
	}
	std::string line;
	while(getline(file,line)){
		returnedVector.push_back(line);
	}
	file.close();
	return returnedVector;
}

GloveTopic GloveController::getGloveTopicFromVector(std::vector<std::string> words,std::string name){
	std::vector<GloveWord> gloveWordVector;
	for(unsigned int i = 0; i<words.size(); i++){
		gloveWordVector.push_back(GloveWord(words[i]));
	}
	return GloveTopic(name,gloveWordVector);
}

void GloveController::writeOutputToFile(){
	std::string outputPath = "GloVeTopicsOutput.txt";
	std::ofstream file;
	file.open(outputPath);
	std::vector<GloveWord> wordVector;
	for(unsigned int i = 0; i<_topics.size(); i++){
		_topics[i].writeToFile(file);
		wordVector = _topics[i].getWordVector();
		for(unsigned int j = 0; j<wordVector.size(); j++){
			wordVector[j].writeToFile(file);
		}
	}
	file.close();
}

void GloveController::runQuery(std::string query){
	_fileReader->reset();
	bool wordFound = false;
	float* arr;
	std::string currentWord;
	GloveWord word(query);
	do{
		currentWord = _fileReader->getWord();
		if (currentWord==query){
			wordFound = true;
			arr = _fileReader->getCoords();
			word.setCoords(arr,_nDimensions);	
		}
	}while(_fileReader->nextLine() && !wordFound);
	if (_saveOutput){
		word.writeToFile(_outputFile);
	}
	word.print();
}
