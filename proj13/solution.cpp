#include <string>
#include <unordered_map>
#include <iostream>
/*
* 	//正常 求和
	//不正常，正常-错位次数*错位值*2
	//VI=4 
	//IV=6
	//XL=40
	//LX=60
	//不正常：IV,IX,XL,XC,CD,CM
*/
using namespace std;
class Solution
{
public:

	int romanToInt(string s)
	{
		if (empty(s)) return -1;
		const int TypeSize = 7;
		unordered_map<char, int> types{ {'I',1},{'V',5},{'X',10},
			{'L',50},{'C',100},{'D',500},{'M',1000} };
		unordered_map<string, int> special{ {"IV",2},{"IX",2},{"XL",20},
			{"XC",20},{"CD",200},{"CM",200} };
		unordered_map<char, int> nums;
		int value = 0;
		for (int i = 0; i < s.size(); i++)
		{

			switch (s[i])
			{
			case 'I':
				nums['I']++;
				break;
			case 'V':
				nums['V']++;
				break;
			case 'X':
				nums['X']++;
				break;
			case 'L':
				nums['L']++;
				break;
			case 'C':
				nums['C']++;
				break;
			case 'D':
				nums['D']++;
				break;
			case 'M':
				nums['M']++;
				break;
			}
		}
		for (auto kv : nums)
		{
			//cout << kv.first <<": " << kv.second << endl;
			value += types[kv.first] * kv.second;

		}
		for (int i = 0; i < s.size() - 1; i++)
		{
			string t = "";
			t = t + s[i] + s[i + 1];
			for (auto kv : special)
			{
				if (kv.first == t)
				{
					value -= kv.second;
				}
			}
		}

		return value;
	}
};