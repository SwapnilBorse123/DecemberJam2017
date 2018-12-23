/*
Date: 12/21/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(s.empty() || s.length() < 4 || s.length() > 12){
            return res;   
        }
        int begin = 0, end = s.length()-1;
        int f, sc, t; 
        for(int i = 0; i < 3; ++i){
            f = begin + i;
            for(int j = 1; j < 4; ++j){
                sc = f + j;
                if(sc < s.length() - 2){
                    for(int k = 1; k < 4; ++k){
                        t = sc + k;
                        if(t < s.length()){
                            // cout << begin << " " << f << " " << sc << " " << t << " -> ";
                            // cout << s.substr(begin, (f-begin)+1) << " ";
                            // cout << s.substr(f+1, (sc-f)) << " ";
                            // cout << s.substr(sc+1, (t-sc)) << " ";
                            // cout << s.substr(t+1, (s.length()-1-t)) << " ";
                            // cout << endl;
                            if(verify(s.substr(begin, (f-begin)+1), s.substr(f+1, (sc-f)), s.substr(sc+1, (t-sc)), s.substr(t+1, (s.length()-1-t)))){
                                string result = s.substr(begin, (f-begin)+1) + "." + s.substr(f+1, (sc-f)) +"."+ s.substr(sc+1, (t-sc)) +"."+ s.substr(t+1, (s.length()-1-t));
                                res.push_back(result);
                            }
                        }
                    }   
                }
            }
        }
        return res;
    }
    
    bool verify(string f, string s, string t, string fo){
        if(f.empty() || s.empty() || t.empty() || fo.empty()){
            return false;
        }
        return (testEach(f) && testEach(s) && testEach(t) && testEach(fo));
    }
    
    bool testEach(string s){
        if (s.length() > 3){
            return false;
        }
        int num = stoi(s);
        //cout << "\"" <<s << "\"" << ":" << num << "<->";
        if(s.length() == 2){
            if(num < 10){
                return false;
            }
        }else if(s.length() == 3){
            if(num < 100 || num > 255){
                return false;
            }
        }
        return true;
    }
};