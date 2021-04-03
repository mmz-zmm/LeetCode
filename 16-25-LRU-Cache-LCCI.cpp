/**
 * 1、unordered_map + list 
 * 2、list.splice
 * */
class LRUCache {
public:
    typedef int key;
    typedef int val;
    typedef list<pair<key, val>>::iterator cache_itr; 

    LRUCache(int capacity):capacity_(capacity) {

    }
    void adjustLRU(cache_itr itr) {
        cache.splice(cache.end(), cache, itr);
    } 
    
    int get(int key) {
        auto res = index.find(key);
        if (res != index.end()) {
            adjustLRU(res->second);
            return res->second->second;
        } else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto res = index.find(key);
        if(res != index.end()) {
            res->second->second = value;
            adjustLRU(res->second);
        } else {
            if(cache.size() >= capacity_) {
                index.erase(cache.begin()->first);
                cache.pop_front();
            }
            cache.emplace_back(key, value);
            index.emplace(key, --cache.end());
        }
    }

    int capacity_;
    list<pair<key, val>> cache;
    unordered_map<key, cache_itr> index;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */