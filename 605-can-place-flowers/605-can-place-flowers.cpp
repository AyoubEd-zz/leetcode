class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int count = 0;
        bed.insert(bed.begin(), 0);
        bed.push_back(0);
        for(int i=1 ; i<bed.size()-1 ; i++){
            if(bed[i-1]+bed[i]+bed[i+1]==0){
                count++;
                bed[i]=1;
            }
            if(count>=n)return 1;
        }
        if(count>=n)return 1;
        else return 0;
    }
};