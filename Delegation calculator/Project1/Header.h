#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include<sstream>
#ifndef HEAD_H
#define HEAD_H
using namespace System;
using namespace std;


class delegation_base
{
public:
	string delegation_number;
	string aim;
	string f_data;
	string mtrans;
	string daily_pay;
	float dailypay;
	int diet = 30;
	void StrToF(string& in, float& out)
	{
		out = stof(in);
	}

	void SysStrToStr(std::string& os, System::String^ s) //conversion from system string to std::string
	{
		using namespace System::Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	void DateConv(string& s, int *tab) //conversion data from string to tokenized int
	{
		string buffor;
		int cnt = 0;

		char *str = new char[s.length() + 1];
		strcpy(str, s.c_str());
		char * pch;
		pch = strtok(str, " ,.-");

		while (pch != NULL)
		{
			buffor = string(pch);
			stringstream ss(buffor);
			ss >> tab[cnt];
			cnt++;
			pch = strtok(NULL, " ,.-");

		}
	}
	void HourConv(string& s, int *tab) //same situation but for hours
	{
		string buffor;
		int cnt = 0;

		char *str = new char[s.length() + 1];
		strcpy(str, s.c_str());
		char * pch;
		pch = strtok(str, ": ,.-");

		while (pch != NULL)
		{
			buffor = string(pch);
			stringstream ss(buffor);
			ss >> tab[cnt];
			cnt++;
			pch = strtok(NULL, ": ,.-");

		}
	}
};



#endif