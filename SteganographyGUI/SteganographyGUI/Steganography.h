#pragma once
#include <string>

class Steganography
{
public:
	Steganography(unsigned char*, int, int);
	
	void write(std::string);
	std::string read();
	int findCapacity();

private: 
	void write(char);
	char readChar();

	unsigned char* data;
	int width;
	int height;

	int readIdx;
	int writeIdx;
};