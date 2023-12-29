#include "stdafx.h" 

// Метод Serealizer::SerealizeData(): Выполняет сериализацию данных и запись их в бинарный файл
void Serealizer::SerealizeData()
{
	file = ofstream("D:\\asm4\\asm4\\bin.bin");

	file.clear();

	file.write((char*)&longMarker, 1);
	file.write((char*)&longLength, 1);

	file.write(reinterpret_cast<char*>(&Long), longLength);

	file.write((char*)&byteMarker, 1);
	file.write((char*)&byteLength, 1);

	file.write(reinterpret_cast<char*>(&byte), byteLength);

	file.write((char*)&stringMarker, 1);
	file.write((char*)&stringLength, 1);

	file.write(str, stringLength);

	file.close();
}
