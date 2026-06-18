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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* new_head = new ListNode(-1);
        ListNode* tep = new_head;
        ListNode* temp = list1;
        ListNode* temp1 = list2;
        while(temp && temp1){
            if(temp->val<= temp1->val){
                tep->next = new ListNode(temp->val);
                tep = tep->next;
                temp = temp->next;
            }
            else{
                tep->next = new ListNode(temp1->val);
                tep = tep->next;
                temp1= temp1->next;
            }
        }
        while(temp){
            tep->next = new ListNode(temp->val);
            tep = tep->next;
            temp = temp->next;
        }
        while(temp1){
            tep->next = new ListNode(temp1->val);
            tep = tep->next;
            temp1= temp1->next;
        }
        return new_head->next;
    }
};
