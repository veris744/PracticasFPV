#include "FileUtils.h"

#include<cstdio>

bool CFile::OpenFile(const char* _sFileName, const char* _sMode)
{
	errno_t error_code;

	FILE* pFile = reinterpret_cast<FILE*>(m_pfile);

	error_code = fopen_s(&pFile, _sFileName, _sMode);
	if (error_code != 0)
	{
		printf("Error abriendo el fichero %s!", _sFileName);
		return false;
	}
	else
	{
		return true;
	}
}


void CFile::CloseFile()
{
	fclose(reinterpret_cast<FILE*>(m_pfile));
}

unsigned int CFile::ReadFile(char* _pBuffer, unsigned int _uBufferSize)
{

}

void CFile::WriteFile(char* _pBuffer, unsigned int _uBufferSize)
{

}
