#ifndef _TEXT__
#define _TEXT__

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Text
{
public:
	Text(const string& str = "");
	~Text();
	static Text open(const string& filename);
	/** Returns the size (in bytes) of the text file */
	std::string::size_type size() const;

	/** Returns the contents of the text file as a `std::string` object */
	std::string str() const;

	/** Convert into std::string */
	operator std::string() const;

	/** Overloads the `<<` operator to be used for I/O */
	friend std::ostream& operator<<(std::ostream&, const Text&);

	/** Appends the given string to the text file */
	Text& append(const std::string& str);

	/** Appends the given string to the text file */
	Text& operator+=(const std::string& str);

	/** Appends the given text file to the text file */
	Text& append(const Text& textFile);
	/** Appends the given text file to the text file */
	Text& operator+=(const Text& textFile);

	/** Saves the text file to the disk with the given filename */
	void save(const std::string& filename);
private:
	string mText;
};



#endif
