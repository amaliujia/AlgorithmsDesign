/*
	assume we only need to deal with 'A-Z'
*/

void removeDuplicates(Node head)
{
    int flag = 0;
	Node n = head;
	flag = flag | (1 << head.data - 'A' + 1);
    while(n.next != null){
        if(flag & (1 << n.next.data - 'A' + 1) == 0){
            flag = flag | (1 << n.next.data - 'A' + 1);
            n = n.next;
        }else{
            n.next = n.next.next;
        }
    }
}
~ 
