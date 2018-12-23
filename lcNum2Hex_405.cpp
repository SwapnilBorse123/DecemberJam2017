/*
Date: 12/23/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string toHex(int num) {
        if(!(num ^ 0)){
            return "0";
        }
        string res = "";
        if(num < 0){
            num = abs(num);
            for(int i = (sizeof(int)*8)-1; i >= 0; --i){
                num = num ^ (1 << i);
            }
            num = num + 1; // take 2's complement
        }
        int val = 0, includeVal = 0;
        char ch;
        for(int i = (sizeof(int)*8)-1; i >= 0; --i){
            if(i % 4 == 0){
                if(num & (1 << i)){ val = val + pow(2,(i % 4)); }
                if(val){ includeVal = 1;}
                if(includeVal){
                    if(!(val ^ 10)){ ch = 'a';}
                    else if(!(val ^ 11)){ ch = 'b';}
                    else if(!(val ^ 12)){ ch = 'c';}
                    else if(!(val ^ 13)){ ch = 'd';}
                    else if(!(val ^ 14)){ ch = 'e';}
                    else if(!(val ^ 15)){ ch = 'f';}
                    if(val >= 10 && val <= 15){
                        res = res + ch;
                    }else{
                        res = res + to_string(val);
                    }
                }
                val = 0;
            }else{
                if(num & (1 << i)){
                    val = val + pow(2,(i % 4));
                }   
            }
        }
        return res;
    }
};