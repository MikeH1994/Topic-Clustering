all:
	g++ -std=c++11 run.cpp core/GloveController.cpp core/GloveWord.cpp core/GloveTopic.cpp core/FileReader.cpp -o run
