#include "Steganography.h"

Steganography::Steganography(unsigned char* data, int width, int height) : data(data), width(width), height(height) 
{
	writeIdx = 0;
	readIdx = 0;
}

void Steganography::write(std::string)
{
	// convert string to char queue? 
	// While string has chars: 
	// Get the next char
	// Write that char
	// Remove char from string
}

void Steganography::write(char)
{
	// convert the char to 8 bits
	// insert the ith bit of the char at writeIdx's last bit
}

std::string Steganography::read()
{}

char Steganography::readChar()
{}

int Steganography::findCapacity()
{}
