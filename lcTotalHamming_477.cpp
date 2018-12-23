/*
Date: 12/23/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int totalHd = 0;
        for(int i = 0; i < sizeof(int)*8; ++i){
            int count = 0;
            for(int j = 0; j < nums.size(); ++j){
                //totalHd += hammingDistance(nums[i], nums[j]);
                if(nums[j] & (1 << i)){
                    count++;
                }
            }
            totalHd += count * (nums.size()-count) * 2;
        }
        return totalHd/2;
    }
    /*
    int hammingDistance(int x, int y) {
        //int hD = 0;
        // for(int i = 0; i < (sizeof(int)*8); ++i){
        //     if(!((x & (1 << i)) ^ (y & (1 << i)))){
        //         hD++;   
        //    }
        // }
        return __builtin_popcount (x ^ y);
        //return (sizeof(int)*8)-hD;
    }
    */
};