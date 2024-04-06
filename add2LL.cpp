/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i = 0, num1 = 0, num2 = 0, num3 = 0;

        while (l1 != NULL) {
            num1 += (l1->val) * (pow(10, i));
            l1 = l1->next;
            i++;
        }
        i = 0;
        while (l2) {
            num2 += (l2->val) * (pow(10, i));
            l2 = l2->next;
            i++;
        }
        num3 = num1 + num2;
        ListNode* head = NULL;
        int rem;
        ListNode* prev = NULL;
        if (num3 == 0) {
            return new ListNode(num3);
        }
        while (num3) {
            rem = num3 % 10;
            num3 = num3 / 10;
            ListNode* newNode = new ListNode(rem);
            if (head == NULL) {
                head = newNode;
            }
            if (prev) {
                prev->next = newNode;
            }

            prev = newNode;
        }

        // how do i maintain a head to the new linkedlist
        return head;
    }
};