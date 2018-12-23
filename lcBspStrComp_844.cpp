/*
Date: 12/22/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        if(S.empty() && T.empty()){
            return true;
        }
        if(S.empty() || T.empty()){
            return false;
        }
        int i = S.length()-1, j = T.length()-1, sCnt = 0, tCnt = 0;
        while(i >= 0 || j >= 0){
            while(i>=0 && !(S[i] ^ '#') || sCnt > 0){
                if(!(S[i] ^ '#')){
                    ++sCnt;
                    --i;
                }else if(sCnt > 0){ --i; --sCnt;}
            }
            while(j>=0 && !(T[j] ^ '#') || tCnt > 0){
                if(!(T[j] ^ '#')){
                    ++tCnt;
                    --j;
                }else if(tCnt > 0){ --j; --tCnt;}
            }
            if(i>=0 && j>=0 && (S[i] ^ T[j])){ 
                cout << S[i] << " " << T[j] << endl;
                return false;
            } else if(i>=0 && j>=0 && !(S[i] ^ T[j])){ 
                cout << S[i] << " equals " << T[j] << endl;
                --i; --j; 
            }
            if(i < 0 && j >= 0 && (T[j] ^ '#')){
                return false;
            }else if(j < 0 && i >= 0 && (S[i] ^ '#')){
                return false;
            }
        }
        //if(i < 0 && j < 0){ return true; }
        return true;
    }
};