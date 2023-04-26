#include <iostream>
#include "solution.cpp"
using namespace std;
int main()
{
	ListNode* l1 = nullptr, * p = nullptr;
	ListNode* l2 = nullptr;
	//{0,1,2,3,4}
	for (int i = 0; i < 5; i++)
	{
		if (l1 == nullptr)
		{
			l1 = new ListNode(i);
			p = l1;
		}
		else
		{
			p->next = new ListNode((i + 4) % 10);
			p = p->next;
		}
	}
	//{1,2,3,4,5}
	for (int i = 0; i < 3; i++)
	{
		if (l2 == nullptr)
		{
			l2 = new ListNode((i*7+4) %10);
			p = l2;
		}
		else
		{
			p->next = new ListNode(i%5);
			p = p->next;
		}
	}
	//for (; l1; l1 = l1->next)
	//	cout << l1->val << endl;
	Solution sol = Solution();
	ListNode* res = nullptr;
	res = sol.addTwoNumbers(l1, l2);
	sol.printItem(res);

	return 0;
}