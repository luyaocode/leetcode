#include "solution.cpp"
#include <iostream>
int main()
{
	Solution s = Solution();
	//正常 求和
	//不正常，正常-错位次数*错位值*2
	//VI=4 
	//IV=6
	//XL=40
	//LX=60
	//不正常：IV,IX,XL,XC,CD,CM
	string str = "MMDXIV";

	cout << str << endl;
	cout << s.romanToInt(str) << endl;

	return 0;
}