class Solution {
public:
    string temp;
    int vis[781];
    void helper(int i, int j, int k, int sumHrs, int sumMins, vector<int> &hrs, vector<int> &mins, vector<string> &result){
        if(sumHrs>=12 || sumMins>=60 || vis[(sumHrs*60)+sumMins]==1){
            return;
        }
        if(k==0){
            temp="";
            vis[(sumHrs*60)+sumMins]=1;
            if(sumHrs >= 10){
                temp.push_back('1');
            }
            temp.push_back((char)(sumHrs%10 + '0'));
            temp.push_back(':');
            temp.push_back((char)(sumMins/10 + '0'));
            temp.push_back((char)(sumMins%10 + '0'));
            result.push_back(temp);
            return;
        }
        if(i<hrs.size()){
            helper(i+1, j, k-1, sumHrs+hrs[i], sumMins, hrs, mins, result);
            helper(i+1, j, k, sumHrs, sumMins, hrs, mins, result);
        }
        if(j<mins.size()){
            helper(i, j+1, k-1, sumHrs, sumMins+mins[j], hrs, mins, result);
            helper(i, j+1, k, sumHrs, sumMins, hrs, mins, result);
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn==9 || turnedOn==10){
            return {};
        }
        if(turnedOn==0){
            return {"0:00"};
        }
        vector<int> hrs={1,2,4,8}, mins={1,2,4,8,16,32};
        memset(vis, 0, sizeof(vis));
        vector<string> result;
        helper(0, 0, turnedOn, 0, 0, hrs, mins, result);
        return result;
    }
};
