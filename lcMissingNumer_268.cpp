class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*if(nums.size() == 1){
            return 1;
        }
        */
        int total_sum = 0, max = nums.size();
        for(int i  = 0; i < nums.size(); ++i){          
            total_sum += nums[i];
        }
        return (max*(max+1)/2) - total_sum;
    }
};