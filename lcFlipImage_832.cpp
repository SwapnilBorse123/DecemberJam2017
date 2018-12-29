/*
    Date: 12/29/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &it : A){
            std::reverse(it.begin(), it.end());
        }
        for(auto &it : A){
            for(auto &i : it){
                i = i ^ 1;
            }
        }
        return A;
    }
};