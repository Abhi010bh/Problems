/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

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

        
        return head;
    }
};

//approach 2:
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
        int n1,n2,n3,carry=0;
        ListNode* prevNode=NULL;
        ListNode* head=NULL;
        while(l1!=nullptr || l2!=nullptr){
            
            (l1==nullptr)?n1=0:n1=l1->val;
            (l2==nullptr)?n2=0:n2=l2->val;
            
            n3=n1+n2+carry;
            carry=0;
            
            if(n3>=10){
                n3=n3-10;
                carry=1;
            }
            ListNode* newNode=new ListNode(n3);
            if(head==NULL){
                head=newNode;
            }
            if(prevNode){
                prevNode->next=newNode;
            }
            prevNode=newNode;
            if(l1!=nullptr){
                l1=l1->next;
            }
            if(l2!=nullptr){
                l2=l2->next;
            }
        }
        if(carry==1){
            ListNode* newNode=new ListNode(carry);
            prevNode->next=newNode;
        }
        
        return head;
    
    }
};

