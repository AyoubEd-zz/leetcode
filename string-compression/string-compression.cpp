class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, k = 0;
        while(i < chars.size()) {
            int freq = 0;
            while(j < chars.size() && chars[i] == chars[j]) {
                j++;
                freq++;
            }
            
            chars[k++] = chars[i];
            if(freq > 1) {
                string tmp = to_string(freq);
                for(char c: tmp)
                    chars[k++] = c;
            } 
            i = j;
        }
        
        return k;
    }
};