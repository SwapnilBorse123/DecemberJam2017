
/*
    Date: 12/26/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    string toLowerCase(string str) {
        string res = "";
        for(auto& it : str){
            res = res + (char)tolower(it);
        }
        return res;
    }
};