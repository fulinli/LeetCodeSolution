/*
You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example
Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output : 7 -> 0 -> 8
	Explanation : 342 + 465 = 807.
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        long sum = 0, l1value = 0, l2value = 0, mul;
        struct ListNode* result = NULL;
        struct ListNode* curr = l1;
        mul = 1;
        while(curr!= NULL)
        {
            l1value = l1value + curr->val*mul;
            curr = curr->next;
            mul = mul * 10;
        }
        curr = l2;
        mul = 1;
        while(curr != NULL)
        {
            l2value = l2value + curr->val*mul;
            curr = curr->next;
            mul = mul * 10;
        }
        sum = l1value + l2value;
        result = (ListNode*)malloc(sizeof(ListNode));
//      result = new ListNode(0);
        curr = result;
        while (sum > 0)
        {
            curr->val = sum % 10;
            if (sum >= 10)
            {
                sum = sum / 10;
                curr->next = (ListNode*)malloc(sizeof(ListNode));
//              curr->next = new ListNode(0);
                curr = curr->next;
            }
            else
            {
                curr->next = NULL;
                sum = -1;
            }
        }
        return result; 
    }
};