#include "solution.h"
#include <string>
#include <set>
#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
	//时间复杂度O(n2)
	int lengthOfLongestSubstring(string s) {
		if (empty(s)) return 0;
		int len = 1;
		int lenMax = 1;
		set<char> set;
		for (int i = 0; i < s.size(); i++)
		{
			set.clear();
			if (len > lenMax) {
				lenMax = len;
			}
			len = 1;
			set.insert(s[i]);
			for (int j = i + 1; j < s.size(); j++)
			{
				if (set.find(s[j]) == set.end())
				{
					set.insert(s[j]);
					len++;
				}
				else {
					break;
				}
			}
		}
		return lenMax;
	}
	//滑动窗口：O（n）
	int lengthOfLongestSubstring_SlidingWindow(string s) {
		unordered_set<char> uset;
		int left = 0;
		int lenMax = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (uset.find(s[i]) != uset.end())
			{
				uset.erase(s[i]);
				left++;
			}
			uset.insert(s[i]);
			lenMax = max(lenMax, i - left + 1);
		}
		return lenMax;
	}
};



int main()
{
	string s = "abcabcbb";
	Solution sol = Solution();
	cout<<sol.lengthOfLongestSubstring(s)<<endl;
	cout << sol.lengthOfLongestSubstring_SlidingWindow(s) << endl;
	return 0;
}
