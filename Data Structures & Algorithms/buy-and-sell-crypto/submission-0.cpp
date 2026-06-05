class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int mini=100;
        for(int price:prices){
            mini=min(price,mini);
            maxi=max(maxi,price-mini);
        }
        return maxi;
    }
};
