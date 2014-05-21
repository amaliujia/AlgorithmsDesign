public void drawHorizontalLine(byte[] screen, int width, int x1, int x2, int y){
	int start = ((y - 1) * width + x1) / 8;
	int offset = ((y - 1) * width + x1) % 8;
	int end = ((y - 1) * width + x2) / 8;
	int offsetE = ((y - 1) * width + x2) % 8;
	
	if((end-1-start) != 0 ){
		for(int i = start+1; i < end; i++){
			screen[i] = screen[i] | 0xff;
		}
	}

	if(offset != 0){
		byte startMask = 0xff >> offset;
		screen[start] |= startMask;	
	}

	if(offsetE != 0){
		byte endMask = 0xff << (8 - offsetE);
		screen[end] |= endMask;
	}
}
