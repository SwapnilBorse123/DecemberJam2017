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
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(1){
            string num1 = "", num2 = "";
            while(version1[i] != '.' && i < version1.length()){
                num1 = num1 + version1[i];
                i++;
            }
            while(version2[j] != '.' && j < version2.length()){
                num2 = num2 + version2[j];
                j++;
            }
            //cout << num1 << " " << num2 << endl;
            
            if(stoi(num1) < stoi(num2)){
                return -1;
            }else if(stoi(num1) > stoi(num2)){
                return 1;
            }
            if(i >= version1.length() || j >= version2.length()){
                break;
            }
            i++; j++;
        }
        if(i >= version1.length() && j >= version2.length()){
            return 0;
        }else if(i >= version1.length()){
            //string num2 = "";
            while(j++ < version2.length()){
                //num2 = num2 + version2[j];
                if(version2[j] >= 49 && version2[j] <= 57){
                    return -1;
                }
            }
            return 0;
            // if(stoi(num2) > 0){
            //     return -1;   
            // }else{
            //     return 0;
            // }
        }else{
            //string num1 = "";
            while(i++ < version1.length()){
                if(version1[i] >= 49 && version1[i] <= 57){
                    return 1;
                }
                //num1 = num1 + version1[i];
            }
            return 0;
            // if(stoi(num1) > 0){
            //     return 1;   
            // }else{
            //     return 0;
            // }
        }
    }
};