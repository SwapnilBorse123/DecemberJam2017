/*
Date: 12/21/2019
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()){
            return 0;
        }
        int cnt = 0, i = s.length()-1;
        while(s[i] == ' '){
            --i;
        }
        for(; i >= 0; --i){
            if(s[i] != ' '){
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }
};