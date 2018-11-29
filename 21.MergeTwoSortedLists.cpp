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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2 == NULL){
            return l1;
        }else if(l1==NULL && l2 != NULL){
            return l2;
        }else if(l1!=NULL && l2 == NULL){
            return l1;
        }else{
            struct ListNode *p = l1;
            struct ListNode *q = l2;
            struct ListNode *s, *t;
            if(p->val >= q->val){
                s = new ListNode(q->val);
                q = q->next;
            }
            else{
                s = new ListNode(p->val);
                p = p->next;
            }
            t = s;
            while(q != NULL && p != NULL){
                if(p->val < q->val){
                    t->next = new ListNode(p->val);
                    p = p->next;
                    t = t->next;
                }
                else if(p->val > q->val){
                    t->next = new ListNode(q->val);
                    q = q->next;
                    t = t->next;
                }
                else{
                    t->next = new ListNode(p->val);
                    t = t->next;
                    p = p->next;
                    t->next = new ListNode(q->val);
                    t = t->next;
                    q = q->next;
                }
            }
            if(p == NULL && q != NULL){
                while(q != NULL)
                {
                    t->next = new ListNode(q->val);
                    t = t->next;
                    q = q->next;
                }
            }
            if(p != NULL && q == NULL){
                    while(p != NULL)
                    {
                        t->next = new ListNode(p->val);
                        t = t->next;
                        p = p->next;
                    }
            }
            t->next = NULL;
            return s;
        }
    }
};

//只要是链表题，就要极力避免new新节点。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val > l2->val) {
            return mergeTwoLists(l2, l1);
        }
        
        ListNode *l3 = l1;
        ListNode *t3 = l3;
        l1 = l1->next;
        t3->next = NULL;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                t3->next = l1;
                l1 = l1->next;
            } else {
                t3->next = l2;
                l2 = l2->next;
            }
            t3 = t3->next;
            t3->next = NULL;
        }
        if (l1 != NULL) {
            t3->next = l1;
            l1 = NULL;
        }
        if (l2 != NULL) {
            t3->next = l2;
            l2 = NULL;
        }
        return l3;
    }
};