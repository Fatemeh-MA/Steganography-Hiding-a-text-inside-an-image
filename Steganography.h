#ifndef _STEGANOGRAPHY_
#define _STEGANOGRAPHY_

#include <vector>
#include <string>
#include <iostream>
#include "lodepng.h"

using namespace std;
/**
Class for naive steganography.
Can read and write messages to png files.

Messages are stored by breaking down the characters into
bits and saving each bit in the red channel of a pixel
*/
class Stegano {
private:
	std::vector<unsigned char> img;
	unsigned int width, height;
	bool imgError();
	int d;
public:
	Stegano();
	~Stegano();
	//image decode
	void decode_img(string);

	//image encode
	void encode_img(string);

	//write data on image
	void write_data(vector<char>);


	//read data from image
	vector<char> read_data();
	

	unsigned char & operator [] (int n);
	
};

#endif