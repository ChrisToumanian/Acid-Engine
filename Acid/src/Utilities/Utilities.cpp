#include "Utilities.h"

int Utilities::GetRandomInt(int min, int max)
{
	int x = min + (int)((double)(max - min) * (rand() / (RAND_MAX + 1.0)));
	return x;
}

float Utilities::GetRandomFloat(float min, float max) {
	return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

char* Utilities::StringToChar(string input)
{
	return &input[0u];
}