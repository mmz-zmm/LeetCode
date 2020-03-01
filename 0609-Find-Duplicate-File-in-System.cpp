class Solution {
public:
// https://leetcode-cn.com/problems/find-duplicate-file-in-system/solution/c-istringstremunordered_map-by-mengdtt/
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ret;
        if(paths.size() == 0) return ret;

        typedef vector<string> dirs;
        unordered_map<string, dirs> maps;
        

        string base_path;
        string file;
        string ab_path;
        string content;
        string::size_type pos = 0;
        istringstream record;

        for( auto path : paths) {
            // istringstream多次使用时的用法，需要先调用clear，再使用str进行赋值
            record.clear();
            record.str(path);
            record >> base_path;
            while( record >> file) {
                pos = file.find('(');
                content = file.substr(pos);
                ab_path = base_path + "/" + file.substr(0, pos);
                maps[content].push_back(ab_path);
            }
        }

        for(auto map : maps) {
            if(map.second.size() > 1) {
                ret.push_back(map.second);
            }
        }

        return ret;
    }
};