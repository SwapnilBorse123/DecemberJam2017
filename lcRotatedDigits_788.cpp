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
    int rotatedDigits(int N) {
        int count = 0;
        for(int i = 1; i <= N; ++i){
            int curNum = i;
            bool onlyMirrors = true, isGood = true;
            while(curNum > 0){
                int dig = curNum % 10;
                if(dig == 3 || dig == 4 || dig == 7){
                    isGood = onlyMirrors = false;
                    break;
                }else if(dig == 2 || dig == 5 || dig == 6 || dig == 9){
                    onlyMirrors = false;
                }
                curNum = curNum / 10;
            }
            if(!onlyMirrors && isGood){
                //cout << i << endl;
                count++;
            }
        }
        return count;
    }
};