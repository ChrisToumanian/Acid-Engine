#include "XmlReader.h"

XmlReader::XmlReader(string _filename)
{
	filename = _filename;
	stream.open(filename);

	if (!stream.is_open())
	{
		readable = false;
	}
	else
	{
		readable = true;
	}
}

string XmlReader::GetXML()
{
	string xml = "";
	if (readable)
	{
		string word;
		stream >> word;
		while (stream.good())
		{
			xml += word;
			xml += " ";
			stream >> word;
		}
		Reset();
	}
	return xml;
}

string XmlReader::FindValue(string name)
{
	string value = "";
	string xml = GetXML();
	int occurance = xml.find(name);
	if (occurance != -1)
	{
		value = xml.substr(occurance, xml.size());
		int begin = value.find(">") + 1;
		int end = value.find("</");
		value = value.substr(begin, end - begin);
	}
	return value;
}

void XmlReader::Reset()
{
	stream.clear();
	stream.seekg(0);
}