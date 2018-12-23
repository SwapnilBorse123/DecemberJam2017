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
    bool isLongPressedName(string name, string typed) {
        if(name.empty() && typed.empty()){ return true; }
        if(name.empty()){return false;}
        int i = 0, _i = 0, j = 0, _j = 0;
        while(i < name.length()){
            
            while((_i < name.length()) && (name[_i] == name[i])) {++_i;}
            
            //if(_j >= typed.length() && i < name.length()) {return false;}
            while((_j < typed.length()) && (typed[_j] == typed[j]) && (typed[_j] == name[i])) {++_j;}
            if((_j - j) < (_i - i)){
                return false;
            }
            //cout << name[i] <<" in name: " << (_i - i) << "\t" << typed[j] << " in typed: " << (_j - j) << endl;
            i = _i;
            j = _j;
        }
        // if((typed.length() - j) < (name.length() - i)){
        //     return false;
        // }
        if(!(i == name.length() && j == typed.length())){
            return false;
        }
        return true;
    }
};