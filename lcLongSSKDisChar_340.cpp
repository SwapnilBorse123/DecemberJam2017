# define ALPHABET 500
class Solution {
public:
    int cntArr[ALPHABET];
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s == ""){
            return 0;
        }
        int curMax = 0, max = 0;
        int l = 0, h = 0;
        //memset(cntArr, 0, sizeof(cntArr));
        for(int i = 0; i < ALPHABET; ++i){
            cntArr[i] = 0;
        }
        //cntArr[s[h]-'a']++; // initialization
        //h++;
        while(l <= h){
            
            if(chkIfValid(k)){
                curMax = h-l;
                if(h >= s.length()) break;
                cntArr[(int)s[h]]++;
                h++;
            }else{
                if(curMax > max){
                    max = curMax;
                }
                curMax = 0;
                cntArr[(int)s[l]]--;
                l++;
            }
        }
        if(curMax > max){
            max = curMax;
        }
        return max;
    }
    
    bool chkIfValid(int k){
        int curCnt = 0;
        for(int i = 0; i < ALPHABET; ++i){
            if(cntArr[i] > 0){
                curCnt++;
            }
            if(curCnt > k){
                return false;
            }
        }
        return true;
    }
};