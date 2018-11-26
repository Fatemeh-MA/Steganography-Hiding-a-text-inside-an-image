#include "Text.h"
#include <fstream>

using namespace std;


Text::Text(const string& str) : mText(str) { }

Text::~Text()
{
}


Text Text::open(const std::string & filename)
{
	Text t;

	ifstream file(filename.c_str());

	string line;
	getline(file, t.mText);
	while (getline(file, line))
		t.mText += "\n" + line;

	return t;
	
}

string::size_type Text::size() const
{
	return mText.size();
}

string Text::str() const
{
	return mText;
}

// Convert to string
Text::operator std::string() const
{
	return mText;
}



void Text::save(const std::string & filename)
{
	ofstream file(filename.c_str());

	string::iterator sit;
	for (sit = mText.begin(); sit != mText.end(); ++sit)
		file.put(*sit);
	file.close();
}

// `<<` overloading
ostream & operator<<(ostream& out, const Text& textFile)
{
	return (out << textFile.str());
}

Text & Text::append(const std::string & str)
{
	mText += str;
	return *this;
}

Text & Text::operator+=(const std::string & str)
{
	return this->append(str);
}

Text & Text::append(const Text & textFile)
{
	return this->append(textFile.str());
}

Text & Text::operator+=(const Text & textFile)
{
	return this->append(textFile.str());
}
