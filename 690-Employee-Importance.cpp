/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> maps;
        for (auto employ : employees) {
            maps.emplace(employ->id, employ);
        }

        return accumulate(maps, id);
    }

    int accumulate(unordered_map<int, Employee *> &maps, int id) {
        auto employ = maps[id];
        if (employ->subordinates.empty()) {
            return employ->importance;
        }
        int res = employ->importance;
        for (int subid : employ->subordinates) {
            res += accumulate(maps, subid);
        }
        return res;
    }

    // by queue
    int getImportance2(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> maps;
        for (auto employ : employees) {
            maps.emplace(employ->id, employ);
        }

        queue<int> related;
        related.push(id);
        int res = 0;
        int top = 0;
        while (!related.empty()) {
            top = related.front();
            res += maps[top]->importance;
            related.pop();
            if (!maps[top]->subordinates.empty()) {
                for (auto subid : maps[top]->subordinates)
                    related.push(subid);
            }
        }
        return res;
    }
};