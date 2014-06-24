#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

#define CACHE_OK							0
#define CACHE_ARGUMENT_LOST                 1
#define CACHE_ARGUMENT_UNKNOWN              2
#define CACHE_ARGUMENT_LACK					3
#define CACHE_FILE_OPEN_FAIL				4


struct Line{
	int valid;
	unsigned long int tag;
	int counter;
};

//typedef struct _Line Line;
//typedef struct _Line *pLine; 
int getSet(unsigned long int addr, int s, int b);
unsigned long int getTag(unsigned long int addr, int s, int b);
int getBlock(int addr, int b);
int isDigit(char *a);
int myPow(int n, int power);
int getError(int code);
void myPrintSummary(int hit, int miss, int eviction);


int main(int argc,  char *argv[]){
	int rc = CACHE_OK;
		
	// argument
	if(argc <= 7){
		rc = getError(CACHE_ARGUMENT_LACK);
		return rc;
	}
	//here
	int set = 0, line = 0, block = 0, s = 0;
	int hit = 0, miss = 0, eviction = 0;
	char *path;
	int ch;
	int vflag = 0;
    while((ch = getopt(argc, argv, "vs:E:b:t:")) != -1){
        switch(ch){
            case 'v':
                printf("-v\n");
                vflag = 1;
				break;
            case 's':
                if(isDigit((&optarg[0])) == 0){
					//here
					s = atoi(optarg);
					set = myPow(2, atoi(optarg)); 
					printf("sets : %d\n", set);
                }else{
                    rc = getError(CACHE_ARGUMENT_LOST);
					return rc;
				}
                break;
            case 'E':
                if(isDigit(&optarg[0]) == 0){
                    line = atoi(optarg);
					printf("line: %d\n", line);
                }else{
                    rc = getError(CACHE_ARGUMENT_LOST);
					return rc;
				}
                break;
            case 'b':
               if(isDigit(&optarg[0]) == 0){
                    block = atoi(optarg); 
					printf("block: %d\n", block);
                }else{
                    rc = getError(CACHE_ARGUMENT_LOST);
					return rc;
				}
                break;
            case 't':
				path = optarg;	
				printf("-t %s\n", optarg);
                break;
            default:
                printf("Unknow arguments, argv = %c. \nPlease check your input\n", ch);
                rc = CACHE_ARGUMENT_LACK;
				return rc;}
    }
// File 
	FILE *fp; 
	fp = fopen(path, "r");
	if(!fp){
		rc = getError(CACHE_FILE_OPEN_FAIL);
		return rc;
	}	
	struct Line cache[set][line];	
	int capacity[set];
	int i ,j;
	for(i = 0; i < set; i++){
		capacity[i] = line;;
	}
	for(i = 0; i < set; i++){
		for(j = 0; j < line; j++){
			cache[i][j].valid = 0;
			cache[i][j].tag = -1;
			cache[i][j].counter = 0;
		}
	}
	char identifier;
	unsigned long int address;
	int size;
	
	while(fscanf(fp, " %c %lx,%d", &identifier, &address, &size) > 0){
		if(identifier == 'I')	continue;
		if(vflag == 1){
			printf("%c %lx,%d ", identifier, address, size);
		}
		int aSet = getSet(address, s, block);
		unsigned long int aTag = getTag(address, s, block);
		int i, j, z;
		int c = 0;
		for(i = 0; i < line; i++){
				if((cache[aSet][i].tag == aTag) && (cache[aSet][i].valid == 1)){
					if((identifier == 'L') || (identifier == 'S')){
						hit++;
						 if(vflag == 1){
							printf("hit\n");	
						  }	
					}
					else{
						hit++;
						hit++;	
						if(vflag == 1){
							printf("hit hit\n");
						}
					}
					cache[aSet][i].counter = line;
					for(j = 0; j < line; j++){
						if(j != i){
							cache[aSet][j].counter--;
						}
					}
					c = 1;
					break;
				}
		}
		if(c == 1)	continue;
		miss++;
		if(vflag == 1){
			printf("miss ");
		}
		// decide if need to evict
		if(capacity[aSet] != 0){
		//code miss
			capacity[aSet]--;
			for(j = 0; j < line; j++){
				if(cache[aSet][j].valid == 0){
					cache[aSet][j].valid = 1;
					cache[aSet][j].tag = aTag;
					cache[aSet][j].counter = line;
					for(i = 0; i < line; i++){
						if(j != i){
							cache[aSet][i].counter--;
						}
					}
					break;
				}
			}
			if(identifier == 'M') {
				hit++;
				if(vflag == 1) printf("hit ");
			} 
		}else{
			// need to evict
			eviction++;
			if(vflag == 1){
				printf("eviction ");
			}
			int tempCounter = cache[aSet][0].counter;
			z = 0;
			for(i = 1; i < line; i++){
				if(cache[aSet][i].counter < tempCounter){
					tempCounter = cache[aSet][i].counter;
					z = i;
				} 
			}
			cache[aSet][z].counter = line;
			cache[aSet][z].tag = aTag;
			for(j = 0; j < line; j++){
				if(j != z){
					cache[aSet][j].counter--;
				}
			}
			if(identifier == 'M') {
				hit++;
				if(vflag == 1) printf("hit ");
			}
		}
		if(vflag == 1){
			printf("\n");
		}	
	}

	fclose(fp);
	
	myPrintSummary(hit, miss, eviction);
	return rc;
}


int getSet(unsigned long int addr, int s, int b){
	unsigned long int mask = 0x7fffffffffffffff >> (63 - s);
	addr = addr >> b;
	return mask & addr;	
}

unsigned long int getTag(unsigned long int addr, int s, int b){
	unsigned long int mask = 0x7fffffffffffffff >> (63 - s - b);
	addr = addr >> (s + b);
	return mask & addr;
}

int getBlock(int addr, int b){
	int mask = 0x7fffffff >> (31 - b);
	return mask & addr;
}

int isDigit(char *a){
    return (*a >= '0' && *a <= '9') ? 0 : 1;
}

int myPow(int n, int power){
	int val = 1;
	int i;
	for(i = 0; i < power; i++){
		val = val * n;	
	}
	return val;
}

int getError(int code){
    switch(code){
        case CACHE_ARGUMENT_LOST:
            printf("Lost necessry argument\n");
            break;
        case CACHE_ARGUMENT_UNKNOWN:
            break;
		case CACHE_FILE_OPEN_FAIL:
			printf("Failed to open test file\n");	
			break;
        case CACHE_ARGUMENT_LACK: 
			printf("Not enough parameters!\n");
			break;
		default:
            break;
    }
    return code;
}

void myPrintSummary(int hit, int miss, int eviction){
	printf("hits: %d, misses: %d, evictions %d\n", hit, miss, eviction);
}
