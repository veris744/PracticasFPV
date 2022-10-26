#include "FileUtils.h"

#include<cstdio>
#include <stdlib.h>

unsigned int OpenFile(const char* _sFileName, const char* _sMode)
{
	errno_t error_code;

	FILE* pFile = nullptr;

	error_code = fopen_s(&pFile, _sFileName, _sMode);
	if (error_code != 0)
	{
		printf("Error abriendo el fichero %s!\n", _sFileName);
	}
	else
	{
		unsigned int uId = reinterpret_cast<unsigned int>(pFile);
		printf("Abierto\n");
		return uId;
	}
}


void CloseFile(unsigned int _uId)
{
	fclose(reinterpret_cast<FILE*>(_uId));
}

unsigned int ReadFile(unsigned int _uId, char* _pBuffer, unsigned int _uBufferSize)
{
	FILE* pFile = reinterpret_cast<FILE*>(_uId);
	if (pFile == NULL) { fputs("File error", stderr); exit(1); }

	size_t result  = fread(_pBuffer, 1, _uBufferSize, pFile);

	return result;
}

void WriteFile(unsigned int _uId, char* _pBuffer, unsigned int _uBufferSize)
{
	FILE* pFile = reinterpret_cast<FILE*>(_uId);
	if (pFile == NULL) { fputs("File error", stderr); exit(1); }
	size_t result = fwrite(_pBuffer, sizeof(char), _uBufferSize, pFile);
	printf("%d", result);
}
