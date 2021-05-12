class Solution {
public:
// 根据提示： x^y^x = y
// 因此： XOR(0,m-1) ^ XOR(m,n) = XOR(0,n); XOR(0,m-1) ^ XOR(m,n) ^ XOR(0,m-1) = XOR(m,n)
// 即：XOR(0,n) ^ XOR(0,m-1) = XOR(m,n)
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> XOR(arr.size(), 0);

        XOR[0] = arr[0];
        for(auto i = 1; i < arr.size(); ++i) {
            XOR[i] = XOR[i-1] ^ arr[i];
        }

        vector<int> ret;
        for(auto & query: queries) {
            int left = query[0];
            int right = query[1];
            if (left == 0) {
                ret.push_back(XOR[right]);
            } else {
                ret.push_back(XOR[right] ^ XOR[left-1]);
            }    
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix_xor(arr.size() + 1);
        
        prefix_xor[0] = 0;
        for(int i = 1; i < arr.size() + 1; ++i) {
            prefix_xor[i] = prefix_xor[i - 1] ^ arr[i - 1];
        }
        
        vector<int> res;
        res.reserve(queries.size());

        for(auto & query : queries) {
            res.push_back(prefix_xor[query[1] + 1] ^ prefix_xor[query[0]]);
        }

        return res;
    }
};