#include <string>
#include <iostream>
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		//check nullptr
		if (!l1 || !l2) return nullptr;

		//define temp variables
		ListNode* p, * q, * res = nullptr, * temp = nullptr;
		p = l1;
		q = l2;
		int len1{ 1 }, len2{ 1 }, sum{}, flag{};

		//show items of l1,l2
		//printItem(l1); printItem(l2);

		//count the length of l1,l2
		for (; p->next; p = p->next) len1++;
		for (; q->next; q = q->next) len2++;

		//add 0 to equalize the length of l1 and l2
		if (len1 > len2)
		{
			for (int i = 0; i < len1 - len2; i++)
			{
				q->next = new ListNode(0);
				q = q->next;
			}
		}
		else if (len1 < len2)
		{
			for (int i = 0; i < len2 - len1; i++)
			{
				p->next = new ListNode(0);
				p = p->next;
			}
		}
		p = l1;
		q = l2;
		printItem(p);
		printItem(q);

		//calculate
		//if len1=1
		if (len1 == 1 && len2 == 1)
		{
			sum = p->val + q->val;
			if (sum >= 10) flag = 1;
			res = new ListNode(sum % 10);
			if (flag) res->next = new ListNode(flag);
			return res;
		}
		//if len1>1
		for (; p->next; p = p->next, q = q->next)
		{
			sum = p->val + q->val + flag;
			flag = 0;
			if (sum >= 10) flag = 1;
			if (!res)
			{
				res = new ListNode(sum % 10);
				temp = res;
			}
			else
			{
				temp->next = new ListNode(sum % 10);
				temp = temp->next;
			}
		}
		sum = p->val + q->val + flag;
		flag = 0;
		temp->next = new ListNode(sum % 10);
		if (sum >= 10) {
			flag = 1;
			temp->next->next = new ListNode(flag);
		}
		return res;
	}
	void printItem(ListNode* L)
	{
		ListNode* t = L;
		if (t == nullptr) return;
		for (; t->next; t = t->next) cout << t->val;
		cout << t->val << endl;
	}
};

