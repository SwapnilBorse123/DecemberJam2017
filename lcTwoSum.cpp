// Date: 26/9/2017
// Website: Leetcode
// Problem: Two Sum

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* retArr = (int*)malloc(sizeof(int)*2);
    for(int i = 0; i < numsSize-1; ++i){
        
        for(int j = i+1; j < numsSize; ++j){
            
            if(nums[i] + nums[j] == target){
                retArr[0] = i;
                retArr[1] = j;
                return retArr;
            }
        }
    }
    return retArr;
}