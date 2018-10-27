// lab8_stroki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstring> // strcat(), strlen(), strcmp()
#include <string>
#include <fstream>
using namespace std;
//стороки старого С-типа
//char cstr1[] = "abs";
//char cstr2[] = { 'a','b','s' };
//char cstr3[] = { '\33','\33','\46' };
//вывод на печатьprintf(char[],,,)
//http://www.cplusplus.com/reference/cstdio/printf/
/*%f- параметр подставляет на место %f оформленное в виде числа с плавающей точкой
%s-параметр подставляет на место % как строка
%d-параметр подставляет на место % как целое число
%e-параметр подставляет на место % как число в экспонентальном виде

strcat() объединение или строка1+строка2
strcpy() копирование из одной строки в другую или строка1=строка2
strcmp() сравнение или строка1==строка2
strlen() длина строки 

ввод getline(cin, строка);
*/
int main()
{
	fstream fin, fout;
	string str1,sim;
	fin.open("fin.txt", std::fstream::in);
	fout.open("fout.txt", std::fstream::out);
	getline(fin, str1);
	getline(fin, sim);
	size_t i = 0;
	while (i!=std::string::npos)
	{
		i = str1.find(sim, i+1);
		if (i == std::string::npos) break;
		fout << i<<" ";
	}
	fin.close();
	fout.close();
}

