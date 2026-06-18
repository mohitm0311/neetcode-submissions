class Solution {
public:
    int len(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = len(head);
        int index = count - n;
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        return head;
    }
};