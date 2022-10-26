#pragma once
class CFile
{
public:
	bool OpenFile(const char* _sFileName, const char* sMode);
	void CloseFile();
	unsigned int ReadFile(char* pBuffer_, unsigned int _uBufferSize);
	void WriteFile(char* pBuffer_, unsigned int _uBufferSize);

private:
	void* m_pfile;
};

