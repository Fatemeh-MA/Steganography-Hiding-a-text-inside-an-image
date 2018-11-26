
#include <vector>
#include "Steganography.h"

using namespace std;

Stegano::Stegano() {
	width = 0;
	height = 0;
}

Stegano::~Stegano() {}

bool Stegano::imgError() {
	return img.size() == 0 || img.size() % 4 != 0;
}

void Stegano::decode_img(string filename) {
	unsigned error = lodepng::decode(img, width, height, filename);
	if (error) {
		cout << "decoder error " << error << ": " << lodepng_error_text(error) << endl;
		exit(1);
	}


}

void Stegano::encode_img(std::string filename) {
	if (imgError()) {
		std::cout << "image not loaded ";
		return;
	}
	unsigned error = lodepng::encode(filename, img, width, height);
	if (error) {
		std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
		exit(1);
	}
}

void Stegano::write_data(vector<char> data) {
	if (imgError()) {
		cout << "image not loaded or corrupt";
		return;
	}
	if (data.size() == 0) {
		cout << "data empty";
		return;
	}
	if (data.size() * 8 > width*height) {
		cout << "data too big";
		return;
	}

	int pc = 0;
	for (unsigned int i = 0; i < data.size(); ++i) {
		char c = data[i];
		for (int j = 0; j < 8; j++) {
			char mask = 128 >> j;
			
			char bit = (mask & c) >> (7 - j);
			
			img[pc * 4] = ((img[pc * 4] | 1) ^ 1) ^ bit;
			
			
			pc++;
		}
	}
	for (int j = 0; j < 8; j++) {
		img[pc * 4] = (img[pc * 4] | 1) ^ 1;
		
		pc++;
	}
}

vector<char> Stegano::read_data() {
	if (imgError()) {
		cout << "image not loaded or corrupt";
	}
	vector<char> data;
	int bits_read = 0;
	char acc_c = 0;
	char bit;
	for (unsigned int i = 0; i < img.size(); i++) {
		bit = 0;
		bit = (img[i * 4] & 1) << (7 - bits_read);
		bits_read++;
		acc_c = bit | acc_c;
		if (bits_read == 8) {
			if (acc_c == 0) {
				return data;
			}
			data.push_back(acc_c);
			bits_read = 0;
			acc_c = 0;
		}
	}

	return data; // if we get here we didn't find a null character, meaning we didnt find any fitting data...
}

unsigned char & Stegano::operator[](int n)
{
	return img[n];
}



