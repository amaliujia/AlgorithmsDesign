stNode *p1 = headA;
        ListNode *p2 = headB;
        bool pf = false;
        bool pp = false;
        while(!(p1 == NULL || p2 == NULL || p1 == p2)){
            if(p1->next == NULL && !pf){
                p1 = headB;
                pf = true;
            }else{
                p1 = p1->next;
            }
            if(p2->next == NULL && !pp){
                p2 = headA;
                pp = true;
            }else{
                p2 = p2->next;
            }            
            
        }
        
        if(p1 == p2 && p1 != NULL && p2 != NULL){
            return p1;
        }else{
            return NULL;
        }
    }
