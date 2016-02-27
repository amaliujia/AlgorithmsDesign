Mergesort(item_type s[], int low, int high)
{
	int i;			//counter
	int middle;		//middle flag
	if(low < high)
	{
		middle = (high + low) / 2;
		Mergesort(s, low, middle);
		Mergesort(s, middle, high);
		Merge(s, low, middle, high);
	}
}

Merge(item_Type s[], int low, int middle, int high)
{
	int i;						//counter
	queue buffer1, buffer2;		//buffer for merge
	
	init_queue(&buffer1);
	init_queue(&buffer2);

	for(i = low; i <= middle; i++)  enqueue(&buffer1, s[i]);
	for(i = middle + 1; i <= high; i++) enqueue(&buffer1,s[i]);
	
	i = low;
	while(!(empty_queue(&buffer1) || !(empty_queue(&buffer2))))
	{
		if(headq(&buffer1) <= headq(&buffer2))
		{
			s[i++] = dequeue(&buffer1);
		}else{
			s[i++] = dequeue(&buffer2);
		}
	}
	
	while(!empty_queue(&buffer1)) s[i++] = dequeue(&buffer1);
	while(!empty_queue(&buffer2)) s[i++] = dequeue(&buffer2);

	destroy_queue(&buffer1);
	destroy_queue(&buffer2);				
}
