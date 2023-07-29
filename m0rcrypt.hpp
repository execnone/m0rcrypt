#include <iostream>

char M0rCryptByte(char plainByte, const char* inputKey, std::size_t size);
char* M0rCryptData(const char* plainData, std::size_t size, const char* inputKey);
char De_M0rCryptByte(char plainByte, const char* inputKey, std::size_t size);
char* De_M0rCryptData(const char* encryptedData, std::size_t size, const char* inputKey);
