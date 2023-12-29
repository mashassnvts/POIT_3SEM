#pragma once: 
#include "stdafx.h" 
// Класс Serealizer: Описывает функциональность для сериализации данных и записи их в файл
class Serealizer
{
private:
	
	std::ofstream file;            // Поток для записи данных в файл
	unsigned char longMarker;       // Маркер для длинного целого числа
	unsigned char byteMarker;       // Маркер для байта
	unsigned char stringMarker;     // Маркер для строки
	unsigned char longLength;        // Длина (в байтах) для длинного целого числа
	unsigned char byteLength;        // Длина (в байтах) для байта
	unsigned char stringLength;      // Длина (в байтах) для строки
	long Long;                      // Сериализованное длинное целое число
	unsigned char byte;             // Сериализованный байт
	char str[150];                  // Сериализованная строка

public:
	
	Serealizer(long Long, int byte, char* str)
	{
		this->Long = Long;
		this->byte = (unsigned char)byte;
		strcpy_s(this->str, str);
		this->stringLength = strlen(str) + 1;  // Длина строки в байтах, включая завершающий нулевой символ
	}

	void SerealizeData();
};
