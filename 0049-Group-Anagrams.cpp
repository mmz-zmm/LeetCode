class Solution {
public:
    /*
    说来惭愧，最近一直在做回溯法的题目，所以一上来以为还是要用回溯法。结果没做出来。后来看了他人的回答才明白，直接暴力处理也没啥问题(STL一把梭)。
    验证了一句话，心里有锤子，看哪哪都是钉子。
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for( const auto& s:strs)
        {   
            string str(26,'0');
            for( const auto& c: s)
            {
                str[c - 'a']++;
            }
            map[str].push_back(s);
        }

        vector<vector<string>> res;
        for( auto & p : map)
        {
            res.push_back(std::move(p.second));
        }

        return res;
    }
};