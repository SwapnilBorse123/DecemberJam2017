/*
    Date: 12/27/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty()){
            return 0;
        }
        int low = 0, high = 0, tLen = 0, rIdx = 0;
        while(high < chars.size()){
            int count = 0;
            while(chars[high] == chars[low]){
                count++;
                high++;
            }
            chars[rIdx++] = chars[low];
            tLen += ceil(log10(count)) + 1;
            //cout << chars[low] << " : " << count << " : " << tLen << endl;
            if(count > 1 && count < 10){
                string cStr = to_string(count);
                chars[rIdx++] = cStr[0];
            }else if(count >= 10){
                //chars[rIdx++] = chars[low];
                //tLen += ceil(log(count)) + 1;
                string cStr = to_string(count);
                for(int i = 0; i < cStr.length(); ++i){
                    chars[rIdx++] = cStr[i];
                }
            }
            low = high;
        }
        //cout << "total length: " << tLen;
        return tLen;
    }
};