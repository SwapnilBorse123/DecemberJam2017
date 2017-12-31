class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        if(x < 0){
            isNegative = true;
            x = -x;
        }
        
        int _revNum = 0, revNum = 0;
        while(x != 0){
            int thisDigit = x % 10;
            revNum = (revNum * 10) + thisDigit;
            
            if((revNum - thisDigit) / 10 != _revNum){
                return 0;
            }
            
            _revNum  = revNum;
            x = x/10;
        }
        if(isNegative){
            return -revNum;
        }else{
            return revNum;
        }
    }
};