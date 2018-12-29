class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < B.size(); ++j){
                if(!(A[i] ^ B[j])){
                    res.emplace_back(j);
                    break;
                }
            }
        }
        return res;
    }
};