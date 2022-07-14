class RandomizedCollection {
public:
    vector<int> v1;
    unordered_map<int, unordered_set<int>> m1;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v1.push_back(val);
        m1[val].insert(v1.size() - 1);
        return m1[val].size() == 1;
    }
    
    bool remove(int val) {
        auto it = m1.find(val);
        if (it != end(m1)) {
            auto free_pos = *it->second.begin();
            it->second.erase(it->second.begin());
            v1[free_pos] = v1.back();
            m1[v1.back()].insert(free_pos);
            m1[v1.back()].erase(v1.size() - 1);
            v1.pop_back();
            if (it->second.size() == 0){
                m1.erase(it);
            }
            return true;
        }   
        return false;
    }
    
    int getRandom() {
        int ind = (rand() % ((int)v1.size()));
        return v1[ind];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */