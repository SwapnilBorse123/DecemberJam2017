/*
    Date: 12/28/2018
*/

// 4 ms solution

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool is_vowel[256] = { false }; // initializes all values to false
    
    string reverseVowels(string s) {
        if(s.empty()){
            return s;
        }
        init();
        int low = 0, high = s.length()-1;
        
        while(low < high){
            while(!isVowel(s[low])){
                low++;
            }
            while(!isVowel(s[high])){
                high--;
            }
            if(low<high && (s[low] ^ s[high])){
                //cout << "swapping: " << s[low] << " and " << s[high] << endl;
                s[low] = s[low] ^ s[high];
                s[high] = s[low] ^ s[high];
                s[low] = s[low] ^ s[high];
                low++; high--;
            }else{
                low++; high--;
            }
        }
        return s;
    }
    
    void init() {
        is_vowel['A'] = true;
        is_vowel['a'] = true;
        is_vowel['E'] = true;
        is_vowel['e'] = true;
        is_vowel['I'] = true;
        is_vowel['i'] = true;
        is_vowel['O'] = true;
        is_vowel['o'] = true;
        is_vowel['U'] = true;
        is_vowel['u'] = true;
    }
    
    bool inline isVowel(char c){
        return is_vowel[c]; 
    }
};

// 12 ms solution

/*
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    
    string reverseVowels(string s) {
        if(s.empty()){
            return s;
        }
        int low = 0, high = s.length()-1;
        while(low < high){
            while(low < high && s[low]!='a' && s[low]!='e' && s[low]!='i' && s[low]!='o' && s[low]!='u' && s[low]!='A' && s[low]!='E' && s[low]!='I' && s[low]!='O' && s[low]!='U'){
                low++;
            }
            while(high > low && s[high]!='a' && s[high]!='e' && s[high]!='i' && s[high]!='o' && s[high]!='u' && s[high]!='A' && s[high]!='E' && s[high]!='I' && s[high]!='O' && s[high]!='U'){
                high--;
            }
            if(s[low] ^ s[high]){
                cout << "swapping: " << s[low] << " and " << s[high] << endl;
                s[low] = s[low] ^ s[high];
                s[high] = s[low] ^ s[high];
                s[low] = s[low] ^ s[high];
                low++; high--;
            }else{
                low++; high--;
            }
        }
        return s;
    }
    
};
*/