/*
Date: 12/23/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()){
            return t[0];
        }
        int res = s[0];
        for(int i = 1; i < s.length(); ++i){
            res = res ^ s[i];
        }
        int rest = t[0];
        for(int i = 1; i < t.length(); ++i){
            rest = rest ^ t[i];
        }
        return (char)(res ^ rest);
    }
};