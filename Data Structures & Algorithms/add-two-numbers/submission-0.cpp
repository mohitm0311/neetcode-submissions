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
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* new_head = new ListNode(0);
        ListNode* temp3 = new_head;
        while(temp1 && temp2){
            int x = temp1->val;
            int y = temp2->val;
            int new_val = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            temp3->next = new ListNode(new_val);
            temp3 = temp3->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int x = temp1->val;
            int new_val = (x+carry)%10;
            carry = (x+carry)/10;
            temp3->next = new ListNode(new_val);
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
        while(temp2){
            int x = temp2->val;
            int new_val = (x+carry)%10;
            carry = (x+carry)/10;
            temp3->next = new ListNode(new_val);
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        if(carry!=0){
            temp3->next = new ListNode(carry);
        }
        return new_head->next;
    }
};
