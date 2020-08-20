// given an array of prices, find the maximum profit possibe by one transaction

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0,mn=INT_MAX;
        int i,n=prices.size();
        int ans=0;
        for(i=0;i<n;i++){
            if(prices[i]<mn){
                mn=prices[i];
            } else {
                mx = max(mx, prices[i]-mn);
            }
        }
        return mx;
    }
};