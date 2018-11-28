class Solution {
public:
    int pivotIdx = -1;
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        getPivotIndex(nums, 0, nums.size()-1, nums.size());   
        int s1 = bS(nums, 0, pivotIdx-1, target);
        if(-1 != s1){
            return s1;
        }else{
            return bS(nums, pivotIdx, nums.size()-1, target);
        }
    }
    
    int bS(vector<int>& nums, int low, int high, int target){
        if(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                return bS(nums, low, mid-1, target);
            }else{
                return bS(nums, mid+1, high, target) ;
            }
        }
        return -1;
    }
    
    void getPivotIndex(vector<int>& nums, int low, int high, int size){
        if(low <= high){
            int mid = low + (high-low)/2;
            if(mid-1 >= 0 && mid+1 < size && nums[mid+1] > nums[mid] && nums[mid-1] > nums[mid]){
                pivotIdx = mid;
                return;
            }else if(mid == 0 && nums[mid+1] > nums[mid]){
                pivotIdx = mid;
                return;
            }else if(mid == size-1 && nums[mid-1] > nums[mid]){
                pivotIdx = mid;
                return;
            }
            getPivotIndex(nums, low, mid-1, size);
            getPivotIndex(nums, mid+1, high, size);
        }
    }
};