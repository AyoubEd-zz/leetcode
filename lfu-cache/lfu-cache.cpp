class LFUCache {
private:
    int cap;
    int size;
    int minFreq;
    map<int, pair<int, int>> m; // key -> (val, freq)
    map<int, list<int>::iterator> it; // key -> iterator
    map<int, list<int>> fm; // freq -> [key...] list
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        
        fm[m[key].second].erase(it[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        it[key] = --fm[m[key].second].end();
        
        while(fm[minFreq].size() == 0)
            minFreq++;
        
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        
        int prev = get(key);
        if(prev != -1) {
            m[key].first = value;
            return;
        }
        
        if(size >= cap) {
            m.erase(fm[minFreq].front());
            it.erase(fm[minFreq].front());
            fm[minFreq].pop_front();
            size--;
        }
        
        m[key] = {value, 1};
        fm[1].push_back(key);
        it[key] = --fm[1].end();
        minFreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */