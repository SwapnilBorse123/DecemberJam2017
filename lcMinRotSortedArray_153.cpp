class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int l = 0, h = nums.size()-1;
        while(l <= h){
            //if(!(l^h)) return nums[l];
            int mid = l + (h - l)/2;            
            if(mid-1>=0 && mid+1 <= nums.size()-1 && nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid]){ // left and right are greater
                return nums[mid+1];
            }else if(mid-1>=0 && mid+1 <= nums.size()-1 && nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid]){
                return nums[mid];
            }else if(mid == 0){ 
                if(nums[mid+1] < nums[mid]){
                    return nums[mid+1];
                }else{
                    return nums[mid];
                }
            }else if(mid == nums.size()-1 && nums[mid-1] < nums[mid]){
                return nums[mid-1];
            }else if(nums[mid] < nums[h]){
                h = mid-1;
            }else if(nums[mid] > nums[h]){
                l = mid+1;
            }
        }
    }
    
    // int bs(vector<int>& nums, int l, int h){
    //     if(l <= h){
    //         int m = l + (h-l)/2;
    //         if(m>=0 && m<nums.size()-1){
    //             if(nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid]){
    //                 return mid;
    //             }else if(nums[mid-1] > nums[mid]){
    //                 return mid;
    //             }else if(nums[mid+1] < nums[])
    //         }
    //     }
    // }
};