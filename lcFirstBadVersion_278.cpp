/*
    Date: 12/27/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return helper(1,n);    
    }
    
    int helper(int low, int high){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};