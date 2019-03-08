/* https://leetcode.com/problems/maximize-distance-to-closest-person
 * Solution: Group Zeros
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int xh=0, ch=0, j;
        seats.insert(seats.begin(), 1);      
        for(int i=1; i<seats.size() ; i++){
            if(seats[i-1]==1 && seats[i]==0){
                xh=i; 
                j=i;
                while(seats[j]==0 && j<seats.size()) j++;
                if(j==seats.size() || xh==1) ch = max(ch, j-xh);
                else ch = max((j-xh+1)/2, ch);
                i=j;
            }
            
        }
        return ch;
    }
};
