class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> banned_set(banned.begin(), banned.end());
        map<string, int> freq;
        string most_freq_word = "";
        int max_freq = 0;
        
        string word = "";
        for(char c: paragraph) {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                word.append(1, c);
            else {
                string lower_word = "";
                for(char cc: word)
                    lower_word.append(1, tolower(cc));
                
                if(lower_word.size() > 0 && banned_set.count(lower_word) == 0) {
                    freq[lower_word]++;
                    if(freq[lower_word] > max_freq) {
                        max_freq = freq[lower_word];
                        most_freq_word = lower_word;
                    }
                }
                word = "";
            }
        }
        string lower_word = "";
                for(char cc: word)
                    lower_word.append(1, tolower(cc));
        if(lower_word.size() > 0 && banned_set.count(lower_word) == 0) {
                    freq[lower_word]++;
                    if(freq[lower_word] > max_freq) {
                        max_freq = freq[lower_word];
                        most_freq_word = lower_word;
                    }
        }
        
        return most_freq_word;
    }
};
