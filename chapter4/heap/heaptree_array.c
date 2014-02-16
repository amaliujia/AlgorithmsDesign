typedef struct 
{
	item_type q[PQ_SIZE + 1];	// body of queue
	int n;						// number of member of this queue
}priority_queue;

pq_parent(int n)
{
	if(n == 1)
		return -1;
	else
		return ((int)(n / 2));
}

pq_little_child(int n)
{
	return 2 * n;
}

pq_big_child(int n)
{
	return 2 * n + 1;
}

