#ifndef _H_GLOVECONTROLLER_H_
#define _H_GLOVECONTROLLER_H_
#include<string>
#include<vector>
#include"FileReader.h"

class GloveController{
protected:
	std::string _filepath;
	int _nDimensions;
	FileReader* _fileReader;
	
public:
	GloveController(std::string filepath,int nDimensions);
	
};

#endif
