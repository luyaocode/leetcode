#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					res.push_back(i);
					res.push_back(j);
					break;
				}
			}
		}
		return res;
	}

	//use hashtable Ê±¼ä¸´ÔÓ¶ÈO(N)
	vector<int> twoSumHash(vector<int>& nums, int target) {
		vector<int> vec = {};
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = hashtable.find(target - nums[i]);
			if (it == hashtable.end())
			{
				hashtable[nums[i]] = i;
			}
			else
			{
				vec.push_back(it->second);
				vec.push_back(i);
			}
		}

		return vec;
	}
	void printVector(vector<int>& vec)
	{
		cout << "[";
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i];
			if (i != vec.size() - 1)
				cout << ",";
			else
				cout << "]";

		}
	}

};