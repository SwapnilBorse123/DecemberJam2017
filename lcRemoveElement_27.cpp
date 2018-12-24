/*
Date: 12/24/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int idx = 0, rIdx = 0, count = 0;
        while(nums[rIdx] == val){ rIdx++; }
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == val){ count++; }
            while((rIdx < nums.size()) && (nums[rIdx] == val)){ rIdx++; }
            if(i ^ rIdx){ nums[i] = nums[rIdx]; rIdx++; }
            else{ rIdx++; }
        }
        
        return nums.size() - count;
    }
};