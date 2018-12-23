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
    int longestPalindrome(string s) {
        if(s.empty()){ return 0; }
        int hash[256] = {0};
        for(int i = 0; i < s.length(); ++i){
            hash[s[i]]++;
        }
        int total = 0; 
        for(int i = 0; i < 256; ++i){
            total += (hash[i] / 2)*2;
        }
        if(s.length() > total){
            return total + 1;
        }else{
            return total;
        }
    }
};