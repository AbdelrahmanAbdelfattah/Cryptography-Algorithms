#include <string>
#include <vector>
#include<iostream>
#include<fstream>
using namespace std;


class FileProcessor
{
private:
	string path;

public:
	vector <string> readFile(string path);


};

