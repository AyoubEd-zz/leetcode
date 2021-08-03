class FreqStack {
private:
  int max_freq; 
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> mp;
public:
    FreqStack() {
        max_freq = 0;
        freq.clear();
        mp.clear();
    }
    
    void push(int val) {
        freq[val]++;
        mp[freq[val]].push(val);
        max_freq = max(max_freq, freq[val]);
    }
    
    int pop() {
        auto p = mp[max_freq].top();
        mp[max_freq].pop();
        
        freq[p]--;
        if(mp[max_freq].empty()) max_freq--;
        
        return p;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */