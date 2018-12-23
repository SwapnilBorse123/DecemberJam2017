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
    //vector<int> res;
    vector<int> diffWaysToCompute(string input) {
        if(input.empty()){
            vector<int> res;
            return res;
        }
        return solve(input);
        //return res;
    }
    
    vector<int> solve(string input){
        vector<int> res;
        // base case
        if(!containsSign(input)){
            res.push_back(stoi(input));
            return res;    
        }else{
            for(int i = 0; i < input.length(); ++i){
                char sign;
                if(!(input[i]^'+') || !(input[i]^'-') || !(input[i]^'*')){
                    sign = input[i];
                    // cout << sign << " ";
                    // cout << input.substr(0, i-0) << " " << input.substr(i+1, input.length()-1-i) << endl;
                    vector<int> leftRes = solve(input.substr(0, i-0));
                    vector<int> rightRes = solve(input.substr(i+1, input.length()-1-i));
                    for(auto &il : leftRes){
                        for(auto &ir : rightRes){
                            switch(sign){
                                case '+': {
                                    res.push_back(il + ir);
                                    break;
                                }
                                case '-':{
                                    res.push_back(il - ir);
                                    break;
                                }
                                default:{
                                    res.push_back(il * ir);
                                    break;
                                }
                            }       
                        }
                    }
                }
            }   
        }
        // cout<< "res content: ";
        // for(auto &it: res){
        //     cout << it << " ";
        // }
        // cout<< "\n";
        return res;
    }
    
    bool containsSign(string input){
        if(input.find("*")!=std::string::npos || input.find("+")!=std::string::npos || input.find("-")!=std::string::npos){
            return true;
        }
        return false;
    }
};