#include<map>
#include<string>
using namespace std;


class analyzeText
{
private:
	string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
	map <char, int> analyzeString(string text);
	void showAnalysis(string text);
};

