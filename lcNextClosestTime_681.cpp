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
    string nextClosestTime(string time) {
        int avDig = 0, mxMin = 60, mxHr = 24, cMin = 0, cHr = 0;
        for(int i = 0; i < time.length(); ++i){
            avDig |= (1 << time[i]-'0');
        }
        int gMin = (time[3]-'0')*10 + (time[4]-'0');
        int gHr = (time[0]-'0')*10 + (time[1]-'0');
        
        bool ifMinRot = false;
        
        //char* result = new char[6]; int rIdx = 
        string result = "";
        
        //find next possible min with available digit
        int valMin = getNextValMin(gMin, avDig, &ifMinRot);
        // cout << "next valid minute: " << valMin << endl;
        int _valMin = valMin;
        
        if(!ifMinRot){
            //result = result + time[0] + time[1] + ":";
            //cout << "if block result " << result << endl;
            //while(valMin > 0){
                // int tmpDig = valMin % 10;
                // char tmpChr = tmpDig + '0';
                // result = result + tmpChr;
                // valMin = valMin/10;
            //}
            if(valMin >= 10){
                  result = time.substr(0, 3) + to_string(valMin);
            }else{
                result = time.substr(0, 3) + "0" + to_string(valMin);
            }
            // if(_valMin < 10){
            //     char tmpChr = 0 + '0';
            //     result = result + tmpChr;
            // }
            // //cout << "time[0]: " << time[0] << " time[1]: "<< time[1] << " result: " << result << endl;
            // cout << result << endl;
            return result;
        }else{
            int valHr = getNextValHr(gHr, avDig);
            // cout << "valid hour: " << valHr << endl;
            // int _valHr = valHr;
            // while(valMin > 0){
            //     int tmpDig = valMin % 10;
            //     char tmpChr = tmpDig + '0';
            //     result = tmpChr + result;
            //     valMin = valMin/10;
            // }
            // if(_valMin < 10){
            //     char tmpChr = 0 + '0';
            //     result = tmpChr + result;
            // }
            // cout << "minutes result: " << result << endl;
            // result = ":" + result;
            // while(valHr > 0){
            //     int tmpDig = valHr % 10;
            //     char tmpChr = tmpDig + '0';
            //     result = tmpChr + result;
            //     valHr = valHr/10;
            // }
            // if(_valHr < 10){
            //     char tmpChr = 0 + '0';
            //     result = tmpChr + result;
            // }
            // cout << "result: " << result;
            if(valHr >= 10){
                result += to_string(valHr);    
            }else{
                result += "0" + to_string(valHr);
            }
            if(valMin >= 10){
                  result += ":" + to_string(valMin);
            }else{
                result += ":0" + to_string(valMin);
            }
            return result;
        }
    }
    
    int getNextValMin(int gMin, int avDig, bool* ifMinRot){
        int cMin = 0;
        while(1){
            gMin++;
            cMin = gMin % 60;
            if(cMin == 0){ // we took a rotation for minute hand
                *ifMinRot = true;
            }
            if(valDigs(cMin, avDig)){
                //cout << "next val min : " << cMin << endl;
                return cMin;
            }
        }
    }
    
    int getNextValHr(int gHr, int avDig){
        int cHr = 0;
        while(1){
            gHr++;
            cHr = gHr % 24;
            if(valDigs(cHr, avDig)){
                //cout << "next val Hr: " << cHr << endl;
                return cHr;
            }
        }
    }
    
    bool valDigs(int cMin, int avDig){
        //cout << "checking: " << cMin << endl;
        if(cMin < 10 && !(avDig & (1))){
            return false;
        }
        while(1){
            int tmpDig = cMin % 10;
            if(!(avDig & (1 << tmpDig))){
                return false;
            }
            cMin = cMin / 10;
            if(cMin == 0){
                break;
            }
        }
        return true;
    }
};