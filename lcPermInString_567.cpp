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
    bool checkInclusion(string s1, string s2) {
        if(s2.empty() || s1.length() > s2.length()){
            return false;
        }
        string p = s1; string s = s2;
        int low = 0, pLen = p.length(), high = low + pLen-1;
        int hash[256] = {0}, wHash[256] = {0};
        int present = 0;
        for(int i = 0; i < p.length(); ++i){
            hash[p[i]]++;
            present |= (1 << (p[i])); // hash all present chars in p string
        }
        for(int j = low; j <= high; ++j){
            wHash[s[j]]++;
        }
        
        while(high < s.length()){
            bool found = true;
            //if(!found){
            for(int i = 0; i < p.length(); ++i){
                //int j = low;
                //cout << s[i] << ":";
                if(hash[p[i]] != wHash[p[i]]){
                    found = false;
                    break;
                }
            }
            //cout << endl;
            if(found){
                //cout << "pushing: " << low << endl;
                //res.push_back(low);
                return true;
            }
            wHash[s[low]]--;
            low++; high++;
            if(low < s.length() && high < s.length()){ wHash[s[high]]++; }
            // }else{
            //     if(hash[s[high]-'a'] == wHash[s[high]-'a']){
            //         res.push_back(low);
            //     }
            // }            
        }
        return false;
    }
};