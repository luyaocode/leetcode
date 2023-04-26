#include <iostream>
#include "solution.cpp"
int main()
{

	vector<int> nums = { 1,32,435,232,434,21,3,21,21,43 };
	vector<int> res;
	int target = 46;
	Solution s = Solution();
	res = s.twoSumHash(nums, target);
	s.printVector(res);
	return 0;
}