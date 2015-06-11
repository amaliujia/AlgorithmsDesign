class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0;
        int b = 0;
        ListNode *ta = headA;
        while(ta != NULL){
            a++;
            ta = ta->next;
        }
        ListNode *tb = headB;
        while(tb != NULL){
            b++;
            tb = tb->next;
        }
        int distance = abs(a - b);
        
        ta = headA;
        tb = headB;
       
        if(a > b){
            while(distance > 0){
                distance--;
                ta = ta->next;
            }
        }else{
            while(distance > 0){
                distance--;
                tb = tb->next;
            }            
        }
        
        while(ta != NULL && tb != NULL){
            if(ta == tb){
                return ta;
            }
            ta = ta->next;
            tb = tb->next;
        }
        return NULL;
    }
};
