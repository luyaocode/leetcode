#include "solution.cpp"
#include <iostream>
int main()
{
	Solution s = Solution();
	//���� ���
	//������������-��λ����*��λֵ*2
	//VI=4 
	//IV=6
	//XL=40
	//LX=60
	//��������IV,IX,XL,XC,CD,CM
	string str = "MMDXIV";

	cout << str << endl;
	cout << s.romanToInt(str) << endl;

	return 0;
}