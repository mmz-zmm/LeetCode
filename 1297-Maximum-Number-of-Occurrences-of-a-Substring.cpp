class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // 频次统计
        map<string, int> freq;
        // 注意end的计算，题目中的迷惑项，只需要找到minSize的即可，无需关心maxSize约束
        int end = s.size() - minSize + 1;
        for(auto i = 0; i < end; ++i) {
            string str = s.substr(i, minSize);
            if(substrCount(str) <= maxLetters) {
                freq[str]++;
            }
        }
        // 注意map可能为空，此时每个字串都不符合要求
        if (freq.size() == 0) return 0;

        // 调用max_element
        auto ret =  max_element(freq.begin(), freq.end(), 
        [](const pair<string, int> &lhs, const pair<string, int> &rhs){
            return lhs.second < rhs.second;
        });
        return ret->second;
    }

    // 字符统计
    int substrCount(const string & str){
        set<char> s;
        for(const auto & c : str) {
            s.insert(c);
        }
        return s.size();
    }
};