class ThroneInheritance {
public:
    struct ThroneNode {
        string name_;
        int state_;
        vector<ThroneNode *> children_;
        ThroneNode(const string &name) : name_(name), state_(1) {}
        void setState(int state) { state_ = state; }
        ~ThroneNode() {
            for (auto node : children_) {
                delete node;
            }
        }
    };
    ThroneInheritance(string kingName) {
        king_ = new ThroneNode(kingName);
        index_.emplace(kingName, king_);
    }

    void birth(string parentName, string childName) {
        auto parent = index_[parentName];

        auto child = new ThroneNode(childName);

        parent->children_.push_back(child);
        index_.emplace(childName, child);
    }

    void death(string name) { index_[name]->setState(0); }

    vector<string> getInheritanceOrder() {
        vector<string> res;

        function<void(const ThroneNode *node)> preorder =
            [&](const ThroneNode *node) {
                if (node != nullptr && node->state_) {
                    res.push_back(node->name_);
                }

                for (auto child : node->children_) {
                    preorder(child);
                }
            };

        preorder(king_);

        return res;
    }

    ~ThroneInheritance() { delete king_; }

    ThroneNode *king_;
    unordered_map<string, ThroneNode *> index_;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */