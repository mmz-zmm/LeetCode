// advanced version, use extra vector to store increments, so increments operation is O(1) now.
// when need pop, add increments to the origin value.
class CustomStack {
public:
    CustomStack(int maxSize) {
        imp.reserve(maxSize);
    }
    
    void push(int x) {
        if (imp.size() >= imp.capacity()) {
            return;
        }
        imp.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        if (imp.empty()) {
            return -1;
        }
        int ret = imp.back();
        int cur_cnt = imp.size();
        if (cur_cnt >= 1) {
            int extra = inc[cur_cnt - 1];
            ret += extra;
            inc[cur_cnt - 1] = 0;
            if( cur_cnt >= 2) {
                inc[cur_cnt - 2] += extra;
            }
        }
        imp.pop_back();
        
        return ret;  
    }
    
    void increment(int k, int val) {
        int limit = (k < imp.size()) ? k: imp.size();
        if( limit >= 1) {
            inc[limit - 1] += val;
        }
    }
    vector<int> imp;
    vector<int> inc;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */