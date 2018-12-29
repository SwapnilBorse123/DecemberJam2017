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
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int dp[nums.size()] = {0};
        dp[0] = 1;
        int globalMax = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i-1]){
                dp[i] = dp[i-1]+1;
            }else{
                dp[i] = 1;
            }
            if(dp[i] > globalMax){
                globalMax = dp[i];
            }
            // int len = 0;
            // for(int j = i; j > 0; --j){
            //     if(nums[j-1] < nums[j]){
            //        len++; 
            //     }else{
            //         break;
            //     }
            // }
            // dp[i] = len+1;
            // //cout << "for " << nums[i] << " " << dp[i] << endl;
            // if(dp[i] > globalMax){
            //     globalMax = dp[i];
            // }
            // cout << "for " << nums[i] << " " << dp[i] << endl;
        }
        return globalMax;
    }
};