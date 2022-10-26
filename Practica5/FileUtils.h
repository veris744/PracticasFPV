#pragma once

unsigned int OpenFile(const char* _sFileName, const char* sMode);
void CloseFile(unsigned int _uId);
unsigned int ReadFile(unsigned int _uId, char* pBuffer_, unsigned int _uBufferSize);
void WriteFile(unsigned int _uId, char* pBuffer_, unsigned int _uBufferSize);
