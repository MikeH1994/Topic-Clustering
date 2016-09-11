#include"core/GloveController.h"

int main(){
	//std::vector<std::string> topicsFilepath = {"topics/physics.txt","topics/biology.txt",
//				"topics/chemistry.txt","topics/biochemistry.txt","topics/names.txt"};
	GloveController glove("glove.6B/glove.6B.50d.txt",50);
	glove.runQuery("king");
	glove.runQuery("man");
	glove.runQuery("woman");
	glove.runQuery("queen");
	glove.runQuery("maths");
	glove.runQuery("physics");
	glove.runQuery("chemistry");
	glove.runQuery("biology");
}
