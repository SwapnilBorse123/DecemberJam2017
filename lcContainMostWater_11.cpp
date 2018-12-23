/*
Date: 12/22/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int low = 0, high = height.size()-1, maxArea = 0;
        while(low < high){
            int area = (height[low] <= height[high] ? height[low] : height[high]) * (high - low);
            if(maxArea < area){
                maxArea = area;
            }
            if(height[high] <= height[low]){
                --high;
            }else if(height[high] > height[low]){
                ++low;
            }
        }
        return maxArea;
    }
};