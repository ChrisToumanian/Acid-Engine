#ifndef ACID_UTILITIES
#define ACID_UTILITIES

#include <cmath>
#include <string>

using namespace std;

class Utilities
{
public:
	static int GetRandomInt(int min, int max);
	static float GetRandomFloat(float min, float max);
	static char* StringToChar(string input);
};

#endif