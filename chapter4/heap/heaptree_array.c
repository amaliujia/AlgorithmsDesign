/*
	Total time: O(nlogn)
*/

typedef struct 
{
	item_type q[PQ_SIZE + 1];	// body of queue
	int n;						// number of member of this queue
}priority_queue;

int pq_parent(int n)
{
	if(n == 1)
		return -1;
	else
		return ((int)(n / 2));
}

int pq_little_child(int n)
{
	return 2 * n;
}

int pq_big_child(int n)
{
	return 2 * n + 1;
}

// constant time plus logn time
void pq_insert(priority_queue *q, item_type x)
{
	if (q->n >= PQ_SIZE)
	{
		printf("Warning: priority queue overflow insert x = %d\n", x);
	}else{
		q->n = (q->n) + 1;
		q->q[q->n] = x;
		bubble_up(p, p->n);
	}
}

void bubble_up(priority_queue *q, int p)
{
	if (pq_parent(p) == -1)
	{
		return; // root of heap, no need to adjust
	}

	if (q->q[p] < q->q[pq_parent(p)])
	{
		pq_swap(q, p);
		bubble_up(q, pq_parent(p));
	}
}
// constant time
void pq_swap(priority_queue *q, int p)
{
	item_type temp;
	temp = q->q[p];
	q->q[p] = q->q[pq_parent(p)];
	q->q[pq_parent(p)] = temp;
}

void pq_init(priority_queue *q)
{
	q->n = 0;
}

void make_heap(priority_queue *q, int n, item_type s[])
{
	pq_init(q);
	for (int i = 0; i < n; ++i)
	{		
		/* code */
		insert(q, s[i]);
	}
}


