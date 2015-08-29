#include <iostream>
using namespace std;

#define MAX_CHARS 26

struct TrieNode{
  int isEnd;
  unsigned int frequency;
  TrieNode* child[MAX_CHARS];
  
  int indexMinHeap;
};

struct MinHeapNode{
  TrieNode *root; //indicates the leaf node of TRIE.
  unsigned frequency; // num of word occurrences
  char *word; // actual word stored
};

struct MinHeap{
  unsigned capacity; // total size of a min heap, should be k here
  int count; // indicates the number of slots filled.
  MinHeapNode *array; // represents the collection of minHeapNodes.
};

TrieNode *newTrieNode(){
  TrieNode *node = new TrieNode;
  node->isEnd = 0;
  node->frequency = 0;
  node->indexMinHeap = -1;
  for(int i = 0; i < MAX_CHARS; i++){
    node->child[i] = NULL;
  }
  
  return node;
}

MinHeap *createMinHeap(int capacity){
  MinHeap *minHeap = new MinHeap;
  
  minHeap->capacity = capacity;
  minHeap->count = 0;
  
  minHeap->array = new MinHeapNode[minHeap->capacity];
  return minHeap;
}

void swapMinHeapNodes(MinHeapNode *a, MinHeapNode *b){
  MinHeapNode temp = *a;
  *a = *b;
  *b = temp;
}

// heapify
void minHeapify(MinHeap *minHeap, int idx){
  int left, right, smallest;
  
  left = 2 * idx + 1;
  right = 2 * idx + 2;
  smallest = idx;
  if(left < minHeap->count &&
      minHeap->array[left].frequency < 
      minHeap->array[smallest].frequency
    ){
    smallest = left;
  }
  
  if(right < minHeap->count &&
      minHeap->array[right].frequency <
     minHeap->array[smallest].frequency
    ){
    smallest = right;
  }
  
  if(smallest != idx){
    swapMinHeapNodes(&minHeap->array[idx], &minHeap->array[smallest]);
    
    minHeapify(minHeap, smallest);
  }
}

void buuildMinHeap(MinHeap *minHeap){
  int n, i;
  n = minHeap->count - 1;
  for(i = (n-1) / 2; i >= 0; i++){
    minHeapify(minHeap, i);
  }
}

void insertInMinHeap( MinHeap* minHeap, TrieNode** root, const char* word )
{
    // Case 1: the word is already present in minHeap
    if( (*root)->indexMinHeap != -1 )
    {
        ++( minHeap->array[ (*root)->indexMinHeap ]. frequency );
 
        // percolate down
        minHeapify( minHeap, (*root)->indexMinHeap );
    }
 
   // Case 2: Word is not present and heap is not full
    else if( minHeap->count < minHeap->capacity )
    {
        int count = minHeap->count;
        minHeap->array[ count ]. frequency = (*root)->frequency;
        minHeap->array[ count ]. word = new char [strlen( word ) + 1];
        strcpy( minHeap->array[ count ]. word, word );
 
        minHeap->array[ count ]. root = *root;
        (*root)->indexMinHeap = minHeap->count;
 
        ++( minHeap->count );
        buildMinHeap( minHeap );
    }
  
   else if ( (*root)->frequency > minHeap->array[0]. frequency )
    {
 
        minHeap->array[ 0 ]. root->indexMinHeap = -1;
        minHeap->array[ 0 ]. root = *root;
        minHeap->array[ 0 ]. root->indexMinHeap = 0;
        minHeap->array[ 0 ]. frequency = (*root)->frequency;
 
        // delete previously allocated memoory and
        delete [] minHeap->array[ 0 ]. word;
        minHeap->array[ 0 ]. word = new char [strlen( word ) + 1];
        strcpy( minHeap->array[ 0 ]. word, word );
 
        minHeapify ( minHeap, 0 );
    }
  
}

void insertUtil(TrieNode **root, MinHeap *minHeap, const char *word, const char *dupWord){
  if(*root == NULL){
    *root = new TrieNode();
  }
  
  if(*word != '\0'){
    insertUtil(&((*root)->child[tolower(*word) - 'a']), minHeap, word+1, dupWord);
  }else{
    if((*root)->isEnd){
      ++((*root)->frequency);
    }else{
          (*root)->isEnd = 1;
          (*root)->frequency = 1;      
    }
    insertInMinHeap(minHeap, root, dupWord);
  }
}

void insertTrieAndHeap(const char *word, TrieNode ** root, MinHeap* minHeap){
  insertUtil(root, minHeap, word, word);
}

void displayMinHeap( MinHeap* minHeap )
{
    int i;
 
    // print top K word with frequency
    for( i = 0; i < minHeap->count; ++i )
    {
        printf( "%s : %d\n", minHeap->array[i].word,
                            minHeap->array[i].frequency );
    }
}

void printKMostFreq(FILE *fp, int k){
  //Create a min heap of capacity k
  MinHeap *heap = createMinHeap(k);
  
  TrieNode *root = NULL;
  
  char buffer[1024];
  
  while(fscanf(fp, "%s", buffer) != EOF){
    //insert a word to trie and heap
    insertTrieAndHeap(buffer, &root, minHeap);
  }
}

int main() {
    int k = 5;
    FILE *fp = fopen ("file.txt", "r");
    if (fp == NULL)
        printf ("File doesn't exist ");
    else
        printKMostFreq (fp, k);
    return 0;
}
