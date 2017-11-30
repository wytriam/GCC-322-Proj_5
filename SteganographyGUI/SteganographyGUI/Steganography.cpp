#include "Steganography.h"

Steganography::Steganography(unsigned char* data, int capacity) : data(data), capacity(capacity) 
{
	writeIdx = 0;
	readIdx = 0;
}

void Steganography::write(std::string message)
{
	writeIdx = 0;
	// Encode each char in message
	for (int i = 0; i < message.length(); i++)
	{
		write(message[i]);
	}
}

void Steganography::write(char c)
{
	if (writeIdx + 7 >= capacity)
	{
		// There is not enough room to write this message. Abort. 
		throw "You tried to encrypt a message longer than possible. This method should have never been called; what did you do?";
	}
	
	for (int i = 0; i < 8; i++)
	{
		char val = c & 1 << (7 - i);
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
	readIdx = 0;
	std::string returnVal = "";
	char nextChar = 'c'; // c for char 
	while (nextChar != 0x00)
	{
		nextChar = readChar();
		returnVal += nextChar;
	}

	return returnVal;
}

char Steganography::readChar()
{
	char returnVal = 0x00;
	for (int i = 0; i < 8; i++)
	{
		// put a 1 at the end of c. If this should instead be a 0, nothing will be added
		if (readBit(data[readIdx]))
		{
			returnVal = returnVal & 0x01;
		}
		// shift everything left
		returnVal = returnVal << 1;
		// increment readIdx
		readIdx++;
	}

	return returnVal;
}

// Returns true if the last bit of c is 1, false if it is 0
bool Steganography::readBit(char c)
{
	return c & 0x01;
}

int Steganography::getCapacity()
{
	return capacity;
}
