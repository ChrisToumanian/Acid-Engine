#ifndef ACID_XMLREADER
#define ACID_XMLREADER

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class XmlReader
{
public:
	XmlReader(string _filename);
	string GetXML();
	string FindValue(string name);

private:
	string filename;
	bool readable;
	ifstream stream;

	void Reset();
	
};

#endif