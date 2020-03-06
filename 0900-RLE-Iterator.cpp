class RLEIterator {
public:
    /*
     * 如果A[i] > n, 返回A[i+1]
     * 如果A[i] < n, 向右移动，n变为n-A[i]
     * 使用pos记录当前的位置,使用count记录当前位置剩余的元素个数，移动过程中需要更新count
    */
    RLEIterator(vector<int>& A): ref_(A), pos(0),count(ref_[0]){}
    
    int next(int n) {
        while( pos < ref_.size() && count < n) {
            n -= count;
            pos += 2;
            if(pos < ref_.size())
                count = ref_[pos];
        }

        if( pos >= ref_.size()) {
            return -1;
        }

        count -= n;  // A[pos] > n;

        return ref_[pos+1];
    }

private:
    vector<int>&  ref_;
    int pos;
    int count;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
