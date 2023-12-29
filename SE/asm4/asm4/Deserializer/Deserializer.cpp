#include "stdafx.h"		

// Метод Deserializer::DeserializeData(): Выполняет десериализацию данных из файла
void Deserializer::DeserializeData()
{
	file = ifstream("D:\\asm4\\asm4\\bin.bin");

	unsigned char marker;
	unsigned char currentLength;

	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&marker), 1);
		file.read(reinterpret_cast<char*>(&currentLength), 1);

		// Обработка данных в соответствии с маркером
		if (marker == 0x01)
			file.read(reinterpret_cast<char*>(&Long), currentLength);
		else if (marker == 0x02)
			file.read(reinterpret_cast<char*>(&byte), currentLength);
		else if (marker == 0x03)
			file.read(str, currentLength);
	}

	cout << Long << " " << (int)byte << " " << str << endl;

	file.close();
}

// Метод Deserializer::ConvertToAssembler(): Преобразует десериализованные данные в код на ассемблере
void Deserializer::ConvertToAssembler()
{
	fileAsm = ofstream("D:\\3 sem\\SE\\asm4\\asm4\\asm4\\asm4.asm");

	fileAsm.clear();

	fileAsm  ASM_HEAD;

	fileAsm << "LONGF	SDWORD " << Long << endl;
	fileAsm << "BYTEF	DB " << (int)byte << endl;
	fileAsm << "STRF	DB \"" << str << "\", 0" << endl << endl;

	fileAsm  ASM_FOOTER;

	fileAsm.close();
}
