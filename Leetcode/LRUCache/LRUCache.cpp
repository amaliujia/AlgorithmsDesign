/*
	set func needs O(nm) time, n is set times, m is capacity of cache.
*/

class LRUCache{
public:
	LRUCache(int capacity){
		plate.capacity = capacity;	
	}
	
	int get(int key){
		map<int, breastplate>::iterator it;
		if((it = plate.cache.find(key)) != plate.cache.end()){
			(it->second).count++;	
			return (it->second).value;
		};
		return -1;
	}

	void set(int key, int value){
		if(plate.cache.find(key) != plate.cache.end()){
			plate.cache[key].value = value;
			plate.cache[key].count++;
			return;	
		}else if(plate.capacity <= plate.cache.size()){
			map<int, breastplate>::iterator it;
			int max = -1;
			int thisKey;	
			for(it = plate.cache.begin(); it != plate.cache.end(); it++){
				if((it->second).count > max){
					max = (it->second).count;
					thisKey = it->first;
				}
			}
			plate.cache.erase(plate.cache.find(thisKey));
		}
            plate.cache[key] = breastplate(value, 1);
	}

private:
	 struct breastplate{
		int value;
		int count;
		breastplate(int v, int c):value(v), count(c);
	};

	class Armor{
	public:
		map<int, breastplate> cache;
		int capacity;
	};

private:
	Armor plate;
};
