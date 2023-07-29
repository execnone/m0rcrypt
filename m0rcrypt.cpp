#include "m0rcrypt.hpp"
#include <cstring>
#include <iostream>
#include <cstdint>

using namespace std;


int main()
{
    const char* plainText = "merhaba dünya!";
    const char* encryptedText = M0rCryptData(plainText, strlen(plainText), "testkey123");

    cout << encryptedText << endl;
    cout << De_M0rCryptData(encryptedText, strlen(plainText), "testkey123");

    return 0;
}

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

char* M0rCryptData(const char* plainData, std::size_t size, const char* inputKey)
{
	char* encryptedData = new char[size];
	std::memcpy(encryptedData, plainData, size);

    std::size_t keySize = strlen(inputKey);

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

char* De_M0rCryptData(const char* encryptedData, std::size_t size, const char* inputKey)
{
	char* decryptedData = new char[size];
	std::memcpy(decryptedData, encryptedData, size);

    std::size_t keySize = strlen(inputKey);

	for (std::size_t i = 0; i < size; i++)
	{
		decryptedData[i] = De_M0rCryptByte(decryptedData[i], inputKey, keySize);
	}

	return decryptedData;
}
