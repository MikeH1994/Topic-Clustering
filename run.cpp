#include"core/GloveController.h"

int main(int argc, char* argv[]){
	//std::vector<std::string> topicsFilepath = {"topics/physics.txt","topics/biology.txt",
//				"topics/chemistry.txt","topics/biochemistry.txt","topics/names.txt"};
	GloveController glove("glove.6B/glove.6B.50d.txt",50);
	
	for(int i = 1; i<argc; i++){
		glove.runQuery(std::string(argv[i]));
	}
}
