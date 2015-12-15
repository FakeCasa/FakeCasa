#pragma once
class MgFileIni
{
private:
	_TCHAR m_cFullPathFile[MAX_PATH];

public:
	MgFileIni();
	~MgFileIni();
public:
	void getFullPathName(_TCHAR DesPath[MAX_PATH]){ _tcscpy_s(DesPath, MAX_PATH, m_cFullPathFile); };

};

