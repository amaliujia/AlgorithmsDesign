/*
	what is time complexity?
	O(n) space
*/

class LRUCache{
  private:
    struct CacheNode{
      int key;
      int value;	
      CacheNode(int k, int v):key(k), value(v){};
    };

  public:
    LRUCache(int capacity){
      this->capacity = capacity;
    }

    int get(int key){
      if(cacheMap.find(key) != cacheMap.end()){
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;			
      }
      return -1;
    }

    int set(int key, int value){
      if(cacheMap.find(key) == cacheMap.end()){
        if(capacity <= cacheMap.size()){
          cacheMap.erase(cacheList.back().key);
          cacheList.pop_back();
        }
        cacheList.push_front(CacheNode(key, value));
        cacheMap[key] = cacheList.begin();
      }else{
        cacheMap[key]->value = value;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();	
      }
    }

  private:
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;
};
