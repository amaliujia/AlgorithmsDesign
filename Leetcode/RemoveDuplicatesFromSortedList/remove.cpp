/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
	O(n) space
	O(n) time
*/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        vector<int> v;
        if(!head) return NULL;
        v.push_back(head->val);
        ListNode *cursor = head;
        while(cursor->next){
            if(v[v.size()-1] == cursor->next->val){
                cursor->next = cursor->next->next;
            }else{
                v.push_back(cursor->next->val);
                cursor = cursor->next;
            }
        }
        return head;
    }
};
