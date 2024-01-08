#pragma once: 
#include "stdafx.h"

// Класс Deserializer: Описывает функциональность для десериализации данных и преобразования их в код на ассемблере.
class Deserializer
{
protected:

	std::ifstream file;        // Поток для чтения данных из файла
	std::ofstream fileAsm;     // Поток для записи ассемблерного кода в файл
	unsigned char longMarker;   // Маркер для длинного целого числа
	unsigned char byteMarker;   // Маркер для байта
	unsigned char stringMarker; // Маркер для строки

	// Переменные для хранения десериализованных данных
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
