#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void output(ListNode* head) {
	while (head != NULL) {
		cout << head->val << "->";
		head = head->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
	ListNode* cur = &head;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}

	if (l1 != NULL) {
		cur->next = l1;
	}
	if (l2 != NULL) {
		cur->next = l2;
	}

	return head.next;
    }
};

int main() {
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(3);

	ListNode* l2 = new ListNode(2);
	l2->next = new ListNode(4);

	output(l1);
	output(l2);

	Solution s;
	output(s.mergeTwoLists(l1, l2));

	return 0;
}
