class Iterator {
    struct Data;
    Data* data;
public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  // virtual destructor. 
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int cur;
    Iterator *iter;
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        iter = this;
        cur = INT_MAX;
  }
  int peek() {
        if(cur == INT_MAX){
            cur = iter->next();
        }
        return cur;
  }

  int next() {
      int val;
      if(cur == INT_MAX){
          val = iter->next();
      }else{
          val = cur;
          cur = INT_MAX;
      } 
      
      return val;
  }

  bool hasNext() const {
      return cur != INT_MAX || iter->hasNext();
  }
};
