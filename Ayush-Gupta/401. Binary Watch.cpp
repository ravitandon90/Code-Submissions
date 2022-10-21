class Solution {
public:
    string ToString(int hour, int minute){
        return to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
    }
    int bits(int n){
        int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int n) {
        int hour,minute;
        vector<string> res;
        for(hour=0;hour<12;hour++){
            for(minute=0;minute<60;minute++){
                if(bits(hour)+bits(minute)==n) res.push_back(ToString(hour,minute));
            }
        }
        return res;
    }
};
