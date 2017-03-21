#include <iostream>
#include <string>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void printList(ListNode* l1) {
        while(l1 != NULL) {
            cout << l1->val << "->";
            l1 = l1->next;
        }
        cout << endl;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;

            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* remain = NULL;
        if (l1 != NULL) {
            remain = l1;
        }
        else {
            remain = l2;
        }

        while(remain != NULL) {
            int sum = remain->val + carry;
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;

            cur = cur->next;
            remain = remain->next;
        }
        if (carry != 0) {
            cur->next = new ListNode(carry);
        }

        ListNode* res = head->next;
        delete head;
        return res;
    }
};


int main() {
    ListNode* add1 = new ListNode(1);
//    add1->next = new ListNode(4);
//    add1->next->next = new ListNode(3);

    ListNode* add2 = new ListNode(9);
//    add2->next = new ListNode(6);
//    add2->next->next = new ListNode(4);

    Solution s;

    s.printList(add1);
    s.printList(add2);
    s.printList(s.addTwoNumbers(add1, add2));
}
