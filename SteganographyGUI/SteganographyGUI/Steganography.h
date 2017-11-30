#pragma once
#include <string>

class Steganography
{
public:
	Steganography(unsigned char*, int);
	
	void write(std::string);
	std::string read();
	int getCapacity();

private: 
	void write(char);
	char readChar();
	bool readBit(char);

	unsigned char* data;

	int capacity;

	int readIdx;
	int writeIdx;
};