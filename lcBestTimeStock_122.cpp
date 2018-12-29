/*
    Date: 12/26/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int maxProfit = 0;
        for(int i = 0; i < prices.size()-1; ++i){
            if(prices[i+1] > prices[i]){
                int p = i+1;
                while(p+1 < prices.size() && prices[p+1] > prices[p]){
                    ++p;
                }
                maxProfit += prices[p] - prices[i];
                i = p;
            }
        }
        return maxProfit;
    }
};