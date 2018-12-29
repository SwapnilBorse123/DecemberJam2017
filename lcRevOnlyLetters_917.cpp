
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
    string reverseOnlyLetters(string S) {
        int low = 0, high = S.length()-1;
        while(low < high){
            while(low<S.length() && !((S[low]>=97 && S[low]<=122) || (S[low]>=65 && S[low]<=90))){
                //cout << "skipping: " << S[low] << endl;
                low++;
            }
            while(high>=0 && !((S[high]>=97 && S[high]<=122) || (S[high]>=65 && S[high]<=90))){
                //cout << "skipping: " << S[high] << endl;
                high--;
            }
            if(low < high){
                S[low] = S[low] ^ S[high];
                S[high] = S[low] ^ S[high];
                S[low] = S[low] ^ S[high];
                low++; high--;   
            }
        }
        return S;
    }
};