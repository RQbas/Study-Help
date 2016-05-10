#include <iostream>
#include <string>
#include "Header.h"
#ifndef HEAD2_H
#define HEAD2_H
using namespace System;
using namespace std;

class departure :public delegation_base
{
public:
	string initial_city;
	string destination_city;
	string day_departure;
	string day_comeback;

	int dday[3]; //departure day array containing day|month|year
	int cday[3]; //same for comeback day

	int f_dhour[2]; //departure hour array hour|minutes
	string dhour;

	int f_chour[2]; //same for comeback
	string chour;

	string distance;
	float f_distance;
	
	
	int hourdiff_d(int *d) //method returning minutes to end of the departure day
	{
		int minperday;
		minperday = (60 - d[1]) + ((23 - d[0]) * 60);
			return minperday;
	}
	int hourdiff_c(int *d) //method returning minutes of comebackday
	{
		int minperday;
		minperday = d[0] * 60 + d[1];

		return minperday;
	}
	int daydiff(int *d, int *c) //method calculating how many days delegation lasts
	{
		int daypermonth[12];
		daypermonth[0] = 31; daypermonth[2] = 31; daypermonth[4] = 31; daypermonth[6] = 31; daypermonth[7] = 31; daypermonth[11] = 31; daypermonth[9] = 31;
		daypermonth[1] = 28;
		daypermonth[3] = 30; daypermonth[5] = 30; daypermonth[8] = 30; daypermonth[10] = 30;
		int daynumbd;
		int daynumbc;
		int difference;

		if (d[2] == c[2])
		{
			for (int i = 0; i < (d[1] - 1); i++)
			{
				daynumbd += daypermonth[i];
			}
			daynumbd += (d[0]+1);

			for (int i = 0; i < (c[1] - 1); i++)
			{
				daynumbc += daypermonth[i];
			}
			daynumbc += c[0];
		}
		if (d[2] < c[2])
		{
			for (int i = 0; i < (d[1] - 1); i++)
			{
				daynumbd += daypermonth[i];
			}
			daynumbd += (d[0] + 1);

			for (int i = 0; i < (c[1] - 1); i++)
			{
				daynumbc += daypermonth[i];
			}
			daynumbc += c[0]+abs(c[2]-d[2])*365;
		}
		difference = daynumbc - daynumbd;
		return difference;
	}

};
#endif