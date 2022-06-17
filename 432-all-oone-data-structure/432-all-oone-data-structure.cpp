class AllOne {
public:
    set<pair<int,string>> s1;
    map<string,int> freq;
    
    AllOne() {
        
    }
    
    void inc(string key) {
        if(freq[key] > 0){
            auto it = s1.find({freq[key], key});
            s1.erase(it);
            freq[key]++;
            s1.insert({freq[key], key});
        }
        else{
            freq[key]++;
            s1.insert({freq[key], key});
        }
    }
    
    void dec(string key) {
        auto it = s1.find({freq[key], key});
        s1.erase(it);
        freq[key]--;
        if(freq[key] > 0) s1.insert({freq[key], key});
    }
    
    string getMaxKey() {
        if(s1.empty()) return "";
        auto it = s1.end();
        it--;
        return (*it).second;
    }
    
    string getMinKey() {
        if(s1.empty()) return "";
        auto it = s1.begin();
        return (*it).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */