class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {

        auto cmp = [](const vector<string> &order_left,
                      const vector<string> &order_right) {
            int tableno_left = stoi(order_left[1]);
            int tableno_right = stoi(order_right[1]);
            return tableno_left < tableno_right ||
                   (tableno_left == tableno_right &&
                    order_left[2] < order_right[2]);
        };

        sort(orders.begin(), orders.end(), cmp);

        map<int, map<string, int>> table;
        set<string> foods;
        for (auto &order : orders) {
            auto tableno = stoi(order[1]);
            auto &food = order[2];
            table[tableno][food]++;
            foods.emplace(std::move(food));
        }

        vector<vector<string>> res;

        int n = foods.size() + 1;
        vector<string> header;
        header.reserve(n);
        header.emplace_back("Table");
        for (auto &food : foods) {
            header.emplace_back(std::move(food));
        }

        res.emplace_back(std::move(header));

        for (auto &[tableno, table_foods] : table) {
            vector<string> tuple;
            tuple.reserve(n);
            tuple.emplace_back(to_string(tableno));
            for (int i = 1; i < n; ++i) {
                auto &food = res[0][i];
                int cnt = table_foods.count(food) ? table_foods[food] : 0;
                tuple.emplace_back(to_string(cnt));
            }
            res.emplace_back(std::move(tuple));
        }

        return res;
    }
};