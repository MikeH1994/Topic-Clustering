#ifndef _H_GLOVECONTROLLER_H_
#define _H_GLOVECONTROLLER_H_
#include<string>
#include<vector>
#include<map>
#include"FileReader.h"
#include"GloveTopic.h"

class GloveController{
/*
Handle the creation and processing of glove words
*/
protected:
	std::string _gloveFilepath;
	int _nDimensions;
	FileReader* _fileReader;
	std::vector<std::string> _topicFilepaths;
	std::vector<GloveTopic> _topics;
	void loadTopicWords();
	void writeOutputToFile();
	std::vector<std::string> loadWordsFromFilepath(std::string filepath,std::vector<std::string> returnedVector);
	GloveTopic getGloveTopicFromVector(std::vector<std::string> words, std::string name);
public:
	GloveController(std::string filepath,std::vector<std::string> topicFilepaths,int nDimensions);
	GloveController(std::string gloveFilepath,int nDimensions);
	void run();
	void print();
};

#endif
