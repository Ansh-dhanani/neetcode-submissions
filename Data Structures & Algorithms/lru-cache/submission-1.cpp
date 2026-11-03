class LRUCache {
   private:
    int c;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

   public:
    LRUCache(int capacity) { c = capacity; }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        int ans = it->second->second;
        l.erase(it->second);
        l.emplace_front(key, ans);
        mp[key] = l.begin();
        return ans;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            l.erase(it->second);
            mp.erase(it);
        }
        if (c == mp.size()) {
            mp.erase(l.back().first);
            l.pop_back();
        }
        l.emplace_front(key, value);
        mp[key] = l.begin();
    }
};
