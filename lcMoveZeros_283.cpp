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
    void moveZeroes(vector<int>& nums) {
        int idx = 0, rIdx = 0, count = 0;
        //while(nums[rIdx] == 0){ rIdx++;}
        //if(rIdx == nums.size()){ return; }
        int i = 0;
        for(i = 0; i < nums.size();){
            if(rIdx < nums.size()){
                if(nums[rIdx] == 0){
                    rIdx++;
                }else{ //if(rIdx < nums.size() && (i ^ rIdx)){
                    nums[i] = nums[rIdx];
                    ++i; ++rIdx;
                }   
            }else{
                break;
            }
            // if(nums[i] == 0){ count++; }
            // while(nums[rIdx] == 0){ rIdx++; }
            // if((i ^ rIdx) && rIdx < nums.size()){ nums[i] = nums[rIdx]; rIdx++; }
            // else{ rIdx++; }
            // if(rIdx >= nums.size()){ break; }
            //cout << i << " <-> " << rIdx << endl;
        }
        //cout << i;
        for(int j = i; j < nums.size(); ++j){
            nums[j] = 0;
        }
    }
};