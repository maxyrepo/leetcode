#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void output(ListNode* l) {
	while(l) {
		cout << l->val << "->";
		l = l->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
	ListNode* new_head = head;
	if (head && head->next) {
		new_head = head->next;
	}

	ListNode* pre = NULL;
	ListNode* next = NULL;
	while (head && head->next) {
		if (pre) {
			pre->next = head->next;
		}
		next = head->next;
		head->next = head->next->next;
		next->next = head;
		pre = head;
		head = head->next;
	}

	return new_head;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	output(head);
	Solution s;
	output(s.swapPairs(head));

	return 0;
}
