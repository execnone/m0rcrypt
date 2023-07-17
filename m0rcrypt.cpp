#include "m0rcrypt.h"

char M0rCryptByte(char plainByte, const char* inputKey, std::size_t size)
{
	for (std::size_t i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			plainByte += static_cast<int>(inputKey[i]);
		}
		else
		{
			plainByte -= static_cast<int>(inputKey[i]);
		}
	}

	return plainByte;
}

unsigned char* M0rCryptData(unsigned char* plainData, std::size_t size, const char* inputKey, std::size_t keySize)
{
	unsigned char* encryptedData = new unsigned char[size];
	std::memcpy(encryptedData, plainData, size);

	for (std::size_t i = 0; i < size; i++)
	{
		encryptedData[i] = M0rCryptByte(encryptedData[i], inputKey, keySize);
	}

	return encryptedData;
}

char De_M0rCryptByte(char plainByte, const char* inputKey, std::size_t size)
{
	for (std::size_t i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			plainByte -= static_cast<int>(inputKey[i]);
		}
		else
		{
			plainByte += static_cast<int>(inputKey[i]);
		}
	}

	return plainByte;
}

unsigned char* De_M0rCryptData(unsigned char* encryptedData, std::size_t size, const char* inputKey, std::size_t keySize)
{
	unsigned char* decryptedData = new unsigned char[size];
	std::memcpy(decryptedData, encryptedData, size);

	for (std::size_t i = 0; i < size; i++)
	{
		decryptedData[i] = De_M0rCryptByte(decryptedData[i], inputKey, keySize);
	}

	return decryptedData;
}
