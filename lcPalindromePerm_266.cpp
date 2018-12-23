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
    bool canPermutePalindrome(string s) {
        if(s.empty()){
            return true;
        }        
        int hash[256] = {0};
        for(int i = 0; i < s.length(); ++i){
            hash[s[i]]++;
        }
        int oddCnt = 0;
        for(int i = 0; i < 256; ++i){
            if(hash[i] & 1){
                oddCnt++;
                if(oddCnt > 1){
                    return false;
                }
            }
        }
        return true;
    }
};