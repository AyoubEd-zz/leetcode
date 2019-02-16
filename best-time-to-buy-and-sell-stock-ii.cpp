//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// Peak Valley Approach
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        int p = prices[0], v = prices[0], maxProfit = 0, i = 0;
        while (i < n - 1)
        {
            while (i < n - 1 && prices[i] >= prices[i + 1])
                i++;
            v = prices[i];
            while (i < n - 1 && prices[i] <= prices[i + 1])
                i++;
            p = prices[i];
            maxProfit += p - v;
        }
        return maxProfit;
    }
};