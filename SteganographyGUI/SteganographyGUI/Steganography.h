#pragma once
#include <string>

/*
	This class, seperate from the GUI classes, exists to handle all the steganography stuff. 
	Because it is a seperate class, it may be reused in other projects. 
*/

class Steganography
{
public:
	// A default contructor for this class. This should almost never be used. I made it so that VS would be happy (was receiving an error for no default constructor)
	Steganography();

	// The correct constuctor for this class
	Steganography(unsigned char*, int);
	
	// Hides the message passed as a string in the data array
	void write(std::string);

	// reads the data array
	std::string read();

	// returns the raw data
	unsigned char* getData();

private: 
	// write a single char into the data array
	void write(char);
	// read a single char from the data array
	char readChar();
	// determine the value of the last bit of a char. True if 1; False if 0. 
	bool readBit(char);
	// The raw data
	unsigned char* data;
	// the size of the raw data
	int capacity;
	// the current char that is being read from the data
	int readIdx;
	// the current char that is being modified in the data
	int writeIdx;
};