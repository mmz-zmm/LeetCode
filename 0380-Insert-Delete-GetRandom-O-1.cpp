class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = my_map.find(val);
        if(it != my_map.end()) {
            return false;
        }
        my_map[val] = key_index.size();
        key_index.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = my_map.find(val);
        if( it == my_map.end()) return false;
        
        int index = my_map[val];
        int sz = key_index.size();
        my_map[key_index[sz - 1]] = index;
        swap(key_index[index], key_index[sz - 1]);
        key_index.pop_back();
        my_map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // std::random_device rd;
        // std::mt19937 gen(rd());
        // std::uniform_int_distribution<> dis(0, key_index.size()-1);
        // return key_index[dis(gen)];
        int idx  = rand() % key_index.size();
        return key_index[idx];
    }

private:
    vector<int> key_index;
    unordered_map<int, int> my_map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */