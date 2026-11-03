class TimeMap {
   private:
    unordered_map<string, map<int, string>> tm;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { tm[key].insert({timestamp, value}); }

    string get(string key, int timestamp) {
        auto it = tm[key].upper_bound(timestamp);
        if (it == tm[key].begin()) {
            return "";
        }
        --it;
        return it->second;
    }
};
