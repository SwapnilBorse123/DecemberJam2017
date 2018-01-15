#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		/*if(m == n){
			return m;
		}
        int hash = INT_MAX, max = sizeof(int)*8 - 1;
		while(hash != 0){
			for(int i = sizeof(int)*8 - 1; i >= 0; --i){
				if(!(m & (1 << i))){
					hash &= ~(1 << i);
                    //max--;
				}
			}
			m++;
			if(m > n){
				break;
			}
		}
		return hash;*/
		return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->rangeBitwiseAnd(26,30) << endl;
	return 0;
}