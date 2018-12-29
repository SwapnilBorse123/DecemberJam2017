/*
    Date: 12/28/2018
*/
/*
int skipped = 0, low = 0, high = s.length()-1;
        while(low < high){
            if(s[low] == s[high]){
                cout << s[low] << " = " << s[high] << endl;
                ++low; --high;
            }else if(s[low] == s[high-1]){
                cout << s[low] << " = " << s[high-1] << " skipped: " << s[high] << endl;
                ++skipped;
                --high;
            }else if(s[low+1] == s[high]){
                cout << s[low+1] << " = " << s[high] << " skipped: " << s[high] << endl;
                ++skipped;
                ++low;
            }else{
                return false;
            }
            if(skipped > 1){
                return false;
            }
        }
        return true;
*/


static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    //int skipped = 0;
    bool validPalindrome(string s) {
        if(s.empty()){
            return false;
        }
        return checkPalindrome(s, 0, s.length()-1, 0);
    }
    
    bool checkPalindrome(string s, int low, int high, int skipped){
        while(low <= high){
            if(skipped > 1){ return false; }
            if(s[low] != s[high]){
                // skipped++;
                // if(skipped < 1){
                return (checkPalindrome(s, low, high-1, skipped+1) || checkPalindrome(s, low+1, high, skipped+1));   
                // }else{
                //     return false;
                // }
            }else{
                low++; high--;
            }
        }
        return true;
    }
};