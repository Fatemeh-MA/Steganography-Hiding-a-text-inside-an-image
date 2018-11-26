// in the name of allah
// programmed by Fatemeh 

#include <iostream>
#include "Text.h"
#include "Steganography.h"
#include <conio.h>
using namespace std;



int main() {
	

	Stegano st;
	
	// input the text massage
	Text t = Text::open("TextFiles\\text.txt");
	
	// this program has 2 parts: 1- Hiding a text massage inside an image
	// 2- Decode the message (The hidden message will be displayed on your console)
	if (t.size() == 0) {
		st.decode_img("Images\\output.png");
		cout << " there is no text file  " << endl;
		std::vector<char> data = st.read_data();
		string ss= string(data.begin(), data.end());
		t= Text::Text(ss);
		
		t.save("TextFiles\\output.txt");
		
		cout << "  the detect text is  :  \n " << ss << endl;
		cout << "  the last output is :  output.txt ";
	}
	else {
		st.decode_img("Images\\input.png");
		cout << "  text file load !!  " << endl;
		string msg = t.str();
		st.write_data(std::vector<char>(msg.begin(), msg.end()));
		st.encode_img("Images\\output.png");
		cout << "  the hidden text is  :  \n" << t.str() << endl <<endl;
		cout << "  the last output is :  output.png ";
	}


	_getch();
	//bits();
	return 0;
}