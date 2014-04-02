/*
 Inputs are two linked lists representing two non-negative numbers. The digits are stored in reverse order.

*/ 

/*
 * Defination for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        unsigned long long sum1 = 0;
        unsigned long long sum2 = 0;
        ListNode *l1s = l1;
        ListNode *l2s = l2;
        int i;
        int count1 = 0, count2 = 0;
        int count;
        while(l1s != NULL)
        {
            sum1 += (pow(10, count1) * l1s->val);   
            count1++;         
            l1s = l1s->next;
        }
        
        while(l2s != NULL)
        {
            sum2 += (pow(10, count2) * l2s->val);
            count2++;         
            l2s = l2s->next;
        }
        
        sum1 = sum1 + sum2;
        if(sum1 == 0)
        {
            return (new ListNode(0));
        }
        unsigned long long temp = sum1 - sum1/10*10;
        ListNode *pl = new ListNode((int)temp);
        ListNode *result = pl;
        sum1 = sum1/10;
        while(sum1 > 0)
        {
            temp = sum1 - sum1/10*10;
            pl->next = new ListNode((int)temp);
            pl = pl->next;
            sum1 = sum1/10;
        }
        return result;
    }
};
