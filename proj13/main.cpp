#include "solution.cpp"
#include <iostream>
int main()
{
	Solution s = Solution();

	string str = "MMDXIV";

	cout << str << endl;
	cout << s.romanToInt(str) << endl;

	return 0;
}