// O(n) time
// O(n) space

class Solution {
    typedef unordered_map<RandomListNode *, RandomListNode *> Map;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copy(head);
    }

    RandomListNode *copy(RandomListNode *head){
        if(head == NULL)    return NULL;
        Map map;
        RandomListNode *headCopy = new RandomListNode(head->label);
        map[head] = headCopy;
        RandomListNode *curr = head;
        if(curr->random != NULL){
            if(map.find(curr->random) == map.end()){
                RandomListNode *pRand = new RandomListNode(curr->random->label);
                map[curr->random] = pRand;
                map[curr]->random = pRand;
            }else{
                map[curr]->random = map[curr->random];
            }
        }else{
            map[curr]->random = NULL;
        }
        while(curr->next != NULL){
            if(map.find(curr->next) == map.end()){
              RandomListNode *p = new RandomListNode(curr->next->label);
              map[curr]->next = p;
              map[curr->next] = p;
            }else{
                map[curr]->next = map[curr->next];
            }
            
            curr = curr->next;
            
            if(curr->random != NULL){
                if(map.find(curr->random) == map.end()){
                    RandomListNode *pRand = new RandomListNode(curr->random->label);
                    map[curr->random] = pRand;
                    map[curr]->random = pRand;
                }else{
                    map[curr]->random = map[curr->random];
                }
            }else{
                map[curr]->random = NULL;
            }
        }
        map[curr]->next = NULL;
        return headCopy;
    }
};
