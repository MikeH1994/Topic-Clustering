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
	bool _saveOutput = true;
	std::string _gloveFilepath;
	int _nDimensions;
	FileReader* _fileReader;
	std::vector<std::string> _topicFilepaths;
	std::vector<GloveTopic> _topics;
	std::ofstream _outputFile;
	void loadTopicWords();
	void writeOutputToFile();
	void createOutputFile();
	std::vector<std::string> loadWordsFromFilepath(std::string filepath,std::vector<std::string> returnedVector);
	GloveTopic getGloveTopicFromVector(std::vector<std::string> words, std::string name);
	
public:
	GloveController(std::string gloveFilepath,int nDimensions);
	~GloveController();
	void runListOfTopics(std::vector<std::string> topicFilepaths);
	void runQuery(std::string word);
};

#endif
