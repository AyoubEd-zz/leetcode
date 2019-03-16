/* https://leetcode.com/problems/find-common-characters
 * Solution: brute force, take the min of occurences of a given character in every string
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> v;
        vector<int> occ(26, INT_MAX);
        for(auto a:A){
            vector<int> occ_tmp(26, 0);
            for(char c:a) occ_tmp[c-'a']++;
            for(int i=0;i<26;i++) occ[i] = min(occ[i], occ_tmp[i]);
        }
        for(int i=0;i<26;i++){
            if(occ[i]!=0){
                  while(occ[i]--){
                          v.push_back(string(1, (char)i+'a'));
                          occ[i]--;
                  }      
            }
        }
        return v;
    }
};
