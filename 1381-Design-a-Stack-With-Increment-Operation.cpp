// simple plain version
class CustomStack {
public:
    CustomStack(int maxSize):maxSize_(maxSize) {
        imp.reserve(maxSize);
    }
    
    void push(int x) {
        if (imp.size() >= maxSize_) {
            return;
        }
        imp.push_back(x);
    }
    
    int pop() {
        if (imp.empty()) {
            return -1;
        }
        int ret = imp.back();
        imp.pop_back();
        return ret;
        
    }
    
    void increment(int k, int val) {
        int limit = (k < imp.size()) ? k: imp.size();
        for (int i = 0; i < limit; ++i) {
            imp[i] += val;
        }
    }
    vector<int> imp;
    int maxSize_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */