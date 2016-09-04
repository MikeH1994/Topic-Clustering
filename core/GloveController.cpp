#include "GloveController.h"

GloveController::GloveController(std::string filepath, int nDimensions)
															:_filepath(filepath),_nDimensions(nDimensions){
	_fileReader = new FileReader(_filepath,_nDimensions);
	
}
