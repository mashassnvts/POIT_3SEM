#pragma once: 
#include "stdafx.h" 
// ����� Serealizer: ��������� ���������������� ��� ������������ ������ � ������ �� � ����
class Serealizer
{
private:
	
	std::ofstream file;            // ����� ��� ������ ������ � ����
	unsigned char longMarker;       // ������ ��� �������� ������ �����
	unsigned char byteMarker;       // ������ ��� �����
	unsigned char stringMarker;     // ������ ��� ������
	unsigned char longLength;        // ����� (� ������) ��� �������� ������ �����
	unsigned char byteLength;        // ����� (� ������) ��� �����
	unsigned char stringLength;      // ����� (� ������) ��� ������
	long Long;                      // ��������������� ������� ����� �����
	unsigned char byte;             // ��������������� ����
	char str[150];                  // ��������������� ������

public:
	
	Serealizer(long Long, int byte, char* str)
	{
		this->Long = Long;
		this->byte = (unsigned char)byte;
		strcpy_s(this->str, str);
		this->stringLength = strlen(str) + 1;  // ����� ������ � ������, ������� ����������� ������� ������
	}

	void SerealizeData();
};
