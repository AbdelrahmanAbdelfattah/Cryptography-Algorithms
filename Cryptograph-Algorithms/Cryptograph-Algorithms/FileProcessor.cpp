#include "FileProcessor.h"


vector<string> FileProcessor::readFile(string path)
{
	this->path = path;
	vector<string> words;
	ifstream inputFile(this->path);

	// Read and print each line from the file
	string line;
	while (getline(inputFile, line)) {
		words.push_back(line);
	}

	// Close the file
	inputFile.close();
	return words;

}
