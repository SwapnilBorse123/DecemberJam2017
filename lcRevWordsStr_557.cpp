class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()){
            return s;
        }
        int low = 0, high = 0;
        while(high < s.length()){
            while(high < s.length() && s[high] != ' '){high++;}
            swap(s, low, high-1);
            ++high; low = high;
        }
        swap(s, low, high-1);
        return s;
    }
    
    void swap(string& s, int low, int high){
        while(low < high){
            s[low] = s[low] ^ s[high];
            s[high] = s[low] ^ s[high];
            s[low] = s[low] ^ s[high];
            low++; high--;
        }
    }
};