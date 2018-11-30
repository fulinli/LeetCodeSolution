/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return ;
        ListNode *t1, *t2, *nhead;
        t1 = head;
        while(t1->next->next != NULL){
            t1 = t1->next;
        }
        t2 = t1->next;
        t1->next = NULL;
        t1 = head->next;
        head->next = t2;
        t2->next = t1;
        nhead = t1;

        reorderList(nhead);
    }
};

