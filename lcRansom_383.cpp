/*
Date: 12/21/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

//#define APLHABET 26

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty()){
            return true;
        }
        if(magazine.empty()){
            return false;
        }
        int hash[26] = {0};
        for(int i = 0; i < magazine.length(); ++i){
            hash[magazine[i]-'a']++;   
        }
        for(int j = 0; j < ransomNote.length(); ++j){
            if(hash[ransomNote[j]-'a'] <= 0){
                return false;
            }else{
                hash[ransomNote[j]-'a']--;
            }
        }
        return true;
    }
};