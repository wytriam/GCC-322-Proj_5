#include "Steganography.h"

Steganography::Steganography() { data = nullptr; capacity = 0; writeIdx = 0; readIdx = 0; }	// don't call this ever. 

Steganography::Steganography(unsigned char* data, int capacity) : data(data), capacity(capacity) 
{
	// set the write and read Idx to 0. Just to be safe. 
	writeIdx = 0;
	readIdx = 0;
}

void Steganography::write(std::string message)
{
	// Set the writeIdx to 0, so if we are asked to rewrite something it doesn't break stuff. 
	writeIdx = 0;
	// Encode each char in message
	for (int i = 0; i < message.length(); i++)
	{
		write(message[i]);
	}
	// add a null-terminator 
	write(0x00);
}

void Steganography::write(char c)
{
	// make sure we have space to write this message
	if (writeIdx + 7 >= capacity)
	{
		// There is not enough room to write this message. Abort. 
		throw "You tried to encrypt a message longer than possible. This method should have never been called; what did you do?";
	}
	
	// encode the next 8 chars
	for (int i = 0; i < 8; i++)
	{
		char val = c & (0x01 << (7 - i));
		if (val == 0x00) //val is all 0's, indicating that the desired bit was 0
		{
			if (readBit(data[writeIdx])) // the last bit of the next char to write is 1. This needs to change to 0. 
				data[writeIdx] = data[writeIdx] ^ 0x01;
		}
		else // val has some non-0 values, indicating that the desired bit was 1
		{
			if (!readBit(data[writeIdx])) // the last bit of the next to write is 0. This needs to change to 1. 
				data[writeIdx] = data[writeIdx] | 0x01;
		}
		writeIdx++;
	}
}

std::string Steganography::read()
{
	// read from the beginning
	readIdx = 0;
	std::string returnVal = "";
	char nextChar = 'c'; // c for char 
	// keep getting chars until you reach a null terminator
	while (nextChar != 0x00)
	{
		// get the next char
		nextChar = readChar();
		// append the next char to the return value
		returnVal += nextChar;
	}

	return returnVal;
}

char Steganography::readChar()
{
	// set up an empty char
	unsigned char returnVal = 0x00;
	for (int i = 0; i < 8; i++)
	{
		// put a 1 at the end of c. If this should instead be a 0, nothing will be added
		if (readBit(data[readIdx]))
		{
			returnVal = returnVal | 0x01;
		}
		// shift everything left
		returnVal = returnVal << 1;
		// increment readIdx
		readIdx++;
	}

	// I don't understand why, but this is necessary to get the right values. I was shifting one time too many. 
	// It was really weird. 
	returnVal >>= 1;

	return returnVal;
}

// Returns true if the last bit of c is 1, false if it is 0
bool Steganography::readBit(char c)
{
	// check against the last bit of the char
	return c & 0x01;
}

unsigned char* Steganography::getData()
{
	return data;
}
