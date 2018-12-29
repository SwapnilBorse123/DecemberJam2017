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
    vector<int> res;
    vector<int> findAnagrams(string s, string p) {
        if(s.empty() || p.length() > s.length()){
            return res;
        }
        int low = 0, pLen = p.length(), high = low + pLen-1;
        int hash[26] = {0}, wHash[26] = {0};
        int present = 0;
        for(int i = 0; i < p.length(); ++i){
            hash[p[i]-'a']++;
            present |= (1 << (p[i]-'a')); // hash all present chars in p string
        }
        for(int j = low; j <= high; ++j){
            wHash[s[j]-'a']++;
        }
        
        while(high < s.length()){
            bool found = true;
            //if(!found){
            for(int i = 0; i < p.length(); ++i){
                //int j = low;
                //cout << s[i] << ":";
                if(hash[p[i]-'a'] != wHash[p[i]-'a']){
                    found = false;
                    break;
                }
            }
            //cout << endl;
            if(found){
                //cout << "pushing: " << low << endl;
                res.push_back(low);
            }
            wHash[s[low]-'a']--;
            low++; high++;
            if(low < s.length() && high < s.length()){ wHash[s[high]-'a']++; }
            // }else{
            //     if(hash[s[high]-'a'] == wHash[s[high]-'a']){
            //         res.push_back(low);
            //     }
            // }            
        }
        return res;
    }
};

/*
found = true;
for(int j = low; j <= high; ++j){
    if(present & (1 << (s[j]))){ // char present in p string
        wHash[s[j]-'a']++;
        if(wHash[s[j]-'a'] > hash[s[j]-'a']){
            wHash[s[j]-'a']--;
            low++;
            high = low + pLen-1;
            found = false;
        }else{
            low++; high++;
        }
    }else{
        low = j + 1;
        high = low + pLen-1;
    }
}
if(found){
    res.push_back(low);
    wHash[s[low]-'a']--;
    low++; high++;
}
*/