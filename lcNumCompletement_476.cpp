class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        bool consider = false;
        for(int i = sizeof(int)*8 - 1; i >= 0; --i){
            if(!(num & (1 << i)) && !consider){
                continue;    
            }else{
                if(!(num & (1 << i))){
                    ans = ans | (1 << i);
                }
                consider = true;
            }
        }
        return ans;
    }
};