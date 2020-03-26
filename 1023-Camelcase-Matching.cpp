class Solution {
public:
   /*
    * 双指针法，但是分别指向query和pattern
   */
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        ret.reserve(queries.size());

        for(const auto & query : queries) {
            auto i = 0;
            auto j = 0;
            while(i < query.size()) {
                if(j < pattern.size() && query[i] == pattern[j]) {
                    i++;
                    j++;               
                } else if (islower(query[i])) {
                    i++;
                } else {
                    break;
                }
            }
            
            if(i == query.size() && j == pattern.size()) {
                ret.push_back(true);
            } else {
                ret.push_back(false);
            }
            
        }

        return ret;
    }
};
