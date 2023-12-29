#pragma once: 
#include "stdafx.h"

// ����� Deserializer: ��������� ���������������� ��� �������������� ������ � �������������� �� � ��� �� ����������.
class Deserializer
{
protected:

	std::ifstream file;        // ����� ��� ������ ������ �� �����
	std::ofstream fileAsm;     // ����� ��� ������ ������������� ���� � ����
	unsigned char longMarker;   // ������ ��� �������� ������ �����
	unsigned char byteMarker;   // ������ ��� �����
	unsigned char stringMarker; // ������ ��� ������

	// ���������� ��� �������� ����������������� ������
	long Long;
	unsigned char byte;
	char str[150];

public:

	Deserializer()
	{
		this->Long = NULL;
		this->byte = NULL;
	}

	void DeserializeData();
	void ConvertToAssembler();
};
