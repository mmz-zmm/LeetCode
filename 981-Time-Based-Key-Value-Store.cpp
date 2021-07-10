class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        index[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto iter = index.find(key);
        if (iter == index.end()) {
            return "";
        }
        auto &values = iter->second;
        auto iter2 =
            upper_bound(values.begin(), values.end(), make_pair(timestamp, ""),
                        [&timestamp](const pair<int, string> &lhs,
                                     const pair<int, string> &rhs) {
                            return lhs.first < rhs.first;
                        });

        if (iter2 != values.begin()) {
            return (--iter2)->second;
        }

        return "";
    }
    typedef vector<pair<int, string>> val_vec;
    unordered_map<string, val_vec> index;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */