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
    int countPrimeSetBits(int L, int R) {
        if(L > R){
            return 0;
        }
        int total = 0;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
        for(int i = L; i <= R; ++i){
            if(binary_search(primes.begin(), primes.end(), __builtin_popcount(i))){
                total++;
            }
        }
        return total;
    }
};