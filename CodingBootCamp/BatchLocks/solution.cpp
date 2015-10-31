class Lock{
 public:
   void lock(); //if cannot lock, suspend
   bool try_lock(); // if lock, return true, else return false
   void unlock();
};

static Lock Lock_map;
static map<int, Lock *> locks;

void batch(vector<int>& entites, map<int, Lock *>& locks){
  for(int i : entities) {
      Lock_map.lock();
      Lock *cur = NULL; 
      if (locks.find(i) == locks.end()){
          cur = new Lock();
          Lock_map.insert(pair<int, Lock*>(id, cur)); 
      }else{
        cur = locks[id];
      }
      Lock_map.unlock();

      while(!cur->try_lock());
  } 
}
