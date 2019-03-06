/* https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards
 * Solution: calculate occurences and find GCD
*/

class Solution {
public:
    int pgcd(int a, int b){
        if(b==0) return a;
        return pgcd(b, a%b);
    }
    int pgcd(vector<int>& A){
        int p = pgcd(A[0], A[1]);
        for(int i=2 ; i<A.size(); i++) p = pgcd(p, A[i]);
        return p;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<2) return false;
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0 ; i<deck.size() ; i++) {
            mp[deck[i]]++;
        }
        for (const auto &s : mp) v.push_back(s.second);
        int prec = (v.size()<2)?v[0]:pgcd(v);
        if(prec<2) return 0;
        else return 1;
    }
}

