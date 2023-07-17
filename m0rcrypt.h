#include <iostream>

char M0rCryptByte(char plainByte, const char* inputKey, std::size_t size);
unsigned char* M0rCryptData(unsigned char* plainData, std::size_t size, const char* inputKey, std::size_t keySize);
char De_M0rCryptByte(char plainByte, const char* inputKey, std::size_t size);
unsigned char* De_M0rCryptData(unsigned char* plainData, std::size_t size, const char* inputKey, std::size_t keySize);
