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
		printf("warning: priority queue overflow insert x = %d\n", x);
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
		insert(q, s[i]);
	}
}

item_type extract_min(priority_queue *q)
{
	int min = -1;
	if(q->n < 0)
		printf("warning: empty priority queue.\n");
	else{
		min = q->q[1];
		q->n = q->n -1;
		bubble_down(q, 1);
	}
	return min;
}

bubble_down(priority_queue *q, int p)
{
	int c;			//child index
	int i;			//counter
	int min_index;	//index of lightest child

	c= pq_little_child(p);
	min_index = p;

	for (int i = 0; i <= 1; ++i)
	{
		if ((c + i) <= p->n)
		{
			if (q->q[min_index] > q->q[c+i])
			{
				min_index = c + i;
			}
		}
	}

	if (min_index != p)
	{
		pq_swap(q, p, min_index);
		bubble_down(q, min_index);
	}
}


