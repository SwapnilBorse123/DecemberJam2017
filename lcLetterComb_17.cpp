/*
author: Swapnil Borse
date: 10th Oct'18
*/

class Solution {
public:
    std::map<int, string> digMap = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return result;
        }else{
            char* currComb = (char*)malloc(sizeof(char) * digits.length() + sizeof(char));
            util(currComb, 0, 0, 0, digits);
            return result;
        }
    }
    
    void util(char* currComb, int cCIdx, int dIdx, int crStrIdx, string digits){
        if(cCIdx == digits.length()){
            currComb[cCIdx] == '\0';
            result.push_back(currComb);
            return;
        }
        string currStr = digMap.at(digits[dIdx]-'0');
        for(int i = 0; i < currStr.length(); i++){
            currComb[cCIdx] = currStr[i];
            util(currComb, cCIdx+1, dIdx+1, crStrIdx, digits);
        }
    }
};