/*
Date: 12/21/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int high = target - reader.get(0), low = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(reader.get(mid) == target){
                return mid;
            }else if(reader.get(mid) == 2147483647 || reader.get(mid) > target){
                high = mid-1;
            }else if(reader.get(mid) < target){ // out of range, update mid
                low = mid+1;
            }
        }
        return -1;
    }
};