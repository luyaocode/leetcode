#ifndef PROJ9_H__
#define PROJ9_H__
#include <string>
using namespace std;
class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0) return false;
		string str = to_string(x);
		for (int i = 0; i < str.size() / 2; i++)
		{
			if (str[i] != str[str.size() - 1 - i]) return false;
		}
		return true;
	}
};

#endif