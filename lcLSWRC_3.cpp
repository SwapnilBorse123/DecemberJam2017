/*
hash[s[low]]++;
        while(low < high && high < s.length()){
            while(high < s.length() && hash[s[high]] < 1){
                hash[s[high]]++;
                high++;
            }
            cLen = high - low;
            cout << s[low] << " to " << s[high] << " : " << cLen << endl;
            if(cLen > max){
                max = cLen;
            }
            high++;
            int temp = low;
            while(temp <= high && s[temp] != s[high]){ temp++; }
            if((temp ^ high)){
                low = temp+1; 
            }
        }
        return max;
*/


/*
    Date: 12/29/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int count[256] = {0}, lInd[256];
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        memset(lInd, -1, sizeof(int)*256);
        int low = 0, high = 1, max = 1, cLen = 0, skipIdx = -1;
        for(int i = 0; i < s.length(); ++i){
            if(count[s[i]] == 0){
                count[s[i]]++;
                cLen++; //skipIdx++;
            }else{
                if(cLen > max){
                    max = cLen;
                    //cout << "max till " << s[i] <<" "<< max << endl; 
                }
                if(lInd[s[i]] > skipIdx){
                    cLen = i - lInd[s[i]];
                    skipIdx = lInd[s[i]];
                    //cout << "till " << s[i] << " " << cLen << endl;
                }else{
                    cLen++;
                }
                //cout << "till " << s[i] << " " << cLen << endl;
            }
            lInd[s[i]] = i;
            //cout << s[i] << " " << lInd[s[i]] << "\n";
        }
        //cout << cLen << endl;
        return cLen > max ? cLen : max;
    }
};